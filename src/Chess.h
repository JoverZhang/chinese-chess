#ifndef CHINESE_CHESS_CHESS_H
#define CHINESE_CHESS_CHESS_H

#include <vector>

#include "Board.h"
#include "common/inittypes.h"
#include "tuple"

// { col, row }
typedef std::tuple<u8, u8> Point;

enum ChessColor {
  kRed,
  kBlk,
};

enum ChessType {
  kPawn,
  kCannon,
  kRook,
  kKnight,
  kElephant,
  kMandarin,
  kKing,
};

class Board;

class Chess {
 public:
  explicit Chess(ChessType type, ChessColor color)
      : kType(type), kColor(color) {}

  virtual ~Chess() = default;

  inline ChessType type() { return kType; }

  inline ChessColor color() { return kColor; };

  virtual std::vector<Point> legal_next_steps(const Board &board,
                                              Point &point) const = 0;

 private:
  const ChessType kType;
  const ChessColor kColor;
};

#endif //CHINESE_CHESS_CHESS_H
