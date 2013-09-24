#using -std=c++11 causes compile probs with boost
CC = g++ 
FLAGS = -Wall -ggdb

all: Cribbage

Cribbage: game.o Cribbage.o Cards.o
	$(CC) -o $@ $^

game.o: game.cpp
	$(CC) $(FLAGS) -c $<

Cribbage.o: Cribbage.cpp
	$(CC) $(FLAGS) -c $<

Cards.o: Cards.cpp
	$(CC) $(FLAGS) -c $<

.PHONY: clean

clean:
	rm *.o Cribbage