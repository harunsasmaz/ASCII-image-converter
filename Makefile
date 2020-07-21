CPP=g++
CCFLAGS=-Wall -std=c++14

BIN=./ascii
OBJ=ascii
MAIN=main.cpp
HEADER=ascii.h
LIB=ascii.cpp

compile:
	$(CPP) $(CCFLAGS) -o $(OBJ) $(MAIN) $(LIB)
	gcc -o bonus/donut bonus/donut.c

run_bonus:
	bonus/donut

run_socrates:
	$(BIN) in/socrates.bmp 1 2 > out/socrates.txt
valgrind_socrates:
	valgrind $(BIN) in/socrates.bmp 1 2 > out/socrates.txt

run_woman:
	$(BIN) in/woman.bmp 4 4 > out/woman.txt
valgrind_woman:
	valgrind $(BIN) in/woman.bmp 4 4 > out/woman.txt

run_js:
	$(BIN) in/js.bmp 4 4 > out/js.txt
valgrind_js:
	valgrind $(BIN) in/js.bmp 4 4 > out/js.txt

clean:
	rm -f ascii out/*.txt bonus/donut