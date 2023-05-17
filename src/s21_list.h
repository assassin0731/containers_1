#ifndef CPP2_S21_CONTAINERS_S21_LIST_H_
#define CPP2_S21_CONTAINERS_S21_LIST_H_

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>

namespace s21 {

enum MoreLessValue {kEqValue, kMoreValue, kLessValue};

template <class T>
struct list_node {
  T value;
  list_node *prev;
  list_node *next;
  list_node() : value(), prev(nullptr), next(nullptr) {}
};

template <class T, class A = std::allocator<T>>
class list {
 
 public:
  class ListIterator;
  class ListConstIterator;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;
  using node = list_node<value_type>;

  using node_allocator =
      typename std::allocator_traits<A>::template rebind_alloc<node>;
  node_allocator allocator;

  list() noexcept : size_(0), empty_node(InitEmpty()) {}
  list(size_type n) : size_(0), empty_node(InitEmpty()) {
    value_type empty_{};
    for (size_type i = 0; i < n; ++i) {
      push_back(empty_);
    }
  }
  list(std::initializer_list<T> const &items)
      : size_(0), empty_node(InitEmpty()) {
    for (auto it : items) {
      push_back(it);
    }
  }
  list(const list &l) noexcept : size_(0), empty_node(InitEmpty()) { Copy(l); }
  list(list &&l) noexcept { Move(l); }
  list &operator=(const list &l) {
    clear();
    Copy(l);
    size_ = l.size_;
    return *this;
  }
  list &operator=(list &&l) {
    clear();
    delete empty_node;
    Move(l);
    return *this;
  }
  ~list() {
    clear();
    delete empty_node;
  }

  void clear() {
    while (size_) {
      pop_back();
    }
  }

  size_type max_size() const noexcept { return allocator.max_size(); }

  void push_back(const_reference value) {
    if (size_ == max_size()) {
      throw(std::out_of_range("Container reached its limit"));
    }
    node *tmp = new node;
    tmp->value = value;
    tmp->prev = empty_node->prev;
    tmp->next = empty_node;
    empty_node->prev = tmp;
    tmp->prev->next = tmp;
    ++size_;
  }

  void push_front(const_reference value) {
    if (size_ == max_size()) {
      throw(std::out_of_range("Container reached its limit"));
    }
    node *tmp = new node;
    tmp->value = value;
    tmp->prev = empty_node;
    tmp->next = empty_node->next;
    empty_node->next = tmp;
    tmp->next->prev = tmp;
    ++size_;
  }

  void pop_back() {
    EmptyThrow();
    --size_;
    node *tmp = empty_node->prev->prev;
    delete empty_node->prev;
    empty_node->prev = tmp;
  }

  void pop_front() {
    EmptyThrow();
    --size_;
    node *tmp = empty_node->next->next;
    delete empty_node->next;
    empty_node->next = tmp;
  }

  const_reference front() const noexcept { return empty_node->next->value; }

  const_reference back() const noexcept { return empty_node->prev->value; }

  bool empty() const noexcept {
    bool return_value = true;
    if (size_ != 0) {
      return_value = false;
    }
    return return_value;
  }

  size_type size() const noexcept { return size_; }

  void sort() noexcept {
    node *tmp;
    node *first_swap;
    node *second_swap;
    bool swaped = true;
    for (size_type i = 0; i < size_ && swaped; ++i) {
      swaped = false;
      tmp = empty_node->next;
      for (size_type j = 0; j < size_ - 1; ++j) {
        first_swap = tmp;
        second_swap = tmp->next;
        if (first_swap->value > second_swap->value) {
          node *first_prev = first_swap->prev;
          first_swap->prev->next = second_swap;
          first_swap->next = second_swap->next;
          first_swap->prev = second_swap;
          second_swap->next->prev = first_swap;
          second_swap->next = first_swap;
          second_swap->prev = first_prev;
          swaped = true;
          tmp = first_swap;
        } else {
          tmp = tmp->next;
        }
      }
    }
  }

  void reverse() noexcept {
    node *tmp = empty_node->next;
    std::swap(empty_node->next, empty_node->prev);
    for (size_type i = 0; i < size_; ++i) {
      std::swap(tmp->next, tmp->prev);
      tmp = tmp->prev;
    }
  }

  void unique() {
    node *tmp = empty_node->next;
    while (tmp->next != empty_node) {
      if (tmp->value == tmp->next->value) {
        node *remember_tmp = tmp->next;
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        --size_;
        delete tmp;
        tmp = remember_tmp;
      } else {
        tmp = tmp->next;
      }
    }
  }

  void swap(list &other) noexcept {
    if (this != &other) {
      std::swap(empty_node, other.empty_node);
      std::swap(this->size_, other.size_);
    }
  }

  void merge(list &other) noexcept {
    if (this != &other) {
      node *first = empty_node->next;
      node *second = other.empty_node->next;
      node *tmp = second->next;
      while (second != other.empty_node && first != empty_node) {
        while (second->value < first->value && second != other.empty_node) {
          node *remember = first->prev;
          first->prev->next = second;
          first->prev = second;
          second->next = first;
          second->prev = remember;
          second = tmp;
          tmp = tmp->next;
        }
        first = first->next;
      }
      if (second != other.empty_node) {
        empty_node->prev->next = second;
        second->prev = empty_node->prev;
        empty_node->prev = other.empty_node->prev;
        other.empty_node->prev->next = empty_node;
      }
      other.empty_node->next = other.empty_node;
      other.empty_node->prev = other.empty_node;
      size_ += other.size();
      other.size_ = 0;
    }
  }

  bool operator==(const list &other) const noexcept {
    bool return_value = false;
    int compare_return = CompareValues(other);
    if (compare_return == kEqValue) {
      return_value = true;
    }
    return return_value;
  }

  bool operator<(const list &other) const noexcept {
    bool return_value = false;
    int compare_return = CompareValues(other);
    if (compare_return == kLessValue) {
      return_value = true;
    }
    return return_value;
  }

  bool operator!=(const list &other) const noexcept {
    return !(*this == other);
  }

  bool operator>(const list &other) const noexcept {
    return !(*this < other || *this == other);
  }

  bool operator>=(const list &other) const noexcept {
    return (*this > other || *this == other);
  }

  bool operator<=(const list &other) const noexcept {
    return (*this < other || *this == other);
  }

  class ListConstIterator {
   public:
    ListConstIterator() noexcept : data_(nullptr) {}
    ListConstIterator(const ListConstIterator &other) noexcept
        : data_(other.data_) {}
    ~ListConstIterator() noexcept {}
    ListConstIterator(node *pointer) noexcept { data_ = pointer; }

    const_reference operator*() const {
      CheckNull();
      return data_->value;
    }

    ListConstIterator &operator++() {
      CheckNull();
      data_ = data_->next;
      return *this;
    }

    ListConstIterator &operator--() {
      CheckNull();
      data_ = data_->prev;
      return *this;
    }

    bool operator==(const ListConstIterator &it) const {
      CheckNull();
      it.CheckNull();
      return data_ == it.data_;
    }

    bool operator!=(const ListConstIterator &it) const {
      CheckNull();
      it.CheckNull();
      return data_ != it.data_;
    }

    ListConstIterator &operator=(const ListConstIterator &other) {
      data_ = other.data_;
      return *this;
    }

    node *get_data() const {
      CheckNull();
      return data_;
    }

   private:
    void CheckNull() const {
      if (data_ == nullptr) {
        throw(std::out_of_range("Iterator is at nullptr"));
      }
    }

   protected:
    node *data_;
  };

  class ListIterator : public ListConstIterator {
   public:
    ListIterator() noexcept : ListConstIterator(nullptr) {}
    ListIterator(const ListIterator &other) noexcept
        : ListConstIterator(other) {}
    ListIterator(const ListConstIterator &other) noexcept
        : ListConstIterator(other) {}
    ~ListIterator() noexcept {}
    ListIterator(node *pt) noexcept : ListConstIterator(pt) {}

    reference operator*() {
      if (this->data_ == nullptr) {
        throw(std::out_of_range("Iterator is at nullptr"));
      }
      return this->data_->value;
    }
    ListIterator &operator=(const ListIterator &other) {
      this->data_ = other.data_;
      return *this;
    }

    void set_data(node *other) { this->data_ = other; }
  };

  iterator begin() noexcept { return iterator(empty_node->next); }

  iterator end() noexcept { return iterator(empty_node); }

  iterator insert(iterator pos, const_reference value) {
    node *old_elem = pos.get_data();
    node *tmp = new node;
    tmp->value = value;
    tmp->next = old_elem;
    tmp->prev = old_elem->prev;
    old_elem->prev->next = tmp;
    old_elem->prev = tmp;
    ++size_;
    return iterator(tmp);
  }

  template <typename... Args>
  iterator emplace(const_iterator pos, Args &&...args) {
    for (auto arg : {std::forward<Args>(args)...}) {
      insert(pos, arg);
      --pos;
    }
    return pos;
  }

  template <typename... Args>
  void emplace_back(Args &&...args) {
    for (auto arg : {std::forward<Args>(args)...}) {
      push_back(arg);
    }
  }

  template <typename... Args>
  void emplace_front(Args &&...args) {
    node *current_node = empty_node;
    for (auto arg : {std::forward<Args>(args)...}) {
      if (size_ == max_size()) {
        throw(std::out_of_range("Container reached its limit"));
      }
      node *tmp = new node;
      tmp->value = arg;
      tmp->prev = current_node ;
      tmp->next = current_node ->next;
      current_node ->next = tmp;
      tmp->next->prev = tmp;
      current_node = current_node->next;
      ++size_;
    }
  }

  void erase(iterator pos) {
    node *old_elem = pos.get_data();
    old_elem->prev->next = old_elem->next;
    old_elem->next->prev = old_elem->prev;
    --size_;
    delete old_elem;
    old_elem = nullptr;
  }

  void splice(const_iterator pos, list &other) {
    if (this != &other) {
      pos.get_data()->prev->next = other.empty_node->next;
      other.empty_node->next->prev = pos.get_data()->prev;
      pos.get_data()->prev = other.empty_node->prev;
      other.empty_node->prev->next = pos.get_data();
      other.empty_node->next = other.empty_node;
      other.empty_node->prev = other.empty_node;
      size_ += other.size_;
      other.size_ = 0;
    }
  }

 private:
  node *InitEmpty() noexcept {
    empty_node = new node;
    empty_node->next = empty_node;
    empty_node->prev = empty_node;
    return empty_node;
  }

  int CompareValues(const list &other) const noexcept {
    int this_value = kEqValue;
    node *this_node = empty_node->next;
    node *other_node = other.empty_node->next;
    size_type min_size = size_;
    if (min_size > other.size_) {
      min_size = other.size_;
    }
    for (size_type i = 0; i < min_size && this_value == kEqValue; ++i) {
      if (this_node->value > other_node->value) {
        this_value = kMoreValue;
      }
      if (this_node->value < other_node->value) {
        this_value = kLessValue;
      }
      this_node = this_node->next;
      other_node = other_node->next;
    }
    if (this_value == kEqValue && size_ > other.size_) {
      this_value = kMoreValue;
    } else if (this_value == kEqValue && size_ < other.size_) {
      this_value = kLessValue;
    }
    return this_value;
  }

  void EmptyThrow() const {
    if (empty()) {
      throw(std::out_of_range("List is empty"));
    }
  }

  void Copy(const list &l) noexcept {
    node *tmp = l.empty_node->next;
    for (size_type i = 0; i < l.size_; ++i) {
      push_back(tmp->value);
      tmp = tmp->next;
    }
  }

  void Move(list &l) noexcept {
    size_ = l.size_;
    empty_node = new node;
    l.empty_node->next->prev = empty_node;
    l.empty_node->prev->next = empty_node;
    empty_node->next = l.empty_node->next;
    empty_node->prev = l.empty_node->prev;
    l.empty_node->next = l.empty_node;
    l.empty_node->prev = l.empty_node;
    l.size_ = 0;
  }
  
  size_type size_;
  node *empty_node;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_LIST_H_