#ifndef CPP2_S21_CONTAINERS_S21_QUEUE_H_
#define CPP2_S21_CONTAINERS_S21_QUEUE_H_

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>

#include "s21_list.h"

namespace s21 {
template <class T, class Container = s21::list<T>>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  queue() noexcept : obj() {}
  queue(std::initializer_list<value_type> const &items) : obj(items) {}
  queue(const queue &other) noexcept : obj(other.obj) {}
  queue(queue &&other) noexcept : obj((Container &&) other.obj) {}
  queue &operator=(const queue &other) noexcept {
    obj = other.obj;
    return *this;
  }
  queue &operator=(queue &&other) noexcept {
    obj = (Container &&) other.obj;
    return *this;
  }
  ~queue() noexcept {}
  const_reference front() const {
    if (obj.size() == 0) {
      throw(std::out_of_range("queue is empty"));
    }
    return obj.front();
  }
  const_reference back() const {
    if (obj.size() == 0) {
      throw(std::out_of_range("queue is empty"));
    }
    return obj.back();
  }

  void push(const_reference value) { obj.push_back(value); }

  void pop() { obj.pop_front(); }

  bool empty() const noexcept { return obj.size() == 0; }

  size_type size() const noexcept { return obj.size(); }

  void swap(queue &other) noexcept { obj.swap(other.obj); }

  template <typename... Args>
  void emplace(Args &&...args) {
    obj.emplace_back((args)...);
  }

  bool operator==(const queue &other) const noexcept {
    return obj == other.obj;
  }
  bool operator!=(const queue &other) const noexcept {
    return obj != other.obj;
  }
  bool operator>(const queue &other) const noexcept { return obj > other.obj; }
  bool operator>=(const queue &other) const noexcept {
    return obj >= other.obj;
  }
  bool operator<(const queue &other) const noexcept { return obj < other.obj; }
  bool operator<=(const queue &other) const noexcept {
    return obj <= other.obj;
  }

 private:
  Container obj;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_QUEUE_H_