#include "Cards.h"

Cards::Cards()
{
}

/*
Not sure if I should just make a seperate function to do this since I'm not
releasing any memory.
*/
Cards::~Cards()
{
    vector<card>::iterator it;

    for(it = deck.begin(); it != deck.end(); it++)
    {
        deck.pop_back();
    }
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

void Cards::dealACard(vector<card> &hand)
{
	/*
	 * TODO: this is now going to be a lazy solution where you check if a card
	 * is in the set and if so move the iterator to the next card to be dealt
	*/
    vector<card>::iterator it = deck.end()-1; //Top of the deck
    hand.push_back(*it); //Deal the card
    playedCards.insert(*it); //Put the card in the set of cards that are already played

    //PROBLEM HERE: Looks like it tries to do pop_back after my couts in game.cpp causing a
    //problem that says vector iterator not incrementable
    //deck.pop_back(); //Remove the card from the deck
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
    return deck.size();
}
