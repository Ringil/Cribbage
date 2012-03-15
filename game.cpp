#include "Cards.h"

int main()
{
    Cards newDeck;
    newDeck.init();

    cout<<"\nPrinting shuffled deck:\n";
    newDeck.shuffle();
    newDeck.shuffle();
    newDeck.printDeck();

    //newDeck.~Cards();
}
