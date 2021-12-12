package org.chinesechess.chess;

import lombok.Getter;

public enum ChessColorEnum {
    RED("红方"),
    BLACK("黑方"),
    ;

    @Getter
    private final String name;

    ChessColorEnum(String name) {
        this.name = name;
    }
}
