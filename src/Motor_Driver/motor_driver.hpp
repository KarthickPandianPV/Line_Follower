#ifndef LINE_FOLLOWER_SRC_MOTOR_DRIVER_MOTOR_DRIVER_HPP
#define LINE_FOLLOWER_SRC_MOTOR_DRIVER_MOTOR_DRIVER_HPP

#include "Arduino.h"

namespace line_follower {
class MotorDriver {
 private:
  int left_motor_pin1_;
  int left_motor_pin2_;
  int left_motor_pwm_pin_;
  int right_motor_pin1_;
  int right_motor_pin2_;
  int right_motor_pwm_pin_;
  int min_pwm_;
  int max_pwm_;

 public:
  MotorDriver();
  ~MotorDriver();

  void Initialize();
  void StopMotors();
  void DriveLeftMotor(int speed);
  void DriveRightMotor(int speed);
  void ControlMotors(float ir_weighted_position, int turn_threshold_low,
                     int turn_threshold_high, int base_speed,
                     int pid_correction);
};
}  // namespace line_follower

#endif  // LINE_FOLLOWER_SRC_MOTOR_DRIVER_MOTOR_DRIVER_HPP