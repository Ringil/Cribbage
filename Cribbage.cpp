#include "Cribbage.h"

Cribbage::Cribbage(int numHumans, int numAI)
{
    this->numHumans = numHumans;
    this->numAI = numAI;
    numFifteens = 0;
}

int Cribbage::calcScore(vector<card> hand, card cut, bool crib, bool verbose)
{
    int total = 0;

    total = calcRightJack(hand, cut);

    if(verbose)
    {
        cout<<"Points for right jack: " << total << endl;
    }

    hand.push_back(cut);
    sort(hand.begin(), hand.end()); //Sort card structs by val

    //Think about moving verbosity to the seperate calc funcs
    if(verbose)
    {
        cout<<"Points for 15's: "<<calcFifteen(hand)<<"\nPoints for runs: "<<calcRuns(hand)<<"\nPoints "
            <<"for pairs: "<<calcPairs(hand)<<"\nPoints for flushes: "<<calcFlush(hand, crib)<<endl;
    }
    
    //Calculate rest of the points
    total +=  calcRuns(hand) + calcPairs(hand) + calcFlush(hand, crib) + calcFifteen(hand);

    return total;
}

int Cribbage::calcFifteen(vector<card> hand)
{
    int target = 15;
    vector<card> partial;

    numFifteens = 0;
    subSetSum(hand, target, partial);
    numFifteens = numFifteens*2; //Set the actual amount of points you get from fifteens
    
    return numFifteens; 
}

void Cribbage::subSetSum(vector<card> hand, int target, vector<card> partial)
{
    int s = 0;

    for(vector<card>::iterator it = partial.begin(); it != partial.end(); it++)
    {
        if(it->val > 10) //Takes care of face cards being >10
            s+=10;
        else
            s += it->val;
    }

    if(s == target)
    {
        numFifteens++;
    }

    if(s >= target)
        return;

    for(vector<card>::iterator it = hand.begin(); it != hand.end(); it++)
    {
        vector<card> remaining (it+1, hand.end());
        vector<card> partialRec (partial);
        card pCard;

        pCard.suit = it->suit;
        pCard.val = it->val;
        partialRec.push_back(pCard);

        subSetSum(remaining, target, partialRec);
    }
}

int Cribbage::calcFlush(vector<card> hand, bool crib)
{
    int total = 0;
    int numSuits[4] = {0,0,0,0};
    vector<card>::iterator it;

    for(it = hand.begin(); it != hand.end(); it++)
    {
        if(it->suit == 'C')
            numSuits[0]++;
        else if(it->suit == 'H')
            numSuits[1]++;
        else if(it->suit == 'D')
            numSuits[2]++;
        else if(it->suit == 'S')
            numSuits[3]++;
        else
        {
            cout<<it->suit<<" is not a real suit.\n Exiting program!\n";
            exit(0);
        }
    }

    /*
    Check each suit for a 4 card flush or higher when it isn't a crib hand.
    Need all as the same suit when it is a crib.
    */
    for(int i = 0; i<=3; i++)
    {
        if(crib == false && numSuits[i] >= 4)
        {
            total = numSuits[i];
            return total;
        }
        else if(crib == true && numSuits[i] == 5)
        {
            total = 5;
            return total;
        }
    }

    return total;
}

int Cribbage::calcRuns(vector<card> hand)
{
    int total = 0;
    int duplicate = 0;
    stack<card> runs;
    vector<card>::iterator it;

    for(it = hand.begin(); it != hand.end(); it++)
    {
        /*
        Does not account for run using ace after the king 
        */
        if(runs.empty() || it->val == runs.top().val + 1)
        {
            runs.push(*it);
        }
        else if(it->val == runs.top().val)
        {
            duplicate++;
        }

        /* 
        Check if the next card will break the run or if it is the last 
        card in the hand.
        */
        if((it == hand.end() - 1) || (it + 1)->val > runs.top().val + 1)
        {
            if(runs.size() >= 3) //Minimum size for a run
            {
                if(duplicate > 0)
                    total = (int) (pow((double) runs.size(), (double) duplicate) + runs.size());
                else
                    total = runs.size();
            }

            duplicate = 0;
            eraseStack(runs);
        }
    }

    return total;
}

int Cribbage::calcPairs(vector<card> hand)
{
    stack<card> sameCards;
    vector<card>::iterator it;
    int total = 0;

    for(it = hand.begin(); it != hand.end(); it++)
    {
        //If nothing in the stack or if the card is the same as what is on the stack, push the card
        if(sameCards.empty() || it->val == sameCards.top().val)
        {
            sameCards.push(*it);
        }

        //This makes sure you calculate all the points even if the last two cards are the same.
        if((it == hand.end() - 1) || (it + 1)->val != sameCards.top().val)
        {
            /*
            Calculate amount of points from the amount of same cards ((n^2)-n)
            */
            total += (sameCards.size() * sameCards.size()) - sameCards.size();
            
            eraseStack(sameCards);
        }
    }

    return total;
}

int Cribbage::calcRightJack(vector<card> hand, card cut)
{
    vector<card>::iterator it;

    //Check if you have a jack in your hand and if the cut card is the same suit
    for(it = hand.begin(); it != hand.end(); it++)
    {
        if(it->val == 11 && (it->suit == cut.suit))
            return 1;
    }
    return 0;
}

void Cribbage::deal(vector<card> &hand1, vector<card> &hand2)
{
    vector<card>::iterator it = deck.end() - 1; //Top of the deck

    if(this->numCardsLeft() >= 14)
    {
        //Deal 6 cards to each hand
        for(int i = 0; i < 6; i++)
        {
            hand1.push_back(*it); //Deal the card
            it--;
            deck.pop_back(); //Needed so numCardsLeft gives right value

            hand2.push_back(*it); //Deal the card
            it--;
            deck.pop_back();
        }
    }
    else
        cout << endl << "No more cards left in the deck!" << endl;
}

void Cribbage::deal(vector<card> &hand1, vector<card> &hand2, vector<card> &hand3)
{
    vector<card>::iterator it = deck.end() - 1; //Top of the deck

    if(this->numCardsLeft() >= 17)
    {
        //Deal 5 cards to each player
        for(int i = 0; i < 5; i++)
        {
            hand1.push_back(*it); //Deal the card
            it--;
            deck.pop_back();      //Needed so numCardsLeft gives right value

            hand2.push_back(*it); //Deal the card
            it--;
            deck.pop_back();

            hand3.push_back(*it); //Deal the card
            it--;
            deck.pop_back();
        }
    }
    else
        cout << endl << "No more cards left in the deck!" << endl;
}

card Cribbage::cutDeck()
{
    int max = this->numCardsLeft() - 1; //-1 because boost::uid uses a closed range
    int index = 0;
    card cut;
    mt19937 gen;
    uniform_int_distribution<> dist(0, max); //A closed range

    index = dist(gen); //Choose the cut card index
    cut.suit = deck.at(index).suit;
    cut.val = deck.at(index).val;
    deck.erase(deck.begin() + index - 1); //Remove the cut card from the deck

    return cut;
}
