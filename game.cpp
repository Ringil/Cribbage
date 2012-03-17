#include "Cribbage.h"

int main()
{
    Cribbage deck;
    vector<card> hand;

    deck.init();
    deck.shuffle();
    deck.printDeck();
    deck.dealACard(hand);

    cout<<endl<<endl<<hand.at(0).val<<hand.at(0).suit<<endl;
    cout<<"lakjsdklajsdlkj";
}
