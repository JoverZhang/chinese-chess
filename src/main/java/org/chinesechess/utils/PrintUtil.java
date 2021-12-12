package org.chinesechess.utils;

import lombok.AccessLevel;
import lombok.NoArgsConstructor;

@NoArgsConstructor(access = AccessLevel.PRIVATE)
public abstract class PrintUtil {

    private static final String ANSI_RESET = "\u001B[0m";

    private static final String ANSI_RED = "\u001B[31m";

    public static String red(String str) {
        return ANSI_RED + str + ANSI_RESET;
    }

}
