#include "Cribbage.h"
/*
 * -Randomly choose first player and make sure turns are taken clockwise
 * -Deal cards based on that number
 * -Everyone throws into the kitty and a card from the deck is put in the kitty
 * -Play
 * -Reveal hand
 * -Calculate own hand and kitty
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
    return 0;
}

int Cribbage::calcRuns(vector<card> hand)
{
    //FIXME MAY HAVE A PROBLEM HERE With the sets
    int counter = 0;
    multiset<card> fullHand;
    set<card> uniqueHand;
    vector<card> diff;

    //MIGHT BE UNNECESSARY SINCE SETS ONLY TAKE UNIQUE VALUES ANYWAY
    //Make a copy of only the unique values from the original hand
    unique_copy(hand.begin(), hand.end(), uniqueHand.begin(),comparisonFunc);

    //Copy the full hand into a set so the set difference can be used
    copy(hand.begin(), hand.end(), fullHand.begin());

    unique(hand.begin(), hand.end());

    //Find the difference between the full hand and unique hand
    set_symmetric_difference(fullHand.begin(), fullHand.end(), uniqueHand.begin(), uniqueHand.end(), diff.begin());

    /*
     * Loop through unique hand and see if there is a run.
     * If there is a run then check if diff contains any of the same values
     * as the ones in the run.
     * If so add appropriate amount of points
     */

    return counter;
}

bool Cribbage::comparisonFunc(card i, card j)
{
    //FIXME: MAY HAVE A PROBLEM HERE BUT SHOULD WORK
    return i.val == j.val;
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
     * A utility function for erasing the stack
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
