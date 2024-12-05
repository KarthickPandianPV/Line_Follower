#ifndef LINE_FOLLOWER_SRC_PID_CONTROLLER_PID_CONTROLLER_HPP
#define LINE_FOLLOWER_SRC_PID_CONTROLLER_PID_CONTROLLER_HPP

namespace line_follower{

class PIDController{
    private:
        double kp_;
        double ki_;
        double kd_;
        double target_;
        double actual_;
        double error_;
        double previous_error_;
        double derivative_;
        double proportional_;
        double integral_;
        double output_;
        double max_integral_;
        double min_integral_;
        double max_output_;
        double min_output_;
        double dt_;

        double limitToRange(double value, double min, double max);
        
        
    public:
        PIDController();
        ~PIDController();
        void setGains(double kp, double ki, double kd);
        void setTarget(double target);
        void setMinMaxLimits(double min_integral,double max_integral, double min_output, double max_output);
        double calculateOutput(double actual,double dt);
        void reset();
};


}




#endif // LINE_FOLLOWER_SRC_PID_CONTROLLER_PID_CONTROLLER_HPP