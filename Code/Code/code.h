#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#pragma endregion

#pragma region Structs

typedef struct Scoreboard {
    char name[4];
    int score;
    struct Scoreboard *next;
} Scoreboard;

typedef struct Game {
    int game;
    Scoreboard *scoreboard;
    struct Game *next;
} Game;

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

void ScoreboardRead();
void ScoreboardWrite();
Game* GameAdd(int numberGame);
void GameInsert(Game* newGame);
Scoreboard* ScoreboardAdd(char* name, int score);
void ScoreboardInsert(Game* game, Scoreboard* newScoreboard);
void ScoreboardPrint(int numberGame);
int ScoreExists(int numberGame, char* name);
void ScoreGameAdd(int numberGame, char* name, int score);
int GiveScoreGlobal(char* name);
void ScoreGlobalReadInitial();

#pragma endregion

#pragma region Global Score

void ScoreGlobalRead(Game* header);
int GlobalExists(char* name);
ScoreGlobal* GlobalAdd(char* name, int scoreGlobal);
void GlobalInsert(ScoreGlobal* newScoreGlobal);
void GlobalPrint();
void GlobalPrintOne();

#pragma endregion

#pragma region Extra Functions

int getChoice(int min, int max);
int randomInt(int min, int max);
char* getName();

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

#pragma region HangMan

char* RandomWord(char* words[], int length);
int IsLetterInWord(char* word, char letter);
int IsWordCorrect(char* word, char letters[]);
void DisplayWord(char* word, char letters[]);
void HangMan();

#pragma endregion

#pragma region FourInARow

void clearBoardConnectFour();
void printBoardConnectFour();
int makeMove(int player, int col);
int checkWinConnectFour(int player);
void connectfour();
void playerVSplayerConnectFour();
void playerVScomputerConnectFour();

#pragma endregion

#pragma region MasterMind

char** computerSymbols();
char** playerSymbols();
int checkSymbols(char** playerSymbols, char** computerSymbols);
void masterMind();

#pragma endregion

#pragma endregion