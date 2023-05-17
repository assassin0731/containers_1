#include "test_s21_list.cc"
#include "test_s21_queue.cc"
#include "test_s21_stack.cc"

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
