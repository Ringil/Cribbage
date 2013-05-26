#using -std=c++11 causes compile probs with boost
CC = g++ -ggdb

all: Cribbage

Cribbage: game.o Cribbage.o Cards.o
	$(CC) -o $@ $^

game.o: game.cpp
	$(CC) -c $<

Cribbage.o: Cribbage.cpp
	$(CC) -c $<

Cards.o: Cards.cpp
	$(CC) -c $<

.PHONY: clean

clean:
	rm *.o Cribbage