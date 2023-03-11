// Below is what was initally created during my time in Intro to C++

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string temp, replaceCard, temp1, temp2, temp3, temp4, test;
    srand(time(NULL));
    int same, shuffleDeck = (rand() % 1000) + 1;
    vector<string> deck;
    vector<char> suit(4);
    vector<string> cards(13);
    vector<string> player0Hand;
    vector<string> player1Hand;
    vector<string> player2Hand;
    vector<string> player3Hand;
    vector<string> player4Hand;

    // The suits of the cards
    suit.at(0) = 'S', suit.at(1) = 'D', suit.at(2) = 'H', suit.at(3) = 'C';

    // Cards number
    cards.at(0) = "2", cards.at(1) = "3", cards.at(2) = "4", cards.at(3) = "5";
    cards.at(4) = "6", cards.at(5) = "7", cards.at(6) = "8", cards.at(7) = "9";
    cards.at(8) = "10", cards.at(9) = "J", cards.at(10) = "Q", cards.at(11) = "K";
    cards.at(12) = "A";

    // Creates the Deck
    for (int j = 0; j < 4; ++j)
    {
        for (int k = 0; k < 13; ++k)
        {
            temp = suit.at(j) + cards.at(k);
            deck.push_back(temp);
        }
    }

    // Shuffles cards a random amount of times to create a different game each time
    for (int i = 1; i <= shuffleDeck; ++i)
    {
        random_shuffle(deck.begin(), deck.end());
    }

    // Assigns 7 cards to each player
    for (int i = 0; i < 7; ++i)
    {
        player0Hand.push_back(deck.at(51 - i));
        deck.pop_back();
    }
    for (int i = 0; i < 7; ++i)
    {
        player1Hand.push_back(deck.at(44 - i));
        deck.pop_back();
    }
    for (int i = 0; i < 7; ++i)
    {
        player2Hand.push_back(deck.at(37 - i));
        deck.pop_back();
    }
    for (int i = 0; i < 7; ++i)
    {
        player3Hand.push_back(deck.at(30 - i));
        deck.pop_back();
    }
    for (int i = 0; i < 7; ++i)
    {
        player4Hand.push_back(deck.at(23 - i));
        deck.pop_back();
    }

    // THE GAME BEGINS
    while (true)
    {
        /*Player 1 Intelligence. Organizes Cards where it moves the card that doesn't match the suit of the
        first card to the end of its end, for it later be passed on to another the next players deck*/

        for (int i = 1; i < 7; ++i)
        {
            if (player1Hand.at(0).at(0) != player1Hand.at(i).at(0))
            {
                test = player1Hand.at(i);
                player1Hand.at(i) = player1Hand.at(6);
                player1Hand.at(6) = test;
            }
        }
        /*Player 2 Intelligence. Organizes Cards where it moves the card that doesn't match the suit of the
        first card to the end of its end, for it later be passed on to another the next players deck*/
        for (int i = 1; i < 7; ++i)
        {
            if (player2Hand.at(0).at(0) != player2Hand.at(i).at(0))
            {
                test = player2Hand.at(i);
                player2Hand.at(i) = player2Hand.at(6);
                player2Hand.at(6) = test;
            }
        }
        /*Player 3 Intelligence. Organizes Cards where it moves the card that doesn't match the suit of the
        first card to the end of its end, for it later be passed on to another the next players deck*/
        for (int i = 1; i < 7; ++i)
        {
            if (player3Hand.at(0).at(0) != player3Hand.at(i).at(0))
            {
                test = player3Hand.at(i);
                player3Hand.at(i) = player3Hand.at(6);
                player3Hand.at(6) = test;
            }
        }
        /*Player 4 Intelligence. Organizes Cards where it moves the card that doesn't match the suit of the
        first card to the end of its end, for it later be passed on to another the next players deck*/
        for (int i = 1; i < 7; ++i)
        {
            if (player4Hand.at(0).at(0) != player4Hand.at(i).at(0))
            {
                test = player4Hand.at(i);
                player4Hand.at(i) = player4Hand.at(6);
                player4Hand.at(6) = test;
            }
        }

        // Outputs Player 0 cards
        for (int i = 0; i < 7; ++i)
        {
            cout << "(" << static_cast<char>('a' + i) << ")" << player0Hand.at(i) << " ";
        }
        cout << endl;
        // Choosing which card to get rid of
        cout << endl
             << "Which one to replace? ";
        cin >> replaceCard;
        cout << endl;
        if (replaceCard == "a")
        {
            cout << "Hint: player 0 passed " << player0Hand.at(0) << " to player 1" << endl;
            cout << "Hint: player 1 passed " << player1Hand.at(6) << " to player 2" << endl;
            cout << "Hint: player 2 passed " << player2Hand.at(6) << " to player 3" << endl;
            cout << "Hint: player 3 passed " << player3Hand.at(6) << " to player 4" << endl;
            cout << "Hint: player 4 passed " << player4Hand.at(6) << " to player 0" << endl;

            // Passes the Cards
            temp = player0Hand.at(0), temp1 = player1Hand.at(6);
            temp2 = player2Hand.at(6), temp3 = player3Hand.at(6);
            temp4 = player4Hand.at(6);
            player0Hand.at(0) = temp4, player1Hand.at(6) = temp;
            player2Hand.at(6) = temp1, player3Hand.at(6) = temp2;
            player4Hand.at(6) = temp3;
        }

        else if (replaceCard == "b")
        {
            cout << "Hint: player 0 passed " << player0Hand.at(1) << " to player 1" << endl;
            cout << "Hint: player 1 passed " << player1Hand.at(6) << " to player 2" << endl;
            cout << "Hint: player 2 passed " << player2Hand.at(6) << " to player 3" << endl;
            cout << "Hint: player 3 passed " << player3Hand.at(6) << " to player 4" << endl;
            cout << "Hint: player 4 passed " << player4Hand.at(6) << " to player 0" << endl;

            // Passes the Cards
            temp = player0Hand.at(1), temp1 = player1Hand.at(6);
            temp2 = player2Hand.at(6), temp3 = player3Hand.at(6);
            temp4 = player4Hand.at(6);
            player0Hand.at(1) = temp4, player1Hand.at(6) = temp;
            player2Hand.at(6) = temp1, player3Hand.at(6) = temp2;
            player4Hand.at(6) = temp3;
        }

        else if (replaceCard == "c")
        {
            cout << "Hint: player 0 passed " << player0Hand.at(2) << " to player 1" << endl;
            cout << "Hint: player 1 passed " << player1Hand.at(6) << " to player 2" << endl;
            cout << "Hint: player 2 passed " << player2Hand.at(6) << " to player 3" << endl;
            cout << "Hint: player 3 passed " << player3Hand.at(6) << " to player 4" << endl;
            cout << "Hint: player 4 passed " << player4Hand.at(6) << " to player 0" << endl;

            // Passes the Cards
            temp = player0Hand.at(2), temp1 = player1Hand.at(6);
            temp2 = player2Hand.at(6), temp3 = player3Hand.at(6);
            temp4 = player4Hand.at(6);
            player0Hand.at(2) = temp4, player1Hand.at(6) = temp;
            player2Hand.at(6) = temp1, player3Hand.at(6) = temp2;
            player4Hand.at(6) = temp3;
        }

        else if (replaceCard == "d")
        {
            cout << "Hint: player 0 passed " << player0Hand.at(3) << " to player 1" << endl;
            cout << "Hint: player 1 passed " << player1Hand.at(6) << " to player 2" << endl;
            cout << "Hint: player 2 passed " << player2Hand.at(6) << " to player 3" << endl;
            cout << "Hint: player 3 passed " << player3Hand.at(6) << " to player 4" << endl;
            cout << "Hint: player 4 passed " << player4Hand.at(6) << " to player 0" << endl;

            // Passes the Cards
            temp = player0Hand.at(3), temp1 = player1Hand.at(6);
            temp2 = player2Hand.at(6), temp3 = player3Hand.at(6);
            temp4 = player4Hand.at(6);
            player0Hand.at(3) = temp4, player1Hand.at(6) = temp;
            player2Hand.at(6) = temp1, player3Hand.at(6) = temp2;
            player4Hand.at(6) = temp3;
        }

        else if (replaceCard == "e")
        {
            cout << "Hint: player 0 passed " << player0Hand.at(4) << " to player 1" << endl;
            cout << "Hint: player 1 passed " << player1Hand.at(6) << " to player 2" << endl;
            cout << "Hint: player 2 passed " << player2Hand.at(6) << " to player 3" << endl;
            cout << "Hint: player 3 passed " << player3Hand.at(6) << " to player 4" << endl;
            cout << "Hint: player 4 passed " << player4Hand.at(6) << " to player 0" << endl;

            // Passes the Cards
            temp = player0Hand.at(4), temp1 = player1Hand.at(6);
            temp2 = player2Hand.at(6), temp3 = player3Hand.at(6);
            temp4 = player4Hand.at(6);
            player0Hand.at(4) = temp4, player1Hand.at(6) = temp;
            player2Hand.at(6) = temp1, player3Hand.at(6) = temp2;
            player4Hand.at(6) = temp3;
        }
        else if (replaceCard == "f")
        {
            cout << "Hint: player 0 passed " << player0Hand.at(5) << " to player 1" << endl;
            cout << "Hint: player 1 passed " << player1Hand.at(6) << " to player 2" << endl;
            cout << "Hint: player 2 passed " << player2Hand.at(6) << " to player 3" << endl;
            cout << "Hint: player 3 passed " << player3Hand.at(6) << " to player 4" << endl;
            cout << "Hint: player 4 passed " << player4Hand.at(6) << " to player 0" << endl;

            // Passes the Cards
            temp = player0Hand.at(5), temp1 = player1Hand.at(6);
            temp2 = player2Hand.at(6), temp3 = player3Hand.at(6);
            temp4 = player4Hand.at(6);
            player0Hand.at(5) = temp4, player1Hand.at(6) = temp;
            player2Hand.at(6) = temp1, player3Hand.at(6) = temp2;
            player4Hand.at(6) = temp3;
        }
        else if (replaceCard == "g")
        {
            cout << "Hint: player 0 passed " << player0Hand.at(6) << " to player 1" << endl;
            cout << "Hint: player 1 passed " << player1Hand.at(6) << " to player 2" << endl;
            cout << "Hint: player 2 passed " << player2Hand.at(6) << " to player 3" << endl;
            cout << "Hint: player 3 passed " << player3Hand.at(6) << " to player 4" << endl;
            cout << "Hint: player 4 passed " << player4Hand.at(6) << " to player 0" << endl;

            // Passes the Cards
            temp = player0Hand.at(6), temp1 = player1Hand.at(6);
            temp2 = player2Hand.at(6), temp3 = player3Hand.at(6);
            temp4 = player4Hand.at(6);
            player0Hand.at(6) = temp4, player1Hand.at(6) = temp;
            player2Hand.at(6) = temp1, player3Hand.at(6) = temp2;
            player4Hand.at(6) = temp3;
        }
        else if (replaceCard == "?")
        {
            cout << "Player 0   ";
            for (int i = 0; i < 7; ++i)
            {
                cout << "(" << static_cast<char>('a' + i) << ")" << player0Hand.at(i) << " ";
            }
            cout << endl
                 << "Player 1   ";
            for (int i = 0; i < 7; ++i)
            {
                cout << "(" << static_cast<char>('a' + i) << ")" << player1Hand.at(i) << " ";
            }
            cout << endl
                 << "Player 2   ";
            for (int i = 0; i < 7; ++i)
            {
                cout << "(" << static_cast<char>('a' + i) << ")" << player2Hand.at(i) << " ";
            }
            cout << endl
                 << "Player 3   ";
            for (int i = 0; i < 7; ++i)
            {
                cout << "(" << static_cast<char>('a' + i) << ")" << player3Hand.at(i) << " ";
            }
            cout << endl
                 << "Player 4   ";
            for (int i = 0; i < 7; ++i)
            {
                cout << "(" << static_cast<char>('a' + i) << ")" << player4Hand.at(i) << " ";
            }
            cout << endl;
        }

        else
        {
            cout << "Wrong Input" << endl
                 << endl;
        }

        cout << endl;
        // Breaks Loop if all suits of player 0 are the same
        if (player0Hand.at(0).at(0) == player0Hand.at(1).at(0) && player0Hand.at(0).at(0) == player0Hand.at(2).at(0) &&
            player0Hand.at(0).at(0) == player0Hand.at(3).at(0) && player0Hand.at(0).at(0) == player0Hand.at(4).at(0) &&
            player0Hand.at(0).at(0) == player0Hand.at(5).at(0) && player0Hand.at(0).at(0) == player0Hand.at(6).at(0))
            break;

        // Breaks Loop if all suits of player 1 are the same
        if (player1Hand.at(0).at(0) == player1Hand.at(1).at(0) && player1Hand.at(0).at(0) == player1Hand.at(2).at(0) &&
            player1Hand.at(0).at(0) == player1Hand.at(3).at(0) && player1Hand.at(0).at(0) == player1Hand.at(4).at(0) &&
            player1Hand.at(0).at(0) == player1Hand.at(5).at(0) && player1Hand.at(0).at(0) == player1Hand.at(6).at(0))
            break;

        // Breaks Loop if all suits of player 2 are the same
        if (player2Hand.at(0).at(0) == player2Hand.at(1).at(0) && player2Hand.at(0).at(0) == player2Hand.at(2).at(0) &&
            player2Hand.at(0).at(0) == player2Hand.at(3).at(0) && player2Hand.at(0).at(0) == player2Hand.at(4).at(0) &&
            player2Hand.at(0).at(0) == player2Hand.at(5).at(0) && player2Hand.at(0).at(0) == player2Hand.at(6).at(0))
            break;

        // Breaks Loop if all suits of player 3 are the same
        if (player3Hand.at(0).at(0) == player3Hand.at(1).at(0) && player3Hand.at(0).at(0) == player3Hand.at(2).at(0) &&
            player3Hand.at(0).at(0) == player3Hand.at(3).at(0) && player3Hand.at(0).at(0) == player3Hand.at(4).at(0) &&
            player3Hand.at(0).at(0) == player3Hand.at(5).at(0) && player3Hand.at(0).at(0) == player3Hand.at(6).at(0))
            break;

        // Breaks Loop if all suits of player 4 are the same
        if (player4Hand.at(0).at(0) == player4Hand.at(1).at(0) && player4Hand.at(0).at(0) == player4Hand.at(2).at(0) &&
            player4Hand.at(0).at(0) == player4Hand.at(3).at(0) && player4Hand.at(0).at(0) == player4Hand.at(4).at(0) &&
            player4Hand.at(0).at(0) == player4Hand.at(5).at(0) && player4Hand.at(0).at(0) == player4Hand.at(6).at(0))
            break;
    }

    // End of Game. Shows winners
    // If Player 0 won
    same = 0;
    for (int l = 1; l < 7; ++l)
    {
        if (player0Hand.at(0).at(0) == player0Hand.at(l).at(0))
        {
            same += 1;
        }
    }
    if (same == 6)
    {
        cout << "My Ship Sails! --- Player 0 Won..." << endl;
    }

    // If Player 1 won
    same = 0;
    for (int l = 1; l < 7; ++l)
    {
        if (player1Hand.at(0).at(0) == player1Hand.at(l).at(0))
        {
            same += 1;
        }
    }
    if (same == 6)
    {
        cout << "My Ship Sails! --- Player 1 Won..." << endl;
    }

    // If Player 2 won
    same = 0;
    for (int l = 1; l < 7; ++l)
    {
        if (player2Hand.at(0).at(0) == player2Hand.at(l).at(0))
        {
            same += 1;
        }
    }
    if (same == 6)
    {
        cout << "My Ship Sails! --- Player 2 Won..." << endl;
    }

    // If Player 3 won
    same = 0;
    for (int l = 1; l < 7; ++l)
    {
        if (player3Hand.at(0).at(0) == player3Hand.at(l).at(0))
        {
            same += 1;
        }
    }
    if (same == 6)
    {
        cout << "My Ship Sails! --- Player 3 Won..." << endl;
    }

    // If Player 4 won
    same = 0;
    for (int l = 1; l < 7; ++l)
    {
        if (player4Hand.at(0).at(0) == player4Hand.at(l).at(0))
        {
            same += 1;
        }
    }
    if (same == 6)
    {
        cout << "My Ship Sails! --- Player 4 Won..." << endl;
    }
    cout << endl;

    // Shows every players last hand
    cout << "[FINAL DISTRIBUTION]" << endl
         << "Player 0   ";
    for (int i = 0; i < 7; ++i)
    {
        cout << "(" << static_cast<char>('a' + i) << ")" << player0Hand.at(i) << " ";
    }
    cout << endl
         << "Player 1   ";
    for (int i = 0; i < 7; ++i)
    {
        cout << "(" << static_cast<char>('a' + i) << ")" << player1Hand.at(i) << " ";
    }
    cout << endl
         << "Player 2   ";
    for (int i = 0; i < 7; ++i)
    {
        cout << "(" << static_cast<char>('a' + i) << ")" << player2Hand.at(i) << " ";
    }
    cout << endl
         << "Player 3   ";
    for (int i = 0; i < 7; ++i)
    {
        cout << "(" << static_cast<char>('a' + i) << ")" << player3Hand.at(i) << " ";
    }
    cout << endl
         << "Player 4   ";
    for (int i = 0; i < 7; ++i)
    {
        cout << "(" << static_cast<char>('a' + i) << ")" << player4Hand.at(i) << " ";
    }
    return 0;
}