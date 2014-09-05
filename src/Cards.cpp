#include "Cards.h"

void Cards::genDeck()
{
    //Generate a deck of cards
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
    srand(unsigned(time(0)));
    random_shuffle(deck.begin(), deck.end());
}

void Cards::printDeck()
{
    vector<card>::iterator vit;
    for (vit = deck.begin(); vit != deck.end(); ++vit)
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

/*
Deal a single card
*/
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

card Cards::cutDeck()
{
    int max = this->numCardsLeft() - 1; //-1 because boost::uid uses a closed range
    int index = 0;
    card cut;
    mt19937 gen(int(time(0))); //I think this has to be unsigned
    boost::random::uniform_int_distribution<> dist(0, max); //A closed range

    index = dist(gen); //Choose the cut card index
    cut.suit = deck.at(index).suit;
    cut.val = deck.at(index).val;
    deck.erase(deck.begin() + index - 1); //Remove the cut card from the deck

    return cut;
}

void Cards::eraseStack(stack<card> &cards)
{
    /*
     * A utility function for erasing a stack of card structs
     */
    while(!cards.empty())
    {
        cards.pop();
    }
}
