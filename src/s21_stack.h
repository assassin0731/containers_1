#ifndef CPP2_S21_CONTAINERS_S21_STACK_H_
#define CPP2_S21_CONTAINERS_S21_STACK_H_

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>

#include "s21_list.h"

namespace s21 {
template <class T, class Container = s21::list<T>>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  stack() noexcept : obj() {}
  stack(std::initializer_list<value_type> const &items) : obj(items) {}
  stack(const stack &other) noexcept : obj(other.obj) {}
  stack(stack &&other) noexcept : obj((Container &&) other.obj) {}
  stack &operator=(const stack &other) noexcept {
    obj = other.obj;
    return *this;
  }
  stack &operator=(stack &&other) noexcept {
    obj = (Container &&) other.obj;
    return *this;
  }
  ~stack() noexcept {}
  const_reference top() const {
    if (obj.size() == 0) {
      throw(std::out_of_range("Stack is empty"));
    }
    return obj.back();
  }
  void push(const_reference value) { obj.push_back(value); }

  void pop() { obj.pop_back(); }

  bool empty() const noexcept { return obj.size() == 0; }

  size_type size() const noexcept { return obj.size(); }

  void swap(stack &other) noexcept { obj.swap(other.obj); }

  template <typename... Args>
  void emplace(Args &&...args) {
    obj.emplace_back((args)...);
  }

  bool operator==(const stack &other) const noexcept {
    return obj == other.obj;
  }
  bool operator!=(const stack &other) const noexcept {
    return obj != other.obj;
  }
  bool operator>(const stack &other) const noexcept { return obj > other.obj; }
  bool operator>=(const stack &other) const noexcept {
    return obj >= other.obj;
  }
  bool operator<(const stack &other) const noexcept { return obj < other.obj; }
  bool operator<=(const stack &other) const noexcept {
    return obj <= other.obj;
  }

 private:
  Container obj;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_STACK_H_