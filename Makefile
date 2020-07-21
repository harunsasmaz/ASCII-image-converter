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

run_all: run_socrates run_woman run_js run_cameraman run_deer run_clown \
run_greenland run_hill run_man run_pepper run_snail run_tank run_truck  \
run_womanface run_zelda run_airplane run_boats run_baboon run_barbara

run_socrates:
	$(BIN) in/socrates.bmp 2 2 > out/socrates.txt

run_woman:
	$(BIN) in/woman.bmp 4 4 > out/woman.txt

run_barbara:
	$(BIN) in/barbara.bmp 2 2 > out/barbara.txt

run_js:
	$(BIN) in/js.bmp 4 4 > out/js.txt

run_cameraman:
	$(BIN) in/cameraman.bmp 2 2 > out/cameraman.txt

run_clown:
	$(BIN) in/clown.bmp 2 2 > out/clown.txt

run_snail:
	$(BIN) in/snail.bmp 2 2 > out/snail.txt

run_greenland:
	$(BIN) in/greenland.bmp 2 2 > out/greenland.txt

run_deer:
	$(BIN) in/deer.bmp 2 2 > out/deer.txt

run_airplane:
	$(BIN) in/airplane.bmp 2 2 > out/airplane.txt

run_baboon:
	$(BIN) in/baboon.bmp 4 4 > out/baboon.txt

run_boats:
	$(BIN) in/boats.bmp 4 4 > out/boats.txt

run_hill:
	$(BIN) in/hill.bmp 2 2 > out/hill.txt

run_man:
	$(BIN) in/man.bmp 2 2 > out/man.txt

run_pepper:
	$(BIN) in/pepper.bmp 2 2 > out/pepper.txt

run_tank:
	$(BIN) in/tank.bmp 2 2 > out/tank.txt

run_truck:
	$(BIN) in/truck.bmp 2 2 > out/truck.txt

run_womanface:
	$(BIN) in/womanface.bmp 2 2 > out/womanface.txt

run_zelda:
	$(BIN) in/zelda.bmp 2 2 > out/zelda.txt

clean:
	rm -f ascii out/*.txt bonus/donut