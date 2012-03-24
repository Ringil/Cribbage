#include "Cribbage.h"

int main()
{
    Cribbage deck;
    vector<card> hand;

    deck.init();
    deck.shuffle();
    deck.printDeck();
    deck.deal(hand);
    deck.deal(hand);

    for(vector<card>::iterator it = hand.begin(); it!=hand.end(); it++)
    {
        cout<<endl<<endl<<it->val<<it->suit<<endl;
    }
}
