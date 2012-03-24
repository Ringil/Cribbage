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
	/*
	 * This is now going to be a lazy solution where you check if a card
	 * is in the set and if so move the iterator to the next card to be dealt
	*/
    vector<card>::iterator it = deck.end()-1; //Top of the deck

    while(this->numCardsLeft() > 0)
    {
        if(!(this->isPlayed(*it)))
        {
            hand.push_back(*it); //Deal the card
            playedCards.insert(*it); //Put the card in the set of cards that are already played
            break;
        }
        else
            it--; //Move on to next card in the deck
    }
}

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
    return 52-playedCards.size();
}
