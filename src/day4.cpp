#include "adventofcode/day4.hpp"
#include <boost/token_functions.hpp>
#include <boost/tokenizer.hpp>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace boost;

namespace day4 {

auto run(const std::string &input_file) -> int {
  std::ifstream ifs(input_file);
  std::string line;
  char_separator<char> sep("-,");
  int contained_count = 0;
  int overlap_count = 0;
  while (std::getline(ifs, line)) {
    tokenizer tok{line, sep};

    auto it = tok.begin();
    int low1 = std::stoi(*it);
    ++it;
    int high1 = std::stoi(*it);
    ++it;
    Assignment first = {low1, high1};
    int low2 = std::stoi(*it);
    ++it;
    int high2 = std::stoi(*it);
    Assignment second = {low2, high2};

    if (first.overlaps(second)) {
      overlap_count++;
    }
    if (first.contains(second) || second.contains(first)) {
      contained_count++;
    }
  }
  return overlap_count;
   //return contained_count;
}

Assignment::Assignment(int low, int high) {
  low_ = low;
  high_ = high;
}

auto Assignment::contains(const Assignment &other) -> bool {
  return low_ <= other.low_ && high_ >= other.high_;
}

auto Assignment::overlaps(const Assignment &other) -> bool {
  return (low_ <= other.low_ && other.low_ <= high_) || (other.low_ <= low_ && low_ <= other.high_);
}
} // namespace day4
