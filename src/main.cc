#include <iostream>

#include "Board.h"
#include "CarChess.h"
#include "HorseChess.h"

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

      String name;
      if (chess->type() == kCar) name = "车";
      else if (chess->type() == kHorse) name = "马";

      if (chess->color() == kRed)
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

  Board board;
  BoardTable &table = board.get_table();

  table[0][0] = &car_chess_blk;
  table[0][1] = &horse_chess_blk;
  table[0][7] = &horse_chess_blk;
  table[0][8] = &car_chess_blk;

  table[9][0] = &car_chess_red;
  table[9][1] = &horse_chess_red;
  table[9][7] = &horse_chess_red;
  table[9][8] = &car_chess_red;

  print_table(table);

  return 0;
}
