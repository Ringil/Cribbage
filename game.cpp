#include <iostream>
using namespace std;

#include "Cribbage.h"

bool yesNo();
void printHand(vector<card> hand);

int main()
{
    //int numHumans, numAI;

    //TEST CODE
    Cribbage game(1, 1);
    vector<card> hand1, hand2, hand3, tHand;
    card test;

    //Test hand, change this so its just user input for later
    test.suit = 'H';
    test.val = 1;
    tHand.push_back(test);
    test.val = 4;
    tHand.push_back(test);
    test.val = 5;
    tHand.push_back(test);
    test.val = 5;
    tHand.push_back(test);
    test.suit = 'C';
    test.val = 5;
    tHand.push_back(test);


    game.shuffle();
    //game.printDeck();
    game.deal(hand1,hand2,hand3);
    sort(hand1.begin(), hand1.end());
    sort(hand2.begin(), hand2.end());
    sort(hand3.begin(), hand3.end());
    
    cout<<"Hand1:\n";
    printHand(hand1);
    cout<<"Points for flush: "<< game.calcFlush(hand1, false)<<endl;
    cout<<"Points for pairs: "<< game.calcPairs(hand1) << endl;
    cout<<"Points for runs: "<< game.calcRuns(hand1) << endl<<endl;

    cout<<"Hand2:\n";
    printHand(hand2);
    cout<<"Points for flush: "<< game.calcFlush(hand2, false)<<endl;
    cout<<"Points for pairs: "<< game.calcPairs(hand2) << endl;
    cout<<"Points for runs: "<< game.calcRuns(hand2) << endl<<endl;

    cout<<"Hand3:\n";
    printHand(hand3);
    cout<<"Points for flush: "<< game.calcFlush(hand3, false)<<endl;
    cout<<"Points for pairs: "<< game.calcPairs(hand3) << endl;
    cout<<"Points for runs: "<< game.calcRuns(hand3) << endl<<endl;

    cout<<"Test Hand:\n";
    printHand(tHand);
    cout<<"Points for flush: "<< game.calcFlush(tHand, false)<<endl;
    cout<<"Points for pairs: "<< game.calcPairs(tHand) << endl;
    cout<<"Points for runs: "<< game.calcRuns(tHand) << endl<<endl;


    //cout << endl << game.numCardsLeft() << endl;
}

bool yesNo()
{
    //TODO:Make this work so just pressing enter acts as yes
    char response;
    cout << "Would you like to play again? [Y/n]: ";
    cin >> response;
    switch(response)
    {
        case 'n':
        case 'N':
            return false;
        case 'Y':
        case 'y':
        default:
            return true;
    }
}

void printHand(vector<card> hand)
{
   for(vector<card>::iterator it = hand.begin(); it != hand.end(); it++)
   {
        if(it->val == 11)
            cout<<"J";
        else if(it->val == 12)
            cout<<"Q";
        else if(it->val == 13)
            cout<<"K";
        else if(it->val == 1)
            cout<<"A";
        else
            cout<<it->val;
        cout<<it->suit<<endl;
   }
}
