#include <iostream>

#include "Board.h"
#include "PawnChess.h"
#include "CannonChess.h"
#include "RookChess.h"
#include "KnightChess.h"
#include "ElephantChess.h"
#include "MandarinChess.h"
#include "KingChess.h"

void print_table(BoardTable &table) {
  for (size_t i = 0; i < 10; i++) {
    for (size_t j = 0; j < 9; j++) {
      Chess *chess = table[i][j];
      if (chess == nullptr) {
        String empty = "__";
        if (i > 4) empty = common::recolor(empty, common::kRedColor);
        print(empty, '\t');
        continue;
      }
      ChessType type = chess->type();
      ChessColor color = chess->color();

      String name;
      if (type == kPawn) name = color == kRed ? "兵" : "卒";
      else if (type == kCannon) name = "炮";
      else if (type == kRook) name = "車";
      else if (type == kKnight) name = "馬";
      else if (type == kElephant) name = color == kRed ? "相" : "象";
      else if (type == kMandarin) name = "士";
      else if (type == kKing) name = color == kRed ? "帥" : "将";

      if (color == kRed)
        name = common::recolor(name, common::kRedColor);

      print(name, '\t');
    }
    println();
  }
}

int main() {
  PawnChess pawn_chess_red{kRed};
  PawnChess pawn_chess_blk{kBlk};
  CannonChess cannon_chess_red{kRed};
  CannonChess cannon_chess_blk{kBlk};
  RookChess rook_chess_red{kRed};
  RookChess rook_chess_blk{kBlk};
  KnightChess horse_chess_red{kRed};
  KnightChess horse_chess_blk{kBlk};
  ElephantChess elephant_chess_red{kRed};
  ElephantChess elephant_chess_blk{kBlk};
  MandarinChess mandarin_chess_red{kRed};
  MandarinChess mandarin_chess_blk{kBlk};
  KingChess king_chess_red{kRed};
  KingChess king_chess_blk{kBlk};

  Board board;
  BoardTable &table = board.get_table();

  table[3][0] = &pawn_chess_blk;
  table[3][2] = &pawn_chess_blk;
  table[3][4] = &pawn_chess_blk;
  table[3][6] = &pawn_chess_blk;
  table[3][8] = &pawn_chess_blk;
  table[2][1] = &cannon_chess_blk;
  table[2][7] = &cannon_chess_blk;
  table[0][0] = &rook_chess_blk;
  table[0][1] = &horse_chess_blk;
  table[0][2] = &elephant_chess_blk;
  table[0][3] = &mandarin_chess_blk;
  table[0][4] = &king_chess_blk;
  table[0][5] = &mandarin_chess_blk;
  table[0][6] = &elephant_chess_blk;
  table[0][7] = &horse_chess_blk;
  table[0][8] = &rook_chess_blk;

  table[6][0] = &pawn_chess_red;
  table[6][2] = &pawn_chess_red;
  table[6][4] = &pawn_chess_red;
  table[6][6] = &pawn_chess_red;
  table[6][8] = &pawn_chess_red;
  table[7][1] = &cannon_chess_red;
  table[7][7] = &cannon_chess_red;
  table[9][0] = &rook_chess_red;
  table[9][1] = &horse_chess_red;
  table[9][2] = &elephant_chess_red;
  table[9][3] = &mandarin_chess_red;
  table[9][4] = &king_chess_red;
  table[9][5] = &mandarin_chess_red;
  table[9][6] = &elephant_chess_red;
  table[9][7] = &horse_chess_red;
  table[9][8] = &rook_chess_red;

  print_table(table);

  return 0;
}
