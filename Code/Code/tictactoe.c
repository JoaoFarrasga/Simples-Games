#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "code.h"

#pragma endregion

#pragma region Code

char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

/**
 * @brief Starts the game Tic Tac Toe
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void tictactoe() {

	int choice;

	resetBoard();

	printf("\t\t Welcome to Tic Tac Toe \n\n"
           "\t Enter 1 - Player vs Player\n"
           "\t Enter 2 - Player vs Computer\n"
		   "\n\t Enter 0 - Back\n");

	choice = getChoice(0, 2);
	switch (choice) {

		case 1:
			playerVSplayer();
			break;

		case 2:
			selectDifficulty();
			break;

		case 0:
			mainMenu();
			break;

	}

}

/**
 * @brief Resets the Board making it Playable Again
 * 
 * @param [in] Nothing
 * @param [out] Nothing
*/
void resetBoard() {

    for (int i = 0; i < 9; i++) {

        if (board[i] != i + '1') {

			board[i] = i + '1';

        }
    }

}

/**
 * @brief Prints the Board to play
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void printBoard() {

	printf("\t Tic Tac Toe \n\n");

	printf("           |     |     \n");
	printf("        %c  |  %c  |  %c \n", board[0], board[1], board[2]);
	printf("      _____|_____|_____\n");
	printf("           |     |     \n");
	printf("        %c  |  %c  |  %c \n", board[3], board[4], board[5]);
	printf("      _____|_____|_____\n");
	printf("           |     |     \n");
	printf("        %c  |  %c  |  %c \n", board[6], board[7], board[8]);
	printf("           |     |     \n\n");

}

/**
 * @brief Checks if anyone was won the game of if the Board is Full
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
int checkWin() {

    if (board[0] == board[1] && board[1] == board[2]) {
		return 1;

	} else if (board[3] == board[4] && board[4] == board[5]) {
		return 1;

	} else if (board[6] == board[7] && board[7] == board[8]) {
		return 1;

	} else if (board[0] == board[3] && board[3] == board[6]) {
		return 1;

	} else if (board[1] == board[4] && board[4] == board[7]) {
		return 1;

	} else if (board[2] == board[5] && board[5] == board[8]) {
		return 1;

	} else if (board[0] == board[4] && board[4] == board[8]) {
		return 1;

	} else if (board[2] == board[4] && board[4] == board[6]) {
		return 1;

	} else if (board[0] != '1' && board[1] != '2' && board[2] != '3' && board[3] != '4' && board[4] != '5' && board[5] != '6' && board[6] != '7' && board[7] != '8' && board[8] != '9') {
		return 0;
	}
	else
	{
		return -1;
	}
}

/**
 * @brief Starts the game Player vs Player
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void playerVSplayer() {

	int win = -1, player, choice;
	char mark;

	player = randomInt(1, 2);

	do {

		player = (player % 2) ? 1 : 2;

		printBoard();

		printf("Player Number %d Play your Move\n", player);
		choice = getChoice(1, 9);

	    mark = (player == 1) ? 'X' : 'O';

		if (choice == 1 && board[0] == '1') {
        	board[0] = mark;

		} else if (choice == 2 && board[1] == '2') {
			board[1] = mark;

		} else if (choice == 3 && board[2] == '3') {
			board[2] = mark;

		} else if (choice == 4 && board[3] == '4') {
			board[3] = mark;

		} else if (choice == 5 && board[4] == '5') {
			board[4] = mark;

		} else if (choice == 6 && board[5] == '6') {
			board[5] = mark;

		} else if (choice == 7 && board[6] == '7') {
			board[6] = mark;

		} else if (choice == 8 && board[7] == '8') {
			board[7] = mark;

		} else if (choice == 9 && board[8] == '9') {
			board[8] = mark;

		} else {
			printf("\n\t//Invalid Option//\n\n");
			player--;
		}

		win = checkWin();
		player++;

	} while (win == -1);

	printBoard();

	if (win == 1) {
		printf("\n\tPlayer %d you Won\n\n", --player);
	} else {
		printf("\n\tGame Draw\n\n");
	}

}

/**
 * @brief Selects difficulty for playing against the computer
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void selectDifficulty() {
    int choice;

    printf("\t\t Choose Difficulty Level \n\n"
           "\t Enter 1 - Easy (Random Moves)\n"
           "\t Enter 2 - Hard (Minimax AI)\n"
		   "\n\t Enter 0 - Back\n");

	choice = getChoice(0, 2);
	switch (choice) {

		case 1:
			playerVScomputer(0);  // Easy
			break;

		case 2:
			playerVScomputer(1);  // Hard
			break;

		case 0:
			tictactoe();
			break;

	}
}

/**
 * @brief Starts the game Player vs Computer
 * 
 * @param [in] int difficulty (0 for Easy, 1 for Hard)
 * @param [out] Nothing
 */
void playerVScomputer(int difficulty) {
    int win = -1, player, choice;
    char mark;

    player = randomInt(1, 2);

    do {
        player = (player % 2) ? 1 : 2;

        if (player == 1) {
            printBoard();
            printf("Player Play your Move\n", player);
            choice = getChoice(1, 9);
            mark = 'X';

            if (board[choice - 1] != 'X' && board[choice - 1] != 'O') {
                board[choice - 1] = mark;
            } else {
                printf("\n\t//Invalid Option//\n\n");
                player--;
            }
        } else {
            int bestMove;
            if (difficulty == 1) {
                bestMove = findBestMove();  // Hard (Minimax AI)
            } else {
                do {
                    bestMove = randomInt(0, 8);  // Easy (Random Move)
                } while (board[bestMove] == 'X' || board[bestMove] == 'O');
            }
            board[bestMove] = 'O';
        }

        win = checkWin();
        player++;
    } while (win == -1);

    printBoard();

    if (win == 1) {
        if (--player == 1) {
            printf("The Player Won");
            endGameMenu(4, 1);
        } else {
            printf("The Computer Won");
            endGameMenu(4, -1);
        }
    } 
    else if (win == 0) {
        printf("\n\tGame Draw\n\n");
        endGameMenu(4, 0);
    }
}

/**
 * @brief Evaluates the Board
 *  
 * @param [out] int Evaluation of the Board
 */
int evaluateBoard() {
    // Check for all possible winning lines for 'X' or 'O'
    if ((board[0] == board[1] && board[1] == board[2]) ||
        (board[0] == board[3] && board[3] == board[6]) ||
        (board[0] == board[4] && board[4] == board[8])) {
        if (board[0] == 'X') return +10;
        else if (board[0] == 'O') return -10;
    }
    if ((board[3] == board[4] && board[4] == board[5]) ||
        (board[1] == board[4] && board[4] == board[7]) ||
        (board[2] == board[4] && board[4] == board[6])) {
        if (board[4] == 'X') return +10;
        else if (board[4] == 'O') return -10;
    }
    if ((board[6] == board[7] && board[7] == board[8]) ||
        (board[2] == board[5] && board[5] == board[8])) {
        if (board[8] == 'X') return +10;
        else if (board[8] == 'O') return -10;
    }

    // If no one has won, return 0
    return 0;
}

/**
 * @brief The AI for the TicTacToe Bot using Minimax Theorem
 * 
 * @param [in] depth The depth of the Minimax
 * @param [in] isMaximizing If is Maximizing
 * @param [out] int The result of the Minimax
 */
int minimax(int depth, int isMaximizing) {
    int score = evaluateBoard();

    // If Maximizer has won the game, return the evaluated score
    if (score == 10) return score - depth;

    // If Minimizer has won the game, return the evaluated score
    if (score == -10) return score + depth;

    // If there are no more moves and no winner, it's a draw
    if (checkWin() == 0) return 0;

    if (isMaximizing) {
        int best = -1000;

        for (int i = 0; i < 9; i++) {
            if (board[i] != 'X' && board[i] != 'O') {
                char backup = board[i];
                board[i] = 'X';  // Simulate the player's move (Maximizer)

                int moveVal = minimax(depth + 1, 0);
                best = getMax(best, moveVal);

                board[i] = backup;

                // Prioritize winning moves
                if (best == 10 - depth) return best;
            }
        }
        return best;
    } else {
        int best = 1000;

        for (int i = 0; i < 9; i++) {
            if (board[i] != 'X' && board[i] != 'O') {
                char backup = board[i];
                board[i] = 'O';  // Simulate AI's move (Minimizer)

                int moveVal = minimax(depth + 1, 1);
                best = getMin(best, moveVal);

                board[i] = backup;

                // Prioritize winning moves
                if (best == -10 + depth) return best;
            }
        }
        return best;
    }
}

/**
 * @brief Finds the Best Move for the Minimax AI
 * 
 * @param [out] int The Best Move
 */
int findBestMove() {
    int bestVal = 1000;  // Minimizer seeks the smallest value
    int bestMove = -1;

    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            char backup = board[i];
            board[i] = 'O';  // AI's move

            int moveVal = minimax(0, 1);  // Call minimax for the minimizing player

            board[i] = backup;

            if (moveVal < bestVal) {  // For minimizing, find the smallest value
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }
    return bestMove;
}


#pragma endregion