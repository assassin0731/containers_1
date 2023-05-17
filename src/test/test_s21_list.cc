#include <gtest/gtest.h>

#include <list>
#include <string>

#include "../s21_list.h"

TEST(List, empty_list) {
  s21::list<int> lister;
  EXPECT_EQ(0, static_cast<int>(lister.size()));
}

TEST(List, empty_elements_1) {
  s21::list<int> lister(20);
  std::list<int> lister_orig(20);
  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, empty_elements_2) {
  s21::list<char> lister(20);
  std::list<char> lister_orig(20);
  s21::list<char>::iterator iter(lister.begin());
  std::list<char>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, empty_elements_3) {
  s21::list<std::pair<double, std::string>> lister(20);
  std::list<std::pair<double, std::string>> lister_orig(20);
  s21::list<std::pair<double, std::string>>::iterator iter(lister.begin());
  std::list<std::pair<double, std::string>>::iterator iter_orig(
      lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, int_elements_1) {
  s21::list<int> lister{1, 2, 3};
  std::list<int> lister_orig{1, 2, 3};
  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, double_elements_2) {
  s21::list<double> lister{1.443, 2432.156334, 743.135453};
  std::list<double> lister_orig{1.443, 2432.156334, 743.135453};
  s21::list<double>::iterator iter(lister.begin());
  std::list<double>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_NEAR(*iter, *iter_orig, 0.0000001);
  }
}

TEST(List, pair_elements_3) {
  s21::list<std::pair<char, std::string>> lister{
      {'s', "asdvs"}, {'g', "dsgvfs"}, {'n', "ASd32DFA"}};
  std::list<std::pair<char, std::string>> lister_orig{
      {'s', "asdvs"}, {'g', "dsgvfs"}, {'n', "ASd32DFA"}};
  s21::list<std::pair<char, std::string>>::iterator iter(lister.begin());
  std::list<std::pair<char, std::string>>::iterator iter_orig(
      lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, copy_empty) {
  s21::list<int> lister;
  std::list<int> lister_orig;
  s21::list<int> lister_copy(lister);
  std::list<int> lister_orig_copy(lister_orig);
  EXPECT_EQ(lister_orig_copy.size(), lister_copy.size());
}

TEST(List, copy_filled) {
  s21::list<std::string> lister{"sdfgfd", "fsdgdf", "fdvbdw", "fdhd",
                                " dfgdffd ef34"};
  std::list<std::string> lister_orig{"sdfgfd", "fsdgdf", "fdvbdw", "fdhd",
                                     " dfgdffd ef34"};
  s21::list<std::string> lister_copy(lister);
  std::list<std::string> lister_orig_copy(lister_orig);
  s21::list<std::string>::iterator iter(lister_copy.begin());
  std::list<std::string>::iterator iter_orig(lister_orig_copy.begin());
  for (size_t i = 0; i < lister_copy.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, move_filled) {
  s21::list<std::string> lister{"sdfgfd", "fsdgdf", "fdvbdw", "fdhd",
                                " dfgdffd ef34"};
  std::list<std::string> lister_orig{"sdfgfd", "fsdgdf", "fdvbdw", "fdhd",
                                     " dfgdffd ef34"};
  s21::list<std::string> lister_copy((s21::list<std::string> &&) lister);
  std::list<std::string> lister_orig_copy((std::list<std::string> &&)
                                              lister_orig);
  s21::list<std::string>::iterator iter(lister_copy.begin());
  std::list<std::string>::iterator iter_orig(lister_orig_copy.begin());
  for (size_t i = 0; i < lister_copy.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
  EXPECT_EQ(lister_orig.size(), lister.size());
  EXPECT_EQ(lister_orig_copy.size(), lister_copy.size());
}

TEST(List, move_empty) {
  s21::list<std::string> lister;
  std::list<std::string> lister_orig;
  s21::list<std::string> lister_copy((s21::list<std::string> &&) lister);
  std::list<std::string> lister_orig_copy((std::list<std::string> &&)
                                              lister_orig);
  s21::list<std::string>::iterator iter(lister_copy.begin());
  std::list<std::string>::iterator iter_orig(lister_orig_copy.begin());
  for (size_t i = 0; i < lister_copy.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
  EXPECT_EQ(lister_orig.size(), lister.size());
  EXPECT_EQ(lister_orig_copy.size(), lister_copy.size());
}

TEST(List, oper_copy) {
  s21::list<std::string> lister{"sdfgfd", "fsdgdf", "fdvbdw", "fdhd",
                                " dfgdffd ef34"};
  std::list<std::string> lister_orig{"sdfgfd", "fsdgdf", "fdvbdw", "fdhd",
                                     " dfgdffd ef34"};
  s21::list<std::string> lister_copy{"dftghfs", "sdvsd,", "dsgs234324"};
  std::list<std::string> lister_orig_copy{"dsbs", "sdvsfdbdfsd,", "dsgs"};
  lister_copy = lister;
  lister_orig_copy = lister_orig;
  s21::list<std::string>::iterator iter(lister_copy.begin());
  std::list<std::string>::iterator iter_orig(lister_orig_copy.begin());
  for (size_t i = 0; i < lister_copy.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
  EXPECT_EQ(lister_orig.size(), lister.size());
  EXPECT_EQ(lister_orig_copy.size(), lister_copy.size());
}

TEST(List, oper_copy_empty) {
  s21::list<std::string> lister;
  std::list<std::string> lister_orig;
  s21::list<std::string> lister_copy{"dftghfs", "sdvsd,", "dsgs234324"};
  std::list<std::string> lister_orig_copy{"dsbs", "sdvsfdbdfsd,", "dsgs"};
  lister_copy = lister;
  lister_orig_copy = lister_orig;
  s21::list<std::string>::iterator iter(lister_copy.begin());
  std::list<std::string>::iterator iter_orig(lister_orig_copy.begin());
  for (size_t i = 0; i < lister_copy.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
  EXPECT_EQ(lister_orig.size(), lister.size());
  EXPECT_EQ(lister_orig_copy.size(), lister_copy.size());
}

TEST(List, oper_move) {
  s21::list<std::string> lister{"sdfgfd", "fsdgdf", "fdvbdw", "fdhd",
                                " dfgdffd ef34"};
  std::list<std::string> lister_orig{"sdfgfd", "fsdgdf", "fdvbdw", "fdhd",
                                     " dfgdffd ef34"};
  s21::list<std::string> lister_copy{"dftghfs", "sdvsd,", "dsgs234324"};
  std::list<std::string> lister_orig_copy{"dsbs", "sdvsfdbdfsd,", "dsgs"};
  lister_copy = std::move(lister);
  lister_orig_copy = std::move(lister_orig);
  s21::list<std::string>::iterator iter(lister_copy.begin());
  std::list<std::string>::iterator iter_orig(lister_orig_copy.begin());
  for (size_t i = 0; i < lister_copy.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
  EXPECT_EQ(lister_orig.size(), lister.size());
  EXPECT_EQ(lister_orig_copy.size(), lister_copy.size());
}

TEST(List, oper_move_empty) {
  s21::list<std::string> lister;
  std::list<std::string> lister_orig;
  s21::list<std::string> lister_copy{"dftghfs", "sdvsd,", "dsgs234324"};
  std::list<std::string> lister_orig_copy{"dsbs", "sdvsfdbdfsd,", "dsgs"};
  lister_copy = std::move(lister);
  lister_orig_copy = std::move(lister_orig);
  s21::list<std::string>::iterator iter(lister_copy.begin());
  std::list<std::string>::iterator iter_orig(lister_orig_copy.begin());
  for (size_t i = 0; i < lister_copy.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
  EXPECT_EQ(lister_orig.size(), lister.size());
  EXPECT_EQ(lister_orig_copy.size(), lister_copy.size());
}

TEST(List, max_size) {
  s21::list<std::string> lister_str;
  std::list<std::string> lister_orig_str;
  s21::list<std::pair<unsigned int, float>> lister_pair;
  std::list<std::pair<unsigned int, float>> lister_orig_pair;
  s21::list<long double> lister_ld;
  std::list<long double> lister_orig_ld;
  EXPECT_EQ(lister_orig_str.max_size(), lister_str.max_size());
  EXPECT_EQ(lister_orig_pair.max_size(), lister_pair.max_size());
  EXPECT_EQ(lister_orig_ld.max_size(), lister_ld.max_size());
}

TEST(List, push_back_empty) {
  s21::list<std::string> lister;
  std::list<std::string> lister_orig;
  lister.push_back("fbdfb");
  lister.push_back("fbddfgsfb");
  lister.push_back("fbfdsbdfb");
  lister.push_back("f3423bdg dsfb");

  lister_orig.push_back("fbdfb");
  lister_orig.push_back("fbddfgsfb");
  lister_orig.push_back("fbfdsbdfb");
  lister_orig.push_back("f3423bdg dsfb");

  s21::list<std::string>::iterator iter(lister.begin());
  std::list<std::string>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
  EXPECT_EQ(lister_orig.size(), lister.size());
}

TEST(List, push_back_filled) {
  s21::list<std::string> lister{"dftghfs", "sdvsd,", "dsgs234324"};
  std::list<std::string> lister_orig{"dftghfs", "sdvsd,", "dsgs234324"};
  lister.push_back("fbdfb");
  lister.push_back("fbddfgsfb");
  lister.push_back("fbfdsbdfb");
  lister.push_back("f3423bdg dsfb");

  lister_orig.push_back("fbdfb");
  lister_orig.push_back("fbddfgsfb");
  lister_orig.push_back("fbfdsbdfb");
  lister_orig.push_back("f3423bdg dsfb");

  s21::list<std::string>::iterator iter(lister.begin());
  std::list<std::string>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
  EXPECT_EQ(lister_orig.size(), lister.size());
}

TEST(List, push_front_empty) {
  s21::list<std::string> lister;
  std::list<std::string> lister_orig;
  lister.push_front("fbdfb");
  lister.push_front("fbddfgsfb");
  lister.push_front("fbfdsbdfb");
  lister.push_front("f3423bdg dsfb");

  lister_orig.push_front("fbdfb");
  lister_orig.push_front("fbddfgsfb");
  lister_orig.push_front("fbfdsbdfb");
  lister_orig.push_front("f3423bdg dsfb");

  s21::list<std::string>::iterator iter(lister.begin());
  std::list<std::string>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
  EXPECT_EQ(lister_orig.size(), lister.size());
}

TEST(List, push_front_filled) {
  s21::list<std::string> lister{"dftghfs", "sdvsd,", "dsgs234324"};
  std::list<std::string> lister_orig{"dftghfs", "sdvsd,", "dsgs234324"};
  lister.push_front("fbdfb");
  lister.push_front("fbddfgsfb");
  lister.push_front("fbfdsbdfb");
  lister.push_front("f3423bdg dsfb");

  lister_orig.push_front("fbdfb");
  lister_orig.push_front("fbddfgsfb");
  lister_orig.push_front("fbfdsbdfb");
  lister_orig.push_front("f3423bdg dsfb");

  s21::list<std::string>::iterator iter(lister.begin());
  std::list<std::string>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
  EXPECT_EQ(lister_orig.size(), lister.size());
}

TEST(List, pop_back) {
  s21::list<std::string> lister{"dftghfs", "sdvsd,", "dsgs234324"};
  std::list<std::string> lister_orig{"dftghfs", "sdvsd,", "dsgs234324"};
  lister.push_front("fbdfb");
  lister.push_front("fbddfgsfb");
  lister.push_front("fbfdsbdfb");
  lister.push_front("f3423bdg dsfb");

  lister_orig.push_front("fbdfb");
  lister_orig.push_front("fbddfgsfb");
  lister_orig.push_front("fbfdsbdfb");
  lister_orig.push_front("f3423bdg dsfb");
  size_t size = lister.size();
  for (size_t i = 0; i < size; i++) {
    EXPECT_EQ(lister.back(), lister_orig.back());
    lister.pop_back();
    lister_orig.pop_back();
  }
  EXPECT_THROW(lister.pop_back(), std::out_of_range);
  EXPECT_EQ(lister_orig.size(), lister.size());
}

TEST(List, pop_front) {
  s21::list<std::string> lister{"dftghfs", "sdvsd,", "dsgs234324"};
  std::list<std::string> lister_orig{"dftghfs", "sdvsd,", "dsgs234324"};
  lister.push_back("fbdfb");
  lister.push_back("fbddfgsfb");
  lister.push_back("fbfdsbdfb");
  lister.push_back("f3423bdg dsfb");

  lister_orig.push_back("fbdfb");
  lister_orig.push_back("fbddfgsfb");
  lister_orig.push_back("fbfdsbdfb");
  lister_orig.push_back("f3423bdg dsfb");
  size_t size = lister.size();
  for (size_t i = 0; i < size; i++) {
    EXPECT_EQ(lister.front(), lister_orig.front());
    lister.pop_front();
    lister_orig.pop_front();
  }
  EXPECT_THROW(lister.pop_front(), std::out_of_range);
  EXPECT_EQ(lister_orig.size(), lister.size());
}

TEST(List, empty) {
  s21::list<std::string> lister;
  std::list<std::string> lister_orig;
  EXPECT_EQ(lister_orig.empty(), lister.empty());
  EXPECT_EQ(lister_orig.size(), lister.size());
}

TEST(List, not_empty) {
  s21::list<std::string> lister{"dfgb"};
  std::list<std::string> lister_orig{"fsgbdf", "fsbdf"};
  EXPECT_EQ(lister_orig.empty(), lister.empty());
}

TEST(List, size) {
  s21::list<std::string> lister{"dfgb", "fsdgdfdf"};
  std::list<std::string> lister_orig{"fsgbdf", "fsbdf"};
  lister.push_front("fbdfb");
  lister.push_front("fbddfgsfb");
  lister.push_front("fbfdsbdfb");
  lister.push_front("f3423bdg dsfb");

  lister_orig.push_front("fbdfb");
  lister_orig.push_front("fbddfgsfb");
  lister_orig.push_front("fbfdsbdfb");
  lister_orig.push_front("f3423bdg dsfb");
  EXPECT_EQ(lister_orig.size(), lister.size());
}

TEST(List, sort_empty) {
  s21::list<int> lister;
  std::list<int> lister_orig;
  lister.sort();
  lister_orig.sort();
  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, sort_int) {
  s21::list<int> lister{3,  6,  2, 0, -2, 24, 56, -42, 72, 454, -2,  14,
                        -6, 32, 8, 0, 0,  0,  1,  -5,  -2, -76, -14, 54};
  std::list<int> lister_orig{3,  6,  2, 0, -2, 24, 56, -42, 72, 454, -2,  14,
                             -6, 32, 8, 0, 0,  0,  1,  -5,  -2, -76, -14, 54};
  lister.sort();
  lister_orig.sort();
  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, sort_string) {
  s21::list<std::string> lister{"dfgb", "fsdgdfdf"};
  std::list<std::string> lister_orig{"dfgb", "fsdgdfdf"};
  lister.push_front("fbdfb");
  lister.push_front("fbddfgsfb");
  lister.push_front("fbfdsbdfb");
  lister.push_front("f3423bdg dsfb");

  lister_orig.push_front("fbdfb");
  lister_orig.push_front("fbddfgsfb");
  lister_orig.push_front("fbfdsbdfb");
  lister_orig.push_front("f3423bdg dsfb");

  lister.sort();
  lister_orig.sort();
  s21::list<std::string>::iterator iter(lister.begin());
  std::list<std::string>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, sort_pair) {
  s21::list<std::pair<char, double>> lister{
      {'a', 435.123}, {'q', -322.1234}, {'9', 0.123}};
  std::list<std::pair<char, double>> lister_orig{
      {'a', 435.123}, {'q', -322.1234}, {'9', 0.123}};
  lister.push_front({'v', 34.13});
  lister.push_front({'U', -24.0023});
  lister.push_front({'.', 52324.123});
  lister.push_front({'v', -34532.23});

  lister_orig.push_front({'v', 34.13});
  lister_orig.push_front({'U', -24.0023});
  lister_orig.push_front({'.', 52324.123});
  lister_orig.push_front({'v', -34532.23});

  lister.sort();
  lister_orig.sort();
  s21::list<std::pair<char, double>>::iterator iter(lister.begin());
  std::list<std::pair<char, double>>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ((*iter).first, (*iter_orig).first);
    EXPECT_EQ((*iter).second, (*iter_orig).second);
  }
}

TEST(List, reverse_empty) {
  s21::list<int> lister;
  std::list<int> lister_orig;
  lister.reverse();
  lister_orig.reverse();
  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, reverse_int) {
  s21::list<int> lister{3,  6,  2, 0, -2, 24, 56, -42, 72, 454, -2,  14,
                        -6, 32, 8, 0, 0,  0,  1,  -5,  -2, -76, -14, 54};
  std::list<int> lister_orig{3,  6,  2, 0, -2, 24, 56, -42, 72, 454, -2,  14,
                             -6, 32, 8, 0, 0,  0,  1,  -5,  -2, -76, -14, 54};
  lister.reverse();
  lister_orig.reverse();
  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, reverse_string) {
  s21::list<std::string> lister{"dfgb", "fsdgdfdf"};
  std::list<std::string> lister_orig{"dfgb", "fsdgdfdf"};
  lister.push_front("fbdfb");
  lister.push_front("fbddfgsfb");
  lister.push_front("fbfdsbdfb");
  lister.push_front("f3423bdg dsfb");

  lister_orig.push_front("fbdfb");
  lister_orig.push_front("fbddfgsfb");
  lister_orig.push_front("fbfdsbdfb");
  lister_orig.push_front("f3423bdg dsfb");

  lister.reverse();
  lister_orig.reverse();
  s21::list<std::string>::iterator iter(lister.begin());
  std::list<std::string>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, reverse_pair) {
  s21::list<std::pair<char, double>> lister{
      {'a', 435.123}, {'q', -322.1234}, {'9', 0.123}};
  std::list<std::pair<char, double>> lister_orig{
      {'a', 435.123}, {'q', -322.1234}, {'9', 0.123}};
  lister.push_front({'v', 34.13});
  lister.push_front({'U', -24.0023});
  lister.push_front({'.', 52324.123});
  lister.push_front({'v', -34532.23});

  lister_orig.push_front({'v', 34.13});
  lister_orig.push_front({'U', -24.0023});
  lister_orig.push_front({'.', 52324.123});
  lister_orig.push_front({'v', -34532.23});

  lister.reverse();
  lister_orig.reverse();
  s21::list<std::pair<char, double>>::iterator iter(lister.begin());
  std::list<std::pair<char, double>>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ((*iter).first, (*iter_orig).first);
    EXPECT_EQ((*iter).second, (*iter_orig).second);
  }
}

TEST(List, unique_empty) {
  s21::list<int> lister;
  std::list<int> lister_orig;
  lister.sort();
  lister_orig.sort();
  lister.unique();
  lister_orig.unique();
  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, unique_int) {
  s21::list<int> lister{3,  6,  2, 3, 0, -2, 24, 56, -42, 72,  8,  454, -2, 14,
                        -6, 32, 8, 0, 0, 0,  1,  -5, -2,  -76, 72, -14, 54};
  std::list<int> lister_orig{3,  6, 2,   3,  0,  -2,  24, 56,  -42,
                             72, 8, 454, -2, 14, -6,  32, 8,   0,
                             0,  0, 1,   -5, -2, -76, 72, -14, 54};
  lister.sort();
  lister_orig.sort();
  lister.unique();
  lister_orig.unique();
  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, unique_string) {
  s21::list<std::string> lister{"dfgb", "fsdgdfdf"};
  std::list<std::string> lister_orig{"dfgb", "fsdgdfdf"};
  lister.push_front("fbdfb");
  lister.push_front("fbddfgsfb");
  lister.push_front("fbfdsbdfb");
  lister.push_front("f3423bdg dsfb");

  lister_orig.push_front("fbdfb");
  lister_orig.push_front("fbddfgsfb");
  lister_orig.push_front("fbfdsbdfb");
  lister_orig.push_front("f3423bdg dsfb");

  lister.sort();
  lister_orig.sort();
  lister.unique();
  lister_orig.unique();
  s21::list<std::string>::iterator iter(lister.begin());
  std::list<std::string>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, unique_pair) {
  s21::list<std::pair<char, double>> lister{
      {'a', 435.123}, {'q', -322.1234}, {'9', 0.123}, {'a', 435.123}};
  std::list<std::pair<char, double>> lister_orig{
      {'a', 435.123}, {'q', -322.1234}, {'9', 0.123}, {'a', 435.123}};
  lister.push_front({'v', 34.13});
  lister.push_front({'U', -24.0023});
  lister.push_front({'v', -34532.23});
  lister.push_front({'.', 52324.123});
  lister.push_front({'v', -34532.23});
  lister.push_front({'v', 34.13});

  lister_orig.push_front({'v', 34.13});
  lister_orig.push_front({'U', -24.0023});
  lister_orig.push_front({'v', -34532.23});
  lister_orig.push_front({'.', 52324.123});
  lister_orig.push_front({'v', -34532.23});
  lister_orig.push_front({'v', 34.13});
  lister.sort();
  lister_orig.sort();
  lister.unique();
  lister_orig.unique();
  s21::list<std::pair<char, double>>::iterator iter(lister.begin());
  std::list<std::pair<char, double>>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ((*iter).first, (*iter_orig).first);
    EXPECT_EQ((*iter).second, (*iter_orig).second);
  }
}

TEST(List, swap_empty) {
  s21::list<int> lister;
  std::list<int> lister_orig;
  s21::list<int> lister_swap;
  std::list<int> lister_orig_swap;

  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
  lister.swap(lister_swap);
  lister_orig.swap(lister_orig_swap);
  iter = lister_swap.begin();
  iter_orig = lister_orig_swap.begin();
  for (size_t i = 0; i < lister_swap.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, swap_empty_first) {
  s21::list<int> lister;
  std::list<int> lister_orig;
  s21::list<int> lister_swap{1, 2, 3, 4, 5};
  std::list<int> lister_orig_swap{1, 2, 3, 4, 5};

  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
  lister.swap(lister_swap);
  lister_orig.swap(lister_orig_swap);
  iter = lister_swap.begin();
  iter_orig = lister_orig_swap.begin();
  for (size_t i = 0; i < lister_swap.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, swap_empty_second) {
  s21::list<int> lister{1, 2, 3, 4, 5};
  std::list<int> lister_orig{1, 2, 3, 4, 5};
  s21::list<int> lister_swap;
  std::list<int> lister_orig_swap;

  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
  lister.swap(lister_swap);
  lister_orig.swap(lister_orig_swap);
  iter = lister_swap.begin();
  iter_orig = lister_orig_swap.begin();
  for (size_t i = 0; i < lister_swap.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, swap) {
  s21::list<int> lister{1, 2, 3, 4, 5};
  std::list<int> lister_orig{1, 2, 3, 4, 5};
  s21::list<int> lister_swap{0};
  std::list<int> lister_orig_swap{0};

  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
  lister.swap(lister_swap);
  lister_orig.swap(lister_orig_swap);
  iter = lister_swap.begin();
  iter_orig = lister_orig_swap.begin();
  for (size_t i = 0; i < lister_swap.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, merge_empty) {
  s21::list<int> lister;
  std::list<int> lister_orig;
  s21::list<int> lister_merge;
  std::list<int> lister_orig_merge;

  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
  lister.merge(lister_merge);
  lister_orig.merge(lister_orig_merge);
  iter = lister.begin();
  iter_orig = lister_orig.begin();
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, merge_empty_first) {
  s21::list<int> lister;
  std::list<int> lister_orig;
  s21::list<int> lister_merge{3, 2, 1, 4, 5};
  std::list<int> lister_orig_merge{3, 2, 1, 4, 5};

  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  lister.merge(lister_merge);
  lister_orig.merge(lister_orig_merge);
  iter = lister.begin();
  iter_orig = lister_orig.begin();
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, merge_empty_second) {
  s21::list<int> lister{3, 2, 3, 1, 5};
  std::list<int> lister_orig{3, 2, 3, 1, 5};
  s21::list<int> lister_merge;
  std::list<int> lister_orig_merge;

  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  lister.merge(lister_merge);
  lister_orig.merge(lister_orig_merge);
  iter = lister.begin();
  iter_orig = lister_orig.begin();
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, merge_first_more) {
  s21::list<int> lister{2, 1, 5, 30, 12, 6, 3, 6,  566, 0,  43, 9, 8,
                        7, 6, 5, 4,  3,  2, 1, -2, -5,  -6, 4,  -7};
  std::list<int> lister_orig{2, 1, 5, 30, 12, 6, 3, 6,  566, 0,  43, 9, 8,
                             7, 6, 5, 4,  3,  2, 1, -2, -5,  -6, 4,  -7};
  s21::list<int> lister_merge{1, 2, 3, 10, 6, 2, 20, 7, 2};
  std::list<int> lister_orig_merge{1, 2, 3, 10, 6, 2, 20, 7, 2};

  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  lister.merge(lister_merge);
  lister_orig.merge(lister_orig_merge);
  iter = lister.begin();
  iter_orig = lister_orig.begin();
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, merge_second_more) {
  s21::list<int> lister{1, 2, 3, 10, 6, 2, 20, 7, 2};
  std::list<int> lister_orig{1, 2, 3, 10, 6, 2, 20, 7, 2};
  s21::list<int> lister_merge{2, 1, 5, 30, 12, 6, 3, 6,  566, 0,  43, 9, 8,
                              7, 6, 5, 4,  3,  2, 1, -2, -5,  -6, 4,  -7};
  std::list<int> lister_orig_merge{2, 1, 5, 30, 12, 6, 3, 6,  566, 0,  43, 9, 8,
                                   7, 6, 5, 4,  3,  2, 1, -2, -5,  -6, 4,  -7};

  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  lister.merge(lister_merge);
  lister_orig.merge(lister_orig_merge);
  iter = lister.begin();
  iter_orig = lister_orig.begin();
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, merge_equal) {
  s21::list<int> lister{1, 2, 3, 10, 3, 6, 566, 0, 43, 9,  8, 7,
                        6, 5, 4, 3,  2, 1, -2,  6, 2,  20, 7, 2};
  std::list<int> lister_orig{1, 2, 3, 10, 3, 6, 566, 0, 43, 9,  8, 7,
                             6, 5, 4, 3,  2, 1, -2,  6, 2,  20, 7, 2};
  s21::list<int> lister_merge{2, 1, 5, 30, 12, 6, 3, 6,  566, 0,  43, 9, 8,
                              7, 6, 5, 4,  3,  2, 1, -2, -5,  -6, 4,  -7};
  std::list<int> lister_orig_merge{2, 1, 5, 30, 12, 6, 3, 6,  566, 0,  43, 9, 8,
                                   7, 6, 5, 4,  3,  2, 1, -2, -5,  -6, 4,  -7};

  s21::list<int>::iterator iter(lister.begin());
  std::list<int>::iterator iter_orig(lister_orig.begin());
  lister.merge(lister_merge);
  lister_orig.merge(lister_orig_merge);
  iter = lister.begin();
  iter_orig = lister_orig.begin();
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, operator_eq) {
  s21::list<std::pair<std::string, double>> lister_1_empty;
  s21::list<std::pair<std::string, double>> lister_2_empty;
  std::list<std::pair<std::string, double>> lister_orig_1_empty;
  std::list<std::pair<std::string, double>> lister_orig_2_empty;
  s21::list<std::pair<std::string, double>> lister_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::list<std::pair<std::string, double>> lister_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::list<std::pair<std::string, double>> lister_orig_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::list<std::pair<std::string, double>> lister_orig_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};

  EXPECT_EQ(lister_orig_1_empty == lister_orig_2_empty,
            lister_1_empty == lister_2_empty);
  EXPECT_EQ(lister_orig_1_empty == lister_orig_1, lister_1_empty == lister_1);
  EXPECT_EQ(lister_orig_1 == lister_orig_1_empty, lister_1 == lister_1_empty);
  EXPECT_EQ(lister_orig_1 == lister_orig_2, lister_1 == lister_2);

  lister_1.push_front({"fg43df23", 34.13});
  lister_1.push_front({"gfb34dfvsw", -24.0023});
  lister_orig_1.push_front({"fg43df23", 34.13});
  lister_orig_1.push_front({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(lister_orig_1 == lister_orig_2, lister_1 == lister_2);

  lister_2.push_front({"fg43df23", 34.13});
  lister_2.push_front({"gfb34dfvsw", -24.0023});
  lister_2.push_front({"fd34fv23 ", 52324.123});
  lister_2.push_front({"VdfsdDS43", -34532.23});
  lister_orig_2.push_front({"fg43df23", 34.13});
  lister_orig_2.push_front({"gfb34dfvsw", -24.0023});
  lister_orig_2.push_front({"fd34fv23 ", 52324.123});
  lister_orig_2.push_front({"VdfsdDS43", -34532.23});

  EXPECT_EQ(lister_orig_1 == lister_orig_2, lister_1 == lister_2);

  lister_2.pop_front();
  lister_2.pop_front();
  lister_orig_2.pop_front();
  lister_orig_2.pop_front();

  EXPECT_EQ(lister_orig_1 == lister_orig_2, lister_1 == lister_2);
}

TEST(List, operator_not_eq) {
  s21::list<std::pair<std::string, double>> lister_1_empty;
  s21::list<std::pair<std::string, double>> lister_2_empty;
  std::list<std::pair<std::string, double>> lister_orig_1_empty;
  std::list<std::pair<std::string, double>> lister_orig_2_empty;
  s21::list<std::pair<std::string, double>> lister_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::list<std::pair<std::string, double>> lister_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::list<std::pair<std::string, double>> lister_orig_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::list<std::pair<std::string, double>> lister_orig_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};

  EXPECT_EQ(lister_orig_1_empty != lister_orig_2_empty,
            lister_1_empty != lister_2_empty);
  EXPECT_EQ(lister_orig_1_empty != lister_orig_1, lister_1_empty != lister_1);
  EXPECT_EQ(lister_orig_1 != lister_orig_1_empty, lister_1 != lister_1_empty);
  EXPECT_EQ(lister_orig_1 != lister_orig_2, lister_1 != lister_2);

  lister_1.push_front({"fg43df23", 34.13});
  lister_1.push_front({"gfb34dfvsw", -24.0023});
  lister_orig_1.push_front({"fg43df23", 34.13});
  lister_orig_1.push_front({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(lister_orig_1 != lister_orig_2, lister_1 != lister_2);

  lister_2.push_front({"fg43df23", 34.13});
  lister_2.push_front({"gfb34dfvsw", -24.0023});
  lister_2.push_front({"fd34fv23 ", 52324.123});
  lister_2.push_front({"VdfsdDS43", -34532.23});
  lister_orig_2.push_front({"fg43df23", 34.13});
  lister_orig_2.push_front({"gfb34dfvsw", -24.0023});
  lister_orig_2.push_front({"fd34fv23 ", 52324.123});
  lister_orig_2.push_front({"VdfsdDS43", -34532.23});

  EXPECT_EQ(lister_orig_1 != lister_orig_2, lister_1 != lister_2);

  lister_2.pop_front();
  lister_2.pop_front();
  lister_orig_2.pop_front();
  lister_orig_2.pop_front();

  EXPECT_EQ(lister_orig_1 != lister_orig_2, lister_1 != lister_2);
}

TEST(List, operator_more_eq) {
  s21::list<std::pair<std::string, double>> lister_1_empty;
  s21::list<std::pair<std::string, double>> lister_2_empty;
  std::list<std::pair<std::string, double>> lister_orig_1_empty;
  std::list<std::pair<std::string, double>> lister_orig_2_empty;
  s21::list<std::pair<std::string, double>> lister_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::list<std::pair<std::string, double>> lister_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::list<std::pair<std::string, double>> lister_orig_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::list<std::pair<std::string, double>> lister_orig_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};

  EXPECT_EQ(lister_orig_1_empty >= lister_orig_2_empty,
            lister_1_empty >= lister_2_empty);
  EXPECT_EQ(lister_orig_1_empty >= lister_orig_1, lister_1_empty >= lister_1);
  EXPECT_EQ(lister_orig_1 >= lister_orig_1_empty, lister_1 >= lister_1_empty);
  EXPECT_EQ(lister_orig_1 >= lister_orig_2, lister_1 >= lister_2);

  lister_1.push_front({"fg43df23", 34.13});
  lister_1.push_front({"gfb34dfvsw", -24.0023});
  lister_orig_1.push_front({"fg43df23", 34.13});
  lister_orig_1.push_front({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(lister_orig_1 >= lister_orig_2, lister_1 >= lister_2);

  lister_2.push_front({"fg43df23", 34.13});
  lister_2.push_front({"gfb34dfvsw", -24.0023});
  lister_2.push_front({"fd34fv23 ", 52324.123});
  lister_2.push_front({"VdfsdDS43", -34532.23});
  lister_orig_2.push_front({"fg43df23", 34.13});
  lister_orig_2.push_front({"gfb34dfvsw", -24.0023});
  lister_orig_2.push_front({"fd34fv23 ", 52324.123});
  lister_orig_2.push_front({"VdfsdDS43", -34532.23});

  EXPECT_EQ(lister_orig_1 >= lister_orig_2, lister_1 >= lister_2);

  lister_2.pop_front();
  lister_2.pop_front();
  lister_orig_2.pop_front();
  lister_orig_2.pop_front();

  EXPECT_EQ(lister_orig_1 >= lister_orig_2, lister_1 >= lister_2);
}

TEST(List, operator_more) {
  s21::list<std::pair<std::string, double>> lister_1_empty;
  s21::list<std::pair<std::string, double>> lister_2_empty;
  std::list<std::pair<std::string, double>> lister_orig_1_empty;
  std::list<std::pair<std::string, double>> lister_orig_2_empty;
  s21::list<std::pair<std::string, double>> lister_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::list<std::pair<std::string, double>> lister_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::list<std::pair<std::string, double>> lister_orig_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::list<std::pair<std::string, double>> lister_orig_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};

  EXPECT_EQ(lister_orig_1_empty > lister_orig_2_empty,
            lister_1_empty > lister_2_empty);
  EXPECT_EQ(lister_orig_1_empty > lister_orig_1, lister_1_empty > lister_1);
  EXPECT_EQ(lister_orig_1 > lister_orig_1_empty, lister_1 > lister_1_empty);
  EXPECT_EQ(lister_orig_1 > lister_orig_2, lister_1 > lister_2);

  lister_1.push_front({"fg43df23", 34.13});
  lister_1.push_front({"gfb34dfvsw", -24.0023});
  lister_orig_1.push_front({"fg43df23", 34.13});
  lister_orig_1.push_front({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(lister_orig_1 > lister_orig_2, lister_1 > lister_2);

  lister_2.push_front({"fg43df23", 34.13});
  lister_2.push_front({"gfb34dfvsw", -24.0023});
  lister_2.push_front({"fd34fv23 ", 52324.123});
  lister_2.push_front({"VdfsdDS43", -34532.23});
  lister_orig_2.push_front({"fg43df23", 34.13});
  lister_orig_2.push_front({"gfb34dfvsw", -24.0023});
  lister_orig_2.push_front({"fd34fv23 ", 52324.123});
  lister_orig_2.push_front({"VdfsdDS43", -34532.23});

  EXPECT_EQ(lister_orig_1 > lister_orig_2, lister_1 > lister_2);

  lister_2.pop_front();
  lister_2.pop_front();
  lister_orig_2.pop_front();
  lister_orig_2.pop_front();

  EXPECT_EQ(lister_orig_1 > lister_orig_2, lister_1 > lister_2);
}

TEST(List, operator_less_eq) {
  s21::list<std::pair<std::string, double>> lister_1_empty;
  s21::list<std::pair<std::string, double>> lister_2_empty;
  std::list<std::pair<std::string, double>> lister_orig_1_empty;
  std::list<std::pair<std::string, double>> lister_orig_2_empty;
  s21::list<std::pair<std::string, double>> lister_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::list<std::pair<std::string, double>> lister_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::list<std::pair<std::string, double>> lister_orig_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::list<std::pair<std::string, double>> lister_orig_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};

  EXPECT_EQ(lister_orig_1_empty <= lister_orig_2_empty,
            lister_1_empty <= lister_2_empty);
  EXPECT_EQ(lister_orig_1_empty <= lister_orig_1, lister_1_empty <= lister_1);
  EXPECT_EQ(lister_orig_1 <= lister_orig_1_empty, lister_1 <= lister_1_empty);
  EXPECT_EQ(lister_orig_1 <= lister_orig_2, lister_1 <= lister_2);

  lister_1.push_front({"fg43df23", 34.13});
  lister_1.push_front({"gfb34dfvsw", -24.0023});
  lister_orig_1.push_front({"fg43df23", 34.13});
  lister_orig_1.push_front({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(lister_orig_1 <= lister_orig_2, lister_1 <= lister_2);

  lister_2.push_front({"fg43df23", 34.13});
  lister_2.push_front({"gfb34dfvsw", -24.0023});
  lister_2.push_front({"fd34fv23 ", 52324.123});
  lister_2.push_front({"VdfsdDS43", -34532.23});
  lister_orig_2.push_front({"fg43df23", 34.13});
  lister_orig_2.push_front({"gfb34dfvsw", -24.0023});
  lister_orig_2.push_front({"fd34fv23 ", 52324.123});
  lister_orig_2.push_front({"VdfsdDS43", -34532.23});

  EXPECT_EQ(lister_orig_1 <= lister_orig_2, lister_1 <= lister_2);

  lister_2.pop_front();
  lister_2.pop_front();
  lister_orig_2.pop_front();
  lister_orig_2.pop_front();

  EXPECT_EQ(lister_orig_1 <= lister_orig_2, lister_1 <= lister_2);
}

TEST(List, operator_less) {
  s21::list<std::pair<std::string, double>> lister_1_empty;
  s21::list<std::pair<std::string, double>> lister_2_empty;
  std::list<std::pair<std::string, double>> lister_orig_1_empty;
  std::list<std::pair<std::string, double>> lister_orig_2_empty;
  s21::list<std::pair<std::string, double>> lister_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  s21::list<std::pair<std::string, double>> lister_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::list<std::pair<std::string, double>> lister_orig_1{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};
  std::list<std::pair<std::string, double>> lister_orig_2{
      {"dfhbdfsa", 435.123}, {"gfsesfd23 ", -322.1234}, {"df23frws312", 0.123}};

  EXPECT_EQ(lister_orig_1_empty < lister_orig_2_empty,
            lister_1_empty < lister_2_empty);
  EXPECT_EQ(lister_orig_1_empty < lister_orig_1, lister_1_empty < lister_1);
  EXPECT_EQ(lister_orig_1 < lister_orig_1_empty, lister_1 < lister_1_empty);
  EXPECT_EQ(lister_orig_1 < lister_orig_2, lister_1 < lister_2);

  lister_1.push_front({"fg43df23", 34.13});
  lister_1.push_front({"gfb34dfvsw", -24.0023});
  lister_orig_1.push_front({"fg43df23", 34.13});
  lister_orig_1.push_front({"gfb34dfvsw", -24.0023});

  EXPECT_EQ(lister_orig_1 < lister_orig_2, lister_1 < lister_2);

  lister_2.push_front({"fg43df23", 34.13});
  lister_2.push_front({"gfb34dfvsw", -24.0023});
  lister_2.push_front({"fd34fv23 ", 52324.123});
  lister_2.push_front({"VdfsdDS43", -34532.23});
  lister_orig_2.push_front({"fg43df23", 34.13});
  lister_orig_2.push_front({"gfb34dfvsw", -24.0023});
  lister_orig_2.push_front({"fd34fv23 ", 52324.123});
  lister_orig_2.push_front({"VdfsdDS43", -34532.23});

  EXPECT_EQ(lister_orig_1 < lister_orig_2, lister_1 < lister_2);

  lister_2.pop_front();
  lister_2.pop_front();
  lister_orig_2.pop_front();
  lister_orig_2.pop_front();

  EXPECT_EQ(lister_orig_1 < lister_orig_2, lister_1 < lister_2);
}

TEST(List, iterator_empty) {
  s21::list<int>::iterator iter;
  s21::list<int> lister{1, 2, 3};
  s21::list<int>::iterator iter_compare(lister.begin());
  EXPECT_THROW(*iter, std::out_of_range);
  EXPECT_THROW(--iter, std::out_of_range);
  EXPECT_THROW(++iter, std::out_of_range);
  EXPECT_THROW(
      {
        if (iter == iter_compare) {
        }
      },
      std::out_of_range);
  EXPECT_THROW(
      {
        if (iter != iter_compare) {
        }
      },
      std::out_of_range);
}

TEST(List, iterator_insert_empty) {
  s21::list<int> lister;
  s21::list<int>::iterator iter;
  EXPECT_THROW(lister.insert(iter, 1), std::out_of_range);
}

TEST(List, iterator_insert) {
  s21::list<int> lister{2, 3, 4};
  s21::list<int>::iterator iter(lister.begin());
  std::list<int> lister_orig{2, 3, 4};
  std::list<int>::iterator iter_orig(lister_orig.begin());

  EXPECT_EQ(*lister_orig.insert(iter_orig, 1), *lister.insert(iter, 1));
  EXPECT_EQ(*iter_orig, *iter);
  iter = lister.end();
  iter_orig = lister_orig.end();

  lister.insert(iter, 22);
  lister.insert(iter, 33);
  lister.insert(iter, 44);
  lister_orig.insert(iter_orig, 22);
  lister_orig.insert(iter_orig, 33);
  lister_orig.insert(iter_orig, 44);

  EXPECT_EQ(*lister_orig.insert(iter_orig, 66), *lister.insert(iter, 66));
  --iter;
  --iter_orig;
  EXPECT_EQ(*iter_orig, *iter);
  --iter;
  --iter_orig;
  EXPECT_EQ(*iter_orig, *iter);
  --iter;
  --iter_orig;
  EXPECT_EQ(*iter_orig, *iter);
  iter = lister.end();
  iter_orig = lister_orig.end();
  ++iter;
  ++iter_orig;
  EXPECT_EQ(*iter_orig, *iter);
}

TEST(List, iterator_erase) {
  s21::list<int> lister{2, 3, 4, 22, 33, 44, 55, 66};
  s21::list<int>::iterator iter(lister.begin());
  std::list<int> lister_orig{2, 3, 4, 22, 33, 44, 55, 66};
  std::list<int>::iterator iter_orig(lister_orig.begin());
  lister_orig.erase(iter_orig);
  lister.erase(iter);
  iter = lister.end();
  iter_orig = lister_orig.end();
  --iter;
  --iter_orig;
  lister.erase(iter);
  lister_orig.erase(iter_orig);
  iter = lister.end();
  iter_orig = lister_orig.end();
  --iter;
  --iter_orig;
  --iter;
  --iter_orig;
  lister.erase(iter);
  lister_orig.erase(iter_orig);
  iter = lister.end();
  iter_orig = lister_orig.end();
  ++iter;
  ++iter_orig;
  ++iter;
  ++iter_orig;
  iter = lister.begin();
  iter_orig = lister_orig.begin();
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, iterator_splice_begin) {
  s21::list<int> lister{2, 3, 4, 22, 33, 44, 55, 66};
  s21::list<int> lister_splice{256, 3, 345323, 346, 234, 63};
  s21::list<int>::iterator iter(lister.begin());

  std::list<int> lister_orig{2, 3, 4, 22, 33, 44, 55, 66};
  std::list<int> lister_orig_splice{256, 3, 345323, 346, 234, 63};
  std::list<int>::iterator iter_orig(lister_orig.begin());
  lister.splice(iter, lister_splice);
  lister_orig.splice(iter_orig, lister_orig_splice);
  iter = lister.begin();
  iter_orig = lister_orig.begin();
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, iterator_splice_end) {
  s21::list<int> lister{2, 3, 4, 22, 33, 44, 55, 66};
  s21::list<int> lister_splice{256, 3, 345323, 346, 234, 63};
  s21::list<int>::iterator iter(lister.end());

  std::list<int> lister_orig{2, 3, 4, 22, 33, 44, 55, 66};
  std::list<int> lister_orig_splice{256, 3, 345323, 346, 234, 63};
  std::list<int>::iterator iter_orig(lister_orig.end());
  lister.splice(iter, lister_splice);
  lister_orig.splice(iter_orig, lister_orig_splice);
  iter = lister.begin();
  iter_orig = lister_orig.begin();
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, iterator_splice_center) {
  s21::list<int> lister{2, 3, 4, 22, 33, 44, 55, 66};
  s21::list<int> lister_splice{256, 3, 345323, 346, 234, 63};
  s21::list<int>::iterator iter(lister.begin());
  ++iter;
  ++iter;
  ++iter;
  ++iter;
  std::list<int> lister_orig{2, 3, 4, 22, 33, 44, 55, 66};
  std::list<int> lister_orig_splice{256, 3, 345323, 346, 234, 63};
  std::list<int>::iterator iter_orig(lister_orig.begin());
  ++iter_orig;
  ++iter_orig;
  ++iter_orig;
  ++iter_orig;
  lister.splice(iter, lister_splice);
  lister_orig.splice(iter_orig, lister_orig_splice);
  iter = lister.begin();
  iter_orig = lister_orig.begin();
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, iterator_splice_first_empty) {
  s21::list<int> lister;
  s21::list<int> lister_splice{256, 3, 345323, 346, 234, 63};
  s21::list<int>::iterator iter(lister.begin());

  std::list<int> lister_orig;
  std::list<int> lister_orig_splice{256, 3, 345323, 346, 234, 63};
  std::list<int>::iterator iter_orig(lister_orig.begin());
  lister.splice(iter, lister_splice);
  lister_orig.splice(iter_orig, lister_orig_splice);
  iter = lister.begin();
  iter_orig = lister_orig.begin();
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, iterator_splice_second_empty) {
  s21::list<int> lister{2, 3, 4, 22, 33, 44, 55, 66};
  s21::list<int> lister_splice;
  s21::list<int>::iterator iter(lister.begin());

  std::list<int> lister_orig{2, 3, 4, 22, 33, 44, 55, 66};
  std::list<int> lister_orig_splice;
  std::list<int>::iterator iter_orig(lister_orig.begin());
  lister.splice(iter, lister_splice);
  lister_orig.splice(iter_orig, lister_orig_splice);
  iter = lister.begin();
  iter_orig = lister_orig.begin();
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, iterator_splice_empty) {
  s21::list<int> lister;
  s21::list<int> lister_splice;
  s21::list<int>::iterator iter(lister.begin());

  std::list<int> lister_orig;
  std::list<int> lister_orig_splice;
  std::list<int>::iterator iter_orig(lister_orig.begin());
  lister.splice(iter, lister_splice);
  lister_orig.splice(iter_orig, lister_orig_splice);
  iter = lister.begin();
  iter_orig = lister_orig.begin();
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, iterator_splice_same) {
  s21::list<int> lister{2, 3, 4, 22, 33, 44, 55, 66};
  s21::list<int>::iterator iter(lister.begin());

  std::list<int> lister_orig{2, 3, 4, 22, 33, 44, 55, 66};
  std::list<int>::iterator iter_orig(lister_orig.begin());
  lister.splice(iter, lister);
  // lister_orig.splice(iter_orig, lister_orig); если так сделать, то в
  // оригинале утечка, т. к. он занулит size
  iter = lister.begin();
  iter_orig = lister_orig.begin();
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, swap_same) {
  s21::list<int> lister{2, 3, 4, 22, 33, 44, 55, 66};
  s21::list<int>::iterator iter(lister.begin());

  std::list<int> lister_orig{2, 3, 4, 22, 33, 44, 55, 66};
  std::list<int>::iterator iter_orig(lister_orig.begin());
  lister.swap(lister);
  lister_orig.swap(lister_orig);
  iter = lister.begin();
  iter_orig = lister_orig.begin();
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, merge_same) {
  s21::list<int> lister{2, 3, 4, 22, 33, 44, 55, 66};
  s21::list<int>::iterator iter(lister.begin());

  std::list<int> lister_orig{2, 3, 4, 22, 33, 44, 55, 66};
  std::list<int>::iterator iter_orig(lister_orig.begin());
  lister.merge(lister);
  lister_orig.merge(lister_orig);
  iter = lister.begin();
  iter_orig = lister_orig.begin();
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ(*iter, *iter_orig);
  }
}

TEST(List, emplace) {
  s21::list<std::pair<char, double>> lister{
      {'a', 435.123}, {'q', -322.1234}, {'9', 0.123}};
  std::list<std::pair<char, double>> lister_orig{
      {'a', 435.123}, {'q', -322.1234}, {'9', 0.123}};
  s21::list<std::pair<char, double>>::const_iterator iter(lister.begin());
  ++iter;
  ++iter;
  ++iter;
  ++iter;
  std::list<std::pair<char, double>>::const_iterator iter_orig(
      lister_orig.begin());
  ++iter_orig;
  ++iter_orig;
  ++iter_orig;
  ++iter_orig;

  lister.emplace(iter, std::pair<char, double>('v', 34.13));
  lister.emplace(iter, std::pair<char, double>('U', -24.0023));
  lister.emplace(iter, std::pair<char, double>('.', 52324.123));
  lister.emplace(iter, std::pair<char, double>('v', -34532.23));

  lister_orig.emplace(iter_orig, 'v', 34.13);
  lister_orig.emplace(iter_orig, 'U', -24.0023);
  lister_orig.emplace(iter_orig, '.', 52324.123);
  lister_orig.emplace(iter_orig, 'v', -34532.23);

  iter = lister.begin();
  iter_orig = lister_orig.begin();
  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ((*iter).first, (*iter_orig).first);
    EXPECT_EQ((*iter).second, (*iter_orig).second);
  }
  EXPECT_EQ(lister_orig.size(), lister.size());
}

TEST(List, emplace_back) {
  s21::list<std::pair<char, double>> lister{
      {'a', 435.123}, {'q', -322.1234}, {'9', 0.123}};
  std::list<std::pair<char, double>> lister_orig{
      {'a', 435.123}, {'q', -322.1234}, {'9', 0.123}};

  lister.emplace_back(std::pair<char, double>('v', 34.13));
  lister.emplace_back(std::pair<char, double>('U', -24.0023));
  lister.emplace_back(std::pair<char, double>('.', 52324.123));
  lister.emplace_back(std::pair<char, double>('v', -34532.23));

  lister_orig.emplace_back('v', 34.13);
  lister_orig.emplace_back('U', -24.0023);
  lister_orig.emplace_back('.', 52324.123);
  lister_orig.emplace_back('v', -34532.23);

  s21::list<std::pair<char, double>>::const_iterator iter(lister.begin());
  std::list<std::pair<char, double>>::const_iterator iter_orig(
      lister_orig.begin());

  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ((*iter).first, (*iter_orig).first);
    EXPECT_EQ((*iter).second, (*iter_orig).second);
  }
  EXPECT_EQ(lister_orig.size(), lister.size());
}

TEST(List, emplace_front) {
  s21::list<std::pair<char, double>> lister{
      {'a', 435.123}, {'q', -322.1234}, {'9', 0.123}};
  std::list<std::pair<char, double>> lister_orig{
      {'a', 435.123}, {'q', -322.1234}, {'9', 0.123}};

  lister.emplace_front(std::pair<char, double>('v', 34.13));
  lister.emplace_front(std::pair<char, double>('U', -24.0023));
  lister.emplace_front(std::pair<char, double>('.', 52324.123));
  lister.emplace_front(std::pair<char, double>('v', -34532.23));

  lister_orig.emplace_front('v', 34.13);
  lister_orig.emplace_front('U', -24.0023);
  lister_orig.emplace_front('.', 52324.123);
  lister_orig.emplace_front('v', -34532.23);

  s21::list<std::pair<char, double>>::const_iterator iter(lister.begin());
  std::list<std::pair<char, double>>::const_iterator iter_orig(
      lister_orig.begin());

  for (size_t i = 0; i < lister.size(); i++, ++iter, ++iter_orig) {
    EXPECT_EQ((*iter).first, (*iter_orig).first);
    EXPECT_EQ((*iter).second, (*iter_orig).second);
  }
  EXPECT_EQ(lister_orig.size(), lister.size());
}
