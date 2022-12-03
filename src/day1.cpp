#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace day1
{

  int topThreeCalories(const std::string& input_file)
  {
    std::ifstream ifs(input_file);
    std::string line;
    std::vector<int> calorie_heap;
    int calories = 0;
    while (std::getline(ifs, line))
    {
      if (!line.empty())
      {
        std::istringstream iss(line);
        int item = 0;
        iss >> item;
        calories += item;
      }
      else
      {
        if (calorie_heap.size() < 3)
        {
          calorie_heap.push_back(calories);
          if (calorie_heap.size() == 3)
          {
            std::make_heap(calorie_heap.begin(), calorie_heap.end(), std::greater<>());
          }
        }
        else
        {
          if (calories > calorie_heap.front())
          {
            calorie_heap.at(0) = calories;
            std::make_heap(calorie_heap.begin(), calorie_heap.end(), std::greater<>());
          }
        }
        calories = 0;
      }
    }
    int total = 0;
    for (auto const &calorie_count : calorie_heap) {
        total+= calorie_count;
    }
    return total;
  }

  int maxCalories(const std::string& input_file)
  {
    std::ifstream ifs(input_file);

    int max = INT32_MIN;

    std::string line;
    int calories = 0;
    while (std::getline(ifs, line))
    {
      std::cout << line << std::endl;
      if (!line.empty())
      {
        std::istringstream iss(line);
        int item = 0;
        iss >> item;
        calories += item;
      }
      else
      {
        if (calories > max)
        {
          max = calories;
        }
        calories = 0;
      }
    }
    return max;
  }
}  // namespace day1
