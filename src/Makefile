CC = g++ 
CFLAGS = -std=c++17 -Wall -Werror -Wextra
GCOVFLAGS = -g -O0 -Wall -fprofile-arcs -ftest-coverage
GTESTFLAGS = -lgtest #-fsanitize=address
VALGRINDFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose

OPEN = open

OS = $(shell uname -s)
ifeq ($(OS), Linux)
	GTESTFLAGS += -lpthread
	OPEN = xdg-open
endif

PROJECT_NAME = s21_containers

SRC_DIR = .
TEST_DIR = ./test
REPORT_DIR = ./report

TEST_SRC = $(TEST_DIR)/test_main.cc
TEST = $(TEST_DIR)/test

default: all

all:

run: style gcov_report

style:
	clang-format -n --style=google --verbose $(SRC_DIR)/*.h

cppcheck:
	cppcheck -x c++ --std=c++17 --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction --suppress=noExplicitConstructor $(SRC_DIR)/*.h

clean:
	rm -rf *.txt
	rm -rf $(TEST_DIR)/s21_*.h
	rm -rf $(TEST)
	rm -rf $(TEST_DIR)/*.gcno $(TEST_DIR)/*.info  $(TEST_DIR)/*.gcda
	rm -rf $(TEST_DIR)/test_cov
	rm -rf $(REPORT_DIR)

test: $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) $(GTESTFLAGS) -o $(TEST) 
	$(TEST)

valgrind: test
	valgrind $(VALGRINDFLAGS) --log-file=valgrind_report.txt $(TEST)

leaks: test
	leaks -atExit -- $(TEST) > leaks_report.txt

gcov_report: $(TESTOBJS) $(TEST_SRC)
	mkdir -p $(REPORT_DIR)
	$(CC) $(CFLAGS) $(TEST_SRC) $(GCOVFLAGS) $(GTESTFLAGS) -o $(TEST_DIR)/test_cov
	$(TEST_DIR)/test_cov
	# lcov -t "test_$(CORE_NAME)" -o $(TEST_DIR)/test_$(CORE_NAME).info -c -d .
	# genhtml -o $(REPORT_DIR) $(TEST_DIR)/test_$(CORE_NAME).info
	gcovr -r . -e test/ --html --html-details -o $(REPORT_DIR)/index.html
	$(OPEN) $(REPORT_DIR)/index.html

.PHONY: all clean test style cppcheck gcov_report default clang_format valgrind leaks build install uninstall rebuild run dvi dist 
