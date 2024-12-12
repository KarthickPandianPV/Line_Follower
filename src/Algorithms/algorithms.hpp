#ifndef LINE_FOLLOWER_SRC_ALGORITHMS_ALGORITHMS_HPP
#define LINE_FOLLOWER_SRC_ALGORITHMS_ALGORITHMS_HPP

#include <Arduino.h>

namespace line_follower {

class Algorithms {
 public:
  Algorithms();
  ~Algorithms();

  void dfs(uint8_t mode);
  void bfs();
};
}  // namespace line_follower

#endif LINE_FOLLOWER_SRC_ALGORITHMS_ALGORITHMS_HPP