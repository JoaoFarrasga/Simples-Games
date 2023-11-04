#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "code.h"

#pragma endregion

#pragma region Code

/**
 * @brief Computer Symbols is the function that generates the Symbols for the MasterMind.
 * 
 * @param [in] Nothing
 * @param [out] Nothing
*/
char** computerSymbols() {

    char* symbols[4] = {"Red", "Green", "Blue", "Yellow"};
    char** result = (char**)malloc(4 * sizeof(char*));

    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        int randomNumber = rand() % (4);
        result[i] = symbols[randomNumber];
    }

    return result;

}

/**
 * @brief Player Symbols is the function that aks the Symbols from the Player.
 * 
 * @param [in] Nothing
 * @param [out] Nothing
*/
char** playerSymbols() {

    char* symbols[4] = {"Red", "Green", "Blue", "Yellow"};
    char** guess = (char**)malloc(4 * sizeof(char*));   

    for (int i = 0; i < 4; i++) {
        printf("\n\n\t\tKnowing that Red = 1, Green = 2, Blue = 3 and Yellow = 4\n\n\t\tEnter your guess: \n");
        int choice = getChoice(1, 4);
        guess[i] = strdup(symbols[choice - 1]);
    }

    return guess;

}

/**
 * @brief Check Symbols is the function that checks the Symbols and sees if the game is Win or Lose.
 * 
 * @param [in] PlayerSymbos The Symbols of the Player.
 * @param [in] ComputerSymbos The Symbols of the Computer.
 * @param [out] Check If 1 the Player Wins if 2 the Player does not Win. 
*/
int checkSymbols(char** playerSymbols, char** computerSymbols) {

    int check = 0;

    for (int i = 0; i < 4; i++) {
        if (strcmp(playerSymbols[i], computerSymbols[i]) == 0) {
            printf("%s is Rigth\t\t", playerSymbols[i]);
            check++;
        } else {
            printf("%s is Wrong\t\t", playerSymbols[i]);
        }
    }

    printf("\n\n");
    return check == 4? 1 : 0;
}
/**
 * @brief MasterMind is the main function of the MasterMind.
 * 
 * @param [in] Nothing
 * @param [out] Nothing
*/
void masterMind() {

    char** symbolsComputer = computerSymbols();
    
    
    char** symbolsPlayer = playerSymbols();

    while (checkSymbols(symbolsPlayer, symbolsComputer) == 0) {
        symbolsPlayer = playerSymbols();
    }

    printf("\n\t\tYou Win");
}

#pragma endregion