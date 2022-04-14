#ifndef CHINESE_CHESS_HORSECHESS_H
#define CHINESE_CHESS_HORSECHESS_H

#include "Chess.h"

class HorseChess : public Chess {
 public:
  explicit HorseChess(ChessColor color) : Chess(kHorse, color) {}

  std::vector<Point> legal_next_steps(const Board &board,
                                      Point &point) const override;

};

std::vector<Point> HorseChess::legal_next_steps(const Board &board,
                                                Point &point) const {
  return {};
}

#endif //CHINESE_CHESS_HORSECHESS_H
