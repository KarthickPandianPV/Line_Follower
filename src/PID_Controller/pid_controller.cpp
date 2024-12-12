#include "pid_controller.hpp"

#include <limits>
namespace line_follower {

PIDController::PIDController() {
  kp_ = ki_ = kd_ = 0.0;
  proportional_ = integral_ = derivative_ = 0.0;
  target_ = actual_ = error_ = previous_error_ = 0.0;
  output_ = 0.0;
  min_integral_ = min_output_ = std::numeric_limits<double>::min();
  max_integral_ = max_output_ = std::numeric_limits<double>::max();
  dt_ = 0.0;
}

PIDController::~PIDController() {}

void PIDController::setGains(float kp, float ki, float kd) {
  kp_ = kp;
  ki_ = ki;
  kd_ = kd;
}

void PIDController::setTarget(double target) { target_ = target; }

void PIDController::setMinMaxLimits(double max_integral, double min_integral,
                                    double max_output, double min_output) {
  max_integral_ = max_integral;
  min_integral_ = min_integral;
  max_output_ = max_output;
  min_output_ = min_output;
}

double PIDController::calculateOutput(double actual, double dt) {
  actual_ = actual;
  dt_ = dt;
  error_ = target_ - actual_;

  proportional_ = kp_ * error_;

  derivative_ = kd_ * (error_ - previous_error_) / dt_;

  integral_ += ki_ * (error_ * dt_);
  integral_ = limitToRange(integral_, min_integral_, max_integral_);

  output_ = proportional_ + integral_ + derivative_;
  output_ = limitToRange(output_, min_output_, max_output_);

  return output_;
}
double PIDController::limitToRange(double value, double min, double max) {
  if (value > max)
    return max;
  else if (value < min)
    return min;
  else
    return value;
}

void PIDController::reset() {
  proportional_ = integral_ = derivative_ = 0;
  dt_ = 0;
}

}  // namespace line_follower