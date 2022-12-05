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
  std::vector<Rucksack> group;
  while (std::getline(ifs, line)) {
    auto r = Rucksack(line);
    group.push_back(r);
    if (group.size() == 3) {
      auto one = group.at(0).itemTypes();
      auto two = group.at(1).itemTypes();
      auto three = group.at(2).itemTypes();
      std::set<char> intersection_1;
      std::set<char> intersection;
      std::set_intersection(
          one.begin(), one.end(), two.begin(), two.end(),
          std::inserter(intersection_1, intersection_1.begin()));
      std::set_intersection(intersection_1.begin(), intersection_1.end(),
                            three.begin(), three.end(),
                            std::inserter(intersection, intersection.begin()));
      char intersect = *(intersection.begin());
      total += Rucksack::convert(intersect);
      group.clear();
    }
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

auto Rucksack::convert(char c) -> int {
  int i = static_cast<int>(c);
  if (i >= 97) { // lowercase letter
    return i - 96;
  } // uppercase
  return i - 38;

}

auto Rucksack::overlapValue() -> int {
  std::vector<char> intersection;
  std::set_intersection(compartment1_.begin(), compartment1_.end(),
                        compartment2_.begin(), compartment2_.end(),
                        std::back_inserter(intersection));
  char intersect = intersection.at(0);
  return convert(intersect);
}

auto Rucksack::itemTypes() -> std::set<char> {
  std::set<char> all_items;
  std::set_union(compartment1_.begin(), compartment1_.end(),
                 compartment2_.begin(), compartment2_.end(),
                 std::inserter(all_items, all_items.begin()));
  return all_items;
}

} // namespace day3
