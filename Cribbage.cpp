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
    if(numHumans + numAI >= 1)
    {
        this->numHumans = numHumans;
        this->numAI = numAI;
    }
    else
    {
        cout << "Not enough players";
        exit(0); //TODO: Fix this
    }
}

void Cribbage::deal(vector<card> &hand1, vector<card> &hand2)
{
    //TODO: POSSIBLY REMOVE PLAYEDCARDS
    vector<card>::iterator it = deck.end() - 1; //Top of the deck

    if(!deck.empty())
    {
        //Deal 6 cards to each player
        for(int i = 0; i < 5; i++)
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

    if(!deck.empty())
    {
        //Deal 6 cards to each player
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
