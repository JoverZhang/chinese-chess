#ifndef INITTYPES_H
#define INITTYPES_H

#include <cstddef>
#include <cstdint>
#include <sys/types.h>

#include <map>
#include <ostream>
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

namespace common {

enum TextColor {
  kRedColor,
  kBlackColor,
};

const static std::map<TextColor, String> kTextColorMap = {
    {kRedColor, "\033[1;31m"},
    {kBlackColor, "\033[0m"},
};

template<typename... ARGS>
constexpr size_t va_len(ARGS &&... args) { return sizeof...(args); }

void print() {};

void println() { std::cout << std::endl; }

template<typename T, typename... ARGS>
void print(T &&arg, ARGS &&... args) {
  std::cout << arg;
  if (va_len(args...) == 0) return;
  std::cout << ' ';
  print(args...);
}

inline String recolor(const String &text, TextColor color) {
  return kTextColorMap.at(color) + text + kTextColorMap.at(kBlackColor);
}

template<typename T, typename... ARGS>
void println(T &&arg, ARGS &&... args) {
  print(arg, args...);
  println();
}

}

using common::print;
using common::println;

#endif //INITTYPES_H
