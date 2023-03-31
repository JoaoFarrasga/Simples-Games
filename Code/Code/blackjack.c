#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "code.h"

#pragma endregion

#pragma region Code

char* symbol[] = { "♠", "♡", "♢", "♣" };

/**
 * @brief Point Card give the Points that one Card Is.
 * 
 * @param [in] Card The Card that is needed the Points
 * @param [out] Points The Points that the Card given Are
 */
int pointCard(int card) {
	int points;

	switch (card % 13)
	{
	case 0:
		points = 1;
		break;
	case 1:
		points = 2;
		break;
	case 2:
		points = 3;
		break;
	case 3:
		points = 4;
		break;
	case 4:
		points = 5;
		break;
	case 5:
		points = 6;
		break;
	case 6:
		points = 7;
		break;
	case 7:
		points = 8;
		break;
	case 8:
		points = 9;
		break;
	case 9:
	case 10:
	case 11:
	case 12:
		points = 10;
		break;
	}

	return points;
}

/**
 * @brief Picture Cards Prints the Card given to the Function
 * 
 * @param [in] Card The Card to Print
 * @param [out] Nothing
 */
void pictureCard(int card) {

	int suit, number;

	suit = card / 13 + 3;
	number = card % 13;

	switch (card % 13) {
	    case 0:
		    printf("*******\n");
		    printf("*     *\n");
		    printf("* %c   *\n", symbol[suit] );
		    printf("*   A *\n");
		    printf("*     *\n");
		    printf("*******\n");
		    break;

	    case 1:
	    case 2:
	    case 3:
	    case 4:
	    case 5:
	    case 6:
	    case 7:
	    case 8:
	    case 9:
            printf("*******\n");
            printf("*     *\n");
            printf("* %c   *\n", symbol[suit] );
            printf("*  %2d *\n", number + 1 );
            printf("*     *\n");
            printf("*******\n");
            break;

        case 10:
            printf("*******\n");
            printf("*     *\n");
            printf("* %c   *\n", symbol[suit] );
            printf("*   J *\n");
            printf("*     *\n");
            printf("*******\n");
            break;

        case 11:
            printf("*******\n");
            printf("*     *\n");
            printf("* %c   *\n", symbol[suit] );
            printf("*   Q *\n");
            printf("*     *\n");
            printf("*******\n");
            break;
            
        case 12:
            printf("*******\n");
            printf("*     *\n");
            printf("* %c   *\n", symbol[suit] );
            printf("*   K *\n");
            printf("*     *\n");
            printf("*******\n");
            break;

	}

}

/**
 * @brief Shuffle Cards is the Function that Shuffles the Cards
 * 
 * @param [in] Deck This are the 53 cards to be Shuffled 
 * @param [out] Deck The Deck already Shuffled
 */
int shuffleCards(int card[]) {

    int random;

    for (int i = 0; i < 52; i++) {

        random = randomInt(0, 52);

        int temp = card[i];
        card[i] = card[random];
        card [random] = temp;

    }

    return card;

}

/**
 * @brief Black Jack is the Function that Calls the Game
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void blackjack() {

    int playerPoints, computerPoints;
    int cards[53] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51 };
	int computerCards[52] = { 0 }, playerCards[52] = { 0 };

    printf("\t\tWelcome to Black Jack \n\n");

    getch();

    shuffleCards(cards);

    playerCards[0] = cards[0];
    playerCards[1] = cards[1];
    computerCards[0] = cards[2];
    computerCards[1] = cards[3];

    playerPoints = pointCard(playerCards[0] + playerCards[1]);
    computerPoints = pointCard(computerCards[0]);

    printf("\nThe Computer Card is: \n\n");
    pictureCard(computerCards[0]);
    printf("\n\nThe Computer Points are: %d\n\n", computerPoints);

    printf("\nThe Player Cards are: \n\n");
    pictureCard(playerCards[0]);
    pictureCard(playerCards[1]);
    printf("\n\nThe Player Points are: %d\n\n", playerPoints);

    for (int i = 0; i < 5; i++) {

        printf("\t\t What is your Choice \n\n"
               "\t Enter 1 - Hit\n"
               "\t Enter 2 - Stand\n");
        int choice = getChoice(1, 2);

        if (choice == 1) {

            playerCards[i + 2] = cards[i + 4];
            playerPoints += pointCard(playerCards[i + 2]);

            printf("\nThe Card you got is: ");
            pictureCard(playerCards[i + 2]);

            if (playerPoints > 21) {

                printf("\n\nYou Bust with %d Points\n", playerPoints);
                
                return;

            }

            printf("\nThe Points you have now are %d", playerPoints);

        } else {

            printf("\nThe Points you end of are: %d", playerPoints);
            break;

        }

    }

    printf("\nThe Computer Cards are: \n\n");
    pictureCard(computerCards[0]);
    pictureCard(computerCards[1]);
    printf("\n\nThe Computer Points are: %d\n\n", computerPoints);

    for (int i = 0; i < 5; i++) {

        while (computerPoints <= playerPoints) {

            computerCards[i + 2] = cards[i + 26];
            computerPoints += pointCard(computerCards[i + 2]);

            printf("\nThe Card that the Computer got is: ");
            pictureCard(computerCards[i + 2]);

            if (computerPoints > 21) {

                printf("\n\nComputer Bust with %d Points\n", computerPoints);
                
                return;

            }

            printf("\nThe Computer Points are: %d", computerPoints);

        }

    }

    if (computerPoints > playerPoints) {

        printf("\n\nThe Computer Won!\n\n");

        return;

    } else {

        printf("\n\nYou Won!\n\n");

        return;

    }

}

#pragma endregion