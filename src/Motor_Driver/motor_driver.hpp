#ifndef LINE_FOLLOWER_SRC_MOTOR_DRIVER_MOTOR_DRIVER_HPP
#define LINE_FOLLOWER_SRC_MOTOR_DRIVER_MOTOR_DRIVER_HPP

#define DEFAULT_SPEED 255
#include <Arduino.h>

namespace line_follower{
    class MotorDriver{
        private:
            int _pin1;
            int _pin2;
            int _pwmPin;
            int _minInput;
            int _maxInput;
            int _minNeutral;
            int _maxNeutral;
            int _controlValue;
            int _controlValueRamp;
            int _minPWM;
            int _maxPWM;
            int _rampTime;
            boolean _neutralBrake;
            boolean _invert;
            unsigned long _previousMillis = 0;
            unsigned long _previousMillisBrake = 0;
            byte _state = 0;
            byte _forward;
            byte _reverse;
            byte _upwards;
            byte _downwards;
        public:
            MotorDriver();
            void begin(int pin1, int pin2, int pwmPin, int minInput, int maxInput, int neutralWidth, boolean invert);
            boolean drive(int controlValue, int minPWM, int maxPWM, int rampTime, boolean neutralBrake);
            boolean brakeActive();

    };
}
#endif // LINE_FOLLOWER_SRC_MOTOR_DRIVER_MOTOR_DRIVER_HPP