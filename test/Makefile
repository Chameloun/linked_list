all: unit_test.o

unit_test.o:
	gcc -Werror -Wall -Wextra -pedantic -fsanitize=address unit_test.c ../linked_list.c ../lib/unity.c -o unit_test.o

test: unit_test.o
	./unit_test.o
	make clean

lint:
	cppcheck --enable=all --output-file=lint_report -I.. -I../lib --suppress=missingIncludeSystem --suppress=unusedFunction ../linked_list.c

coverage:
	gcc -Werror -Wall -Wextra -pedantic -fsanitize=address --coverage unit_test.c ../linked_list.c ../lib/unity.c -o unit_test.o

run_coverage: coverage
	./unit_test.o

coverage_report:
	make run_coverage

	lcov -c -d . -o coverage.info

	lcov -r coverage.info '*/unity.c' -o coverage_filtered.info

	genhtml coverage_filtered.info --output-directory coverage_report

docs:
	doxygen

clean:
	rm -rf *.o lint_report *.gcno *.gcda *.info coverage_report