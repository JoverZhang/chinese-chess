#pragma once

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#include <iostream>
#include <string>

typedef int8_t i8;
typedef uint8_t u8;
typedef int16_t i16;
typedef uint16_t u16;
typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

typedef std::string String;

void print(){};
void println() { std::cout << std::endl; }

template <typename T, typename... TAIL>
void print(const T &t, TAIL... tail) {
  std::cout << t << ' ';
  print(tail...);
}

template <typename T, typename... TAIL>
void println(const T &t, TAIL... tail) {
  std::cout << t << ' ';
  println(tail...);
}
