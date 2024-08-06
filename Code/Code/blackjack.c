#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "code.h"

#pragma endregion

#pragma region Code

/**
 * @brief Shuffles the Deck of Cards
 * 
 * @param [in] Cards The Deck that needs Shuffling
 * @param [out] Nothing
 */
void shuffle(int* cards) {
    srand(time(NULL));

    for (int i = 51; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

/**
 * @brief Prints a Card in the Console
 * 
 * @param [in] Card The Card that needs to be Printed
 * @param [out] Nothing
*/
void printCard(int card) {
    const char* suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char* faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    int suit = card / 13;
    int face = card % 13;
    
    printf("\t%2s of %2s\n\n", faces[face], suits[suit]);
}

/**
 * @brief Gives the Points of the Card
 * 
 * @param [in] Card The Card that the BlackJack needs the Points
 * @param [out] Points The Points of the Card
*/
int pointCard(int card) {
    int value = card % 13 + 1;

    if (value > 10) {
        return 10; // Face cards are worth 10 points
    } else if (value == 1) {
        return 11; // Ace initially counts as 11
    } else {
        return value;
    }
}

/**
 * @brief Adjusts Points if there is an Ace and the total exceeds 21
 * 
 * @param [in] points Current points of the hand
 * @param [in] aceCount Number of aces in the hand
 * @return Adjusted points
 */
int adjustForAces(int points, int aceCount) {
    while (points > 21 && aceCount > 0) {
        points -= 10; // Count Ace as 1 instead of 11
        aceCount--;
    }
    return points;
}

/**
 * @brief The Game BlackJack
 * 
 * @param [in] Nothing
 * @param [out] Nothing
*/
void blackjack() {
    int computerPoints, playerPoints, choice, playerAceCount = 0, computerAceCount = 0;
    int i = 0;
    int deck[52];
    int computerHand[26], playerHand[26];

    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }

    shuffle(deck);

    computerHand[0] = deck[0];
    computerHand[1] = deck[1];
    playerHand[0] = deck[2];
    playerHand[1] = deck[3];

    computerPoints = pointCard(computerHand[0]) + pointCard(computerHand[1]);
    playerPoints = pointCard(playerHand[0]) + pointCard(playerHand[1]);

    if (pointCard(computerHand[0]) == 11) computerAceCount++;
    if (pointCard(computerHand[1]) == 11) computerAceCount++;
    if (pointCard(playerHand[0]) == 11) playerAceCount++;
    if (pointCard(playerHand[1]) == 11) playerAceCount++;

    playerPoints = adjustForAces(playerPoints, playerAceCount);

    printf("\tThe Computer's Hand:\n\n");
    printCard(computerHand[0]);
    printf("\tThe Computer's visible card has %d points\n\n\n", pointCard(computerHand[0]));

    // Check for computer blackjack
    if ((pointCard(computerHand[0]) == 10 && pointCard(computerHand[1]) == 11) || 
        (pointCard(computerHand[0]) == 11 && pointCard(computerHand[1]) == 10)) {
        printf("Computer has Blackjack! You lose!\n");
        endGameMenu(3, -1);
        return;
    }

    printf("\tThe Player's Hand:\n\n");
    printCard(playerHand[0]);
    printCard(playerHand[1]);
    printf("\tThe Player has %d points\n\n\n", playerPoints);

    while (playerPoints <= 21) {
        printf("\tDo you want to Hit or Stand?\n");
        printf("\t1 for Hit, 2 for Stand\n");
        choice = getChoice(1, 2);

        if (choice == 1) {
            playerHand[i + 2] = deck[i + 4];
            int newCard = pointCard(playerHand[i + 2]);
            if (newCard == 11) playerAceCount++;

            playerPoints += newCard;
            playerPoints = adjustForAces(playerPoints, playerAceCount);

            printf("\tThe Card you got is:\n");
            printCard(playerHand[i + 2]);
            printf("\tThe Player has %d points\n\n\n", playerPoints);

            if (playerPoints > 21) {
                printf("You Bust!\n");
                endGameMenu(3, -1);
                return;
            }

        } else {
            break;
        }
        i++;
    }

    printf("\tThe Computer's Hidden Card was:\n");
    printCard(computerHand[1]);
    printf("\tThe Computer has %d points\n\n\n", computerPoints);

    while (computerPoints < 17) {
        computerHand[i + 2] = deck[i + 26];
        int newCard = pointCard(computerHand[i + 2]);
        if (newCard == 11) computerAceCount++;

        computerPoints += newCard;
        computerPoints = adjustForAces(computerPoints, computerAceCount);

        printf("\tThe Computer chooses to Hit\n");
        printCard(computerHand[i + 2]);
        printf("\tThe Computer has %d points\n\n\n", computerPoints);

        if (computerPoints > 21) {
            printf("Computer Busts! You win!\n");
            endGameMenu(3, 1);
            return;
        }
        i++;
    }

    if (computerPoints > playerPoints) {
        printf("The Computer has more points than you!\n");
        endGameMenu(3, -1);
    } else if (computerPoints == playerPoints) {
        printf("It's a draw!\n");
        endGameMenu(3, 0);
    } else {
        printf("You win!\n");
        endGameMenu(3, 1);
    }
}

#pragma endregion
