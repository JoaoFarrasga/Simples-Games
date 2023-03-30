#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
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

char* getChar() {

    int valid = 0;
    char input[4];

    while (!valid) {

        printf("What is your Name? \n");
        printf("\n Select - ");
        scanf(" %s", input);

        if (strlen(input) == 3) {

            valid = 1;
        
        } else {

            printf("Invalid name. Please enter a 3-character string.\n");
        
        }

        char* output = malloc(4 * sizeof(char));
        strncpy(output, input, 3);
        output[3] = '\0';

        return output;

    }

}

#pragma endregion