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

            boardConnectFour[i][j] = ' ';

        }

    }

}

void printBoardConnectFour() {

    printf("\n|---|---|---|---|---|---|---|\n");

    for (int i = 0; i < 6; i++) {

        for (int j = 0; j < 7; j++) {

            printf("| %c ", boardConnectFour[i][j]);

        }

        printf("|\n");
        printf("|---|---|---|---|---|---|---|\n");

    }

    printf("\n");

}

void makeMove(int player, int col) {

    char mark = (player == 1) ? 'X' : 'O';

    col--;

    for (int row = 6; row >= 0; row--) {

        if (boardConnectFour[row][col] == ' ') {
            
            boardConnectFour[row][col] = mark;
            break;

        }

    }

}

int checkWinConnectFour(int player) {

    char mark = (player == 1) ? 'X' : 'O';
    int count;

    // Check if Win per Row
    for (int row = 0; row < 6; row++) {

        count = 0;

        for (int col = 0; col < 7; col++) {

            if (boardConnectFour[row][col] == mark) {

                count++;

                if (count == 4) return 1;

            } else {

                count = 0;

            }

        }

    }

    // Check if Win per Col
    for (int col = 0; col < 7; col++) {

        count = 0;

        for (int row = 0; row < 6; row++) {

            if (boardConnectFour[row][col] == mark) {

                count++;

                if (count == 4) return 1;

            } else {

                count = 0;

            }

        }

    }

    // Checks if Win Diagonals
    for (int row = 0; row <= 2; row++) {

        for (int col = 0; col <= 3; col++) {

            if (boardConnectFour[row][col] == mark &&
                boardConnectFour[row + 1][col + 1] == mark &&
                boardConnectFour[row + 2][col + 2] == mark &&
                boardConnectFour[row + 3][col + 3] == mark) {

                return 1;

            }

            if (boardConnectFour[row][col + 3] == mark &&
                boardConnectFour[row + 1][col + 2] == mark &&
                boardConnectFour[row + 2][col + 1] == mark &&
                boardConnectFour[row + 3][col] == mark) {

                return 1;

            }

        }

    }

    // Check if Board is not Full
    for (int row = 0; row < 6; row++) {

        for (int col = 0; col < 7; col++) {

            if (boardConnectFour[row][col] == ' ') {

                return 0;

            }

        }

    }

    // If Board Full
    return 2;

}

void connectfour() {

    int win, player = randomInt(1, 2);

    printf("   Welcome to Connect Four\n");

    clearBoardConnectFour();
    printBoardConnectFour();

    do {

        if (player == 1) {

            player = 2;

        } else {

            player = 1;

        }

        printf("\n   Player %d is your Turn\n", player);

        int choice = getChoice(1, 7);
        makeMove(player, choice);
        
        printBoardConnectFour();
        
        win = checkWinConnectFour(player);

    } while (win == 0);

    printf("The Player %d won\n\n", player);

}

#pragma endregion