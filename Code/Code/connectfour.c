#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "code.h"

#pragma endregion

#pragma region Code

char boardConnectFour[6][7];

void clearBoardConnectFour() {

    for (int i = 0; i < 6; i++) {

        for (int j = 0; j < 7; j++) {

            boardConnectFour[i][j] = '_';

        }

    }

}

void printBoardConnectFour() {

    printf("\n");

    for (int i = 0; i < 6; i++) {

        for (int j = 0; j < 7; j++) {

            printf("| %c ", boardConnectFour[i][j]);

        }

        printf("|\n");

    }

    printf("\n");

}

void connectfour() {

    printf("     Welcome to Connect Four\n");

    clearBoardConnectFour();
    printBoardConnectFour();

}

#pragma endregion