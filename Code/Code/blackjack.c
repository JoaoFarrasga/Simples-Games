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

        return 10;

    } else {

        return value;

    }

}

/**
 * @brief The Game BlackJack
 * 
 * @param [in] Nothing
 * @param [out] Nothing
*/
void blackjack() {

    int computerPoints, playerPoints, choice;
    int i = 0;
    int deck[52];
    int computerHand[26], playerHand[26];

    for (int i = 0; i < 52; i++) {

        deck[i] = i;

    }

    shuffle(deck);

    computerHand[0] = deck[0];

    playerHand[0] = deck[1];
    playerHand[1] = deck[2];

    computerPoints = pointCard(computerHand[0]);
    playerPoints = pointCard(playerHand[0]) + pointCard(playerHand[1]);

    printf("\tThe Computer Hand:\n\n");
    printCard(computerHand[0]);
    printf("\tThe Computer has %d Points\n\n\n", computerPoints);

    printf("\tThe Player Hand:\n\n");
    printCard(playerHand[0]);
    printCard(playerHand[1]);
    printf("\tThe Player has %d Points\n\n\n", playerPoints);

    while(playerPoints <= 21) {

        printf("\tYou want to Hit or Stand\n");
        printf("\t 1 for Hit, 2 for Stand\n");
        choice = getChoice(1, 2);

        if (choice == 1) {

            playerHand[i + 2] = deck[i + 3];
            playerPoints += pointCard(playerHand[i + 2]);

            printf("\tThe Card you got is: \n");
            printCard(playerHand[i + 2]);
            printf("\tThe Player has %d Points\n\n\n", playerPoints);

        } else {

            break;

        }

        if (playerPoints > 21) {

            printf("You Bust!");
            endGameMenu(3, -1);

        }

        i++;

    }

    while (computerPoints < playerPoints) {

        computerHand[i + 1] = deck[i + 26];
        computerPoints += pointCard(computerHand[i + 1]);

        printf("\tThe Computer Choose Hit\n");
        printCard(computerHand[i + 1]);
        printf("\tThe Computer has %d Points\n\n\n", computerPoints);

        if (computerPoints > 21) {

            printf("Computer Bust!");
            endGameMenu(3, 1);

        }

        i++;

    }

    if (computerPoints > playerPoints) {

        printf("The Computer has more points than you!");
	    endGameMenu(3, -1);

    } else {

        printf("You Won");
        endGameMenu(3, 1);

    }

}

#pragma endregion