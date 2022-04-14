#ifndef CHINESE_CHESS_CARCHESS_H
#define CHINESE_CHESS_CARCHESS_H

#include "Chess.h"

class CarChess : public Chess {
 public:
  explicit CarChess(ChessColor color) : Chess(kCar, color) {}

  std::vector<Point> legal_next_steps(const Board &board,
                                      Point &point) const override;

};

std::vector<Point> CarChess::legal_next_steps(const Board &board,
                                              Point &point) const {
  return {};
}

#endif //CHINESE_CHESS_CARCHESS_H
