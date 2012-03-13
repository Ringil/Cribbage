#include "Cards.h"

int main()
{
    Cards newDeck;

    cout<<"\nPrinting shuffled deck:\n";
    newDeck.shuffle();
    newDeck.shuffle();
    newDeck.printDeck();

    //newDeck.~Cards();
}