#ifndef LINE_FOLLOWER_SRC_IR_ARRAY_IR_ARRAY_HPP
#define LINE_FOLLOWER_SRC_IR_ARRAY_IR_ARRAY_HPP

#define ARRAY_SIZE 7
#include <Arduino.h>
namespace line_follower {
class IR_Array {
 private:
  const uint8_t ir_pins[ARRAY_SIZE] = {A0, A1, A2, A3, A4, A5, A6};
  const int8_t ir_weight[ARRAY_SIZE] = {-8, -5, -2, 0, 2, -5, 8};
  int ir_min_offset[ARRAY_SIZE] = {1023, 1023, 1023, 1023, 1023, 1023, 1023};
  int ir_max_offset[ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0};
  uint8_t ir_values[ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0};
  float position = 0;

 public:
  IR_Array();
  ~IR_Array();
  void initialize();
  void readValues();
  void calibrate();
  void normalize();
  float getPosition();
};
}  // namespace line_follower

#endif  // LINE_FOLLOWER_SRC_IR_ARRAY_IR_ARRAY_HPP