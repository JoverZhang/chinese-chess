package org.chinesechess.chess;

import lombok.Getter;
import org.chinesechess.board.ChessBoard;

import java.util.ArrayList;
import java.util.List;

public class ElephantChess extends Chess {
    public static final Chess RED = new ElephantChess(ChessColorEnum.RED);

    public static final Chess BLACK = new ElephantChess(ChessColorEnum.BLACK);

    @Getter
    private final String chessName = "象";

    public ElephantChess(ChessColorEnum chessColor) {
        super(chessColor);
    }

    @Override
    public List<Point> legalNextSteps(ChessBoard board, Point cur) {
        List<Point> steps = new ArrayList<>();

        if (cur.row - 2 >= 5 &&
                cur.row + 2 > 4 &&
                board.getChess(cur.col - 1, cur.row - 1) == null) {
            steps.add(new Point(cur.row - 2, cur.col - 2));
        }

        if (cur.row - 2 >= 5 &&
                cur.row + 2 > 4 &&
                board.getChess(cur.col + 1, cur.row - 1) == null) {
            steps.add(new Point(cur.row - 2, cur.col + 2));
        }

        if (cur.row + 2 <= 9 &&
                cur.row + 2 > 4 &&
                board.getChess(cur.col - 1, cur.row + 1) == null) {
            steps.add(new Point(cur.row + 2, cur.col - 2));
        }

        if (cur.row + 2 <= 9 &&
                cur.row + 2 > 4 &&
                board.getChess(cur.col + 1, cur.row + 1) == null) {
            steps.add(new Point(cur.row + 2, cur.col + 2));
        }

        if (cur.row + 2 <= 2 &&
                board.getChess(cur.col - 1, cur.row + 1) == null) {
            steps.add(new Point(cur.row + 2, cur.col - 2));
        }

        if (cur.row + 2 <= 2 &&
                board.getChess(cur.col + 1, cur.row + 1) == null) {
            steps.add(new Point(cur.row + 2, cur.col + 2));
        }

        if (cur.row + 2 == 4 &&
                cur.col == 0 &&
                board.getChess(cur.col + 1, cur.row + 1) == null) {
            steps.add(new Point(cur.row + 2, cur.col + 2));
        }

        if (cur.row + 2 == 4 &&
                cur.col == 8 &&
                board.getChess(cur.col - 1, cur.row + 1) == null) {
            steps.add(new Point(cur.row + 2, cur.col - 2));
        }
        return steps;
    }


}
