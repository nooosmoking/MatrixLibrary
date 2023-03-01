GCC = gcc
CFLAGS = -I.
LDFLAGS = -c
SOURCE := $(shell find ./source  -iname "*.c" )
TEST_SOURCE := $(shell find ./tests  -iname "*.c" )
HEADER_SOURCE := $(shell find . -iname "*.h" )
ALL := := $(shell find ./  -iname "*.c" )

ifeq ($(shell uname -s),Darwin)
	TEST_FLAGS  = -fprofile-arcs -ftest-coverage --coverage $^ -o $@ -lcheck -lpthread -lm
else
	TEST_FLAGS  = -fprofile-arcs -ftest-coverage --coverage $^ -o $@ -lcheck -lgcov -lpthread -lm -lsubunit 
endif

all: clean s21_math.a test

s21_math.a: ${SOURCE} clean
	$(GCC) $(CFLAGS) $(LDFLAGS) $(SOURCE)
	ar rc $@  *.o
	ranlib $@

test: ${SOURCE} ${TEST_SOURCE}
	$(GCC) $(CFLAGS) $(TEST_FLAGS) 
	./$@

gcov_report: test
	gcov ./*.c
	rm -rf *test.gcda *test.gcno *est_main.gcda *est_main.gcno
	find ./ -type f -iname '*.gcda'
	lcov --directory ./ --capture --output-file postgresql.info
	mkdir cov-report
	genhtml -o ./cov-report/ postgresql.info

lcov:
ifeq ("", "$(shell PATH=$(PATH) which lcov)")
	$(error Need to install lcov)
endif

cpplint: $(SOURCE) $(SOURCE_TEST)
	python3 ../materials/linters/cpplint.py --extensions=c $^

leaks: test
	leaks -atExit -- ./test

cppcheck: $(ALL)
	cppcheck $^;

format: ${SOURCE} ${TEST_SOURCE} ${HEADER_SOURCE}
	cp .././materials/linters/.clang-format .
	clang-format -i -style=google $^;
	rm .clang-format

clean: 
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./cov-report
	-rm -rf ./report/ && rm -rf test.dSYM
	-rm -rf s21_test
