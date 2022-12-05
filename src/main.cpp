#include "adventofcode/day1.hpp"
#include "adventofcode/day2.hpp"
#include "adventofcode/day3.hpp"
#include "adventofcode/day4.hpp"
#include "boost/program_options.hpp"
#include <iostream>
namespace po = boost::program_options;

auto main(int ac, char *av[]) -> int {
  po::options_description desc("Options");
  desc.add_options()("help", "print this message")("input",
                                                   po::value<std::string>())("day", po::value<int>());

  po::variables_map vm;
  po::store(po::parse_command_line(ac, av, desc), vm);
  po::notify(vm);

  if (vm.count("help") != 0U) {
    std::cout << desc << std::endl;
    return 1;
  }

  std::string input_path = vm["input"].as<std::string>();
  if (vm.count("day") != 0) {
    int day = vm["day"].as<int>();
    switch(day) {
      case 4:
          int result = day4::run(input_path);
          std::cout << result <<std::endl;
        break;
    }
    return 0;
  }

  int result = day4::run(input_path);
  std::cout << result << std::endl;
  return 0;
}
