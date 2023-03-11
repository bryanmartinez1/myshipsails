// Second attempt in My Ship Sails in C++. Using Ordered_Maps and Functions to remove DRY code
// 200 Lines Less

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <unordered_map>

using namespace std;

vector<string> assignHands(vector<string> deck, int j)
{
    vector<string> hand;
    for (int i = 0; i < 7; i++)
    {
        hand.push_back(deck[j + i]);
    }
    return hand;
}

void swappingBetweenPlayers(vector<string> &userHand, vector<string> &comp1Hand, vector<string> &comp2Hand,
                            vector<string> &comp3Hand, vector<string> &comp4Hand, int choosenCard)
{
    string temp;
    temp = userHand[choosenCard];
    userHand[choosenCard] = comp4Hand[6];
    comp4Hand[6] = comp3Hand[6];
    comp3Hand[6] = comp2Hand[6];
    comp2Hand[6] = comp1Hand[6];
    comp1Hand[6] = temp;
}

void leastValuedCard(vector<string> &hand)
{
    int cardPos = 6;
    unordered_map<char, int> suitOccurences;
    suitOccurences.insert({'H', 0});
    suitOccurences.insert({'D', 0});
    suitOccurences.insert({'C', 0});
    suitOccurences.insert({'S', 0});
    // Populates Hash Map to where each Suit is assinged its population value
    for (int i = 0; i < 7; i++)
    {
        suitOccurences.at(hand[i][0])++;
    }
    char mostRepeatingSuit = 'H';
    for (auto i : suitOccurences)
    {
        if (i.second > suitOccurences.at(mostRepeatingSuit))
            mostRepeatingSuit = i.first;
    }
    for (int i = 0; i < hand.size(); i++)
    {
        if (hand[i][0] != mostRepeatingSuit)
        {
            cardPos = i;
            break;
        }
    }
    string temp = hand[6];
    hand[6] = hand[cardPos];
    hand[cardPos] = temp;
}

void hintSequence(vector<string> &userHand, vector<string> &comp1Hand, vector<string> &comp2Hand,
                  vector<string> &comp3Hand, vector<string> &comp4Hand, int choosenCard)
{
    cout << "Hint: Player 1 passed " << userHand[choosenCard] << " to Player 2" << endl;
    cout << "Hint: Player 2 passed " << comp1Hand[6] << " to Player 3" << endl;
    cout << "Hint: Player 3 passed " << comp2Hand[6] << " to Player 4" << endl;
    cout << "Hint: Player 4 passed " << comp3Hand[6] << " to Player 5" << endl;
    cout << "Hint: Player 5 passed " << comp4Hand[6] << " to Player 1" << endl;
}

void printHand(vector<string> hand, int playerNum)
{
    cout << "Player " << playerNum << ": ";
    for (int i = 0; i < 7; i++)
    {
        cout << "(" << i + 1 << ") " << hand[i] << " ";
    }
    cout << endl;
}

bool winCondition(vector<string> hand)
{
    for (int i = 0; i < hand.size(); i++)
    {
        if (hand[0][0] != hand[i][0])
            return false;
    }
    return true;
}

void winnerPrint(vector<string> hand, int playerNum)
{
    cout << "My Ship Sails! --- Player " << playerNum << " Wins..." << endl;
}

int main()
{
    string replaceCard;
    vector<string> deck(52);
    // A Suit Cards
    deck[0] = "H2 ", deck[1] = "H3 ", deck[2] = "H4 ", deck[3] = "H5 ", deck[4] = "H6 ", deck[5] = "H7 ";
    deck[6] = "H8 ", deck[7] = "H9 ", deck[8] = "H10", deck[9] = "HJ ", deck[10] = "HQ", deck[11] = "HK ";
    deck[12] = "HA ";
    // C Suit Cards
    deck[13] = "C2 ", deck[14] = "C3 ", deck[15] = "C4 ", deck[16] = "C5 ", deck[17] = "C6 ", deck[18] = "C7 ";
    deck[19] = "C8 ", deck[20] = "C9 ", deck[21] = "C10", deck[22] = "CJ ", deck[23] = "CQ ", deck[24] = "CK ";
    deck[25] = "CA ";
    // D Suit Cards
    deck[26] = "D2 ", deck[27] = "D3 ", deck[28] = "D4 ", deck[29] = "D5 ", deck[30] = "D6 ", deck[31] = "D7 ";
    deck[32] = "D8 ", deck[33] = "D9 ", deck[34] = "D10", deck[35] = "DJ ", deck[36] = "DQ ", deck[37] = "DK ";
    deck[38] = "DA ";
    // S Suit Cards
    deck[39] = "S2 ", deck[40] = "S3 ", deck[41] = "S4 ", deck[42] = "S5 ", deck[43] = "S6 ", deck[44] = "S7 ";
    deck[45] = "S8 ", deck[46] = "S9 ", deck[47] = "S10", deck[48] = "SJ ", deck[49] = "SQ ", deck[50] = "SK ";
    deck[51] = "SA ";
    // Deck is Shuffled
    srand(time(NULL));
    auto rng = std::default_random_engine{};
    int random = (rand() % 1000) + 1;
    for (int i = 0; i < random; i++)
    {
        shuffle(deck.begin(), deck.end(), rng);
    }

    // Player Hands
    vector<string> userHand = assignHands(deck, 0);
    vector<string> comp1Hand = assignHands(deck, 7);
    vector<string> comp2Hand = assignHands(deck, 14);
    vector<string> comp3Hand = assignHands(deck, 21);
    vector<string> comp4Hand = assignHands(deck, 28);

    cout << "Welcome to My Ship Sails!!!" << endl;

    while (true)
    {
        leastValuedCard(comp1Hand);
        leastValuedCard(comp2Hand);
        leastValuedCard(comp3Hand);
        leastValuedCard(comp4Hand);

        cout << endl;
        printHand(userHand, 1);

        cout << "\nWhich one to replace? ";
        cin >> replaceCard;
        cout << endl;

        if (replaceCard == "1")
        {
            hintSequence(userHand, comp1Hand, comp2Hand, comp3Hand, comp4Hand, stoi(replaceCard) - 1);
            swappingBetweenPlayers(userHand, comp2Hand, comp3Hand, comp1Hand, comp4Hand, stoi(replaceCard) - 1);
        }
        else if (replaceCard == "2")
        {
            hintSequence(userHand, comp1Hand, comp2Hand, comp3Hand, comp4Hand, stoi(replaceCard) - 1);
            swappingBetweenPlayers(userHand, comp2Hand, comp3Hand, comp1Hand, comp4Hand, stoi(replaceCard) - 1);
        }
        else if (replaceCard == "3")
        {
            hintSequence(userHand, comp1Hand, comp2Hand, comp3Hand, comp4Hand, stoi(replaceCard) - 1);
            swappingBetweenPlayers(userHand, comp2Hand, comp3Hand, comp1Hand, comp4Hand, stoi(replaceCard) - 1);
        }
        else if (replaceCard == "4")
        {
            hintSequence(userHand, comp1Hand, comp2Hand, comp3Hand, comp4Hand, stoi(replaceCard) - 1);
            swappingBetweenPlayers(userHand, comp2Hand, comp3Hand, comp1Hand, comp4Hand, stoi(replaceCard) - 1);
        }
        else if (replaceCard == "5")
        {
            hintSequence(userHand, comp1Hand, comp2Hand, comp3Hand, comp4Hand, stoi(replaceCard) - 1);
            swappingBetweenPlayers(userHand, comp2Hand, comp3Hand, comp1Hand, comp4Hand, stoi(replaceCard) - 1);
        }
        else if (replaceCard == "6")
        {
            hintSequence(userHand, comp1Hand, comp2Hand, comp3Hand, comp4Hand, stoi(replaceCard) - 1);
            swappingBetweenPlayers(userHand, comp2Hand, comp3Hand, comp1Hand, comp4Hand, stoi(replaceCard) - 1);
        }
        else if (replaceCard == "7")
        {
            hintSequence(userHand, comp1Hand, comp2Hand, comp3Hand, comp4Hand, stoi(replaceCard) - 1);
            swappingBetweenPlayers(userHand, comp1Hand, comp2Hand, comp3Hand, comp4Hand, stoi(replaceCard) - 1);
        }
        else if (replaceCard == "?")
        {
            printHand(userHand, 1);
            printHand(comp1Hand, 2);
            printHand(comp2Hand, 3);
            printHand(comp3Hand, 4);
            printHand(comp4Hand, 5);
        }
        else
        {
            cout << "\nInvalid Input. Please Try Again\n";
        }

        if (winCondition(userHand) == true)
            break;
        if (winCondition(comp1Hand) == true)
            break;
        if (winCondition(comp2Hand) == true)
            break;
        if (winCondition(comp3Hand) == true)
            break;
        if (winCondition(comp4Hand) == true)
            break;
    }

    cout << endl;

    printHand(userHand, 1);
    printHand(comp1Hand, 2);
    printHand(comp2Hand, 3);
    printHand(comp3Hand, 4);
    printHand(comp4Hand, 5);

    cout << endl;

    if (winCondition(userHand) == true)
        winnerPrint(userHand, 1);
    if (winCondition(comp1Hand) == true)
        winnerPrint(comp1Hand, 2);
    if (winCondition(comp2Hand) == true)
        winnerPrint(comp2Hand, 3);
    if (winCondition(comp3Hand) == true)
        winnerPrint(comp3Hand, 4);
    if (winCondition(comp4Hand) == true)
        winnerPrint(comp4Hand, 5);

    return 0;
}