#ifndef CHINESE_CHESS_BOARD_H
#define CHINESE_CHESS_BOARD_H

#include "Chess.h"
#include "common/inittypes.h"

typedef std::vector<std::vector<Chess *>> BoardTable;

class Chess;

class Board {
 public:
  explicit Board() {
    table_.resize(10);
    for (size_t i = 0; i < 10; i++) {
      table_[i].resize(9);
    }
  };

  inline BoardTable &table() { return table_; }
  inline ChessColor &holder() { return holder_; }
  inline void set_holder(ChessColor holder) { holder_ = holder; }

  const Chess *get_chess(Point point) const {
    auto[col, row] = point;
    return table_[col][row];
  }

  void put_chess(Point point, Chess *chess) {
    auto[col, row] = point;
    table_[col][row] = chess;
  }

 private:
  BoardTable table_;
  ChessColor holder_ = kRed;
};

#endif //CHINESE_CHESS_BOARD_H
