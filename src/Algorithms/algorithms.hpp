#ifndef LINE_FOLLOWER_SRC_ALGORITHMS_ALGORITHMS_HPP
#define LINE_FOLLOWER_SRC_ALGORITHMS_ALGORITHMS_HPP
#include <Arduino.h>

#include "Motor_Driver/motor_driver.hpp"
namespace line_follower
{

  class Algorithms
  {
  private:
    MotorDriver motor_driver_;
    char priorityOrder[3] = {};

  public:
    Algorithms();
    ~Algorithms();

    void free_run();
    void dfs(uint8_t mode);
    void bfs();
  };
} // namespace line_follower

#endif // LINE_FOLLOWER_SRC_ALGORITHMS_ALGORITHMS_HPP