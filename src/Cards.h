#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stack>
// #include <random>       // std::default_random_engine
// #include <chrono> 
// #include <ctime>
// #include <cstdlib>
using namespace std;

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/variate_generator.hpp>
using namespace boost::random;

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
    void eraseStack(stack<card> &cards);
    vector<card> deck;
public:
    card cutDeck(); //Choose and remove the cut card from the deck
    void genDeck();
    void shuffle(); //Shuffle the deck (Currently does not shuffle very well)
    void printDeck(); //TODO: REMOVE THIS AFTER TESTING IS DONE
    virtual void deal(vector<card> &hand); //Deal a single card
};
#endif
