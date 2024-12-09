#ifndef LINE_FOLLOWER_SRC_IR_ARRAY_IR_ARRAY_HPP
#define LINE_FOLLOWER_SRC_IR_ARRAY_IR_ARRAY_HPP

#include <Arduino.h>

#define IR_ARRAY_SIZE 7
//IR Pins
const uint8_t irPins[IR_ARRAY_SIZE] = {A0, A1, A2, A3, A4, A5, A6};
//IR Weight
const uint8_t irWeight[IR_ARRAY_SIZE] = {-3, -2, -1, 0, 1, 2, 3};
//IR Offset
uint8_t irOffset[IR_ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0};

namespace line_follower{
    class IR_Array{
        private:
        uint8_t irValues[IR_ARRAY_SIZE]={0,0,0,0,0,0,0};

        public:
        IR_Array();
        void begin();
        void readValues();
        void calibrate();
        float getError();
    };
}


#endif // LINE_FOLLOWER_SRC_IR_ARRAY_IR_ARRAY_HPP