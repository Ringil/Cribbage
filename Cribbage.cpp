#include "Cribbage.h"
/*
 * -Randomly choose first player and make sure turns are taken clockwise
 * -Deal cards based on that number
 * -Everyone throws into the kitty and a card from the deck is put in the kitty
 * -Play
 * -Reveal hand
 * -Allow for human players to calculate their own score and AI can correct
 */

Cribbage::Cribbage(int numHumans, int numAI)
{
    this->numHumans = numHumans;
    this->numAI = numAI;
}

int Cribbage::calcScore(vector<card> hand, card cut)
{
    int total = 0;

    total = calcRightJack(hand, cut);

    hand.push_back(cut); //Combine the cut with your hand
    sort(hand.begin(), hand.end()); //Sort cards by val

    //Calculate rest of the points
    total += calc15(hand) + calcRuns(hand) + calcPairs(hand);

    return total;
}

int Cribbage::calc15(vector<card> hand)
{
    /*
    TODO: This is a case of the subset problem which is NP-Complete.
    Going to have to brute force this and probably use Boost threads
    to get good performance.

    IDEA: Loop through hand and compare each card to each other card and subtract the summed
    values from 15 then check the next one

    diff ways to make 15: {(7,8), (6,9), (5,10), (5,5,5), (4,5,6), (4,4,7), (4,3,8), (3,5,7), (2,5,8), (1,5,9), 
                          (1,4,10)}
    */
    vector<card>::iterator it;

    return 0;
}

int Cribbage::calcRuns(vector<card> hand)
{
    int total = 0;
    stack<card> runs;
    vector<card> duplicate;
    vector<card>::iterator it;

    //Iterate over the hand and track potential runs
    for(it = hand.begin(); it != hand.end(); it++)
    {
        if(runs.empty() || it->val == runs.top().val + 1)
            runs.push(*it);
        else if(it->val == runs.top().val)
            duplicate.push_back(*it);

        /* Check if you are on the last card of the hand or if the next card will break the run*/
        if(it == hand.end() - 1 || (it + 1)->val > runs.top().val + 1)
        {
            if(runs.size() >= 3) //Check if you have the minimum # of cards to make a run
            {
                total += runs.size(); //Number of points for the run

                if(!duplicate.empty())
                    total *= duplicate.size(); //Number of runs

                /*If you have a run you don't need to check anymore
                cards because there can't be another run*/
                return total; 
            }
            duplicate.clear(); //Clear the duplicates
            eraseStack(runs); //Erase the runs stack
        }
    }
    return total;
}

int Cribbage::calcPairs(vector<card> hand)
{
    stack<card> sameCards;
    vector<card>::iterator it;
    int total = 0;

    for(it = hand.begin(); it != hand.end(); it++)
    {
        //If nothing in the stack or if the card is the same as what is on the stack, push the card
        if(sameCards.empty() || it->val == sameCards.top().val)
        {
            sameCards.push(*it);
        }

        //This makes sure you calculate all the points even if the last two cards are the same.
        if(it == hand.end() - 1 || (it + 1)->val != sameCards.top().val)
        {
            //Calculate amount of points from the amount of same cards ((n^2)-n)
            total += (int) (pow((double) sameCards.size(), 2) - sameCards.size());

            //Remove all cards from the stack
            eraseStack(sameCards);
        }
    }
    return total;
}

void Cribbage::eraseStack(stack<card> &cards)
{
    /*
     * A utility function for erasing a stack of card structs
     */
    while(!cards.empty())
    {
        cards.pop();
    }
}

int Cribbage::calcRightJack(vector<card> hand, card cut)
{
    /*
     * TODO: Take care of all Jack situations currently only takes care of
     * if you have a jack that is the same suit as the cut card
     */
    vector<card>::iterator it;

    //Check if you have a jack in your hand and if the cut card is the same suit
    for(it = hand.begin(); it != hand.end(); it++)
    {
        if(it->val == 11 && strcmp((const char*) it->suit, (const char *) cut.suit) == 0)
            return 1;
    }
    return 0;
}

void Cribbage::deal(vector<card> &hand1, vector<card> &hand2)
{
    vector<card>::iterator it = deck.end() - 1; //Top of the deck

    if(this->numCardsLeft() >= 12)
    {
        //Deal 6 cards to each hand
        for(int i = 0; i < 6; i++)
        {
            hand1.push_back(*it); //Deal the card
            deck.pop_back();

            hand2.push_back(*it); //Deal the card
            deck.pop_back();
        }
    }
    else
        cout << endl << "No more cards left in the deck!" << endl;
}

void Cribbage::deal(vector<card> &hand1, vector<card> &hand2, vector<card> &hand3)
{
    vector<card>::iterator it = deck.end() - 1; //Top of the deck

    if(this->numCardsLeft() >= 15)
    {
        //Deal 5 cards to each player
        for(int i = 0; i < 5; i++)
        {
            hand1.push_back(*it); //Deal the card
            deck.pop_back();

            hand2.push_back(*it); //Deal the card
            deck.pop_back();

            hand3.push_back(*it); //Deal the card
            deck.pop_back();
        }
    }
    else
        cout << endl << "No more cards left in the deck!" << endl;
}

card Cribbage::cutDeck()
{
    int max = this->numCardsLeft() - 1; //-1 because boost::uid uses a closed range
    int index = 0;
    card cut;
    mt19937 gen;
    uniform_int_distribution<> dist(0, max); //A closed range

    index = dist(gen);
    cut.suit = deck.at(index).suit;
    cut.val = deck.at(index).val;
    deck.erase(deck.begin() + index - 1);

    return cut;
}
