#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
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

    //Overwrite the < operator so the set can compare keys
    bool operator<(const card &a) const
    {
        return((this->val < a.val) ? true:false);
    }
};

class Cards
{
protected:    
    vector<card> deck;
public:
    Cards(); //Default Constructor 
    void shuffle(); //Shuffle the deck (Currently does not shuffle very well)
    void printDeck(); //TODO: TO BE REMOVED
    int numCardsLeft(); //Number of cards left in the deck
    void deal(vector<card> &hand); //Deal a single card
};
#endif
