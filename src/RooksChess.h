#ifndef CHINESE_CHESS_ROOKSCHESS_H
#define CHINESE_CHESS_ROOKSCHESS_H

#include "Chess.h"

class RooksChess : public Chess {
 public:
  explicit RooksChess(ChessColor color) : Chess(kRooks, color) {}

  std::vector<Point> legal_next_steps(const Board &board,
                                      Point &point) const override;

};

std::vector<Point> RooksChess::legal_next_steps(const Board &board,
                                                Point &point) const {
  return {};
}

#endif //CHINESE_CHESS_ROOKSCHESS_H
