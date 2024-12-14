#include "ir_array.hpp"

namespace line_follower {
IR_Array::IR_Array() {}
IR_Array::~IR_Array() {}

void IR_Array::initialize() {
  for (int i = 0; i < ARRAY_SIZE; i++) {
    pinMode(ir_pins[i], INPUT);
  }
}

void IR_Array::readValues() {
  for (int i = 0; i < ARRAY_SIZE; i++) {
    ir_values[i] = analogRead(ir_pins[i]);
  }
}

void IR_Array::calibrate() {
  readValues();
  for (int j = 0; j < ARRAY_SIZE; j++) {
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
  for (int i = 0; i < ARRAY_SIZE; i++) {
    ir_values[i] =
        map(ir_values[i], ir_min_offset[i], ir_max_offset[i], 1000, 0);
  }
}

float IR_Array::calculatePosition() {
  float l_weighted_sum = 0;
  float r_weighted_sum = 0;
  float l_sum = 0;
  float r_sum = 0;
  float position = 0;
  for (int i = 0; i < ARRAY_SIZE; i++) {
    if (i < 3) {
      l_weighted_sum += ir_values[i] * ir_weight[i];
      l_sum += ir_values[i];
    } else if (i > 3) {
      r_weighted_sum += ir_values[i] * ir_weight[i];
      r_sum += ir_values[i];
    }
  }
  position = (l_weighted_sum + r_weighted_sum + (ir_values[3] * ir_weight[3])) /
             (l_sum + r_sum + ir_values[3]);
  l_position = l_weighted_sum / l_sum;
  r_position = r_weighted_sum / r_sum;
  return position;
}

float IR_Array::getLeftPosition() { return l_position; }
float IR_Array::getRightPosition() { return r_position; }
}  // namespace line_follower