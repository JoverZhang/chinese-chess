package org.chinesechess.chess;

import lombok.Data;
import lombok.RequiredArgsConstructor;

@Data
@RequiredArgsConstructor
public class Point {

    public final int row;

    public final int col;

}
