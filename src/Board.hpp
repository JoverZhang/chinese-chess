#pragma once

#include "Chess.hpp"
#include "common/inittypes.h"

typedef std::vector<std::vector<Chess*>> BoardTable;

class Board {
 public:
  explicit Board() {
    table.resize(9);
    for (size_t i = 0; i < 9; i++) {
      table[i].resize(10);
    }
  };

  virtual ~Board(){};

  BoardTable& get_table() { return table; }

 private:
  BoardTable table;
  ChessColor holder = ChessColor::RED;
};
