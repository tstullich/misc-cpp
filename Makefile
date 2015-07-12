CC=clang++
FLAGS=-std=c++14 -O3

all:
	$(CC) $(FLAGS) -o run
	cp run ./bin

debug:
	$(CC) $(FLAGS) -g -o run

clean:
	rm -rf ./bin/*
