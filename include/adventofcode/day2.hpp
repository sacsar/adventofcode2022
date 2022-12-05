#ifndef ADVENTOFCODE_DAY2_HPP
#define ADVENTOFCODE_DAY2_HPP

#include <string>
#include <vector>

namespace day2 {

enum Move { Rock = 1, Paper = 2, Scissor = 3 };

enum Player { You, Opponent };

struct Outcome {
  int yourPoints;
  int opponentPoints;
} __attribute__((aligned(8)));

class Result {
public:
  enum Enum { Win, Lose, Draw };

  static auto UseStrategy(Move opponent, Enum result) -> Move {
    switch (result) {
    case Draw:
      return opponent;
      break;
    case Win:
      switch (opponent) {
      case Rock:
        return Paper;
        break;
      case Scissor:
        return Rock;
        break;
      case Paper:
        return Scissor;
      }
    case Lose:
      switch (opponent) {
      case Rock:
        return Scissor;
        break;
      case Paper:
        return Rock;
        break;
      case Scissor:
        return Paper;
        break;
      }
    }
  }
};

class Round {
private:
  Move opponent_;
  Move you_;

public:
  Round(Move, Move);

  auto Score() const -> Outcome;
};

auto load(const std::string &) -> std::vector<Round>;

auto totalScore(const std::string &) -> int;
}; // namespace day2
#endif