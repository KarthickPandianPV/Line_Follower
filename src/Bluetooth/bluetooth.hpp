#ifndef LINE_FOLLOWER_SRC_BLUETOOTH_BLUETOOTH_HPP
#define LINE_FOLLOWER_SRC_BLUETOOTH_BLUETOOTH_HPP

#include <Arduino.h>
#include <SoftwareSerial.h>
#define BT_RX_PIN 10
#define BT_TX_PIN 11

namespace line_follower {
class Bluetooth {
 public:
  Bluetooth();
  ~Bluetooth();
  float* getPIDValues(HardwareSerial& serial);
  std::vector<String> splitString(const String& data, char delimiter);
};

}  // namespace line_follower

#endif  // LINE_FOLLOWER_SRC_BLUETOOTH_BLUETOOTH_HPP