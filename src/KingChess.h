#ifndef CHINESE_CHESS_SRC_KINGCHESS_H_
#define CHINESE_CHESS_SRC_KINGCHESS_H_

#include "Chess.h"

class KingChess : public Chess {
 public:
  explicit KingChess(ChessColor color) : Chess(kKing, color) {}

  std::vector<Point> legal_next_steps(const Board &board,
                                      Point &point) const override;

};

std::vector<Point> KingChess::legal_next_steps(const Board &board,
                                               Point &point) const {
  return {};
}

#endif //CHINESE_CHESS_SRC_KINGCHESS_H_
