#ifndef CHINESE_CHESS_SRC_MANDARINCHESS_H_
#define CHINESE_CHESS_SRC_MANDARINCHESS_H_

#include "Chess.h"

class MandarinChess : public Chess {
 public:
  explicit MandarinChess(ChessColor color) : Chess(kMandarin, color) {}

  std::vector<Point> legal_next_steps(const Board &board,
                                      Point &point) const override;

};

std::vector<Point> MandarinChess::legal_next_steps(const Board &board,
                                                   Point &point) const {
  return {};
}

#endif //CHINESE_CHESS_SRC_MANDARINCHESS_H_
