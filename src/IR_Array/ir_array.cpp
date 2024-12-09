#include "ir_array.hpp"

namespace line_follower{
    IR_Array::IR_Array(){
    }

    void IR_Array::begin(){
        for(int i=0; i<IR_ARRAY_SIZE; i++){
            pinMode(irPins[i], INPUT_ANALOG);
        }
    }

    void IR_Array::readValues(){
        for(int i=0; i<IR_ARRAY_SIZE; i++){
            irValues[i] = analogRead(irPins[i]);
        }
    }

    void IR_Array::calibrate(){
        //Implement calibration
    }

    float IR_Array::getError(){
        //Implement getError
    }
}