#ifndef CHINESE_CHESS_BOARD_H
#define CHINESE_CHESS_BOARD_H

#include "Chess.h"
#include "common/inittypes.h"

typedef std::vector<std::vector<Chess *>> BoardTable;

class Board {
 public:
  explicit Board() {
    table.resize(10);
    for (size_t i = 0; i < 10; i++) {
      table[i].resize(9);
    }
  };

  BoardTable &get_table() { return table; }

 private:
  BoardTable table;
  ChessColor holder = kRed;
};

#endif //CHINESE_CHESS_BOARD_H
