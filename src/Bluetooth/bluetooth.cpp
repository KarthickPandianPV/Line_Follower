#ifndef LINE_FOLLOWER_SRC_BLUETOOTH_BLUETOOTH_CPP
#define LINE_FOLLOWER_SRC_BLUETOOTH_BLUETOOTH_CPP

#include "bluetooth.hpp"

namespace line_follower {
Bluetooth::Bluetooth() {}
Bluetooth::~Bluetooth() {}

std::vector<String> Bluetooth::splitString(const String& data, char delimiter) {
  std::vector<String> result;
  int start = 0;
  int end = data.indexOf(delimiter);

  while (end != -1) {
    result.push_back(data.substring(start, end));
    start = end + 1;
    end = data.indexOf(delimiter, start);
  }

  result.push_back(data.substring(start));
  return result;
}

float* Bluetooth::getPIDValues(HardwareSerial& serial) {
  static float pidValues[3] = {0.0, 0.0, 0.0};

  if (serial.available()) {
    String data = serial.readStringUntil('\n');
    std::vector<String> values = splitString(data, ',');
    if (values.size() == 3) {
      pidValues[0] = values[0].toFloat();  // Kp
      pidValues[1] = values[1].toFloat();  // Ki
      pidValues[2] = values[2].toFloat();  // Kd
    }
  }

  return pidValues;
}

}  // namespace line_follower

#endif  // LINE_FOLLOWER_SRC_BLUETOOTH_BLUETOOTH_CPP