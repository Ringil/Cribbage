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

class Cards
{
protected:
    struct card
    {
        int val;
        char suit; 
        bool operator<(const card &a) const
        {
           return((this->val < a.val) ? true:false);
        }
    };
    
    vector<card> deck;
    set<card> playedCards;
public:
    Cards(); //Unshuffled deck of cards
    ~Cards();
    void init();
    void shuffle();
    void printDeck();
    bool isPlayed(card checkCard);
    int numCardsLeft();
};
#endif
