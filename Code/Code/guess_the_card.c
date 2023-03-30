#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "code.h"

#pragma endregion

#pragma region Guess the Card

/**
 * @brief Starts the game Guess Card
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void guessCard() {

    int randomCard, randomSuit, randomNumb, tries = 0, guessSuit, guessNumb, points;

    enum Suit{ Hearts, Spades, Diamonds, Clubs };

    randomSuit = randomInt(1, 4);
    randomNumb = randomInt(1, 13);

    printf("\t\t Guess the Card \n");
    printf("\n\t Number of the Card: \n");
    guessNumb = getChoice(1, 13);

    printf("\t\t Suit of the Card: \n\n"
           "\tHearts = 1, Spades = 2, Diamonds = 3, Clubs = 4\n");
    guessSuit = getChoice(1, 4);


    while (guessSuit != randomSuit || guessNumb != randomNumb) {

        tries++;

        printf("\t\t Guess the Card \n");
        
        if (guessSuit != randomSuit && guessNumb != randomNumb) {
            
            if (randomNumb > guessNumb)
            {
                printf("\n\t The Number of the Card is Higher than %d \n", guessNumb);
            }
            else if (randomNumb < guessNumb)
            {
                printf("\n\t The Number of the Card is Lower than %d \n", guessNumb);
            }

            printf("\n\t The Suit of the Card is Wrong\n");

            printf("\n\t Number of the Card: \n");
            guessNumb = getChoice(1, 13);

            printf("\t\t Suit of the Card: \n");
            guessSuit = getChoice(1, 4);

        } else if (guessSuit == randomSuit && guessNumb != randomNumb) {

            if (randomNumb > guessNumb)
            {
                printf("\n\t The Number of the Card is Higher than %d \n", guessNumb);
            }
            else if (randomNumb < guessNumb)
            {
                printf("\n\t The Number of the Card is Lower than %d \n", guessNumb);
            }

            printf("\n\t The Suit of the Card is Right\n\n");

            printf("\t\t Number of the Card: \n");
            guessNumb = getChoice(1, 13);

        } else {

            printf("\n\t The Number of the Card is Right\n\n");

            printf("\n\t The Suit of the Card is Wrong\n\n");

            printf("\t\t Suit of the Card: \n");
            guessSuit = getChoice(1, 4);
        }

    }

    points = 6 - tries;

    if (points < 0)
    {
        points = 0;
    }

    printf("%d, %d", randomNumb, randomSuit);

    printf("\t\t Guess the Card \n");

    if (guessSuit == 1) {
        printf("\n\t The Card is %d of Hearts\n\n", guessNumb);
    } else if (guessSuit == 2) {
        printf("\n\t The Card is %d of Spades\n\n", guessNumb);
    } else if (guessSuit == 3) {
        printf("\n\t The Card is %d of Diamonds\n\n", guessNumb);
    } else {
        printf("\n\t The Card is %d of Clubs\n\n", guessNumb);
    }

    printf("\n\t %d points \n\n", points);

    getch();
    system("cls");

    endGameMenu(2, points);

}

#pragma endregion