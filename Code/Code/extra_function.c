#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "code.h"

#pragma endregion

#pragma region Extra Functions

//GetChoice is a function to get the number between the numbers given
int getChoice(int min, int max) {

    int choiceInt = -1;

    printf("\n Select - ");
    scanf(" %d", &choiceInt);
    
    while (choiceInt > max || choiceInt < min) {
        printf("\n\t//Invalid Option//\n\n");
        printf("\n Select - ");
        scanf(" %d", &choiceInt);
    }

    system("cls");
    return choiceInt;
}

//randomInt is a Function to get a random number in a set of numbers given
int randomInt(int min, int max) {

    srand((unsigned)time(NULL));
    return min + rand() % (max - min);

}

#pragma endregion