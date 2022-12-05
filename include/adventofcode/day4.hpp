#ifndef ADVENTOFCODE_DAY4_HPP
#define ADVENTOFCODE_DAY4_HPP

#include <string>

namespace day4 {

auto run(const std::string &) -> int;

class Assignment {
private:
  int low_;
  int high_;

public:
  Assignment() = default;
  Assignment(int, int);

  auto contains(const Assignment &) -> bool;

  auto overlaps(const Assignment &) -> bool;
};
} // namespace day4

#endif
