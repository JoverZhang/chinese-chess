#ifndef CHINESE_CHESS_ROOKCHESS_H
#define CHINESE_CHESS_ROOKCHESS_H

#include "Chess.h"

class RookChess : public Chess {
 public:
  explicit RookChess(ChessColor color) : Chess(kRook, color) {}

  std::vector<Point> legal_next_steps(const Board &board,
                                      Point &point) const override;

};

std::vector<Point> RookChess::legal_next_steps(const Board &board,
                                               Point &point) const {
  return {};
}

#endif //CHINESE_CHESS_ROOKCHESS_H
