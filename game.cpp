#include "Cribbage.h"

int main()
{
    Cribbage deck;
    vector<card> hand;

    deck.init();
    deck.shuffle();
    deck.printDeck();
    deck.deal(hand);
    cout<<endl<<deck.numCardsLeft()<<endl;
    deck.deal(hand);
    cout<<endl<<deck.numCardsLeft()<<endl;

    for(vector<card>::iterator it = hand.begin(); it!=hand.end(); it++)
    {
        cout<<endl<<it->val<<it->suit<<endl;
    }
}
