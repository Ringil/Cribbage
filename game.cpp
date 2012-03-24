#include "Cribbage.h"

int main()
{
    Cribbage deck;
    vector<card> hand;

    deck.init();
    deck.shuffle();
    deck.printDeck();
    cout<<"Number of cards left in the deck: "<<deck.numCardsLeft()<<endl;
    deck.deal(hand);
    deck.deal(hand);
    cout<<"Number of cards left after deal() called: "<<deck.numCardsLeft()<<endl;

    for(vector<card>::iterator it = hand.begin(); it!=hand.end(); it++)
    {
        cout<<endl<<endl<<it->val<<it->suit<<endl;
    }
    cout<<"lakjsdklajsdlkj"<<endl;
}
