#include "ir_array.hpp"

namespace line_follower {
IR_Array::IR_Array() {}
IR_Array::~IR_Array() {}

void IR_Array::initialize() {
  for (int i = 0; i < IR_ARRAY_SIZE; i++) {
    pinMode(ir_pins[i], INPUT);
  }
}

void IR_Array::readValues() {
  for (int i = 0; i < IR_ARRAY_SIZE; i++) {
    ir_values[i] = analogRead(ir_pins[i]);
  }
}

void IR_Array::calibrate() {
  readValues();
  for (int j = 0; j < IR_ARRAY_SIZE; j++) {
    if (ir_values[j] < ir_min_offset[j]) {
      ir_min_offset[j] = ir_values[j];
    }
    if (ir_values[j] > ir_max_offset[j]) {
      ir_max_offset[j] = ir_values[j];
    }
  }
  Serial.println("IR Calibration done");
}

void IR_Array::normalize() {
  for (int i = 0; i < IR_ARRAY_SIZE; i++) {
    ir_values[i] =
        map(ir_values[i], ir_min_offset[i], ir_max_offset[i], 0, 1000);
  }
}

float IR_Array::getPosition() {
  float weighted_sum = 0;
  float total = 0;
  for (int i = 0; i < IR_ARRAY_SIZE; i++) {
    weighted_sum += ir_values[i] * ir_weight[i];
    total += ir_values[i];
  }
  if (total == 0) {
    return 0;
  }
  position = weighted_sum / total;
  return position;
}
}  // namespace line_follower