package org.chinesechess.chess;

import lombok.Getter;
import org.chinesechess.board.ChessBoard;

import java.util.ArrayList;
import java.util.List;

public class HorseChess extends Chess {

    public static final Chess RED = new HorseChess(ChessColorEnum.RED);

    public static final Chess BLACK = new HorseChess(ChessColorEnum.BLACK);

    @Getter
    private final String chessName = "马";

    public HorseChess(ChessColorEnum chessColor) {
        super(chessColor);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public List<Point> legalNextSteps(ChessBoard board, Point cur) {
        List<Point> steps = new ArrayList<>();

        if (cur.row - 2 >= 0 && board.getChess(cur.col, cur.row - 1) == null) {
            // 上左
            if (cur.col - 1 >= 0) {
                steps.add(new Point(cur.row - 2, cur.col - 1));
            }
            // 上右
            if (cur.col + 1 <= 8) {
                steps.add(new Point(cur.row - 2, cur.col + 1));
            }
        }

        if (cur.row + 2 <= 9 && board.getChess(cur.col, cur.row + 1) == null) {
            // 下左
            if (cur.col - 1 >= 0) {
                steps.add(new Point(cur.row + 2, cur.col - 1));
            }
            // 下右
            if (cur.col + 1 <= 8) {
                steps.add(new Point(cur.row + 2, cur.col + 1));
            }
        }

        if (cur.col - 2 >= 0 && board.getChess(cur.col - 1, cur.row) == null) {
            // 左上
            if (cur.row - 1 >= 0) {
                steps.add(new Point(cur.row - 1, cur.col - 2));
            }
            // 左下
            if (cur.row + 1 <= 9) {
                steps.add(new Point(cur.row + 1, cur.col - 2));
            }
        }

        if (cur.col + 2 <= 8 && board.getChess(cur.col + 1, cur.row) == null) {
            // 右上
            if (cur.row - 1 >= 0) {
                steps.add(new Point(cur.row - 1, cur.col + 2));
            }
            // 右下
            if (cur.row + 1 <= 9) {
                steps.add(new Point(cur.row + 1, cur.col + 2));
            }
        }

        return steps;
    }

}
