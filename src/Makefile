GCC = gcc
LDFLAGS = -c
SOURCE := $(shell find ./source  -iname "*.c" )
TEST_SOURCE := $(shell find ./tests  -iname "*.c" )
HEADER_SOURCE := $(shell find . -iname "*.h" )
ALL := $(shell find ./  -iname "*.c" )

ifeq ($(shell uname -s),Darwin)
	TEST_FLAGS  = -fprofile-arcs -ftest-coverage --coverage $^ -o $@ -lcheck -lpthread -lm
else
	TEST_FLAGS  = -fprofile-arcs -ftest-coverage --coverage $^ -o $@ -lcheck -lgcov -lpthread -lm -lsubunit 
endif

ERROR_FLAGS  =  -Wextra -Wall -Werror -Wuninitialized -Winit-self -Wmaybe-uninitialized -fsanitize=address

all: clean s21_matrix.a test

s21_matrix.a: ${SOURCE} clean
	$(GCC) $(LDFLAGS) $(SOURCE)
	ar rc $@  *.o
	ranlib $@

test: ${SOURCE} ${TEST_SOURCE}
	$(GCC) $(TEST_FLAGS) 
	./$@

gcov_report: test
	gcov ./*.c
	# rm -rf *test.gcda *test.gcno *est_main.gcda *est_main.gcno
	find ./ -type f -iname '*.gcda'
	lcov --directory ./ --capture --output-file postgresql.info
	mkdir cov-report
	genhtml -o ./cov-report/ postgresql.info

leaks: test
	leaks -atExit -- ./test

cppcheck: $(ALL)
	cppcheck $^;

format: ${ALL} ${HEADER_SOURCE}
	cp .././materials/linters/.clang-format .
	clang-format -i -style=google $^;
	rm .clang-format

valgrind: test
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --leak-check=yes --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind_log.txt ./test
	valgrind --leak-check=full --leak-resolution=high ./test


clean: 
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./cov-report
	-rm -rf ./report/ && rm -rf test.dSYM
	-rm -rf s21_test
