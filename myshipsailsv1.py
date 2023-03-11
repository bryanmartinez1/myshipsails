import random

card_suits = ["S", "D", "H", "C"]
card_numbers = ["2", "3", "4", "5", "6", "7", "8",
                "9", "10", "J", "Q", "K", "A"]
card_deck = []
for i in range(0, 4):
    for j in range(0, 13):
        temp = card_suits[i] + card_numbers[j]
        card_deck.append(temp)
random.shuffle(card_deck)

player0Hand = []
player1Hand = []
player2Hand = []
player3Hand = []
player4Hand = []

for i in range(0, 7):
    player0Hand.append(card_deck[51-i])
    card_deck.pop()
for i in range(0, 7):
    player1Hand.append(card_deck[44-i])
    card_deck.pop()
for i in range(0, 7):
    player2Hand.append(card_deck[37-i])
    card_deck.pop()
for i in range(0, 7):
    player3Hand.append(card_deck[30-i])
    card_deck.pop()
for i in range(0, 7):
    player4Hand.append(card_deck[23-i])
    card_deck.pop()
while True:
    # Player 1 Intelligence
    for i in range(0, 7):
        if player1Hand[0][0] != player1Hand[i][0]:
            test = player1Hand[i]
            player1Hand[i] = player1Hand[6]
            player1Hand[6] = test
    # Player 2 Intelligence
    for i in range(0, 7):
        if player2Hand[0][0] != player2Hand[i][0]:
            test = player2Hand[i]
            player2Hand[i] = player2Hand[6]
            player2Hand[6] = test
    # Player 3 Intelligence
    for i in range(0, 7):
        if player3Hand[0][0] != player3Hand[i][0]:
            test = player3Hand[i]
            player3Hand[i] = player3Hand[6]
            player3Hand[6] = test
    # Player 4 Intelligence
    for i in range(0, 7):
        if player4Hand[0][0] != player4Hand[i][0]:
            test = player4Hand[i]
            player4Hand[i] = player4Hand[6]
            player4Hand[6] = test
    # Outputs Player 0 cards
    print("\nPlayer 0 Cards:")
    for i in range(1, 8):
        print("(" + str(i) + ")" + player0Hand[i-1], end=" ")
    print("\n")
    replace_card = input("Which one to replace: ")
    if replace_card == "1":
        print("Hint Player 0 passed " + player0Hand[0] + " to Player 1")
        print("Hint Player 1 passed " + player1Hand[6] + " to Player 2")
        print("Hint Player 2 passed " + player2Hand[6] + " to Player 3")
        print("Hint Player 3 passed " + player3Hand[6] + " to Player 4")
        print("Hint Player 4 passed " + player4Hand[6] + " to Player 0")

        temp = player0Hand[0]
        temp1 = player1Hand[6]
        temp2 = player2Hand[6]
        temp3 = player3Hand[6]
        temp4 = player4Hand[6]
        player0Hand[0] = temp4
        player1Hand[6] = temp
        player2Hand[6] = temp1
        player3Hand[6] = temp2
        player4Hand[6] = temp3
    elif replace_card == "2":
        print("Hint Player 0 passed " + player0Hand[1] + " to Player 1")
        print("Hint Player 1 passed " + player1Hand[6] + " to Player 2")
        print("Hint Player 2 passed " + player2Hand[6] + " to Player 3")
        print("Hint Player 3 passed " + player3Hand[6] + " to Player 4")
        print("Hint Player 4 passed " + player4Hand[6] + " to Player 0")

        temp = player0Hand[1]
        temp1 = player1Hand[6]
        temp2 = player2Hand[6]
        temp3 = player3Hand[6]
        temp4 = player4Hand[6]
        player0Hand[1] = temp4
        player1Hand[6] = temp
        player2Hand[6] = temp1
        player3Hand[6] = temp2
        player4Hand[6] = temp3

    elif replace_card == "3":
        print("Hint Player 0 passed " + player0Hand[2] + " to Player 1")
        print("Hint Player 1 passed " + player1Hand[6] + " to Player 2")
        print("Hint Player 2 passed " + player2Hand[6] + " to Player 3")
        print("Hint Player 3 passed " + player3Hand[6] + " to Player 4")
        print("Hint Player 4 passed " + player4Hand[6] + " to Player 0")

        temp = player0Hand[2]
        temp1 = player1Hand[6]
        temp2 = player2Hand[6]
        temp3 = player3Hand[6]
        temp4 = player4Hand[6]
        player0Hand[2] = temp4
        player1Hand[6] = temp
        player2Hand[6] = temp1
        player3Hand[6] = temp2
        player4Hand[6] = temp3

    elif replace_card == "4":
        print("Hint Player 0 passed " + player0Hand[3] + " to Player 1")
        print("Hint Player 1 passed " + player1Hand[6] + " to Player 2")
        print("Hint Player 2 passed " + player2Hand[6] + " to Player 3")
        print("Hint Player 3 passed " + player3Hand[6] + " to Player 4")
        print("Hint Player 4 passed " + player4Hand[6] + " to Player 0")

        temp = player0Hand[3]
        temp1 = player1Hand[6]
        temp2 = player2Hand[6]
        temp3 = player3Hand[6]
        temp4 = player4Hand[6]
        player0Hand[3] = temp4
        player1Hand[6] = temp
        player2Hand[6] = temp1
        player3Hand[6] = temp2
        player4Hand[6] = temp3

    elif replace_card == "5":
        print("Hint Player 0 passed " + player0Hand[4] + " to Player 1")
        print("Hint Player 1 passed " + player1Hand[6] + " to Player 2")
        print("Hint Player 2 passed " + player2Hand[6] + " to Player 3")
        print("Hint Player 3 passed " + player3Hand[6] + " to Player 4")
        print("Hint Player 4 passed " + player4Hand[6] + " to Player 0")

        temp = player0Hand[4]
        temp1 = player1Hand[6]
        temp2 = player2Hand[6]
        temp3 = player3Hand[6]
        temp4 = player4Hand[6]
        player0Hand[4] = temp4
        player1Hand[6] = temp
        player2Hand[6] = temp1
        player3Hand[6] = temp2
        player4Hand[6] = temp3

    elif replace_card == "6":
        print("Hint Player 0 passed " + player0Hand[5] + " to Player 1")
        print("Hint Player 1 passed " + player1Hand[6] + " to Player 2")
        print("Hint Player 2 passed " + player2Hand[6] + " to Player 3")
        print("Hint Player 3 passed " + player3Hand[6] + " to Player 4")
        print("Hint Player 4 passed " + player4Hand[6] + " to Player 0")

        temp = player0Hand[5]
        temp1 = player1Hand[6]
        temp2 = player2Hand[6]
        temp3 = player3Hand[6]
        temp4 = player4Hand[6]
        player0Hand[5] = temp4
        player1Hand[6] = temp
        player2Hand[6] = temp1
        player3Hand[6] = temp2
        player4Hand[6] = temp3
    elif replace_card == "7":
        print("Hint Player 0 passed " + player0Hand[6] + " to Player 1")
        print("Hint Player 1 passed " + player1Hand[6] + " to Player 2")
        print("Hint Player 2 passed " + player2Hand[6] + " to Player 3")
        print("Hint Player 3 passed " + player3Hand[6] + " to Player 4")
        print("Hint Player 4 passed " + player4Hand[6] + " to Player 0")

        temp = player0Hand[6]
        temp1 = player1Hand[6]
        temp2 = player2Hand[6]
        temp3 = player3Hand[6]
        temp4 = player4Hand[6]
        player0Hand[6] = temp4
        player1Hand[6] = temp
        player2Hand[6] = temp1
        player3Hand[6] = temp2
        player4Hand[6] = temp3

    elif replace_card == "?":
        print("PLayer 0:")
        for i in range(1, 8):
            print("(" + str(i) + ")" + player0Hand[i-1], end=" ")
        print("\n")
        print("PLayer 1:")
        for i in range(1, 8):
            print("(" + str(i) + ")" + player1Hand[i-1], end=" ")
        print("\n")
        print("PLayer 2:")
        for i in range(1, 8):
            print("(" + str(i) + ")" + player2Hand[i-1], end=" ")
        print("\n")
        print("PLayer 3:")
        for i in range(1, 8):
            print("(" + str(i) + ")" + player3Hand[i-1], end=" ")
        print("\n")
        print("PLayer 4:")
        for i in range(1, 8):
            print("(" + str(i) + ")" + player4Hand[i-1], end=" ")
        print("\n")
    else:
        print("Wrong Input\n\n")
    if player0Hand[0][0] == player0Hand[1][0] == player0Hand[2][0] == player0Hand[3][0] == player0Hand[4][0] == player0Hand[5][0] == player0Hand[6][0]:
        break
    if player1Hand[0][0] == player1Hand[1][0] == player1Hand[2][0] == player1Hand[3][0] == player1Hand[4][0] == player1Hand[5][0] == player1Hand[6][0]:
        break
    if player2Hand[0][0] == player2Hand[1][0] == player2Hand[2][0] == player2Hand[3][0] == player2Hand[4][0] == player2Hand[5][0] == player2Hand[6][0]:
        break
    if player3Hand[0][0] == player3Hand[1][0] == player3Hand[2][0] == player3Hand[3][0] == player3Hand[4][0] == player3Hand[5][0] == player3Hand[6][0]:
        break
    if player4Hand[0][0] == player4Hand[1][0] == player4Hand[2][0] == player4Hand[3][0] == player0Hand[4][0] == player4Hand[5][0] == player4Hand[6][0]:
        break

same = 0
for i in range(1, 7):
    if player0Hand[0][0] == player0Hand[i][0]:
        same = same + 1
    if same == 6:
        print("\nMy Ship Sails! --- PLayer 0 Won...\n")
for i in range(1, 7):
    if player1Hand[0][0] == player1Hand[i][0]:
        same = same + 1
    if same == 6:
        print("\nMy Ship Sails! --- PLayer 1 Won...\n")
for i in range(1, 7):
    if player2Hand[0][0] == player2Hand[i][0]:
        same = same + 1
    if same == 6:
        print("\nMy Ship Sails! --- PLayer 2 Won...\n")
for i in range(1, 7):
    if player3Hand[0][0] == player3Hand[i][0]:
        same = same + 1
    if same == 6:
        print("\nMy Ship Sails! --- PLayer 3 Won...\n")
for i in range(1, 7):
    if player4Hand[0][0] == player4Hand[i][0]:
        same = same + 1
    if same == 6:
        print("\nMy Ship Sails! --- PLayer 4 Won...\n")
print("[FINAL DISTRIBUTION\nPlayer 0:")
for l in range(1, 8):
    print("(" + str(l) + ")" + player0Hand[l - 1], end=" ")
print("\nPlayer 1:")
for l in range(1, 8):
    print("(" + str(l) + ")" + player1Hand[l - 1], end=" ")
print("\nPlayer 2:")
for l in range(1, 8):
    print("(" + str(l) + ")" + player2Hand[l - 1], end=" ")
print("\nPlayer 3:")
for l in range(1, 8):
    print("(" + str(l) + ")" + player3Hand[l - 1], end=" ")
print("\nPlayer 4:")
for l in range(1, 8):
    print("(" + str(l) + ")" + player4Hand[l - 1], end=" ")
