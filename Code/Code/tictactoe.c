#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "code.h"

#pragma endregion

#pragma region Code

char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void tictactoe() {

	int choice;

	printf("\t\t Welcome to Tic Tac Toe \n"
           "\t Enter 1 - Player vs Player\n"
           "\t Enter 2 - Player vs Computer\n"
		   "\n\t Enter 0 - Back\n");

	choice = getChoice(0, 2);
	switch (choice) {

		case 1:
			playerVSplayer();
			break;

		case 2:
			playerVScomputer();
			break;

		case 0:
			mainMenu();
			break;

	}

}

void printBoard() {

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

void playerVSplayer() {

	int win = -1, player, choice;
	char mark;

	player = randomInt(1, 2);

	do {

		player = (player % 2) ? 1 : 2;

		printBoard();

		printf("Player Number %d Play your Move", player);
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
		printf("Player %d you Won", --player);
	} else {
		printf("Game Draw");
	}

}

void playerVScomputer() {

	int win = -1, player, choice;
	char mark;

	player = randomInt(1, 2);

	do {

		player = (player % 2) ? 1 : 2;

		if (player == 1) {

			printBoard();

			printf("Player Number %d Play your Move", player);
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

		} else {

			choice = randomInt(1, 9);

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
				player--;
			}

			win = checkWin();
			player++;

		}

	} while (win == -1);

	printBoard();

	if (win == 1) {
		printf("Player %d you Won", --player);
	} else {
		printf("Game Draw");
	}

}

#pragma endregion