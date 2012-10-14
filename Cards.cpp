#include "Cards.h"

Cards::Cards()
{
    card cardz;
    for(int i = 1; i<=13;  i++)
    {
        cardz.val = i;
        
        cardz.suit = 'C';
        deck.push_back(cardz);

        cardz.suit = 'H';
        deck.push_back(cardz);

        cardz.suit = 'S';
        deck.push_back(cardz);

        cardz.suit = 'D';
        deck.push_back(cardz);
    }
}

void Cards::shuffle()
{
    //TODO: Redo this later using boost to randomize the cards
    srand(unsigned(time(NULL)));
    random_shuffle(deck.begin(), deck.end());
}

void Cards::printDeck()
{
    vector<card>::iterator vit;
    for (vit=deck.begin(); vit!=deck.end(); ++vit)
    {
        if(vit->val == 11)
            cout<<"J";
        else if(vit->val == 12)
            cout<<"Q";
        else if(vit->val == 13)
            cout<<"K";
        else if(vit->val == 1)
            cout<<"A";
        else
            cout<<vit->val;
        cout<<vit->suit<<endl;
    }
}

void Cards::deal(vector<card> &hand)
{    
    vector<card>::iterator it = deck.end()-1; //Top of the deck

    if(!deck.empty())
    {
        hand.push_back(*it); //Deal the card
        deck.pop_back(); //Remove the card from the deck
    }
    else
        cout<<endl<<"No more cards left in the deck!"<<endl;
}

int Cards::numCardsLeft()
{
    return deck.size();
}

/*
Determines whether or not a subset of the int vector sums to the given target value.
WORK NEEDS TO BE DONE TO MAKE THIS RETURN THE ACTUAL SUBSET
*/
bool Cards::subsetSum(vector<int> set, int target)
{
    //Only a 1 element list so just check if its the target val
    if(set.size()==1)
        return (set.at(0)==target);

    //Create a subset of all vals except the first one
    vector<int> subSet (set.begin()+1,set.end());

    return (subsetSum(subSet, target) || subsetSum(subSet, target-set.at(0)));
}