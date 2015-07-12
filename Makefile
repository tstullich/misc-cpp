CC=clang++
FLAGS=-std=c++14 -O3
DEBUG_FLAGS=-std=c++14 -O3 -g

all:
	$(CC) $(FLAGS) main.cc -o run
	cp run ./bin

debug:
	$(CC) $(DEBUG_FLAGS) main.cc -o run

clean:
	rm -rf ./bin/*
