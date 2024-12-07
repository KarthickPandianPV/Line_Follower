#include "main.hpp"

void setup() {
    //Initialize the motor driver
    left.begin(MOTOR_LEFT_PIN1, MOTOR_LEFT_PIN2, MOTOR_LEFT_PWM, 0, 1023, 0, false);
    right.begin(MOTOR_RIGHT_PIN1, MOTOR_RIGHT_PIN2, MOTOR_RIGHT_PWM, 0, 1023, 0, false);

    //Initialize the PID controller
    pid_controller.setGains(1, 0, 0);
    pid_controller.setMinMaxLimits(-255, 255, -255, 255);
    pid_controller.setTarget(0);

    //Initialize the IR Array
  
}

void loop() {

}

