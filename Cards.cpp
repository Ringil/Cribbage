#include "Cards.h"

Cards::Cards()
{
}


Cards::~Cards()
{
}

void Cards::init()
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
        playedCards.insert(*it); //Put the card in the set of cards that are already played
        it--; //Move the iterator to the next card in the deck because you are about to pop the vector
        deck.pop_back();
    }
    else
        cout<<endl<<"No more cards left in the deck!"<<endl; //blah
}

//This may become useless
bool Cards::isPlayed(card checkCard)
{
    set<card>::iterator it;

    it = playedCards.find(checkCard);
    if(it != playedCards.end())
        return true;
    return false;
}

int Cards::numCardsLeft()
{
    return deck.size();
}
