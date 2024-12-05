#ifndef LINE_FOLLOWER_INCLUDE_CONFIG_HPP_
#define LINE_FOLLOWER_INCLUDE_CONFIG_HPP_

int const kLeftMotorPin = 5;
int const kRightMotorPin = 6;
int const kIrArraySize = 5;
int const kIrArrayPins[kIrArraySize] = {1,2,3,4,5};
int const ir_weights_[kIrArraySize] = {-3,-1,0,1,3};




#endif // LINE_FOLLOWER_INCLUDE_CONFIG_HPP_