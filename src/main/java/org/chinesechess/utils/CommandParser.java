package org.chinesechess.utils;

import org.chinesechess.chess.Point;

public abstract class CommandParser {

    /**
     * 执行命令
     *
     * @param cmd 命令
     * @return 当执行命令 "退出" 时返回 true, 其余一律返回 false
     */
    public boolean exec(String cmd) {
        String[] params = cmd.split(" ");

        // 退出 e.g: quit
        if ("quit".equals(params[0])) {
            Assert.assertEquals(1, params.length, "参数长度不为 1");
            return true;
        }
        // 查看棋盘 e.g: show
        else if ("show".equals(params[0])) {
            Assert.assertEquals(1, params.length, "参数长度不为 1");
            execShow();
        }
        // 行棋提示 e.g: tips 0,0
        else if ("tips".equals(params[0])) {
            Assert.assertEquals(2, params.length, "参数长度不为 2");
            Point point = getPoint(params[1]);
            execTips(point);
        }
        // 行棋 e.g: move 0,0 0,1
        else if ("move".equals(params[0])) {
            Assert.assertEquals(3, params.length, "参数长度不为 3");
            Point from = getPoint(params[1]);
            Point to = getPoint(params[2]);
            execMove(from, to);
        }
        // 非法参数
        else {
            throw new IllegalArgumentException("非法参数");
        }
        return false;
    }

    /**
     * 查看棋盘
     */
    public abstract void execShow();

    /**
     * 行棋提示
     *
     * @param point 棋子位置
     */
    public abstract void execTips(Point point);

    /**
     * 行棋
     *
     * @param from 需要移动棋子的当前位置
     * @param to   需要移动棋子的目标位置
     */
    public abstract void execMove(Point from, Point to);

    private Point getPoint(String point) {
        String[] params = point.split(",");
        Assert.assertEquals(2, params.length, "非法 Point 格式");
        return new Point(Integer.parseInt(params[0]), Integer.parseInt(params[1]));
    }

}
