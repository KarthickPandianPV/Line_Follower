#ifndef LINE_FOLLOWER_SRC_MOTOR_DRIVER_MOTOR_DRIVER_HPP
#define LINE_FOLLOWER_SRC_MOTOR_DRIVER_MOTOR_DRIVER_HPP

#include "Arduino.h"

namespace line_follower {
class MotorDriver {
 private:
  int standby_pin_;
  int min_pwm_;
  int max_pwm_;

 public:
  MotorDriver();
  ~MotorDriver();

  void Initialize();
  void calibrationMode(int rotation_speed);
  void StopMotors();
  void DriveLeftMotor(int speed);
  void DriveRightMotor(int speed);
  void ControlMotors(float ir_weighted_position, int turn_threshold_low,
                     int turn_threshold_high, int base_speed,
                     int pid_correction);
};
}  // namespace line_follower

#endif  // LINE_FOLLOWER_SRC_MOTOR_DRIVER_MOTOR_DRIVER_HPP