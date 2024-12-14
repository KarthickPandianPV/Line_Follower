#include "motor_driver.hpp"

#include "config.hpp"

namespace line_follower {
MotorDriver ::MotorDriver() {
  left_motor_pin1_ = 2;
  left_motor_pin2_ = 3;
  left_motor_pwm_pin_ = 5;
  right_motor_pin1_ = 4;
  right_motor_pin2_ = 7;
  right_motor_pwm_pin_ = 6;
  min_pwm_ = 0;
  max_pwm_ = 255;
}

MotorDriver ::~MotorDriver(){};

void MotorDriver::Initialize() {
  pinMode(standby_pin_, OUTPUT);
  digitalWrite(standby_pin_, HIGH);

  pinMode(left_motor_pin1_, OUTPUT);
  pinMode(left_motor_pin2_, OUTPUT);
  pinMode(left_motor_pwm_pin_, OUTPUT);

  pinMode(right_motor_pin1_, OUTPUT);
  pinMode(right_motor_pin2_, OUTPUT);
  pinMode(right_motor_pwm_pin_, OUTPUT);

  StopMotors();
}

void MotorDriver::StopMotors() {
  digitalWrite(left_motor_pin1_, LOW);
  digitalWrite(left_motor_pin2_, LOW);
  digitalWrite(right_motor_pin1_, LOW);
  digitalWrite(right_motor_pin2_, LOW);

  analogWrite(left_motor_pwm_pin_, 0);
  analogWrite(right_motor_pwm_pin_, 0);
}

void MotorDriver::DriveLeftMotor(int speed) {
  speed = constrain(speed, -max_pwm_, max_pwm_);

  if (speed > 0) {
    digitalWrite(left_motor_pin1_, HIGH);
    digitalWrite(left_motor_pin2_, LOW);
    analogWrite(left_motor_pwm_pin_, speed);
  } else if (speed < 0) {
    digitalWrite(left_motor_pin1_, LOW);
    digitalWrite(left_motor_pin2_, HIGH);
    analogWrite(left_motor_pwm_pin_, -speed);
  } else {
    digitalWrite(left_motor_pin1_, LOW);
    digitalWrite(left_motor_pin2_, LOW);
    analogWrite(left_motor_pwm_pin_, 0);
  }
}

void MotorDriver::DriveRightMotor(int speed) {
  speed = constrain(speed, -max_pwm_, max_pwm_);

  if (speed > 0) {
    digitalWrite(right_motor_pin1_, HIGH);
    digitalWrite(right_motor_pin2_, LOW);
    analogWrite(right_motor_pwm_pin_, speed);
  } else if (speed < 0) {
    digitalWrite(right_motor_pin1_, LOW);
    digitalWrite(right_motor_pin2_, HIGH);
    analogWrite(right_motor_pwm_pin_, -speed);
  } else {
    digitalWrite(right_motor_pin1_, LOW);
    digitalWrite(right_motor_pin2_, LOW);
    analogWrite(right_motor_pwm_pin_, 0);
  }
}

void MotorDriver::calibrationMode(int rotation_speed) {
  DriveLeftMotor(rotation_speed);
  DriveRightMotor(-rotation_speed);
}

void MotorDriver::ControlMotors(float ir_weighted_position,
                                int turn_threshold_low, int turn_threshold_high,
                                int base_speed, int pid_correction) {
  if (ir_weighted_position < turn_threshold_low) {
    // Turn Left
    DriveLeftMotor(0);
    DriveRightMotor(base_speed);
  } else if (ir_weighted_position > turn_threshold_high) {
    // Turn Right
    DriveLeftMotor(base_speed);
    DriveRightMotor(0);
  } else if (ir_weighted_position >= turn_threshold_low &&
             ir_weighted_position < 0) {
    DriveLeftMotor(base_speed - pid_correction);
    DriveRightMotor(base_speed + pid_correction);
  } else if (ir_weighted_position <= turn_threshold_high &&
             ir_weighted_position > 0) {
    DriveLeftMotor(base_speed + pid_correction);
    DriveRightMotor(base_speed - pid_correction);
  }
}

}  // namespace line_follower