all: main.o

main.o:
	gcc -Werror -Wall -Wextra -pedantic -fsanitize=address main.c linked_list.c -o main.o

run: main.o
	./main.o

clean:
	rm *.o