#include <iostream>
#include "boost/program_options.hpp"
#include "adventofcode/day1.hpp"
namespace po = boost::program_options;

int main(int ac, char *av[]) {
  po::options_description desc("Options");
  desc.add_options()("help", "print this message")("input", po::value<std::string>());

  po::variables_map vm;
  po::store(po::parse_command_line(ac, av, desc), vm);
  po::notify(vm);

  if (vm.count("help") != 0U) {
    std::cout<< desc <<std::endl;
    return 1;
  }

  std::string input_path = vm["input"].as<std::string>();
  int result = day1::maxCalories(input_path);
  std::cout << result << std::endl;
  return 0;
}