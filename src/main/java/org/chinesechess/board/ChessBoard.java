package org.chinesechess.board;

import lombok.Getter;
import org.chinesechess.chess.Chess;
import org.chinesechess.chess.ChessColorEnum;
import org.chinesechess.chess.Point;
import org.chinesechess.utils.PrintUtil;

public class ChessBoard {

    /**
     * 棋盘信息
     */
    private final Chess[][] board = new Chess[10][9];

    /**
     * 游戏当前持方
     */
    @Getter
    private ChessColorEnum holder = ChessColorEnum.RED;

    /**
     * 从棋盘中获取棋子
     *
     * @param point 坐标
     * @return 棋子
     */
    public Chess getChess(Point point) {
        return getChess(point.col, point.row);
    }

    /**
     * 从棋盘中获取棋子
     *
     * @param col 第几列
     * @param row 第几行
     * @return 棋子
     */
    public Chess getChess(int col, int row) {
        return board[row][col];
    }

    /**
     * 放置棋子到棋盘的指定位置
     *
     * @param point 坐标
     * @param chess 棋子
     */
    public void putChess(Point point, Chess chess) {
        board[point.row][point.col] = chess;
    }

    /**
     * 下一步棋
     *
     * @param from 需要移动的棋子位置
     * @param to   需要移动的目标位置
     * @return 当有棋子被吃, 则返回该死亡的棋子, 否则返回 null
     */
    public Chess nextStep(Point from, Point to) {
        // 需要移动的棋子
        Chess chess = getChess(from);
        if (chess == null) {
            throw new IllegalArgumentException("无法移动, " + from + " 没有棋子");
        }
        // 校验持方
        if (chess.getChessColor() != holder) {
            throw new IllegalArgumentException("无法移动, 棋子与持方不匹配");
        }
        // 校验棋子要移动的目标位置是否合法
        if (!chess.legalNextSteps(this, from).contains(to)) {
            throw new IllegalArgumentException("无法移动, 非法目标位置");
        }
        // 需要移动的目标位置
        Chess target = getChess(to);
        // 目标位置为己方棋子
        if (target != null && chess.getChessColor() == target.getChessColor()) {
            throw new IllegalArgumentException("无法移动, 与目标棋颜色相同");
        }
        // 移动 | 吃棋
        putChess(to, chess);
        putChess(from, null);
        // 返回目标位置的棋 (如果有)
        return target;
    }

    /**
     * 交换持方
     */
    public void switchHolder() {
        if (holder == ChessColorEnum.RED) {
            holder = ChessColorEnum.BLACK;
        } else if (holder == ChessColorEnum.BLACK) {
            holder = ChessColorEnum.RED;
        } else {
            throw new IllegalArgumentException("持方状态错误");
        }
    }

    /**
     * 打印棋盘
     */
    public void printBoard() {
        System.out.print("\t");

        for (int col = 0; col < 9; col++) {
            System.out.printf("%d\t", col);
        }
        System.out.println();

        for (int row = 0; row < board.length; row++) {
            Chess[] line = board[row];
            System.out.printf("%d\t", row);
            for (Chess chess : line) {
                if (chess == null) {
                    System.out.print("__\t");
                } else if (chess.getChessColor() == ChessColorEnum.RED) {
                    System.out.printf("%s\t", PrintUtil.red(chess.getChessName()));
                } else if (chess.getChessColor() == ChessColorEnum.BLACK) {
                    System.out.printf("%s\t", chess.getChessName());
                }
            }
            System.out.println();
        }
    }

}
