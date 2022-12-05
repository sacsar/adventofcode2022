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

  static auto convert(char c) -> int;

  auto overlapValue() -> int;

  auto itemTypes() -> std::set<char>;
};
}; // namespace day3
#endif
