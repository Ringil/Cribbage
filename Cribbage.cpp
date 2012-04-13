#include "Cribbage.h"
/*
 * -Need number of human/AI players
 * -Randomly choose first player and make sure turns are taken clockwise
 * -Deal cards based on that number
 * -Everyone throws into the kitty and possibly a card from the deck is put in the kitty
 * -Cut the deck
 * -Play
 * -Reveal hand
 * -Calculate own hand and kitty
 * -Allow for human players to calculate their own score and AI can correct
 */

Cribbage::Cribbage(int numHumans, int numAI)
{
    //TODO: Find out if I need to redo the default constructor for this to be the same as cards.cpp
    if(numHumans + numAI >= 2 && numHumans + numAI <= 3)
    {
        this->numHumans = numHumans;
        this->numAI = numAI;
    }
    else
    {
        cout << "Incorrect number of players";
        exit(0); //TODO: Fix this
    }
}

void Cribbage::deal(vector<card> &hand1, vector<card> &hand2)
{
    //TODO: POSSIBLY REMOVE PLAYEDCARDS
    vector<card>::iterator it = deck.end() - 1; //Top of the deck

    if(this->numCardsLeft() >= 12)
    {
        //Deal 6 cards to each hand
        for(int i = 0; i <= 5; i++)
        {
            hand1.push_back(*it); //Deal the card
            playedCards.insert(*it); //Put the card in the set of cards that are already played
            deck.pop_back();

            hand2.push_back(*it); //Deal the card
            playedCards.insert(*it); //Put the card in the set of cards that are already played
            deck.pop_back();
        }
    }
    else
        cout << endl << "No more cards left in the deck!" << endl;
}

void Cribbage::deal(vector<card> &hand1, vector<card> &hand2, vector<card> &hand3)
{
    //TODO: POSSIBLY REMOVE PLAYEDCARDS
    vector<card>::iterator it = deck.end() - 1; //Top of the deck

    if(this->numCardsLeft() >= 15)
    {
        //Deal 5 cards to each player
        for(int i = 0; i < 5; i++)
        {
            hand1.push_back(*it); //Deal the card
            playedCards.insert(*it); //Put the card in the set of cards that are already played
            deck.pop_back();

            hand2.push_back(*it); //Deal the card
            playedCards.insert(*it); //Put the card in the set of cards that are already played
            deck.pop_back();

            hand3.push_back(*it); //Deal the card
            playedCards.insert(*it); //Put the card in the set of cards that are already played
            deck.pop_back();
        }
    }
    else
        cout << endl << "No more cards left in the deck!" << endl;
}

card Cribbage::cutDeck()
{
    int max = this->numCardsLeft()-1;
    int index = 0;
    card cut;

    mt19937 gen;
    uniform_int_distribution<> dist(0, max); //A closed range

    index = dist(gen);
    cut.suit = deck.at(index).suit;
    cut.val = deck.at(index).val;

    deck.erase(deck.begin()+index-1);
    return cut;
}
