#ifndef LINE_FOLLOWER_SRC_IR_ARRAY_IR_ARRAY_HPP
#define LINE_FOLLOWER_SRC_IR_ARRAY_IR_ARRAY_HPP

#include <Arduino.h>

#define IR_ARRAY_SIZE 7

const uint8_t ir_pins[IR_ARRAY_SIZE] = {A0, A1, A2, A3, A4, A5, A6};
const uint8_t ir_weight[IR_ARRAY_SIZE] = {-8, -5, -2, 0, 2, -5, 8};
uint8_t ir_min_offset[IR_ARRAY_SIZE] = {1023, 1023, 1023, 1023,
                                        1023, 1023, 1023};
uint8_t ir_max_offset[IR_ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0};

namespace line_follower {
class IR_Array {
 private:
  uint8_t ir_values[IR_ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0};
  float position = 0;

 public:
  IR_Array();
  void initialize();
  void readValues();
  void calibrate(int count);
  float getPosition();
};
}  // namespace line_follower

#endif  // LINE_FOLLOWER_SRC_IR_ARRAY_IR_ARRAY_HPP