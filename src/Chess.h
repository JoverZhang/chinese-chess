#ifndef CHINESE_CHESS_CHESS_H
#define CHINESE_CHESS_CHESS_H

#include <vector>

#include "Board.h"
#include "common/inittypes.h"
#include "tuple"

// { col, row }
typedef std::tuple<i32, i32> Point;

const i32 kMinCol = 0;
const i32 kMinRow = 0;
const i32 kMaxCol = 10;
const i32 kMaxRow = 9;

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

  inline ChessType type() const { return kType; }

  inline ChessColor color() const { return kColor; };

  inline String name() const {
    String name;
    if (kType == kPawn) name = kColor == kRed ? "兵" : "卒";
    else if (kType == kCannon) name = "炮";
    else if (kType == kRook) name = "車";
    else if (kType == kKnight) name = "馬";
    else if (kType == kElephant) name = kColor == kRed ? "相" : "象";
    else if (kType == kMandarin) name = "士";
    else if (kType == kKing) name = kColor == kRed ? "帥" : "将";
    return name;
  }

  virtual std::vector<Point> legal_next_steps(const Board &board,
                                              Point point) const = 0;

 private:
  const ChessType kType;
  const ChessColor kColor;
};

#endif //CHINESE_CHESS_CHESS_H
