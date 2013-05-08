#include <iostream>
using namespace std;

#include "Cribbage.h"

void printHand(vector<card> hand);

int main()
{
    int numHumans = 2, numAI = 0;

    //TEST CODE
    Cribbage game(numHumans, numAI);
    vector<card> tHand, hand1, hand2, hand3;
    card test;
    card cut;
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
    cut = game.cutDeck();

    cout<<"Test Hand:\n";
    printHand(tHand);
    cout<<"Test cut card:\n"<<cut.val<<cut.suit<<endl;
    cout<<"Total points for tHand: "<<game.calcScore(tHand, cut, crib, verbose)<<endl;

    game.shuffle();
    game.deal(hand1,hand2,hand3);
    printHand(hand1);
    cout<<"Test cut card:\n"<<cut.val<<cut.suit<<endl;
    cout<<"Total points for hand1: "<<game.calcScore(hand1, cut, crib, verbose)<<endl<<endl;
    
    printHand(hand2); 
    cout<<"Test cut card:\n"<<cut.val<<cut.suit<<endl;
    cout<<"Total points for hand2: "<<game.calcScore(hand2, cut, crib, verbose)<<endl<<endl;
    
    printHand(hand3); 
    cout<<"Test cut card:\n"<<cut.val<<cut.suit<<endl;   
    cout<<"Total points for hand3: "<<game.calcScore(hand3, cut, crib, verbose)<<endl<<endl;


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
