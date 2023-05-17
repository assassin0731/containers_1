#include <gtest/gtest.h>

#include <queue>
#include <string>

#include "../s21_queue.h"

TEST(queue, empty) {
  s21::queue<int> que_test;
  std::queue<int> que_test_orig;
  EXPECT_EQ(que_test_orig.size(), que_test.size());
}

TEST(queue, init_list) {
  s21::queue<std::pair<char, std::string>> que_test{
      {'a', "dfbdf"}, {'b', "fsdgbdf"}, {'g', "fdhsd"}};
  EXPECT_EQ('g', que_test.back().first);
  EXPECT_EQ("fdhsd", que_test.back().second);
  EXPECT_EQ('a', que_test.front().first);
  EXPECT_EQ("dfbdf", que_test.front().second);
  que_test.pop();
  EXPECT_EQ('g', que_test.back().first);
  EXPECT_EQ("fdhsd", que_test.back().second);
  EXPECT_EQ('b', que_test.front().first);
  EXPECT_EQ("fsdgbdf", que_test.front().second);
  que_test.pop();
  EXPECT_EQ('g', que_test.back().first);
  EXPECT_EQ("fdhsd", que_test.back().second);
  EXPECT_EQ('g', que_test.front().first);
  EXPECT_EQ("fdhsd", que_test.front().second);
  que_test.pop();
  EXPECT_EQ(1, que_test.empty());
  EXPECT_THROW(que_test.pop(), std::out_of_range);
}

TEST(queue, copy_empty) {
  s21::queue<std::pair<char, std::string>> que_test;
  std::queue<std::pair<char, std::string>> que_test_orig;
  s21::queue<std::pair<char, std::string>> que_test_copy(que_test);
  std::queue<std::pair<char, std::string>> que_test_orig_copy(que_test_orig);
  EXPECT_EQ(que_test_orig_copy.size(), que_test_copy.size());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
}

TEST(queue, copy_second_empty) {
  s21::queue<std::pair<char, std::string>> que_test;
  que_test.push({'a', "dfbdf"});
  que_test.push({'b', "fsdgbdf"});
  que_test.push({'g', "fdhsd"});
  std::queue<std::pair<char, std::string>> que_test_orig;
  que_test_orig.push({'a', "dfbdf"});
  que_test_orig.push({'b', "fsdgbdf"});
  que_test_orig.push({'g', "fdhsd"});
  s21::queue<std::pair<char, std::string>> que_test_copy(que_test);
  std::queue<std::pair<char, std::string>> que_test_orig_copy(que_test_orig);
  EXPECT_EQ(que_test_orig_copy.size(), que_test_copy.size());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
  EXPECT_EQ(que_test_orig_copy.back(), que_test_copy.back());
  EXPECT_EQ(que_test_orig_copy.front(), que_test_copy.front());
}

TEST(queue, move_empty) {
  s21::queue<std::pair<char, std::string>> que_test;
  std::queue<std::pair<char, std::string>> que_test_orig;
  s21::queue<std::pair<char, std::string>> que_test_copy(
      (s21::queue<std::pair<char, std::string>> &&) que_test);
  std::queue<std::pair<char, std::string>> que_test_orig_copy(
      (std::queue<std::pair<char, std::string>> &&) que_test_orig);
  EXPECT_EQ(que_test_orig_copy.size(), que_test_copy.size());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
}

TEST(queue, move_second_empty) {
  s21::queue<std::pair<char, std::string>> que_test;
  que_test.push({'a', "dfbdf"});
  que_test.push({'b', "fsdgbdf"});
  que_test.push({'g', "fdhsd"});
  std::queue<std::pair<char, std::string>> que_test_orig;
  que_test_orig.push({'a', "dfbdf"});
  que_test_orig.push({'b', "fsdgbdf"});
  que_test_orig.push({'g', "fdhsd"});
  s21::queue<std::pair<char, std::string>> que_test_copy(
      (s21::queue<std::pair<char, std::string>> &&) que_test);
  std::queue<std::pair<char, std::string>> que_test_orig_copy(
      (std::queue<std::pair<char, std::string>> &&) que_test_orig);
  EXPECT_EQ(que_test_orig_copy.size(), que_test_copy.size());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
  EXPECT_EQ(que_test_orig_copy.back(), que_test_copy.back());
  EXPECT_EQ(que_test_orig_copy.front(), que_test_copy.front());
}

TEST(queue, copy_oper_empty) {
  s21::queue<std::pair<char, std::string>> que_test;
  std::queue<std::pair<char, std::string>> que_test_orig;
  s21::queue<std::pair<char, std::string>> que_test_copy;
  std::queue<std::pair<char, std::string>> que_test_orig_copy;
  que_test_copy = que_test;
  que_test_orig_copy = que_test_orig;
  EXPECT_EQ(que_test_orig_copy.size(), que_test_copy.size());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
}

TEST(queue, copy_oper_second_empty) {
  s21::queue<std::pair<char, std::string>> que_test;
  que_test.push({'a', "dfbdf"});
  que_test.push({'b', "fsdgbdf"});
  que_test.push({'g', "fdhsd"});
  std::queue<std::pair<char, std::string>> que_test_orig;
  que_test_orig.push({'a', "dfbdf"});
  que_test_orig.push({'b', "fsdgbdf"});
  que_test_orig.push({'g', "fdhsd"});
  s21::queue<std::pair<char, std::string>> que_test_copy;
  std::queue<std::pair<char, std::string>> que_test_orig_copy;
  que_test_copy = que_test;
  que_test_orig_copy = que_test_orig;
  EXPECT_EQ(que_test_orig_copy.size(), que_test_copy.size());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
  EXPECT_EQ(que_test_orig_copy.back(), que_test_copy.back());
  EXPECT_EQ(que_test_orig_copy.front(), que_test_copy.front());
}

TEST(queue, copy_oper_first_empty) {
  s21::queue<std::pair<char, std::string>> que_test;
  std::queue<std::pair<char, std::string>> que_test_orig;
  s21::queue<std::pair<char, std::string>> que_test_copy;
  que_test_copy.push({'a', "dfbdf"});
  que_test_copy.push({'b', "fsdgbdf"});
  que_test_copy.push({'g', "fdhsd"});
  std::queue<std::pair<char, std::string>> que_test_orig_copy;
  que_test_orig_copy.push({'a', "dfbdf"});
  que_test_orig_copy.push({'b', "fsdgbdf"});
  que_test_orig_copy.push({'g', "fdhsd"});
  que_test_copy = que_test;
  que_test_orig_copy = que_test_orig;
  EXPECT_EQ(que_test_orig_copy.size(), que_test_copy.size());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
}

TEST(queue, copy_oper) {
  s21::queue<std::pair<char, std::string>> que_test;
  que_test.push({'b', "df12dbfbdf"});
  que_test.push({'a', "321fsdgdfbdf"});
  que_test.push({'h', "df231bfdhsd"});
  std::queue<std::pair<char, std::string>> que_test_orig;
  que_test_orig.push({'b', "df12dbfbdf"});
  que_test_orig.push({'a', "321fsdgdfbdf"});
  que_test_orig.push({'h', "df231bfdhsd"});
  s21::queue<std::pair<char, std::string>> que_test_copy;
  que_test_copy.push({'a', "dfbdf"});
  que_test_copy.push({'b', "fsdgbdf"});
  que_test_copy.push({'g', "fdhsd"});
  std::queue<std::pair<char, std::string>> que_test_orig_copy;
  que_test_orig_copy.push({'a', "dfbdf"});
  que_test_orig_copy.push({'b', "fsdgbdf"});
  que_test_orig_copy.push({'g', "fdhsd"});
  que_test_copy = que_test;
  que_test_orig_copy = que_test_orig;
  EXPECT_EQ(que_test_orig_copy.size(), que_test_copy.size());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
  EXPECT_EQ(que_test_orig_copy.back(), que_test_copy.back());
  EXPECT_EQ(que_test_orig.back(), que_test.back());
  EXPECT_EQ(que_test_orig_copy.front(), que_test_copy.front());
  EXPECT_EQ(que_test_orig.front(), que_test.front());
}

TEST(queue, move_oper_empty) {
  s21::queue<std::pair<char, std::string>> que_test;
  std::queue<std::pair<char, std::string>> que_test_orig;
  s21::queue<std::pair<char, std::string>> que_test_copy;
  std::queue<std::pair<char, std::string>> que_test_orig_copy;
  que_test_copy = std::move(que_test);
  que_test_orig_copy = std::move(que_test_orig);
  EXPECT_EQ(que_test_orig_copy.size(), que_test_copy.size());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
}

TEST(queue, move_oper_second_empty) {
  s21::queue<std::pair<char, std::string>> que_test;
  que_test.push({'a', "dfbdf"});
  que_test.push({'b', "fsdgbdf"});
  que_test.push({'g', "fdhsd"});
  std::queue<std::pair<char, std::string>> que_test_orig;
  que_test_orig.push({'a', "dfbdf"});
  que_test_orig.push({'b', "fsdgbdf"});
  que_test_orig.push({'g', "fdhsd"});
  s21::queue<std::pair<char, std::string>> que_test_copy;
  std::queue<std::pair<char, std::string>> que_test_orig_copy;
  que_test_copy = std::move(que_test);
  que_test_orig_copy = std::move(que_test_orig);
  EXPECT_EQ(que_test_orig_copy.size(), que_test_copy.size());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
  EXPECT_EQ(que_test_orig_copy.back(), que_test_copy.back());
  EXPECT_EQ(que_test_orig_copy.front(), que_test_copy.front());
}

TEST(queue, move_oper_first_empty) {
  s21::queue<std::pair<char, std::string>> que_test;
  std::queue<std::pair<char, std::string>> que_test_orig;
  s21::queue<std::pair<char, std::string>> que_test_copy;
  que_test_copy.push({'a', "dfbdf"});
  que_test_copy.push({'b', "fsdgbdf"});
  que_test_copy.push({'g', "fdhsd"});
  std::queue<std::pair<char, std::string>> que_test_orig_copy;
  que_test_orig_copy.push({'a', "dfbdf"});
  que_test_orig_copy.push({'b', "fsdgbdf"});
  que_test_orig_copy.push({'g', "fdhsd"});
  que_test_copy = std::move(que_test);
  que_test_orig_copy = std::move(que_test_orig);
  EXPECT_EQ(que_test_orig_copy.size(), que_test_copy.size());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
}

TEST(queue, move_oper) {
  s21::queue<std::pair<char, std::string>> que_test;
  que_test.push({'b', "df12dbfbdf"});
  que_test.push({'a', "321fsdgdfbdf"});
  que_test.push({'h', "df231bfdhsd"});
  std::queue<std::pair<char, std::string>> que_test_orig;
  que_test_orig.push({'b', "df12dbfbdf"});
  que_test_orig.push({'a', "321fsdgdfbdf"});
  que_test_orig.push({'h', "df231bfdhsd"});
  s21::queue<std::pair<char, std::string>> que_test_copy;
  que_test_copy.push({'a', "dfbdf"});
  que_test_copy.push({'b', "fsdgbdf"});
  que_test_copy.push({'g', "fdhsd"});
  std::queue<std::pair<char, std::string>> que_test_orig_copy;
  que_test_orig_copy.push({'a', "dfbdf"});
  que_test_orig_copy.push({'b', "fsdgbdf"});
  que_test_orig_copy.push({'g', "fdhsd"});
  que_test_copy = std::move(que_test);
  que_test_orig_copy = std::move(que_test_orig);
  EXPECT_EQ(que_test_orig_copy.size(), que_test_copy.size());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
  EXPECT_EQ(que_test_orig_copy.back(), que_test_copy.back());
  EXPECT_EQ(que_test_orig_copy.front(), que_test_copy.front());
}

TEST(queue, back_front_empty) {
  s21::queue<std::pair<double, std::string>> que_test;
  EXPECT_THROW(que_test.back(), std::out_of_range);
  EXPECT_THROW(que_test.front(), std::out_of_range);
}

TEST(queue, back_front_push) {
  s21::queue<std::pair<char, std::string>> que_test;
  std::queue<std::pair<char, std::string>> que_test_orig;
  que_test.push({'b', "df12dbfbdf"});
  que_test_orig.push({'b', "df12dbfbdf"});
  EXPECT_EQ(que_test_orig.back(), que_test.back());
  EXPECT_EQ(que_test_orig.front(), que_test.front());

  que_test.push({'a', "321fsdgdfbdf"});
  que_test_orig.push({'a', "321fsdgdfbdf"});
  EXPECT_EQ(que_test_orig.back(), que_test.back());
  EXPECT_EQ(que_test_orig.front(), que_test.front());

  que_test.push({'h', "df231bfdhsd"});
  que_test_orig.push({'h', "df231bfdhsd"});
  EXPECT_EQ(que_test_orig.back(), que_test.back());
  EXPECT_EQ(que_test_orig.front(), que_test.front());

  EXPECT_EQ(que_test_orig.size(), que_test.size());
}

TEST(queue, pop_size_empty) {
  s21::queue<std::pair<double, std::string>> que_test;
  que_test.push({3423.24, "df12dbfbdf"});
  que_test.push({-53.123, "321fsdgdfbdf"});
  que_test.push({0.0004353, "df231bfdhsd"});
  std::queue<std::pair<double, std::string>> que_test_orig;
  que_test_orig.push({3423.24, "df12dbfbdf"});
  que_test_orig.push({-53.123, "321fsdgdfbdf"});
  que_test_orig.push({0.0004353, "df231bfdhsd"});
  EXPECT_EQ(que_test_orig.empty(), que_test.empty());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
  EXPECT_EQ(que_test_orig.back(), que_test.back());
  EXPECT_EQ(que_test_orig.front(), que_test.front());
  que_test.pop();
  que_test_orig.pop();
  EXPECT_EQ(que_test_orig.size(), que_test.size());
  EXPECT_EQ(que_test_orig.back(), que_test.back());
  EXPECT_EQ(que_test_orig.front(), que_test.front());
  que_test.pop();
  que_test_orig.pop();
  EXPECT_EQ(que_test_orig.empty(), que_test.empty());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
  EXPECT_EQ(que_test_orig.back(), que_test.back());
  EXPECT_EQ(que_test_orig.front(), que_test.front());
  que_test.pop();
  que_test_orig.pop();
  EXPECT_EQ(que_test_orig.empty(), que_test.empty());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
  EXPECT_THROW(que_test.pop(), std::out_of_range);
}

TEST(queue, swap_empty) {
  s21::queue<std::pair<char, std::string>> que_test;
  std::queue<std::pair<char, std::string>> que_test_orig;
  s21::queue<std::pair<char, std::string>> que_test_copy;
  std::queue<std::pair<char, std::string>> que_test_orig_copy;
  que_test_copy.swap(que_test);
  que_test_orig_copy.swap(que_test_orig);
  EXPECT_EQ(que_test_orig_copy.size(), que_test_copy.size());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
}

TEST(queue, swap_second_empty) {
  s21::queue<std::pair<char, std::string>> que_test;
  que_test.push({'a', "dfbdf"});
  que_test.push({'b', "fsdgbdf"});
  que_test.push({'g', "fdhsd"});
  std::queue<std::pair<char, std::string>> que_test_orig;
  que_test_orig.push({'a', "dfbdf"});
  que_test_orig.push({'b', "fsdgbdf"});
  que_test_orig.push({'g', "fdhsd"});
  s21::queue<std::pair<char, std::string>> que_test_copy;
  std::queue<std::pair<char, std::string>> que_test_orig_copy;
  que_test_copy.swap(que_test);
  que_test_orig_copy.swap(que_test_orig);
  EXPECT_EQ(que_test_orig_copy.size(), que_test_copy.size());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
  EXPECT_EQ(que_test_orig_copy.back(), que_test_copy.back());
  EXPECT_EQ(que_test_orig_copy.front(), que_test_copy.front());
}

TEST(queue, swap_first_empty) {
  s21::queue<std::pair<char, std::string>> que_test;
  std::queue<std::pair<char, std::string>> que_test_orig;
  s21::queue<std::pair<char, std::string>> que_test_copy;
  que_test_copy.push({'a', "dfbdf"});
  que_test_copy.push({'b', "fsdgbdf"});
  que_test_copy.push({'g', "fdhsd"});
  std::queue<std::pair<char, std::string>> que_test_orig_copy;
  que_test_orig_copy.push({'a', "dfbdf"});
  que_test_orig_copy.push({'b', "fsdgbdf"});
  que_test_orig_copy.push({'g', "fdhsd"});
  que_test_copy.swap(que_test);
  que_test_orig_copy.swap(que_test_orig);
  EXPECT_EQ(que_test_orig_copy.size(), que_test_copy.size());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
  EXPECT_EQ(que_test_orig.back(), que_test.back());
  EXPECT_EQ(que_test_orig.front(), que_test.front());
}

TEST(queue, swap_emplace) {
  s21::queue<std::pair<char, std::string>> que_test;
  que_test.emplace(std::pair<char, std::string>('b', "df12dbfbdf"));
  que_test.emplace(std::pair<char, std::string>('a', "321fsdgdfbdf"));
  que_test.emplace(std::pair<char, std::string>('h', "df231bfdhsd"));
  std::queue<std::pair<char, std::string>> que_test_orig;
  que_test_orig.emplace('b', "df12dbfbdf");
  que_test_orig.emplace('a', "321fsdgdfbdf");
  que_test_orig.emplace('h', "df231bfdhsd");
  EXPECT_EQ(que_test_orig.back(), que_test.back());
  EXPECT_EQ(que_test_orig.front(), que_test.front());
  s21::queue<std::pair<char, std::string>> que_test_copy;
  que_test_copy.emplace(std::pair<char, std::string>('a', "dfbdf"));
  que_test_copy.emplace(std::pair<char, std::string>('b', "fsdgbdf"));
  que_test_copy.emplace(std::pair<char, std::string>('g', "fdhsd"));
  std::queue<std::pair<char, std::string>> que_test_orig_copy;
  que_test_orig_copy.emplace('a', "dfbdf");
  que_test_orig_copy.emplace('b', "fsdgbdf");
  que_test_orig_copy.emplace('g', "fdhsd");
  EXPECT_EQ(que_test_orig_copy.back(), que_test_copy.back());
  EXPECT_EQ(que_test_orig_copy.front(), que_test_copy.front());
  que_test_copy.swap(que_test);
  que_test_orig_copy.swap(que_test_orig);
  EXPECT_EQ(que_test_orig_copy.size(), que_test_copy.size());
  EXPECT_EQ(que_test_orig.size(), que_test.size());
  EXPECT_EQ(que_test_orig_copy.back(), que_test_copy.back());
  EXPECT_EQ(que_test_orig.back(), que_test.back());
  EXPECT_EQ(que_test_orig_copy.front(), que_test_copy.front());
  EXPECT_EQ(que_test_orig.front(), que_test.front());
}

TEST(queue, operator_eq) {
  s21::queue<std::pair<std::string, double>> que_test_1_empty;
  s21::queue<std::pair<std::string, double>> que_test_2_empty;
  std::queue<std::pair<std::string, double>> que_test_orig_1_empty;
  std::queue<std::pair<std::string, double>> que_test_orig_2_empty;

  s21::queue<std::pair<std::string, double>> que_test_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::queue<std::pair<std::string, double>> que_test_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::queue<std::pair<std::string, double>> que_test_orig_1;
  que_test_orig_1.push({"dfhbdfsa", 435.123});
  que_test_orig_1.push({"gfsesfd23 ", -322.1234});
  que_test_orig_1.push({"df23frws312", 0.123});
  std::queue<std::pair<std::string, double>> que_test_orig_2(que_test_orig_1);

  EXPECT_EQ(que_test_orig_1_empty == que_test_orig_2_empty,
            que_test_1_empty == que_test_2_empty);
  EXPECT_EQ(que_test_orig_1_empty == que_test_orig_1,
            que_test_1_empty == que_test_1);
  EXPECT_EQ(que_test_orig_1 == que_test_orig_1_empty,
            que_test_1 == que_test_1_empty);
  EXPECT_EQ(que_test_orig_1 == que_test_orig_2, que_test_1 == que_test_2);

  que_test_1.push({"fg43df23", 34.13});
  que_test_1.push({"gfb34dfvsw", -24.0023});
  que_test_orig_1.push({"fg43df23", 34.13});
  que_test_orig_1.push({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(que_test_orig_1 == que_test_orig_2, que_test_1 == que_test_2);

  que_test_2.push({"fg43df23", 34.13});
  que_test_2.push({"gfb34dfvsw", -24.0023});
  que_test_2.push({"fd34fv23 ", 52324.123});
  que_test_2.push({"VdfsdDS43", -34532.23});
  que_test_orig_2.push({"fg43df23", 34.13});
  que_test_orig_2.push({"gfb34dfvsw", -24.0023});
  que_test_orig_2.push({"fd34fv23 ", 52324.123});
  que_test_orig_2.push({"VdfsdDS43", -34532.23});

  EXPECT_EQ(que_test_orig_1 == que_test_orig_2, que_test_1 == que_test_2);

  que_test_2.pop();
  que_test_2.pop();
  que_test_orig_2.pop();
  que_test_orig_2.pop();

  EXPECT_EQ(que_test_orig_1 == que_test_orig_2, que_test_1 == que_test_2);
}

TEST(queue, operator_not_eq) {
  s21::queue<std::pair<std::string, double>> que_test_1_empty;
  s21::queue<std::pair<std::string, double>> que_test_2_empty;
  std::queue<std::pair<std::string, double>> que_test_orig_1_empty;
  std::queue<std::pair<std::string, double>> que_test_orig_2_empty;

  s21::queue<std::pair<std::string, double>> que_test_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::queue<std::pair<std::string, double>> que_test_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::queue<std::pair<std::string, double>> que_test_orig_1;
  que_test_orig_1.push({"dfhbdfsa", 435.123});
  que_test_orig_1.push({"gfsesfd23 ", -322.1234});
  que_test_orig_1.push({"df23frws312", 0.123});
  std::queue<std::pair<std::string, double>> que_test_orig_2(que_test_orig_1);

  EXPECT_EQ(que_test_orig_1_empty != que_test_orig_2_empty,
            que_test_1_empty != que_test_2_empty);
  EXPECT_EQ(que_test_orig_1_empty != que_test_orig_1,
            que_test_1_empty != que_test_1);
  EXPECT_EQ(que_test_orig_1 != que_test_orig_1_empty,
            que_test_1 != que_test_1_empty);
  EXPECT_EQ(que_test_orig_1 != que_test_orig_2, que_test_1 != que_test_2);

  que_test_1.push({"fg43df23", 34.13});
  que_test_1.push({"gfb34dfvsw", -24.0023});
  que_test_orig_1.push({"fg43df23", 34.13});
  que_test_orig_1.push({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(que_test_orig_1 != que_test_orig_2, que_test_1 != que_test_2);

  que_test_2.push({"fg43df23", 34.13});
  que_test_2.push({"gfb34dfvsw", -24.0023});
  que_test_2.push({"fd34fv23 ", 52324.123});
  que_test_2.push({"VdfsdDS43", -34532.23});
  que_test_orig_2.push({"fg43df23", 34.13});
  que_test_orig_2.push({"gfb34dfvsw", -24.0023});
  que_test_orig_2.push({"fd34fv23 ", 52324.123});
  que_test_orig_2.push({"VdfsdDS43", -34532.23});

  EXPECT_EQ(que_test_orig_1 != que_test_orig_2, que_test_1 != que_test_2);

  que_test_2.pop();
  que_test_2.pop();
  que_test_orig_2.pop();
  que_test_orig_2.pop();

  EXPECT_EQ(que_test_orig_1 != que_test_orig_2, que_test_1 != que_test_2);
}

TEST(queue, operator_more_eq) {
  s21::queue<std::pair<std::string, double>> que_test_1_empty;
  s21::queue<std::pair<std::string, double>> que_test_2_empty;
  std::queue<std::pair<std::string, double>> que_test_orig_1_empty;
  std::queue<std::pair<std::string, double>> que_test_orig_2_empty;

  s21::queue<std::pair<std::string, double>> que_test_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::queue<std::pair<std::string, double>> que_test_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::queue<std::pair<std::string, double>> que_test_orig_1;
  que_test_orig_1.push({"dfhbdfsa", 435.123});
  que_test_orig_1.push({"gfsesfd23 ", -322.1234});
  que_test_orig_1.push({"df23frws312", 0.123});
  std::queue<std::pair<std::string, double>> que_test_orig_2(que_test_orig_1);

  EXPECT_EQ(que_test_orig_1_empty >= que_test_orig_2_empty,
            que_test_1_empty >= que_test_2_empty);
  EXPECT_EQ(que_test_orig_1_empty >= que_test_orig_1,
            que_test_1_empty >= que_test_1);
  EXPECT_EQ(que_test_orig_1 >= que_test_orig_1_empty,
            que_test_1 >= que_test_1_empty);
  EXPECT_EQ(que_test_orig_1 >= que_test_orig_2, que_test_1 >= que_test_2);

  que_test_1.push({"fg43df23", 34.13});
  que_test_1.push({"gfb34dfvsw", -24.0023});
  que_test_orig_1.push({"fg43df23", 34.13});
  que_test_orig_1.push({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(que_test_orig_1 >= que_test_orig_2, que_test_1 >= que_test_2);

  que_test_2.push({"fg43df23", 34.13});
  que_test_2.push({"gfb34dfvsw", -24.0023});
  que_test_2.push({"fd34fv23 ", 52324.123});
  que_test_2.push({"VdfsdDS43", -34532.23});
  que_test_orig_2.push({"fg43df23", 34.13});
  que_test_orig_2.push({"gfb34dfvsw", -24.0023});
  que_test_orig_2.push({"fd34fv23 ", 52324.123});
  que_test_orig_2.push({"VdfsdDS43", -34532.23});

  EXPECT_EQ(que_test_orig_1 >= que_test_orig_2, que_test_1 >= que_test_2);

  que_test_2.pop();
  que_test_2.pop();
  que_test_orig_2.pop();
  que_test_orig_2.pop();

  EXPECT_EQ(que_test_orig_1 >= que_test_orig_2, que_test_1 >= que_test_2);
}

TEST(queue, operator_more) {
  s21::queue<std::pair<std::string, double>> que_test_1_empty;
  s21::queue<std::pair<std::string, double>> que_test_2_empty;
  std::queue<std::pair<std::string, double>> que_test_orig_1_empty;
  std::queue<std::pair<std::string, double>> que_test_orig_2_empty;

  s21::queue<std::pair<std::string, double>> que_test_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::queue<std::pair<std::string, double>> que_test_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::queue<std::pair<std::string, double>> que_test_orig_1;
  que_test_orig_1.push({"dfhbdfsa", 435.123});
  que_test_orig_1.push({"gfsesfd23 ", -322.1234});
  que_test_orig_1.push({"df23frws312", 0.123});
  std::queue<std::pair<std::string, double>> que_test_orig_2(que_test_orig_1);

  EXPECT_EQ(que_test_orig_1_empty > que_test_orig_2_empty,
            que_test_1_empty > que_test_2_empty);
  EXPECT_EQ(que_test_orig_1_empty > que_test_orig_1,
            que_test_1_empty > que_test_1);
  EXPECT_EQ(que_test_orig_1 > que_test_orig_1_empty,
            que_test_1 > que_test_1_empty);
  EXPECT_EQ(que_test_orig_1 > que_test_orig_2, que_test_1 > que_test_2);

  que_test_1.push({"fg43df23", 34.13});
  que_test_1.push({"gfb34dfvsw", -24.0023});
  que_test_orig_1.push({"fg43df23", 34.13});
  que_test_orig_1.push({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(que_test_orig_1 > que_test_orig_2, que_test_1 > que_test_2);

  que_test_2.push({"fg43df23", 34.13});
  que_test_2.push({"gfb34dfvsw", -24.0023});
  que_test_2.push({"fd34fv23 ", 52324.123});
  que_test_2.push({"VdfsdDS43", -34532.23});
  que_test_orig_2.push({"fg43df23", 34.13});
  que_test_orig_2.push({"gfb34dfvsw", -24.0023});
  que_test_orig_2.push({"fd34fv23 ", 52324.123});
  que_test_orig_2.push({"VdfsdDS43", -34532.23});

  EXPECT_EQ(que_test_orig_1 > que_test_orig_2, que_test_1 > que_test_2);

  que_test_2.pop();
  que_test_2.pop();
  que_test_orig_2.pop();
  que_test_orig_2.pop();

  EXPECT_EQ(que_test_orig_1 > que_test_orig_2, que_test_1 > que_test_2);
}

TEST(queue, operator_less_eq) {
  s21::queue<std::pair<std::string, double>> que_test_1_empty;
  s21::queue<std::pair<std::string, double>> que_test_2_empty;
  std::queue<std::pair<std::string, double>> que_test_orig_1_empty;
  std::queue<std::pair<std::string, double>> que_test_orig_2_empty;

  s21::queue<std::pair<std::string, double>> que_test_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::queue<std::pair<std::string, double>> que_test_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::queue<std::pair<std::string, double>> que_test_orig_1;
  que_test_orig_1.push({"dfhbdfsa", 435.123});
  que_test_orig_1.push({"gfsesfd23 ", -322.1234});
  que_test_orig_1.push({"df23frws312", 0.123});
  std::queue<std::pair<std::string, double>> que_test_orig_2(que_test_orig_1);

  EXPECT_EQ(que_test_orig_1_empty <= que_test_orig_2_empty,
            que_test_1_empty <= que_test_2_empty);
  EXPECT_EQ(que_test_orig_1_empty <= que_test_orig_1,
            que_test_1_empty <= que_test_1);
  EXPECT_EQ(que_test_orig_1 <= que_test_orig_1_empty,
            que_test_1 <= que_test_1_empty);
  EXPECT_EQ(que_test_orig_1 <= que_test_orig_2, que_test_1 <= que_test_2);

  que_test_1.push({"fg43df23", 34.13});
  que_test_1.push({"gfb34dfvsw", -24.0023});
  que_test_orig_1.push({"fg43df23", 34.13});
  que_test_orig_1.push({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(que_test_orig_1 <= que_test_orig_2, que_test_1 <= que_test_2);

  que_test_2.push({"fg43df23", 34.13});
  que_test_2.push({"gfb34dfvsw", -24.0023});
  que_test_2.push({"fd34fv23 ", 52324.123});
  que_test_2.push({"VdfsdDS43", -34532.23});
  que_test_orig_2.push({"fg43df23", 34.13});
  que_test_orig_2.push({"gfb34dfvsw", -24.0023});
  que_test_orig_2.push({"fd34fv23 ", 52324.123});
  que_test_orig_2.push({"VdfsdDS43", -34532.23});

  EXPECT_EQ(que_test_orig_1 <= que_test_orig_2, que_test_1 <= que_test_2);

  que_test_2.pop();
  que_test_2.pop();
  que_test_orig_2.pop();
  que_test_orig_2.pop();

  EXPECT_EQ(que_test_orig_1 <= que_test_orig_2, que_test_1 <= que_test_2);
}

TEST(queue, operator_less) {
  s21::queue<std::pair<std::string, double>> que_test_1_empty;
  s21::queue<std::pair<std::string, double>> que_test_2_empty;
  std::queue<std::pair<std::string, double>> que_test_orig_1_empty;
  std::queue<std::pair<std::string, double>> que_test_orig_2_empty;

  s21::queue<std::pair<std::string, double>> que_test_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::queue<std::pair<std::string, double>> que_test_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::queue<std::pair<std::string, double>> que_test_orig_1;
  que_test_orig_1.push({"dfhbdfsa", 435.123});
  que_test_orig_1.push({"gfsesfd23 ", -322.1234});
  que_test_orig_1.push({"df23frws312", 0.123});
  std::queue<std::pair<std::string, double>> que_test_orig_2(que_test_orig_1);

  EXPECT_EQ(que_test_orig_1_empty < que_test_orig_2_empty,
            que_test_1_empty < que_test_2_empty);
  EXPECT_EQ(que_test_orig_1_empty < que_test_orig_1,
            que_test_1_empty < que_test_1);
  EXPECT_EQ(que_test_orig_1 < que_test_orig_1_empty,
            que_test_1 < que_test_1_empty);
  EXPECT_EQ(que_test_orig_1 < que_test_orig_2, que_test_1 < que_test_2);

  que_test_1.push({"fg43df23", 34.13});
  que_test_1.push({"gfb34dfvsw", -24.0023});
  que_test_orig_1.push({"fg43df23", 34.13});
  que_test_orig_1.push({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(que_test_orig_1 < que_test_orig_2, que_test_1 < que_test_2);

  que_test_2.push({"fg43df23", 34.13});
  que_test_2.push({"gfb34dfvsw", -24.0023});
  que_test_2.push({"fd34fv23 ", 52324.123});
  que_test_2.push({"VdfsdDS43", -34532.23});
  que_test_orig_2.push({"fg43df23", 34.13});
  que_test_orig_2.push({"gfb34dfvsw", -24.0023});
  que_test_orig_2.push({"fd34fv23 ", 52324.123});
  que_test_orig_2.push({"VdfsdDS43", -34532.23});

  EXPECT_EQ(que_test_orig_1 < que_test_orig_2, que_test_1 < que_test_2);

  que_test_2.pop();
  que_test_2.pop();
  que_test_orig_2.pop();
  que_test_orig_2.pop();

  EXPECT_EQ(que_test_orig_1 < que_test_orig_2, que_test_1 < que_test_2);
}