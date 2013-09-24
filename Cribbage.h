#ifndef CRIBBAGE_H
#define CRIBBAGE_H

#include <cstring>
#include <cmath>
using namespace std;

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
using namespace boost::random;

#include "Cards.h"

class Cribbage : public Cards
{
private:
	int  numHumans;
	int  numAI;
	int  numFifteens;
	int  calcFlush(vector<card> hand, bool crib);
	int  calcRuns(vector<card> hand);	
	int  calcPairs(vector<card> hand);
	int  calcRightJack(vector<card> hand, card cut);
	int  calcFifteen(vector<card> tail);
	void subSetSum(vector<card> hand, int target, vector<card> partial);
	void printCardVec(vector<card> vec);

public:
	Cribbage(int numHumans, int numAI);
	bool verbose; //Change to "bool verbose = false;" if compiling w/ a c++11 compiler
	card cutDeck(); //Choose and remove the cut card from the deck
    int  calcScore(vector<card> hand, card cut, bool crib);
	virtual void deal(vector<card> &hand1, vector<card> &hand2); //Deal 6 cards to 2 hands
	virtual void deal(vector<card> &hand1, vector<card> &hand2, vector<card> &hand3); //Deal 5 cards to 3 hands
	using Cards::deal;
};
#endif
