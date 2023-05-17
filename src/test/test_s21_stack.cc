#include <gtest/gtest.h>

#include <stack>
#include <string>

#include "../s21_stack.h"

TEST(Stack, empty) {
  s21::stack<int> stacker;
  std::stack<int> stacker_orig;
  EXPECT_EQ(stacker_orig.size(), stacker.size());
}

TEST(Stack, init_list) {
  s21::stack<std::pair<char, std::string>> stacker{
      {'a', "dfbdf"}, {'b', "fsdgbdf"}, {'g', "fdhsd"}};
  EXPECT_EQ('g', stacker.top().first);
  EXPECT_EQ("fdhsd", stacker.top().second);
  stacker.pop();
  EXPECT_EQ('b', stacker.top().first);
  EXPECT_EQ("fsdgbdf", stacker.top().second);
  stacker.pop();
  EXPECT_EQ('a', stacker.top().first);
  EXPECT_EQ("dfbdf", stacker.top().second);
  stacker.pop();
  EXPECT_EQ(1, stacker.empty());
  EXPECT_THROW(stacker.pop(), std::out_of_range);
}

TEST(Stack, copy_empty) {
  s21::stack<std::pair<char, std::string>> stacker;
  std::stack<std::pair<char, std::string>> stacker_orig;
  s21::stack<std::pair<char, std::string>> stacker_copy(stacker);
  std::stack<std::pair<char, std::string>> stacker_orig_copy(stacker_orig);
  EXPECT_EQ(stacker_orig_copy.size(), stacker_copy.size());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
}

TEST(Stack, copy_second_empty) {
  s21::stack<std::pair<char, std::string>> stacker;
  stacker.push({'a', "dfbdf"});
  stacker.push({'b', "fsdgbdf"});
  stacker.push({'g', "fdhsd"});
  std::stack<std::pair<char, std::string>> stacker_orig;
  stacker_orig.push({'a', "dfbdf"});
  stacker_orig.push({'b', "fsdgbdf"});
  stacker_orig.push({'g', "fdhsd"});
  s21::stack<std::pair<char, std::string>> stacker_copy(stacker);
  std::stack<std::pair<char, std::string>> stacker_orig_copy(stacker_orig);
  EXPECT_EQ(stacker_orig_copy.size(), stacker_copy.size());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
  EXPECT_EQ(stacker_orig_copy.top(), stacker_copy.top());
}

TEST(Stack, move_empty) {
  s21::stack<std::pair<char, std::string>> stacker;
  std::stack<std::pair<char, std::string>> stacker_orig;
  s21::stack<std::pair<char, std::string>> stacker_copy(
      (s21::stack<std::pair<char, std::string>> &&) stacker);
  std::stack<std::pair<char, std::string>> stacker_orig_copy(
      (std::stack<std::pair<char, std::string>> &&) stacker_orig);
  EXPECT_EQ(stacker_orig_copy.size(), stacker_copy.size());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
}

TEST(Stack, move_second_empty) {
  s21::stack<std::pair<char, std::string>> stacker;
  stacker.push({'a', "dfbdf"});
  stacker.push({'b', "fsdgbdf"});
  stacker.push({'g', "fdhsd"});
  std::stack<std::pair<char, std::string>> stacker_orig;
  stacker_orig.push({'a', "dfbdf"});
  stacker_orig.push({'b', "fsdgbdf"});
  stacker_orig.push({'g', "fdhsd"});
  s21::stack<std::pair<char, std::string>> stacker_copy(
      (s21::stack<std::pair<char, std::string>> &&) stacker);
  std::stack<std::pair<char, std::string>> stacker_orig_copy(
      (std::stack<std::pair<char, std::string>> &&) stacker_orig);
  EXPECT_EQ(stacker_orig_copy.size(), stacker_copy.size());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
  EXPECT_EQ(stacker_orig_copy.top(), stacker_copy.top());
}

TEST(Stack, copy_oper_empty) {
  s21::stack<std::pair<char, std::string>> stacker;
  std::stack<std::pair<char, std::string>> stacker_orig;
  s21::stack<std::pair<char, std::string>> stacker_copy;
  std::stack<std::pair<char, std::string>> stacker_orig_copy;
  stacker_copy = stacker;
  stacker_orig_copy = stacker_orig;
  EXPECT_EQ(stacker_orig_copy.size(), stacker_copy.size());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
}

TEST(Stack, copy_oper_second_empty) {
  s21::stack<std::pair<char, std::string>> stacker;
  stacker.push({'a', "dfbdf"});
  stacker.push({'b', "fsdgbdf"});
  stacker.push({'g', "fdhsd"});
  std::stack<std::pair<char, std::string>> stacker_orig;
  stacker_orig.push({'a', "dfbdf"});
  stacker_orig.push({'b', "fsdgbdf"});
  stacker_orig.push({'g', "fdhsd"});
  s21::stack<std::pair<char, std::string>> stacker_copy;
  std::stack<std::pair<char, std::string>> stacker_orig_copy;
  stacker_copy = stacker;
  stacker_orig_copy = stacker_orig;
  EXPECT_EQ(stacker_orig_copy.size(), stacker_copy.size());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
  EXPECT_EQ(stacker_orig_copy.top(), stacker_copy.top());
}

TEST(Stack, copy_oper_first_empty) {
  s21::stack<std::pair<char, std::string>> stacker;
  std::stack<std::pair<char, std::string>> stacker_orig;
  s21::stack<std::pair<char, std::string>> stacker_copy;
  stacker_copy.push({'a', "dfbdf"});
  stacker_copy.push({'b', "fsdgbdf"});
  stacker_copy.push({'g', "fdhsd"});
  std::stack<std::pair<char, std::string>> stacker_orig_copy;
  stacker_orig_copy.push({'a', "dfbdf"});
  stacker_orig_copy.push({'b', "fsdgbdf"});
  stacker_orig_copy.push({'g', "fdhsd"});
  stacker_copy = stacker;
  stacker_orig_copy = stacker_orig;
  EXPECT_EQ(stacker_orig_copy.size(), stacker_copy.size());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
}

TEST(Stack, copy_oper) {
  s21::stack<std::pair<char, std::string>> stacker;
  stacker.push({'b', "df12dbfbdf"});
  stacker.push({'a', "321fsdgdfbdf"});
  stacker.push({'h', "df231bfdhsd"});
  std::stack<std::pair<char, std::string>> stacker_orig;
  stacker_orig.push({'b', "df12dbfbdf"});
  stacker_orig.push({'a', "321fsdgdfbdf"});
  stacker_orig.push({'h', "df231bfdhsd"});
  s21::stack<std::pair<char, std::string>> stacker_copy;
  stacker_copy.push({'a', "dfbdf"});
  stacker_copy.push({'b', "fsdgbdf"});
  stacker_copy.push({'g', "fdhsd"});
  std::stack<std::pair<char, std::string>> stacker_orig_copy;
  stacker_orig_copy.push({'a', "dfbdf"});
  stacker_orig_copy.push({'b', "fsdgbdf"});
  stacker_orig_copy.push({'g', "fdhsd"});
  stacker_copy = stacker;
  stacker_orig_copy = stacker_orig;
  EXPECT_EQ(stacker_orig_copy.size(), stacker_copy.size());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
  EXPECT_EQ(stacker_orig_copy.top(), stacker_copy.top());
  EXPECT_EQ(stacker_orig.top(), stacker.top());
}

TEST(Stack, move_oper_empty) {
  s21::stack<std::pair<char, std::string>> stacker;
  std::stack<std::pair<char, std::string>> stacker_orig;
  s21::stack<std::pair<char, std::string>> stacker_copy;
  std::stack<std::pair<char, std::string>> stacker_orig_copy;
  stacker_copy = std::move(stacker);
  stacker_orig_copy = std::move(stacker_orig);
  EXPECT_EQ(stacker_orig_copy.size(), stacker_copy.size());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
}

TEST(Stack, move_oper_second_empty) {
  s21::stack<std::pair<char, std::string>> stacker;
  stacker.push({'a', "dfbdf"});
  stacker.push({'b', "fsdgbdf"});
  stacker.push({'g', "fdhsd"});
  std::stack<std::pair<char, std::string>> stacker_orig;
  stacker_orig.push({'a', "dfbdf"});
  stacker_orig.push({'b', "fsdgbdf"});
  stacker_orig.push({'g', "fdhsd"});
  s21::stack<std::pair<char, std::string>> stacker_copy;
  std::stack<std::pair<char, std::string>> stacker_orig_copy;
  stacker_copy = std::move(stacker);
  stacker_orig_copy = std::move(stacker_orig);
  EXPECT_EQ(stacker_orig_copy.size(), stacker_copy.size());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
  EXPECT_EQ(stacker_orig_copy.top(), stacker_copy.top());
}

TEST(Stack, move_oper_first_empty) {
  s21::stack<std::pair<char, std::string>> stacker;
  std::stack<std::pair<char, std::string>> stacker_orig;
  s21::stack<std::pair<char, std::string>> stacker_copy;
  stacker_copy.push({'a', "dfbdf"});
  stacker_copy.push({'b', "fsdgbdf"});
  stacker_copy.push({'g', "fdhsd"});
  std::stack<std::pair<char, std::string>> stacker_orig_copy;
  stacker_orig_copy.push({'a', "dfbdf"});
  stacker_orig_copy.push({'b', "fsdgbdf"});
  stacker_orig_copy.push({'g', "fdhsd"});
  stacker_copy = std::move(stacker);
  stacker_orig_copy = std::move(stacker_orig);
  EXPECT_EQ(stacker_orig_copy.size(), stacker_copy.size());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
}

TEST(Stack, move_oper) {
  s21::stack<std::pair<char, std::string>> stacker;
  stacker.push({'b', "df12dbfbdf"});
  stacker.push({'a', "321fsdgdfbdf"});
  stacker.push({'h', "df231bfdhsd"});
  std::stack<std::pair<char, std::string>> stacker_orig;
  stacker_orig.push({'b', "df12dbfbdf"});
  stacker_orig.push({'a', "321fsdgdfbdf"});
  stacker_orig.push({'h', "df231bfdhsd"});
  s21::stack<std::pair<char, std::string>> stacker_copy;
  stacker_copy.push({'a', "dfbdf"});
  stacker_copy.push({'b', "fsdgbdf"});
  stacker_copy.push({'g', "fdhsd"});
  std::stack<std::pair<char, std::string>> stacker_orig_copy;
  stacker_orig_copy.push({'a', "dfbdf"});
  stacker_orig_copy.push({'b', "fsdgbdf"});
  stacker_orig_copy.push({'g', "fdhsd"});
  stacker_copy = std::move(stacker);
  stacker_orig_copy = std::move(stacker_orig);
  EXPECT_EQ(stacker_orig_copy.size(), stacker_copy.size());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
  EXPECT_EQ(stacker_orig_copy.top(), stacker_copy.top());
}

TEST(Stack, top_empty) {
  s21::stack<std::pair<double, std::string>> stacker;
  EXPECT_THROW(stacker.top(), std::out_of_range);
}

TEST(Stack, top_push) {
  s21::stack<std::pair<char, std::string>> stacker;
  std::stack<std::pair<char, std::string>> stacker_orig;
  stacker.push({'b', "df12dbfbdf"});
  stacker_orig.push({'b', "df12dbfbdf"});
  EXPECT_EQ(stacker_orig.top(), stacker.top());

  stacker.push({'a', "321fsdgdfbdf"});
  stacker_orig.push({'a', "321fsdgdfbdf"});
  EXPECT_EQ(stacker_orig.top(), stacker.top());

  stacker.push({'h', "df231bfdhsd"});
  stacker_orig.push({'h', "df231bfdhsd"});
  EXPECT_EQ(stacker_orig.top(), stacker.top());

  EXPECT_EQ(stacker_orig.size(), stacker.size());
}

TEST(Stack, pop_size_empty) {
  s21::stack<std::pair<double, std::string>> stacker;
  stacker.push({3423.24, "df12dbfbdf"});
  stacker.push({-53.123, "321fsdgdfbdf"});
  stacker.push({0.0004353, "df231bfdhsd"});
  std::stack<std::pair<double, std::string>> stacker_orig;
  stacker_orig.push({3423.24, "df12dbfbdf"});
  stacker_orig.push({-53.123, "321fsdgdfbdf"});
  stacker_orig.push({0.0004353, "df231bfdhsd"});
  EXPECT_EQ(stacker_orig.empty(), stacker.empty());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
  EXPECT_EQ(stacker_orig.top(), stacker.top());
  stacker.pop();
  stacker_orig.pop();
  EXPECT_EQ(stacker_orig.size(), stacker.size());
  EXPECT_EQ(stacker_orig.top(), stacker.top());
  stacker.pop();
  stacker_orig.pop();
  EXPECT_EQ(stacker_orig.empty(), stacker.empty());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
  EXPECT_EQ(stacker_orig.top(), stacker.top());
  stacker.pop();
  stacker_orig.pop();
  EXPECT_EQ(stacker_orig.empty(), stacker.empty());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
  EXPECT_THROW(stacker.pop(), std::out_of_range);
}

TEST(Stack, swap_empty) {
  s21::stack<std::pair<char, std::string>> stacker;
  std::stack<std::pair<char, std::string>> stacker_orig;
  s21::stack<std::pair<char, std::string>> stacker_copy;
  std::stack<std::pair<char, std::string>> stacker_orig_copy;
  stacker_copy.swap(stacker);
  stacker_orig_copy.swap(stacker_orig);
  EXPECT_EQ(stacker_orig_copy.size(), stacker_copy.size());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
}

TEST(Stack, swap_second_empty) {
  s21::stack<std::pair<char, std::string>> stacker;
  stacker.push({'a', "dfbdf"});
  stacker.push({'b', "fsdgbdf"});
  stacker.push({'g', "fdhsd"});
  std::stack<std::pair<char, std::string>> stacker_orig;
  stacker_orig.push({'a', "dfbdf"});
  stacker_orig.push({'b', "fsdgbdf"});
  stacker_orig.push({'g', "fdhsd"});
  s21::stack<std::pair<char, std::string>> stacker_copy;
  std::stack<std::pair<char, std::string>> stacker_orig_copy;
  stacker_copy.swap(stacker);
  stacker_orig_copy.swap(stacker_orig);
  EXPECT_EQ(stacker_orig_copy.size(), stacker_copy.size());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
  EXPECT_EQ(stacker_orig_copy.top(), stacker_copy.top());
}

TEST(Stack, swap_first_empty) {
  s21::stack<std::pair<char, std::string>> stacker;
  std::stack<std::pair<char, std::string>> stacker_orig;
  s21::stack<std::pair<char, std::string>> stacker_copy;
  stacker_copy.push({'a', "dfbdf"});
  stacker_copy.push({'b', "fsdgbdf"});
  stacker_copy.push({'g', "fdhsd"});
  std::stack<std::pair<char, std::string>> stacker_orig_copy;
  stacker_orig_copy.push({'a', "dfbdf"});
  stacker_orig_copy.push({'b', "fsdgbdf"});
  stacker_orig_copy.push({'g', "fdhsd"});
  stacker_copy.swap(stacker);
  stacker_orig_copy.swap(stacker_orig);
  EXPECT_EQ(stacker_orig_copy.size(), stacker_copy.size());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
  EXPECT_EQ(stacker_orig.top(), stacker.top());
}

TEST(Stack, swap_emplace) {
  s21::stack<std::pair<char, std::string>> stacker;
  stacker.emplace(std::pair<char, std::string>('b', "df12dbfbdf"));
  stacker.emplace(std::pair<char, std::string>('a', "321fsdgdfbdf"));
  stacker.emplace(std::pair<char, std::string>('h', "df231bfdhsd"));
  std::stack<std::pair<char, std::string>> stacker_orig;
  stacker_orig.emplace('b', "df12dbfbdf");
  stacker_orig.emplace('a', "321fsdgdfbdf");
  stacker_orig.emplace('h', "df231bfdhsd");
  EXPECT_EQ(stacker_orig.top(), stacker.top());
  s21::stack<std::pair<char, std::string>> stacker_copy;
  stacker_copy.emplace(std::pair<char, std::string>('a', "dfbdf"));
  stacker_copy.emplace(std::pair<char, std::string>('b', "fsdgbdf"));
  stacker_copy.emplace(std::pair<char, std::string>('g', "fdhsd"));
  std::stack<std::pair<char, std::string>> stacker_orig_copy;
  stacker_orig_copy.emplace('a', "dfbdf");
  stacker_orig_copy.emplace('b', "fsdgbdf");
  stacker_orig_copy.emplace('g', "fdhsd");
  EXPECT_EQ(stacker_orig_copy.top(), stacker_copy.top());
  stacker_copy.swap(stacker);
  stacker_orig_copy.swap(stacker_orig);
  EXPECT_EQ(stacker_orig_copy.size(), stacker_copy.size());
  EXPECT_EQ(stacker_orig.size(), stacker.size());
  EXPECT_EQ(stacker_orig_copy.top(), stacker_copy.top());
  EXPECT_EQ(stacker_orig.top(), stacker.top());
}

TEST(Stack, operator_eq) {
  s21::stack<std::pair<std::string, double>> stacker_1_empty;
  s21::stack<std::pair<std::string, double>> stacker_2_empty;
  std::stack<std::pair<std::string, double>> stacker_orig_1_empty;
  std::stack<std::pair<std::string, double>> stacker_orig_2_empty;

  s21::stack<std::pair<std::string, double>> stacker_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::stack<std::pair<std::string, double>> stacker_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::stack<std::pair<std::string, double>> stacker_orig_1;
  stacker_orig_1.push({"dfhbdfsa", 435.123});
  stacker_orig_1.push({"gfsesfd23 ", -322.1234});
  stacker_orig_1.push({"df23frws312", 0.123});
  std::stack<std::pair<std::string, double>> stacker_orig_2(stacker_orig_1);

  EXPECT_EQ(stacker_orig_1_empty == stacker_orig_2_empty,
            stacker_1_empty == stacker_2_empty);
  EXPECT_EQ(stacker_orig_1_empty == stacker_orig_1,
            stacker_1_empty == stacker_1);
  EXPECT_EQ(stacker_orig_1 == stacker_orig_1_empty,
            stacker_1 == stacker_1_empty);
  EXPECT_EQ(stacker_orig_1 == stacker_orig_2, stacker_1 == stacker_2);

  stacker_1.push({"fg43df23", 34.13});
  stacker_1.push({"gfb34dfvsw", -24.0023});
  stacker_orig_1.push({"fg43df23", 34.13});
  stacker_orig_1.push({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(stacker_orig_1 == stacker_orig_2, stacker_1 == stacker_2);

  stacker_2.push({"fg43df23", 34.13});
  stacker_2.push({"gfb34dfvsw", -24.0023});
  stacker_2.push({"fd34fv23 ", 52324.123});
  stacker_2.push({"VdfsdDS43", -34532.23});
  stacker_orig_2.push({"fg43df23", 34.13});
  stacker_orig_2.push({"gfb34dfvsw", -24.0023});
  stacker_orig_2.push({"fd34fv23 ", 52324.123});
  stacker_orig_2.push({"VdfsdDS43", -34532.23});

  EXPECT_EQ(stacker_orig_1 == stacker_orig_2, stacker_1 == stacker_2);

  stacker_2.pop();
  stacker_2.pop();
  stacker_orig_2.pop();
  stacker_orig_2.pop();

  EXPECT_EQ(stacker_orig_1 == stacker_orig_2, stacker_1 == stacker_2);
}

TEST(Stack, operator_not_eq) {
  s21::stack<std::pair<std::string, double>> stacker_1_empty;
  s21::stack<std::pair<std::string, double>> stacker_2_empty;
  std::stack<std::pair<std::string, double>> stacker_orig_1_empty;
  std::stack<std::pair<std::string, double>> stacker_orig_2_empty;

  s21::stack<std::pair<std::string, double>> stacker_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::stack<std::pair<std::string, double>> stacker_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::stack<std::pair<std::string, double>> stacker_orig_1;
  stacker_orig_1.push({"dfhbdfsa", 435.123});
  stacker_orig_1.push({"gfsesfd23 ", -322.1234});
  stacker_orig_1.push({"df23frws312", 0.123});
  std::stack<std::pair<std::string, double>> stacker_orig_2(stacker_orig_1);

  EXPECT_EQ(stacker_orig_1_empty != stacker_orig_2_empty,
            stacker_1_empty != stacker_2_empty);
  EXPECT_EQ(stacker_orig_1_empty != stacker_orig_1,
            stacker_1_empty != stacker_1);
  EXPECT_EQ(stacker_orig_1 != stacker_orig_1_empty,
            stacker_1 != stacker_1_empty);
  EXPECT_EQ(stacker_orig_1 != stacker_orig_2, stacker_1 != stacker_2);

  stacker_1.push({"fg43df23", 34.13});
  stacker_1.push({"gfb34dfvsw", -24.0023});
  stacker_orig_1.push({"fg43df23", 34.13});
  stacker_orig_1.push({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(stacker_orig_1 != stacker_orig_2, stacker_1 != stacker_2);

  stacker_2.push({"fg43df23", 34.13});
  stacker_2.push({"gfb34dfvsw", -24.0023});
  stacker_2.push({"fd34fv23 ", 52324.123});
  stacker_2.push({"VdfsdDS43", -34532.23});
  stacker_orig_2.push({"fg43df23", 34.13});
  stacker_orig_2.push({"gfb34dfvsw", -24.0023});
  stacker_orig_2.push({"fd34fv23 ", 52324.123});
  stacker_orig_2.push({"VdfsdDS43", -34532.23});

  EXPECT_EQ(stacker_orig_1 != stacker_orig_2, stacker_1 != stacker_2);

  stacker_2.pop();
  stacker_2.pop();
  stacker_orig_2.pop();
  stacker_orig_2.pop();

  EXPECT_EQ(stacker_orig_1 != stacker_orig_2, stacker_1 != stacker_2);
}

TEST(Stack, operator_more_eq) {
  s21::stack<std::pair<std::string, double>> stacker_1_empty;
  s21::stack<std::pair<std::string, double>> stacker_2_empty;
  std::stack<std::pair<std::string, double>> stacker_orig_1_empty;
  std::stack<std::pair<std::string, double>> stacker_orig_2_empty;

  s21::stack<std::pair<std::string, double>> stacker_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::stack<std::pair<std::string, double>> stacker_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::stack<std::pair<std::string, double>> stacker_orig_1;
  stacker_orig_1.push({"dfhbdfsa", 435.123});
  stacker_orig_1.push({"gfsesfd23 ", -322.1234});
  stacker_orig_1.push({"df23frws312", 0.123});
  std::stack<std::pair<std::string, double>> stacker_orig_2(stacker_orig_1);

  EXPECT_EQ(stacker_orig_1_empty >= stacker_orig_2_empty,
            stacker_1_empty >= stacker_2_empty);
  EXPECT_EQ(stacker_orig_1_empty >= stacker_orig_1,
            stacker_1_empty >= stacker_1);
  EXPECT_EQ(stacker_orig_1 >= stacker_orig_1_empty,
            stacker_1 >= stacker_1_empty);
  EXPECT_EQ(stacker_orig_1 >= stacker_orig_2, stacker_1 >= stacker_2);

  stacker_1.push({"fg43df23", 34.13});
  stacker_1.push({"gfb34dfvsw", -24.0023});
  stacker_orig_1.push({"fg43df23", 34.13});
  stacker_orig_1.push({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(stacker_orig_1 >= stacker_orig_2, stacker_1 >= stacker_2);

  stacker_2.push({"fg43df23", 34.13});
  stacker_2.push({"gfb34dfvsw", -24.0023});
  stacker_2.push({"fd34fv23 ", 52324.123});
  stacker_2.push({"VdfsdDS43", -34532.23});
  stacker_orig_2.push({"fg43df23", 34.13});
  stacker_orig_2.push({"gfb34dfvsw", -24.0023});
  stacker_orig_2.push({"fd34fv23 ", 52324.123});
  stacker_orig_2.push({"VdfsdDS43", -34532.23});

  EXPECT_EQ(stacker_orig_1 >= stacker_orig_2, stacker_1 >= stacker_2);

  stacker_2.pop();
  stacker_2.pop();
  stacker_orig_2.pop();
  stacker_orig_2.pop();

  EXPECT_EQ(stacker_orig_1 >= stacker_orig_2, stacker_1 >= stacker_2);
}

TEST(Stack, operator_more) {
  s21::stack<std::pair<std::string, double>> stacker_1_empty;
  s21::stack<std::pair<std::string, double>> stacker_2_empty;
  std::stack<std::pair<std::string, double>> stacker_orig_1_empty;
  std::stack<std::pair<std::string, double>> stacker_orig_2_empty;

  s21::stack<std::pair<std::string, double>> stacker_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::stack<std::pair<std::string, double>> stacker_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::stack<std::pair<std::string, double>> stacker_orig_1;
  stacker_orig_1.push({"dfhbdfsa", 435.123});
  stacker_orig_1.push({"gfsesfd23 ", -322.1234});
  stacker_orig_1.push({"df23frws312", 0.123});
  std::stack<std::pair<std::string, double>> stacker_orig_2(stacker_orig_1);

  EXPECT_EQ(stacker_orig_1_empty > stacker_orig_2_empty,
            stacker_1_empty > stacker_2_empty);
  EXPECT_EQ(stacker_orig_1_empty > stacker_orig_1, stacker_1_empty > stacker_1);
  EXPECT_EQ(stacker_orig_1 > stacker_orig_1_empty, stacker_1 > stacker_1_empty);
  EXPECT_EQ(stacker_orig_1 > stacker_orig_2, stacker_1 > stacker_2);

  stacker_1.push({"fg43df23", 34.13});
  stacker_1.push({"gfb34dfvsw", -24.0023});
  stacker_orig_1.push({"fg43df23", 34.13});
  stacker_orig_1.push({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(stacker_orig_1 > stacker_orig_2, stacker_1 > stacker_2);

  stacker_2.push({"fg43df23", 34.13});
  stacker_2.push({"gfb34dfvsw", -24.0023});
  stacker_2.push({"fd34fv23 ", 52324.123});
  stacker_2.push({"VdfsdDS43", -34532.23});
  stacker_orig_2.push({"fg43df23", 34.13});
  stacker_orig_2.push({"gfb34dfvsw", -24.0023});
  stacker_orig_2.push({"fd34fv23 ", 52324.123});
  stacker_orig_2.push({"VdfsdDS43", -34532.23});

  EXPECT_EQ(stacker_orig_1 > stacker_orig_2, stacker_1 > stacker_2);

  stacker_2.pop();
  stacker_2.pop();
  stacker_orig_2.pop();
  stacker_orig_2.pop();

  EXPECT_EQ(stacker_orig_1 > stacker_orig_2, stacker_1 > stacker_2);
}

TEST(Stack, operator_less_eq) {
  s21::stack<std::pair<std::string, double>> stacker_1_empty;
  s21::stack<std::pair<std::string, double>> stacker_2_empty;
  std::stack<std::pair<std::string, double>> stacker_orig_1_empty;
  std::stack<std::pair<std::string, double>> stacker_orig_2_empty;

  s21::stack<std::pair<std::string, double>> stacker_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::stack<std::pair<std::string, double>> stacker_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::stack<std::pair<std::string, double>> stacker_orig_1;
  stacker_orig_1.push({"dfhbdfsa", 435.123});
  stacker_orig_1.push({"gfsesfd23 ", -322.1234});
  stacker_orig_1.push({"df23frws312", 0.123});
  std::stack<std::pair<std::string, double>> stacker_orig_2(stacker_orig_1);

  EXPECT_EQ(stacker_orig_1_empty <= stacker_orig_2_empty,
            stacker_1_empty <= stacker_2_empty);
  EXPECT_EQ(stacker_orig_1_empty <= stacker_orig_1,
            stacker_1_empty <= stacker_1);
  EXPECT_EQ(stacker_orig_1 <= stacker_orig_1_empty,
            stacker_1 <= stacker_1_empty);
  EXPECT_EQ(stacker_orig_1 <= stacker_orig_2, stacker_1 <= stacker_2);

  stacker_1.push({"fg43df23", 34.13});
  stacker_1.push({"gfb34dfvsw", -24.0023});
  stacker_orig_1.push({"fg43df23", 34.13});
  stacker_orig_1.push({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(stacker_orig_1 <= stacker_orig_2, stacker_1 <= stacker_2);

  stacker_2.push({"fg43df23", 34.13});
  stacker_2.push({"gfb34dfvsw", -24.0023});
  stacker_2.push({"fd34fv23 ", 52324.123});
  stacker_2.push({"VdfsdDS43", -34532.23});
  stacker_orig_2.push({"fg43df23", 34.13});
  stacker_orig_2.push({"gfb34dfvsw", -24.0023});
  stacker_orig_2.push({"fd34fv23 ", 52324.123});
  stacker_orig_2.push({"VdfsdDS43", -34532.23});

  EXPECT_EQ(stacker_orig_1 <= stacker_orig_2, stacker_1 <= stacker_2);

  stacker_2.pop();
  stacker_2.pop();
  stacker_orig_2.pop();
  stacker_orig_2.pop();

  EXPECT_EQ(stacker_orig_1 <= stacker_orig_2, stacker_1 <= stacker_2);
}

TEST(Stack, operator_less) {
  s21::stack<std::pair<std::string, double>> stacker_1_empty;
  s21::stack<std::pair<std::string, double>> stacker_2_empty;
  std::stack<std::pair<std::string, double>> stacker_orig_1_empty;
  std::stack<std::pair<std::string, double>> stacker_orig_2_empty;

  s21::stack<std::pair<std::string, double>> stacker_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::stack<std::pair<std::string, double>> stacker_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::stack<std::pair<std::string, double>> stacker_orig_1;
  stacker_orig_1.push({"dfhbdfsa", 435.123});
  stacker_orig_1.push({"gfsesfd23 ", -322.1234});
  stacker_orig_1.push({"df23frws312", 0.123});
  std::stack<std::pair<std::string, double>> stacker_orig_2(stacker_orig_1);

  EXPECT_EQ(stacker_orig_1_empty < stacker_orig_2_empty,
            stacker_1_empty < stacker_2_empty);
  EXPECT_EQ(stacker_orig_1_empty < stacker_orig_1, stacker_1_empty < stacker_1);
  EXPECT_EQ(stacker_orig_1 < stacker_orig_1_empty, stacker_1 < stacker_1_empty);
  EXPECT_EQ(stacker_orig_1 < stacker_orig_2, stacker_1 < stacker_2);

  stacker_1.push({"fg43df23", 34.13});
  stacker_1.push({"gfb34dfvsw", -24.0023});
  stacker_orig_1.push({"fg43df23", 34.13});
  stacker_orig_1.push({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(stacker_orig_1 < stacker_orig_2, stacker_1 < stacker_2);

  stacker_2.push({"fg43df23", 34.13});
  stacker_2.push({"gfb34dfvsw", -24.0023});
  stacker_2.push({"fd34fv23 ", 52324.123});
  stacker_2.push({"VdfsdDS43", -34532.23});
  stacker_orig_2.push({"fg43df23", 34.13});
  stacker_orig_2.push({"gfb34dfvsw", -24.0023});
  stacker_orig_2.push({"fd34fv23 ", 52324.123});
  stacker_orig_2.push({"VdfsdDS43", -34532.23});

  EXPECT_EQ(stacker_orig_1 < stacker_orig_2, stacker_1 < stacker_2);

  stacker_2.pop();
  stacker_2.pop();
  stacker_orig_2.pop();
  stacker_orig_2.pop();

  EXPECT_EQ(stacker_orig_1 < stacker_orig_2, stacker_1 < stacker_2);
}
