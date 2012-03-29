#ifndef CRIBBAGE_H
#define CRIBBAGE_H

#include "Cards.h"

class Cribbage : public Cards
{
private:
	int numHumans;
	int numAI;
public:
	Cribbage(int numHumans, int numAI);
	void deal(vector<card> &hand1, vector<card> &hand2);
	void deal(vector<card> &hand1, vector<card> &hand2, vector<card> &hand3);
};
#endif
