#include "Board.hpp"
#include <iostream>

int main() {
  Board board;

  BoardTable &table = board.get_table();

  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 10; j++) {
      print(table[i][j]);
    }
    println();
  }

  return 0;
}
