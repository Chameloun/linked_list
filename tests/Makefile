all: test.o

test.o:
	gcc -Werror -Wall -Wextra -pedantic -fsanitize=address test.c ../linked_list.c ../lib/unity.c -o test.o

test: test.o
	./test.o
	make clean

clean:
	rm *.o