#ifndef LINE_FOLLOWER_IR_ARRAY_IR_ARRAY_HPP
#define LINE_FOLLOWER_IR_ARRAY_IR_ARRAY_HPP

#include "config.hpp"

namespace line_follower{

class IRArray{
    private:
        int ir_values_[kIrArraySize];
        int ir_offsets_min_[kIrArraySize];
        int ir_offsets_max_[kIrArraySize];
        double combined_weighted_value_;

        
    


};



}
#endif //LINE_FOLLOWER_IR_ARRAY_IR_ARRAY_HPP