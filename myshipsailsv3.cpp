#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>
#include <iomanip>

using namespace std;

class Card {
    public:
        char suit;
        string rank;
};

vector<Card> handOutCards(vector<Card>& deck) {
    vector<Card> hand;
    for(int i = 0; i < 7; i++) {
        hand.push_back(deck.back());
        deck.pop_back();
    }

    return hand;
}

void printCards(vector<Card> hand) {
    for(int i = 0; i < hand.size(); i++) {
        cout << hand[i].suit << hand[i].rank << " ";
    }
    cout << endl;
}

bool winningHand(vector<Card> hand) {
    for(int i = 1; i < hand.size(); i++) {
        if(hand[i-1].suit != hand[i].suit) return false;
    }

    return true;
}

int main() {
    vector<Card> deck;
    vector<char> suits = {'H', 'D', 'C', 'S'};
    vector<string> ranks = {"2", "3", "4", "5","6", "7", "8", "9","10", "J", "Q", "K", "A"};
    // Create deck
    for(char s: suits) {
        for(string r: ranks) {
            Card c;
            c.suit = s;
            c.rank = r;
            deck.push_back(c);
        }
    }
    // Shuffle deck
    srand(time(NULL));
    auto rng = default_random_engine {};
    int random = (rand() % 1000) + 1;
    for (int i = 0; i < random; i++)
    {
        shuffle(deck.begin(), deck.end(), rng);
    }

    // Create user hands
    vector<Card> userHand = handOutCards(deck);
    vector<Card> comp1Hand = handOutCards(deck);
    vector<Card> comp2Hand = handOutCards(deck);
    vector<Card> comp3Hand = handOutCards(deck);
    vector<Card> comp4Hand = handOutCards(deck);
    printCards(userHand);
    printCards(comp1Hand);
    printCards(comp2Hand);
    printCards(comp3Hand);
    printCards(comp4Hand);

    cout << winningHand(userHand);

    return 0;
}