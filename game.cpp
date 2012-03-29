#include <iostream>
#include "Cribbage.h"
using namespace std;

bool yesNo();

int main()
{
    int numHumans, numAI;

    do{
        //TODO: Find old menu code
        cout<<"blah"<<endl<<endl;
    }while(yesNo());

    /*OLD TEST CODE
     Cribbage deck;
     vector<card> hand;

     deck.shuffle();
     deck.printDeck();
     deck.deal(hand);
     cout<<endl<<deck.numCardsLeft()<<endl;

     for(vector<card>::iterator it = hand.begin(); it!=hand.end(); it++)
     {
     cout<<endl<<it->val<<it->suit<<endl;
     }*/
}

bool yesNo()
{
    //TODO:Make this work so just pressing enter acts as yes
    char response;
    cout<<"Would you like to play again? [Y/n]: ";
    cin>>response;
    switch(response)
    {
        case 'Y':
        case 'y':
            return true;
        default:
            return false;
    }
}
