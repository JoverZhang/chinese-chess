#pragma once

#include <vector>

#include "Board.hpp"
#include "common/inittypes.h"
#include "tuple"

// { col, row }
typedef std::tuple<u8, u8> Point;

enum ChessColor {
  RED,
  BLACK
};

class Board;

class Chess {
 public:
  virtual ~Chess() = 0;

  virtual std::vector<Point> leval_next_steps(const Board &board,
                                              const Point point) const = 0;

  virtual String get_name() const = 0;
};
