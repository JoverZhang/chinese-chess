package org.chinesechess.chess;

import lombok.Data;
import lombok.RequiredArgsConstructor;
import org.chinesechess.board.ChessBoard;

import java.util.List;

@Data
@RequiredArgsConstructor
public abstract class Chess {

    /**
     * 棋颜色
     */
    private final ChessColorEnum chessColor;

    /**
     * 列出合法的下一步棋的所有位置
     *
     * @param board 棋盘
     * @param cur   当前棋的位置
     * @return 下一步棋合法的所有位置
     */
    public abstract List<Point> legalNextSteps(ChessBoard board, Point cur);

    /**
     * 获取棋名
     *
     * @return 棋的名称
     */
    public abstract String getChessName();

}
