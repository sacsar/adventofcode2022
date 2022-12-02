#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace day1
{

  int topThreeCalories(const std::string& input_file) {
    return 0;
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
