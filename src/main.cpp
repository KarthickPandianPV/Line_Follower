#include "main.hpp"

float kp = 0, ki = 0, kd = 0;
bool calibrate_ir_flag = 0, mode_flag = 0, algorithm_flag = 0;
const uint8_t dfs_value[3] = {0, 0, 0};
const uint8_t ir_switch_pin = 1, mode_switch_pin = 2, algorithm_switch_pin = 3;
const uint8_t dfs_pins[3] = {4, 5, 6};
int calibration_time = 5000;
int rotation_speed = 100;
float ir_weighted_position = 0;
long previous_time = 0;
long current_time = 0;
long dt = 0;
float pid_correction = 0;
float turn_threshold_low = -5;
float turn_threshold_high = 5;
int base_speed = 150;
float *pid_values, *previous_pid_values;
HardwareSerial bluetooth_serial(PA10, PA9);

void setup() {
  Serial.begin(9600);
  ir_array.initialize();
  motor_driver.Initialize();
  pid_controller.setGains(kp, ki, kd);
  previous_time = millis();
}

void loop() {
  if (calibrate_ir_flag) {
    for (int i = 0; i < calibration_time; i++) {
      ir_array.calibrate();
      motor_driver.calibrationMode(rotation_speed);
    }
    calibrate_ir_flag = 0;
  }

  if (bluetooth_serial.available()) {
    pid_values = blue_tooth.getPIDValues(bluetooth_serial);
    if (pid_values[0] != previous_pid_values[0] ||
        pid_values[1] != previous_pid_values[1] ||
        pid_values[2] != previous_pid_values[2]) {
      kp = pid_values[0];
      ki = pid_values[1];
      kd = pid_values[2];
      pid_controller.setGains(kp, ki, kd);
      previous_pid_values[0] = kp;
      previous_pid_values[1] = ki;
      previous_pid_values[2] = kd;
    }
  }
  ir_array.readValues();
  ir_array.normalize();
  ir_weighted_position = ir_array.getPosition();
  current_time = millis();
  dt = current_time - previous_time;
  previous_time = current_time;
  pid_correction = pid_controller.calculateOutput(ir_weighted_position, dt);

  motor_driver.ControlMotors(ir_weighted_position, turn_threshold_low,
                             turn_threshold_high, base_speed, pid_correction);

  if (mode_flag) {
    // dry_run();
  } else {
    //  actual_run();
  }
  if (algorithm_flag) {
    // bfs();
  } else {
    // dfs();
  }
}
