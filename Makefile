CC=clang++
FLAGS=-std=c++14 -O3

all:
	$(CC) $(FLAGS) main.cc -o run
	cp run ./bin

debug:
	$(CC) $(FLAGS) -g main.cc -o run

clean:
	rm -rf ./bin/*
