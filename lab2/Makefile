all: build clean
build:
	gcc -c main.c -o main.o

list:
	gcc -c stackl/stack.c -o stack.o
	gcc main.o stack.o -o bin

vector:
	gcc -c stackv/stack.c -o stack.o
	gcc main.o stack.o -o bin

clean:
	rm -rf *.o
	rm -rf bin
