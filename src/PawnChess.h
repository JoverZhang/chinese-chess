#ifndef CHINESE_CHESS_SRC_PAWNCHESS_H_
#define CHINESE_CHESS_SRC_PAWNCHESS_H_

#include "Chess.h"

class PawnChess : public Chess {
 public:
  explicit PawnChess(ChessColor color) : Chess(kPawn, color) {}

  std::vector<Point> legal_next_steps(const Board &board,
                                      Point point) const override;

};

std::vector<Point> PawnChess::legal_next_steps(const Board &board,
                                               Point point) const {
  return {};
}

#endif //CHINESE_CHESS_SRC_PAWNCHESS_H_
