#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
#include <cstdlib>
using namespace std;

//Structure of a basic card
struct card
{
    int val;
    char suit;

    //Overwrite the < operator so cards can be compared by their value
    bool operator<(const card &a) const
    {
        return((this->val < a.val) ? true:false);
    }
};

class Cards
{
protected:    
    int  numCardsLeft(); //Number of cards left in the deck
    vector<card> deck;
public:
    Cards();
    void shuffle(); //Shuffle the deck (Currently does not shuffle very well)
    void printDeck(); //TODO: REMOVE THIS AFTER TESTING IS DONE
    virtual void deal(vector<card> &hand); //Deal a single card
    bool subsetSum(vector<int> set, int target); //Determine if a subset of the cards add to a target val
};
#endif
