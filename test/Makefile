all: unit_test.o

unit_test.o:
	gcc -Werror -Wall -Wextra -pedantic -fsanitize=address unit_test.c ../linked_list.c ../lib/unity.c -o unit_test.o

test: unit_test.o
	./unit_test.o
	make clean

clean:
	rm *.o