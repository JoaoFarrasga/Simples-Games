#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#pragma endregion

#pragma region Structs

typedef struct Scoreboard {
    int game;
    char name[4];
    int score;
    struct Scoreboard *next;
} Scoreboard;

typedef struct ScoreGlobal {
    char name[4];
    int score;
    struct ScoreGlobal *next;
} ScoreGlobal;

#pragma endregion

#pragma region Function Signs

#pragma region Menus

void mainMenu();
void selectGame();
void scoreboardMenu();
void playAgainMenu(int numberGame);
void endGameMenu(int numberGame, int points);
void globalScoreMenu();

#pragma endregion

#pragma region Scoreboard

void scoreboardRead();
void scoreboardWrite();
void scoreboardPrint(int numberGame);
Scoreboard* scoreboardAdd(int numberGame, char* gamerName, int gamerScore);
void scoreboardInsert(Scoreboard* newScoreboard);
void scoreboardReversed();
void scoreGameAdd(int numberGame, char* gamerName, int gamerScore);
int scoreGlobal(char* gamerName);
void scoreGlobalRead();

#pragma endregion

#pragma region Global Score

void globalRead(Scoreboard* header);
void globalPrint();
void globalPrintOne();
ScoreGlobal* globalAdd(char* gamerName, int globalScore);
int scoreExists(int numberGame, char* gamerName);
void globalInsert(ScoreGlobal* newGlobal);
void globalReversed();
int globalExists(char* gamerName);

#pragma endregion

#pragma region Extra Functions

int getChoice(int min, int max);
int randomInt(int min, int max);
char* getName();
char* capitalize(char name[4]);

#pragma endregion

#pragma region Guess the Number

void guessNumber();

#pragma endregion

#pragma region Guess the Card

void guessCard();

#pragma endregion

#pragma region Black Jack

void shuffle(int* cards);
void printCard(int card);
int pointCard(int card);
void blackjack();

#pragma endregion

#pragma region TicTacToe

void tictactoe();
void resetBoard();
void printBoard();
int checkWin();
void playerVSplayer();
void playerVScomputer();

#pragma endregion

#pragma region FourInARow

void clearBoardConnectFour();
void printBoardConnectFour();
void makeMove(int player, int col);
int checkWinConnectFour(int player);
void connectfour();

#pragma endregion

#pragma endregion