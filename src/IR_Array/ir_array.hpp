#ifndef LINE_FOLLOWER_IR_ARRAY_IR_ARRAY_HPP
#define LINE_FOLLOWER_IR_ARRAY_IR_ARRAY_HPP


#define IR_ARRAY_SIZE           5
int const kIrArrayPins[IR_ARRAY_SIZE]   = {1,2,3,4,5};
int const ir_weights[IR_ARRAY_SIZE]     = {-3,-1,0,1,3};

namespace line_follower{

class IRArray{
    private:
        uint8_t ir_values_[IR_ARRAY_SIZE];
        uint8_t ir_offsets_min_[IR_ARRAY_SIZE];
        uint8_t ir_offsets_max_[IR_ARRAY_SIZE];
        float combined_weighted_value_;

        
    


};



}
#endif //LINE_FOLLOWER_IR_ARRAY_IR_ARRAY_HPP