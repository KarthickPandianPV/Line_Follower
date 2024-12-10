#include "ir_array.hpp"

namespace line_follower {
IR_Array::IR_Array() {}

void IR_Array::initialize() {
  for (int i = 0; i < IR_ARRAY_SIZE; i++) {
    pinMode(ir_pins[i], INPUT_ANALOG);
  }
}

void IR_Array::readValues() {
  for (int i = 0; i < IR_ARRAY_SIZE; i++) {
    ir_values[i] = analogRead(ir_pins[i]);
  }
}

void IR_Array::calibrate(int count) {
  for (int i = 0; i < count; i++) {
    readValues();
    for (int j = 0; j < IR_ARRAY_SIZE; j++) {
      if (ir_values[j] < ir_min_offset[j]) {
        ir_min_offset[j] = ir_values[j];
      }
      if (ir_values[j] > ir_max_offset[j]) {
        ir_max_offset[j] = ir_values[j];
      }
    }
  }
  Serial.println("IR Calibration done");
}

float IR_Array::getPosition() {
  float sum = 0;
  float total = 0;
  for (int i = 0; i < IR_ARRAY_SIZE; i++) {
    sum += ir_values[i] * ir_weight[i];
    total += ir_values[i];
  }
  if (total == 0) {
    return 0;
  }
  position = sum / total;
  return position;
}
}  // namespace line_follower