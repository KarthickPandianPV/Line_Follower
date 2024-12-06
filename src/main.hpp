#ifndef LINE_FOLLOWER_SRC_MAIN_HPP
#define LINE_FOLLOWER_SRC_MAIN_HPP

#include <Arduino.h>
#include "Motor_Driver/motor_driver.hpp"
#include "PID_Controller/pid_controller.hpp"
#include "IR_Array/ir_array.hpp"

line_follower::PIDController pid_controller;
line_follower::IRArray ir_array;
line_follower::MotorDriver left,right;

#define MOTOR_LEFT_PIN1 2
#define MOTOR_LEFT_PIN2 3
#define MOTOR_LEFT_PWM 4

#define MOTOR_RIGHT_PIN1 5
#define MOTOR_RIGHT_PIN2 6
#define MOTOR_RIGHT_PWM 7


#endif // LINE_FOLLOWER_SRC_MAIN_HPP