#include <iostream>

#include "Board.h"
#include "CarChess.h"
#include "HorseChess.h"
#include "ElephantChess.h"

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
      if (type == kCar) name = "車";
      else if (type == kHorse) name = "馬";
      else if (type == kElephant) name = color == kRed ? "相" : "象";

      if (color == kRed)
        name = common::recolor(name, common::kRedColor);

      print(name, '\t');
    }
    println();
  }
}

int main() {
  CarChess car_chess_red{kRed};
  CarChess car_chess_blk{kBlk};
  HorseChess horse_chess_red{kRed};
  HorseChess horse_chess_blk{kBlk};
  ElephantChess elephant_chess_red{kRed};
  ElephantChess elephant_chess_blk{kBlk};

  Board board;
  BoardTable &table = board.get_table();

  table[0][0] = &car_chess_blk;
  table[0][1] = &horse_chess_blk;
  table[0][2] = &elephant_chess_blk;
  table[0][6] = &elephant_chess_blk;
  table[0][7] = &horse_chess_blk;
  table[0][8] = &car_chess_blk;

  table[9][0] = &car_chess_red;
  table[9][1] = &horse_chess_red;
  table[9][2] = &elephant_chess_red;
  table[9][6] = &elephant_chess_red;
  table[9][7] = &horse_chess_red;
  table[9][8] = &car_chess_red;

  print_table(table);

  return 0;
}
