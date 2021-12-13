package org.chinesechess.chess;

import com.google.common.collect.Lists;
import org.chinesechess.board.ChessBoard;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class HorseChessTest extends Assertions {

    static Point CP = Point.of(5, 4);

    static Point CP_TL = Point.of(CP.row - 2, CP.col - 1);

    static Point CP_TR = Point.of(CP.row - 2, CP.col + 1);

    static Point CP_BL = Point.of(CP.row + 2, CP.col - 1);

    static Point CP_BR = Point.of(CP.row + 2, CP.col + 1);

    static Point CP_LT = Point.of(CP.row - 1, CP.col - 2);

    static Point CP_LB = Point.of(CP.row + 1, CP.col - 2);

    static Point CP_RT = Point.of(CP.row - 1, CP.col + 2);

    static Point CP_RB = Point.of(CP.row + 1, CP.col + 2);

    @Test
    void testLegalNextSteps() {
        // 中点
        {
            ChessBoard board = createBoard();
            board.putChess(CP, HorseChess.RED);

            assertEquals(
                    Lists.newArrayList(
                            CP_TL, CP_TR,
                            CP_BL, CP_BR,
                            CP_LT, CP_LB,
                            CP_RT, CP_RB),
                    HorseChess.RED.legalNextSteps(board, CP)
            );
        }
        // 敌棋
        {
            ChessBoard board = createBoard();
            board.putChess(CP_TL, HorseChess.BLACK);
            board.putChess(CP_TR, HorseChess.BLACK);
            board.putChess(CP_BL, HorseChess.BLACK);
            board.putChess(CP_BR, HorseChess.BLACK);
            board.putChess(CP_LT, HorseChess.BLACK);
            board.putChess(CP_LB, HorseChess.BLACK);
            board.putChess(CP_RT, HorseChess.BLACK);
            board.putChess(CP_RB, HorseChess.BLACK);
            board.putChess(CP, HorseChess.RED);

            assertEquals(
                    Lists.newArrayList(
                            CP_TL, CP_TR,
                            CP_BL, CP_BR,
                            CP_LT, CP_LB,
                            CP_RT, CP_RB),
                    HorseChess.RED.legalNextSteps(board, CP)
            );
        }
        // 友棋
        {
            ChessBoard board = createBoard();
            board.putChess(CP_TL, HorseChess.RED);
            board.putChess(CP_TR, HorseChess.RED);
            board.putChess(CP_BL, HorseChess.RED);
            board.putChess(CP_BR, HorseChess.RED);
            board.putChess(CP_LT, HorseChess.RED);
            board.putChess(CP_LB, HorseChess.RED);
            board.putChess(CP_RT, HorseChess.RED);
            board.putChess(CP_RB, HorseChess.RED);
            board.putChess(CP, HorseChess.RED);

            assertEquals(0, HorseChess.RED.legalNextSteps(board, CP).size());
        }
        // 卡马脚 上
        {
            ChessBoard board = createBoard();
            board.putChess(Point.of(CP.row - 1, CP.col), HorseChess.RED);
            board.putChess(CP, HorseChess.RED);

            assertEquals(
                    Lists.newArrayList(
                            CP_BL, CP_BR,
                            CP_LT, CP_LB,
                            CP_RT, CP_RB),
                    HorseChess.RED.legalNextSteps(board, CP)
            );
        }
        // 卡马脚 下
        {
            ChessBoard board = createBoard();
            board.putChess(Point.of(CP.row + 1, CP.col), HorseChess.RED);
            board.putChess(CP, HorseChess.RED);

            assertEquals(
                    Lists.newArrayList(
                            CP_TL, CP_TR,
                            CP_LT, CP_LB,
                            CP_RT, CP_RB),
                    HorseChess.RED.legalNextSteps(board, CP)
            );
        }
        // 卡马脚 左
        {
            ChessBoard board = createBoard();
            board.putChess(Point.of(CP.row, CP.col - 1), HorseChess.RED);
            board.putChess(CP, HorseChess.RED);

            assertEquals(
                    Lists.newArrayList(
                            CP_TL, CP_TR,
                            CP_BL, CP_BR,
                            CP_RT, CP_RB),
                    HorseChess.RED.legalNextSteps(board, CP)
            );
        }
        // 卡马脚 右
        {
            ChessBoard board = createBoard();
            board.putChess(Point.of(CP.row, CP.col + 1), HorseChess.RED);
            board.putChess(CP, HorseChess.RED);

            assertEquals(
                    Lists.newArrayList(
                            CP_TL, CP_TR,
                            CP_BL, CP_BR,
                            CP_LT, CP_LB),
                    HorseChess.RED.legalNextSteps(board, CP)
            );
        }
    }

    private static ChessBoard createBoard() {
        return new ChessBoard();
    }

}