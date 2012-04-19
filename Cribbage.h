#ifndef CRIBBAGE_H
#define CRIBBAGE_H

#include <cstdio>
#include <cstring>
using namespace std;

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
using namespace boost::random;

#include "Cards.h"

class Cribbage : public Cards
{
private:
	int numHumans;
	int numAI;
	int calc15(vector<card> hand, card cut);
	int calcRuns(vector<card> hand, card cut);
	int calcPairs(vector<card> hand, card cut);
	int calcRightJack(vector<card> hand, card cut);

public:
	Cribbage(int numHumans, int numAI);
    int calcScore(vector<card> hand, card cut);
	void deal(vector<card> &hand1, vector<card> &hand2); //Deal 6 cards to 2 hands
	void deal(vector<card> &hand1, vector<card> &hand2, vector<card> &hand3); //Deal 5 cards to 3 hands
    card cutDeck(); //Choose and remove the cut card from the deck
};
#endif
