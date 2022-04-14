#ifndef CHINESE_CHESS_SRC_CANNONCHESS_H_
#define CHINESE_CHESS_SRC_CANNONCHESS_H_

#include "Chess.h"

class CannonChess : public Chess {
 public:
  explicit CannonChess(ChessColor color) : Chess(kCannon, color) {}

  std::vector<Point> legal_next_steps(const Board &board,
                                      Point &point) const override;

};

std::vector<Point> CannonChess::legal_next_steps(const Board &board,
                                                 Point &point) const {
  return {};
}

#endif //CHINESE_CHESS_SRC_CANNONCHESS_H_
