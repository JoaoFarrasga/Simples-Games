#pragma region Includes

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "code.h"

#pragma endregion

#pragma region Code

char boardConnectFour[6][7];

/**
 * @brief Clears the Board After the Game or in the Begining of it
 * 
 * @param [in] Nothing
 * @param [out] Nothing
*/
void clearBoardConnectFour() {

    for (int i = 0; i < 6; i++) {

        for (int j = 0; j < 7; j++) {

            boardConnectFour[i][j] = ' ';

        }

    }

}

/**
 * @brief Prints the Board with the Changes made
 * 
 * @param [in] Nothing
 * @param [out] Nothing
*/
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

/**
 * @brief Makes the Move in the Board
 * 
 * @param [in] Player The Player that will make the Move
 * @param [in] Column The Column of the Move
 * @param [out] Boolean 1 if the Function made the Move, 0 otherwise
*/
int makeMove(int player, int col) {

    char mark = (player == 1) ? 'X' : 'O';

    col--;

    for (int row = 5; row >= 0; row--) {

        if (boardConnectFour[row][col] == ' ') {
            
            boardConnectFour[row][col] = mark;
            return 1;

        }

    }

    return 0;

}

/**
 * @brief Checks if the Player has won the Game, or if the Board is Full
 * 
 * @param [in] Player The Player to check if he has won the Game
 * @return Number 2 if the Board is Full, 1 if the Player has won the Game, 0 otherwise
*/
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

/**
 * @brief The main Function of the Connect Four Game
 * 
 * @param [in] Nothing
 * @param [out] Nothing
*/
void connectfour() {

    int win, player = randomInt(1, 2), choice;

    clearBoardConnectFour();

	printf("\t\t Welcome to Connect \n\n"
           "\t Enter 1 - Player vs Player\n"
           "\t Enter 2 - Player vs Computer\n"
		   "\n\t Enter 0 - Back\n");

	choice = getChoice(0, 2);
	switch (choice) {

		case 1:
			playerVSplayerConnectFour();
			break;

		case 2:
			selectDifficultyConnectFour();
			break;

		case 0:
			mainMenu();
			break;

	}

}

/**
 * @brief Selects difficulty for playing against the computer
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void selectDifficultyConnectFour() {
    int choice;

    printf("\t\t Choose Difficulty Level \n\n"
           "\t Enter 1 - Easy (Random Moves)\n"
           "\t Enter 2 - Hard (Better AI)\n"
		   "\n\t Enter 0 - Back\n");

	choice = getChoice(0, 2);
	switch (choice) {

		case 1:
			playerVScomputerConnectFour(0);  // Easy
			break;

		case 2:
			playerVScomputerConnectFour(1);  // Hard
			break;

		case 0:
			connectfour();
			break;

	}
}

/**
 * @brief Player vs Player Connect Four Game
 * 
 * @param [in] Nothing
 * @param [out] Nothing
*/
void playerVSplayerConnectFour() {

    int win = 0, player = randomInt(1, 2);

    printBoardConnectFour();

    do {

        if (player == 1) {

            player = 2;

        } else {

            player = 1;

        }

        printf("\n   Player %d is your Turn\n", player);

        int choice = getChoice(1, 7);
        
        while (makeMove(player, choice) != 1) {
            printBoardConnectFour();
            printf("\n   Player %d is your Turn\n", player);
            printf("\n   Invalid Move\n\n");
            int choice = getChoice(1, 7);
        }
        
        printBoardConnectFour();
        
        win = checkWinConnectFour(player);

    } while (win == 0);

    if (win == 2) {
        printf("\n   The board is Full\n\n");
        endGameMenu(6, 0);
    } else {
        printf("\n   The Player %d won\n\n", player);
        endGameMenuDouble(6, 4, -4, player, player == 1 ? 2 : 1);
    }

}

/**
 * @brief Player vs Computer Connect Four Game
 * 
 * @param [in] Int The difficulty of the game
 * @param [out] Nothing
*/
void playerVScomputerConnectFour(int difficulty) {

    int win = 0, player = randomInt(1, 2);

    printBoardConnectFour();

    do {

        player = player == 1 ? 2 : 1;

        if (player == 1) {

            printf("\n   Player is your Turn\n", player);

            int choice = getChoice(1, 7);
            makeMove(player, choice);
        
            printBoardConnectFour();
        
            win = checkWinConnectFour(player);

        } else {

            int choice = 0;

            if (difficulty == 0) {
                int choice = randomInt(1, 7);
                makeMove(player, choice);
            } else {
                int choice = bestMoveConnectFour(player, player == 1 ? 2 : 1);
                makeMove(player, choice);
            }

            printf("\n   Computer Played %d\n", choice);

            printBoardConnectFour();

            win = checkWinConnectFour(player);

        }

    } while (win == 0);

    if (win == 2) {

        printf("\n   The board is Full\n\n");
        endGameMenu(6, 0);

    } else {

        if (player == 1) {

            printf("\n   The Player won\n\n");
            endGameMenu(6, 4);

        } else {

            printf("\n   The Computer lost\n\n");
            endGameMenu(6, -4);

        }

    }

}

/**
 * @brief Returns the best column for the computer to play in Connect Four
 * 
 * @param [in] Computer The number of the computer player (1 or 2)
 * @param [in] Opponent The number of the opponent player (1 or 2)
 * @return index (1-7)
 */
int bestMoveConnectFour(int computer, int opponent) {
    printf("tryng to find best move");

    // If the computer as a winning move
    for (int col = 1; col <= 7; col++) {
        char backup[6][7];
        memcpy(backup, boardConnectFour, sizeof(boardConnectFour));

        if (makeMove(computer, col)) {
            if (checkWinConnectFour(computer) == 1) {
                memcpy(boardConnectFour, backup, sizeof(boardConnectFour));
                return col;
            }
        }

        memcpy(boardConnectFour, backup, sizeof(boardConnectFour));
    }

    printf("No winning Moves");

    // If the player as a winning move, it blocks it
    for (int col = 1; col <= 7; col++) {
        char backup[6][7];
        memcpy(backup, boardConnectFour, sizeof(boardConnectFour));

        if (makeMove(opponent, col)) {
            if (checkWinConnectFour(opponent) == 1) {
                memcpy(boardConnectFour, backup, sizeof(boardConnectFour));
                return col;
            }
        }

        memcpy(boardConnectFour, backup, sizeof(boardConnectFour));
    }

        printf("Player has no winning Moves");

    // Play in the middle as much as possible
    if (boardConnectFour[0][3] == ' ') {
        return 4; // Collumn of the middle
    }

        printf("Middle is not open");


    // Prefer the collumn next to the middle as possible
    int preferredOrder[7] = {4, 3, 5, 2, 6, 1, 7};
    for (int i = 0; i < 7; i++) {
        if (boardConnectFour[0][preferredOrder[i] - 1] == ' ') {
            return preferredOrder[i];
        }
    } 

        printf("No preferred moves");

    // If everything fails gives a random (safe fail)
    int col;
    do {
        col = randomInt(1, 7);
    } while ( boardConnectFour[0][col - 1] != ' ');

    return col;
}

#pragma endregion