package org.chinesechess.chess;

import lombok.Getter;
import org.chinesechess.board.ChessBoard;

import java.util.ArrayList;
import java.util.List;

public class CarChess extends Chess {
    public static final Chess BLACK = new CarChess(ChessColorEnum.BLACK);
    public static final Chess RED = new CarChess(ChessColorEnum.RED);

    @Getter
    private final String chessName = "車";

    public CarChess(ChessColorEnum chessColor) {
        super(chessColor);
    }

    @Override
    public List<Point> legalNextSteps(ChessBoard board, Point cur) {
        List<Point> steps = new ArrayList<>();

        for (int i = cur.row; i > 0; i--) {
            if (board.getChess(cur.col, cur.row - 1) == null) {
                steps.add(new Point(i - 1, cur.col));
            }
        }

        for (int i = cur.row; i < 9; i++) {
            if (board.getChess(cur.col, cur.row + 1) == null) {
                steps.add(new Point(i + 1, cur.col));
            }
        }

        for (int i = cur.col; i < 8; i++) {
            if (board.getChess(cur.col + 1, cur.row) == null) {
                steps.add(new Point(cur.row, i + 1));
            }
        }

        for (int i = cur.col; i > 0; i--) {
            if (board.getChess(cur.col - 1, cur.row) == null) {
                steps.add(new Point(cur.row, i - 1));
            }
        }

        return steps;
    }

}
