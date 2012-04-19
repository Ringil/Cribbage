#ifndef CRIBBAGE_H
#define CRIBBAGE_H

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
using namespace boost::random;

#include "Cards.h"

class Cribbage : public Cards
{
private:
	int numHumans;
	int numAI;
	int calc15(vector<card> hand);
	int calcRuns(vector<card> hand);
	int calcPairs(vector<card> hand);
public:
	Cribbage(int numHumans, int numAI);
    int calcScore(vector<card> hand);
	void deal(vector<card> &hand1, vector<card> &hand2); //Deal 6 cards to 2 hands
	void deal(vector<card> &hand1, vector<card> &hand2, vector<card> &hand3); //Deal 5 cards to 3 hands
    card cutDeck(); //Choose and remove the cut card from the deck
};
#endif
