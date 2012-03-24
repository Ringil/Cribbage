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

    /*WARNING: this hasn't been tested yet and may not work 
    in windows (this is only a guess from previous experience).
    May turn out not to be necessary if the set is not used*/
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
    set<card> playedCards; //THIS MAY BE UNNECESSARY
public:
    Cards(); //Default Constructor 
    ~Cards(); //Empty the deck
    void init(); //Unshuffled deck of cards
    void shuffle(); //Shuffle the deck
    void printDeck(); //TO BE REMOVED    
    bool isPlayed(card checkCard); //TO BE MOVED
    int numCardsLeft(); //Number of cards left in the deck
    virtual void deal(vector<card> &hand); //Deal a single card
};
#endif