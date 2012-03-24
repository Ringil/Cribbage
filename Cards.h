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
    set<card> playedCards;
    int numCardsLeft(); //Number of cards left in the deck
    bool isPlayed(card checkCard);    
public:
    Cards(); //Default Constructor 
    ~Cards(); //Empty the deck
    void init(); //Unshuffled deck of cards
    void shuffle(); //Shuffle the deck    
    void printDeck(); //TO BE REMOVED
    virtual void deal(vector<card> &hand); //Deal a single card
};
#endif
