#ifndef INITTYPES_H
#define INITTYPES_H

#include <cstddef>
#include <cstdint>
#include <sys/types.h>

#include <map>
#include <string>
#include <sstream>
#include <optional>

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

/// print \n
void println();
/// print variable length parameters and with a '\n'
template<typename T, typename... ARGS>
void println(T &&arg, ARGS &&... args);

/// print tuple
template<typename... T>
void print_tuple(const std::tuple<T...> &tuple);
template<typename... T>
void println_tuple(const std::tuple<T...> &tuple);

/// Definition

void print() {}

template<typename T>
void print(T &&arg) {
  std::cout << arg;
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

template<typename T>
void println_c(T &container) {
  if (container.size() == 0) {
    println("[]");
    return;
  }
  std::stringstream buf;
  buf << '[';
  for (auto v : container) {
    buf << v << ", ";
  }
  buf.seekp(-2, std::stringstream::cur);
  buf << ']';
  println(buf.str());
}

template<typename TUPLE, size_t... I>
void print_tuple(const TUPLE &tuple, std::index_sequence<I...>) {
  print("(");
  (..., (print(I == 0 ? "" : ", ", std::get<I>(tuple))));
  print(")");
}
template<typename... T>
void print_tuple(const std::tuple<T...> &tuple) {
  print_tuple(tuple, std::make_index_sequence<sizeof...(T)>());
}
template<typename... T>
void println_tuple(const std::tuple<T...> &tuple) {
  print_tuple(tuple);
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

/// String Tools

template<typename T>
T from_string(const String &str) {
  std::istringstream is(str);
  T v;
  is >> v;
  return v;
}

/// Result

template<typename T, typename E>
class Result {
 public:
  static Result<T, E> Ok(T t) { return Result<T, E>(t, std::nullopt, true); }
  static Result<T, E> Err(E e) { return Result<T, E>(std::nullopt, e, false); }

  explicit Result(std::optional<T> ok, std::optional<E> err, bool is_ok) :
      kOk(ok), kErr(err), kIsOk(is_ok) {}
  bool is_ok() const { return kIsOk; }
  bool is_err() const { return !is_ok(); }
  inline std::optional<T> ok() const { return kOk; }
  inline std::optional<E> err() const { return kErr; }

 private:
  const std::optional<T> kOk;
  const std::optional<E> kErr;
  const bool kIsOk;
};

template<typename T, typename E>
constexpr Result<T, E> Ok(T t) { return Result<T, E>::Ok(t); }
template<typename T, typename E>
constexpr Result<T, E> Err(E e) { return Result<T, E>::Err(e); }

}

using common::print;
using common::println;

#endif //INITTYPES_H
