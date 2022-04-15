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

/**
 * Define some Common tools
 */
namespace common {

template<typename... ARGS>
constexpr size_t va_len(ARGS &&... args) { return sizeof...(args); }

/// empty print
void print();
/// print a parameter
template<typename T>
void print(T &&arg);
/// print variable length parameters
template<typename T, typename... ARGS>
void print(T &&arg, ARGS &&... args);
/// print tuple
template<typename... T>
void print(const std::tuple<T...> &tuple);

/// print \n
void println();
/// print variable length parameters and with a '\n'
template<typename T, typename... ARGS>
void println(T &&arg, ARGS &&... args);


/// Definition

void print() {}

template<typename T>
void print(T &&arg) {
  std::cout << arg;
}

template<typename TUPLE, size_t... I>
void print_tuple(const TUPLE &tuple, std::index_sequence<I...>) {
  print("(");
  (..., (print(I == 0 ? "" : ", ", std::get<I>(tuple))));
  print(")");
}
template<typename... T>
void print(const std::tuple<T...> &tuple) {
  print_tuple(tuple, std::make_index_sequence<sizeof...(T)>());
}

template<typename T, typename... ARGS>
void print(T &&arg, ARGS &&... args) {
  print(arg);
  if (va_len(args...) == 0) return;
  print(args...);
}

void println() {
  std::cout << std::endl;
}

template<typename T, typename... ARGS>
void println(T &&arg, ARGS &&... args) {
  print(arg, args...);
  println();
}


/// Text recolor

enum TextColor {
  kRedColor,
  kBlackColor,
};
const static std::map<TextColor, String> kTextColorMap = {
    {kRedColor, "\033[1;31m"},
    {kBlackColor, "\033[0m"},
};
inline String recolor(const String &text, TextColor color) {
  return kTextColorMap.at(color) + text + kTextColorMap.at(kBlackColor);
}

}

using common::print;
using common::println;

#endif //INITTYPES_H
