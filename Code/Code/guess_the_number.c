#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "code.h"

#pragma endregion

#pragma region Code

/**
 * @brief Starts the game Guess Number
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void guessNumber() {

    int random, tries = 0, guess, points;

    random = randomInt(0, 100);

    printf("\t\t Guess the Number \n");
    guess = getChoice(0, 100);

    while (guess != random) {

        tries++;

        printf("\t\t Guess the Number \n");
        if (random > guess)
        {
            printf("\n\t The Number is Higher than %d \n\n", guess);
        }
        else if (random < guess)
        {
            printf("\n\t The Number is Lower than %d \n\n", guess);
        }
        guess = getChoice(0, 100);

    }

    points = 10 - tries;

    if (points < 0)
    {
        points = 0;
    }

    printf("\t\t Guess the Number \n");
    printf("\n\t %d is Correct \n", guess);
    printf("\n\t %d points \n", points);

    getch();
    system("cls");

    endGameMenu(1, points);
}

#pragma endregion