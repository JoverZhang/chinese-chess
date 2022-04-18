#include <iostream>
#include <iterator>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

#include "Board.h"
#include "PawnChess.h"
#include "CannonChess.h"
#include "RookChess.h"
#include "KnightChess.h"
#include "ElephantChess.h"
#include "MandarinChess.h"
#include "KingChess.h"

using common::Result, common::Ok, common::Err;

std::vector<String> split(String &str, const String &pred) {
  std::vector<String> vec;
  boost::split(vec, str, boost::is_any_of(pred), boost::token_compress_on);
  return vec;
}

void print_table(BoardTable &table) {
  println("  ====================================");
  println("+  0   1   2   3   4   5   6   7   8");
  for (size_t i = kMinCol; i < kMaxCol; i++) {
    print(i, ": ");
    for (size_t j = kMinRow; j < kMaxRow; j++) {
      Chess *chess = table[i][j];
      if (chess == nullptr) {
        String empty = "__";
        if (i > 4) empty = common::recolor(empty, common::kRedColor);
        print(empty, "  ");
        continue;
      }

      String name = chess->name();
      if (chess->color() == kRed)
        name = common::recolor(name, common::kRedColor);
      print(name, "  ");
    }
    println();
  }
  println("  ====================================");
}

Result<Point, String> parse_point(String &str) {
  std::vector<String> args = split(str, ",");
  if (args.size() != 2 || args[0].empty() || args[1].empty()) {
    return Err<Point, String>("Invalid point");
  }
  i32 col = common::from_string<i32>(args[0]);
  if (col < kMinCol || kMaxCol <= col) {
    return Err<Point, String>("Invalid col");
  }
  i32 row = common::from_string<i32>(args[1]);
  if (row < kMinRow || kMaxRow <= row) {
    return Err<Point, String>("Invalid row");
  }
  return Ok<Point, String>({col, row});
}

Result<const Chess *, String> handler_move(Board &board,
                                           std::vector<String> &args) {
  if (args.size() != 3) {
    return Err<const Chess *, String>("Invalid input");
  }
  Result<Point, String> from = parse_point(args[1]);
  if (from.is_err()) {
    return Err<const Chess *, String>(from.err().value());
  }
  Result<Point, String> to = parse_point(args[2]);
  if (to.is_err()) {
    return Err<const Chess *, String>(to.err().value());
  }

  // Get source chess
  const Chess *source = board.get_chess(from.ok().value());
  if (source == nullptr) {
    return Err<const Chess *, String>("Chess does not exist");
  }
  if (source->color() != board.holder()) {
    return Err<const Chess *, String>("Holder mismatch");
  }

  // Check target point
  const std::vector<Point> &next_steps =
      source->legal_next_steps(board, from.ok().value());
  if (std::none_of(next_steps.begin(), next_steps.end(),
                   [&](Point p) { return p == to.ok().value(); })) {
    return Err<const Chess *, String>("Illegal move");
  }

  // do move
  const Chess *target = board.get_chess(to.ok().value());
  board.put_chess(from.ok().value(), nullptr);
  board.put_chess(to.ok().value(), const_cast<Chess *>(source));

  return Ok<const Chess *, String>(target);
}

void start_game(Board &board) {
  String line;
  std::vector<String> args;
  for (;;) {
    print_table(board.table());
    String holder_name = board.holder() == kRed ?
                         common::recolor("Red", common::kRedColor) : "Black";
    print("Holder is ", holder_name, ": ");
    std::getline(std::cin, line);
    args = split(line, "\t ");

    if (args[0] == "quit") {
      break;
    }
      // Handler move
    else if (args[0] == "move") {
      Result<const Chess *, String> result = handler_move(board, args);
      if (result.is_err()) {
        println(common::recolor("Err: " + result.err().value(),
                                common::kRedColor));
        continue;
      }
      if (result.ok().value() != nullptr) {
        const Chess *chess = result.ok().value();
        String name = chess->name();
        if (chess->color() == kRed)
          name = common::recolor(name, common::kRedColor);
        println("Be eaten: ", name);
      }
      // Exchange holder
      board.set_holder(board.holder() == kRed ? kBlk : kRed);
    }
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
  BoardTable &table = board.table();

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

  start_game(board);

  return 0;
}
