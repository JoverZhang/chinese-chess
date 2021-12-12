package org.chinesechess.utils;

import lombok.AccessLevel;
import lombok.NoArgsConstructor;

import java.util.Objects;

@NoArgsConstructor(access = AccessLevel.PRIVATE)
public abstract class Assert {

    public static void assertEquals(Object except, Object value, String msg) {
        if (!Objects.equals(except, value)) {
            fail(msg);
        }
    }

    public static void fail(String msg) {
        throw new IllegalArgumentException(msg);
    }

}
