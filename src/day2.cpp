#include "adventofcode/day2.hpp"
#include <boost/token_functions.hpp>
#include <boost/tokenizer.hpp>
#include <fstream>
#include <iostream>
#include <map>

using namespace boost;

namespace day2 {
const std::map<std::string, Move> move_parse =
    std::map<std::string, Move>{{"A", Rock}, {"B", Paper}, {"C", Scissor},
                                {"X", Rock}, {"Y", Paper}, {"Z", Scissor}};

const std::map<std::string, Result::Enum> result_parse = std::map<std::string, Result::Enum>{
  {"X", Result::Lose},
  {"Y", Result::Draw},
  {"Z", Result::Win}
};

Round::Round(Move opponent, Move you) {
  this->opponent_ = opponent;
  this->you_ = you;
}

auto Round::Score() const -> Outcome {
  // first, check for a draw
  if (you_ == opponent_) {
    return Outcome{you_ + 3, opponent_ + 3};
  }
  bool win;
  switch (you_) {
  case Rock:
    win = opponent_ == Scissor;
    break;
  case Paper:
    win = opponent_ == Rock;
    break;
  case Scissor:
    win = opponent_ == Paper;
    break;
  }
  int scoreFactor = win ? 6 : 0;

  return Outcome{you_ + scoreFactor, opponent_ + (6 - scoreFactor)};
}

auto load(const std::string &input_file) -> std::vector<Round> {
  std::ifstream ifs(input_file);
  std::string line;
  std::vector<Round> rounds;
  char_separator<char> sep{" "};
  while (std::getline(ifs, line)) {
    tokenizer tok{line, sep};

    auto it = tok.begin();

    Move opponent = move_parse.at(*it);
    ++it;
    Result::Enum result = result_parse.at(*it);
    Move you = Result::UseStrategy(opponent, result);
    rounds.push_back({opponent, you});
  }
  return rounds;
}

auto totalScore(const std::string &input_file) -> int {
  auto rounds = load(input_file);
  int total = 0;
  for (auto const &round : rounds) {
    auto result = round.Score();
    total += result.yourPoints;
  }
  return total;
}

} // namespace day2