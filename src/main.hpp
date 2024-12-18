#ifndef LINE_FOLLOWER_SRC_MAIN_HPP
#define LINE_FOLLOWER_SRC_MAIN_HPP

#include <Arduino.h>

#include "IR_Array/ir_array.hpp"
// #include "Motor_Driver/motor_driver.hpp"
#include "Algorithms/algorithms.hpp"
#include "Bluetooth/bluetooth.hpp"
#include "PID_Controller/pid_controller.hpp"

#define MOTOR_LEFT_PIN1 2
#define MOTOR_LEFT_PIN2 3
#define MOTOR_LEFT_PWM 4

#define MOTOR_RIGHT_PIN1 5
#define MOTOR_RIGHT_PIN2 6
#define MOTOR_RIGHT_PWM 7

using namespace line_follower;

IR_Array ir_array;
PIDController pid_controller;
MotorDriver motor_driver;
Bluetooth blue_tooth;

#endif  // LINE_FOLLOWER_SRC_MAIN_HPP