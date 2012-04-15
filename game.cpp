#include <iostream>
#include "Cribbage.h"
using namespace std;

bool yesNo();

int main()
{
    int numHumans, numAI;

//    do
//    {
//        //TODO: Find old menu code
//        cout << "blah" << endl << endl;
//    } while(yesNo());

    //OLD TEST CODE
    Cribbage game(1,1);
    vector<card> hand;

    game.shuffle();
    game.printDeck();
    cout << endl << game.numCardsLeft() << endl;

//    for(vector<card>::iterator it = hand.begin(); it != hand.end(); it++)
//    {
//        cout << endl << it->val << it->suit << endl;
//    }
}

bool yesNo()
{
    //TODO:Make this work so just pressing enter acts as yes
    char response;
    cout << "Would you like to play again? [Y/n]: ";
    cin >> response;
    switch(response)
    {
        case 'Y':
        case 'y':
            return true;
        default:
            return false;
    }
}
