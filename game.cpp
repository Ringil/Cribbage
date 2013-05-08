#include <iostream>
using namespace std;

#include "Cribbage.h"

void printHand(vector<card> hand);

int main()
{
    int numHumans = 2, numAI = 0;

    //TEST CODE
    Cribbage game(numHumans, numAI);
    vector<card> tHand;
    card test;
    bool crib = false;
    bool verbose = true;

    //Test hand
    test.suit = 'H';
    test.val = 11; //Jack, will be converted to a 10 when calc'ing pts
    tHand.push_back(test);
    test.suit = 'C';
    test.val = 5;
    tHand.push_back(test);
    test.suit = 'D';
    test.val = 3;
    tHand.push_back(test);
    test.suit = 'H';
    test.val = 3;
    tHand.push_back(test);
    
    //Cut card
    test.suit = 'H';
    test.val = 2;

    cout<<"Test Hand:\n";
    printHand(tHand);
    cout<<"Test cut card:\n"<<test.val<<test.suit<<endl;
    cout<<"Total points for hand: "<<game.calcScore(tHand, test, crib, verbose)<<endl;
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
