#ifndef CHINESE_CHESS_SRC_CANNONCHESS_H_
#define CHINESE_CHESS_SRC_CANNONCHESS_H_

#include "Chess.h"

class CannonChess : public Chess {
 public:
  explicit CannonChess(ChessColor color) : Chess(kCannon, color) {}

  std::vector<Point> legal_next_steps(const Board &board,
                                      Point point) const override;

};

std::vector<Point> CannonChess::legal_next_steps(const Board &board,
                                                 Point point) const {

  std::vector<Point> steps;

  auto[col, row] = point;
  int i;
  for (i = col + 1; i < kMaxCol; i++) {
    Chess *chess = board.get_chess({i, row});
    if (chess != nullptr) {
      break;
    }
    steps.emplace_back(i, row);
  }
  i++;
  for (; i < kMaxCol; i++) {
    Chess *chess = board.get_chess({i, row});
    if (chess != nullptr) {
      if (Chess::color() != chess->color()) {
        steps.emplace_back(i, row);
      }
      break;
    }
  }

  return steps;
}

#endif //CHINESE_CHESS_SRC_CANNONCHESS_H_
