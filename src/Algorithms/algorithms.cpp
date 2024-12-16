#ifndef LINE_FOLLOWER_SRC_ALGORITHMS_ALGORITHMS_CPP
#define LINE_FOLLOWER_SRC_ALGORITHMS_ALGORITHMS_CPP

#include "algorithms.hpp"

namespace line_follower
{
  Algorithms::Algorithms() {}
  Algorithms::~Algorithms() {}

  void Algorithms::free_run() {}

  void Algorithms::dfs(uint8_t preference)
  {
    switch (preference)
    {
    case 0:
      priorityOrder[0] = 'S';
      priorityOrder[1] = 'R';
      priorityOrder[2] = 'L';
      break;
    case 1:
      priorityOrder[0] = 'S';
      priorityOrder[1] = 'L';
      priorityOrder[2] = 'R';
      break;
    case 2:
      priorityOrder[0] = 'R';
      priorityOrder[1] = 'S';
      priorityOrder[2] = 'L';
      break;
    case 3:
      priorityOrder[0] = 'R';
      priorityOrder[1] = 'L';
      priorityOrder[2] = 'S';
    case 4:
      priorityOrder[0] = 'L';
      priorityOrder[1] = 'S';
      priorityOrder[2] = 'R';
    case 5:
      priorityOrder[0] = 'L';
      priorityOrder[1] = 'R';
      priorityOrder[2] = 'S';
    default:
      priorityOrder[0] = 'S';
      priorityOrder[1] = 'R';
      priorityOrder[2] = 'L';
    }
  }

} // namespace line_follower

#endif // LINE_FOLLOWER_SRC_ALGORITHMS_ALGORITHMS_CPP