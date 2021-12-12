package org.chinesechess;

import org.chinesechess.board.ChessBoard;
import org.chinesechess.chess.Chess;
import org.chinesechess.chess.HorseChess;
import org.chinesechess.chess.Point;
import org.chinesechess.utils.CommandParser;

import java.util.Scanner;

public class Application {

    public static void main(String[] args) {
        ChessBoard board = new ChessBoard();
        init(board);

        CommandParser commandParser = new CommandParser() {
            @Override
            public void execShow() {
                board.printBoard();
            }

            @Override
            public void execTips(Point point) {
                Chess chess = board.getChess(point);
                System.out.println(chess.legalNextSteps(board, point));
            }

            @Override
            public void execMove(Point from, Point to) {
                if (board.nextStep(from, to)) {
                    System.out.println("吃！！！");
                }
                board.printBoard();
            }
        };
        board.printBoard();

        Scanner sc = new Scanner(System.in);
        for (; ; ) {
            try {
                System.out.printf("当前持方 [%s]：%n", board.getHolder().getName());
                String cmd = sc.nextLine();
                if (commandParser.exec(cmd)) {
                    break;
                }
            } catch (IllegalArgumentException e) {
                System.err.println(e.getMessage());
            }
        }
    }

    private static void init(ChessBoard board) {
        board.putChess(new Point(0, 0), HorseChess.BLACK);
        board.putChess(new Point(0, 1), HorseChess.BLACK);
        board.putChess(new Point(0, 2), HorseChess.BLACK);
        board.putChess(new Point(0, 3), HorseChess.BLACK);
        board.putChess(new Point(0, 4), HorseChess.BLACK);
        board.putChess(new Point(0, 5), HorseChess.BLACK);
        board.putChess(new Point(0, 6), HorseChess.BLACK);
        board.putChess(new Point(0, 7), HorseChess.BLACK);
        board.putChess(new Point(0, 8), HorseChess.BLACK);
        board.putChess(new Point(2, 1), HorseChess.BLACK);
        board.putChess(new Point(2, 7), HorseChess.BLACK);
        board.putChess(new Point(3, 0), HorseChess.BLACK);
        board.putChess(new Point(3, 2), HorseChess.BLACK);
        board.putChess(new Point(3, 4), HorseChess.BLACK);
        board.putChess(new Point(3, 6), HorseChess.BLACK);
        board.putChess(new Point(3, 8), HorseChess.BLACK);

        board.putChess(new Point(9, 0), HorseChess.RED);
        board.putChess(new Point(9, 1), HorseChess.RED);
        board.putChess(new Point(9, 2), HorseChess.RED);
        board.putChess(new Point(9, 3), HorseChess.RED);
        board.putChess(new Point(9, 4), HorseChess.RED);
        board.putChess(new Point(9, 5), HorseChess.RED);
        board.putChess(new Point(9, 6), HorseChess.RED);
        board.putChess(new Point(9, 7), HorseChess.RED);
        board.putChess(new Point(9, 8), HorseChess.RED);
        board.putChess(new Point(7, 1), HorseChess.RED);
        board.putChess(new Point(7, 7), HorseChess.RED);
        board.putChess(new Point(6, 0), HorseChess.RED);
        board.putChess(new Point(6, 2), HorseChess.RED);
        board.putChess(new Point(6, 4), HorseChess.RED);
        board.putChess(new Point(6, 6), HorseChess.RED);
        board.putChess(new Point(6, 8), HorseChess.RED);
    }

}
