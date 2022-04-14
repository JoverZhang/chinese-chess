#ifndef CHINESE_CHESS_SRC_COMMON_ELEPHANTCHESS_H_
#define CHINESE_CHESS_SRC_COMMON_ELEPHANTCHESS_H_

#include "Chess.h"

class ElephantChess : public Chess {
 public:
  explicit ElephantChess(ChessColor color) : Chess(kElephant, color) {}

  std::vector<Point> legal_next_steps(const Board &board,
                                      Point &point) const override;

};

std::vector<Point> ElephantChess::legal_next_steps(const Board &board,
                                                   Point &point) const {
  return {};
}
#endif //CHINESE_CHESS_SRC_COMMON_ELEPHANTCHESS_H_
