#ifndef CHINESE_CHESS_KNIGHTCHESS_H
#define CHINESE_CHESS_KNIGHTCHESS_H

#include "Chess.h"

class KnightChess : public Chess {
 public:
  explicit KnightChess(ChessColor color) : Chess(kKnight, color) {}

  std::vector<Point> legal_next_steps(const Board &board,
                                      Point point) const override;

};

std::vector<Point> KnightChess::legal_next_steps(const Board &board,
                                                 Point point) const {
  return {};
}

#endif //CHINESE_CHESS_KNIGHTCHESS_H
