all: Cribbage

Cribbage: game.o Cribbage.o Cards.o
	g++ game.o Cribbage.o Cards.o -o Cribbage

game.o: game.cpp
	g++ -c game.cpp

Cribbage.o: Cribbage.cpp
	g++ -c Cribbage.cpp

Cards.o: Cards.cpp
	g++ -c Cards.cpp

clean:
	rm -rf Cribbage

