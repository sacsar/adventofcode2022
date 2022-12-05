#include "adventofcode/day3.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

namespace day3 {

auto run(const std::string &input_path) -> int {
  std::ifstream ifs(input_path);
  std::string line;
  int total = 0;
  while (std::getline(ifs, line)) {
    auto r = Rucksack(line);
    total += r.overlapValue();
  }
  return total;
}

Rucksack::Rucksack(std::string s) {
  size_t num_items = s.size();
  for (size_t i = 0; i < num_items / 2; i++) {
    compartment1_.insert(s.at(i));
  }
  for (size_t j = num_items / 2; j < num_items; j++) {
    compartment2_.insert(s.at(j));
  }
}

auto Rucksack::overlapValue() -> int {
  std::vector<char> intersection;
  std::set_intersection(compartment1_.begin(), compartment1_.end(),
                        compartment2_.begin(), compartment2_.end(),
                        std::back_inserter(intersection));
  char intersect = intersection.at(0);
  std::cout << intersect << std::endl;
  int i = static_cast<int>(intersect);
  if (i >= 97) { // lowercase letter
    return i - 96;
  } // uppercase
  return i - 38;
}
} // namespace day3
