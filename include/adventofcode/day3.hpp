#ifndef ADVENTOFCODE_DAY3_HPP
#define ADVENTOFCODE_DAY3_HPP

#include <set>
#include <string>

namespace day3 {
auto run(const std::string &) -> int;

class Rucksack {
private:
  std::set<char> compartment1_;
  std::set<char> compartment2_;

public:
  Rucksack() = default;
  Rucksack(std::string);

  auto overlapValue() -> int;
};
}; // namespace day3
#endif
