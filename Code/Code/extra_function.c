#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "code.h"

#pragma endregion

#pragma region Extra Functions

/**
 * @brief GetChoice asks for a Int from the User
 * 
 * @param [in] Min A Minimum for the Choice
 * @param [in] Max A Maximum for the Choice
 * @param [out] Choice The Choice from the User
 */
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

/**
 * @brief RandomInt Gives a Random Int
 * 
 * @param [in] Min A Minimum for the Random Number
 * @param [in] Max A Maximum for the Random Number
 * @param [out] Random The Random Generated Number
 */
int randomInt(int min, int max) {

    srand((unsigned)time(NULL));
    return min + rand() % (max - min);

}

/**
 * @brief GetName asks for the Name from the User 
 * 
 * @param [in] Nothing
 * @param [out] Name Name of the User
 */
char* getName() {

    int valid = 0;
    char input[4];

    printf("\t\tWhat is your Name? \n");
    printf("\n Select - ");
    scanf(" %s", input);

    while (valid == 0) {

        if (strlen(input) == 3) {

            valid = 1;

        } else {

            printf("\n\nInvalid name. Please enter a 3-character name.\n");
            printf("\n Select - ");
            scanf(" %s", input);

        }

    }

    char* output = malloc(sizeof(char) * 4);

    for (int i = 0; i < 3; i++) {

        output[i] = toupper(input[i]);

    }

    output[3] = '\0';

    system("cls");
    return output;

}

int getMax(int a, int b) {
    return (a > b) ? a : b;
}

int getMin(int a, int b) {
    return (a < b) ? a : b;
}

#pragma endregion