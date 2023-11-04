#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "code.h"

#pragma endregion

#pragma region Code

#pragma region Menus

/**
 * @brief Starts the Main Menu Giving the Choices to the User
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void mainMenu() {

    ScoreboardWrite();

    printf("\t\t Main Menu \n\n"
           "\t Enter 1 - Select Game\n"
           "\t Enter 2 - Scoreboard\n"
           "\t Enter 3 - Global Score\n"
           "\n\t Enter 0 - Quit\n");

    int choice = getChoice(0, 3);
    switch (choice) {
        case 1:
            selectGame();
            break;
        
        case 2:
            scoreboardMenu();
            break;

        case 3:
            globalScoreMenu();
            break;

        case 0:
            printf("\n\tGoodbye\n\n");
            exit;
            break;
        
        default:
            printf("\n\t//Invalid Option//\n\n");
            mainMenu();
            break;
    }
}

/**
 * @brief SelectGame is the Menu that allows the User to Choose the Game
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void selectGame() {
    printf("\t\t Select Game \n\n"
           "\t Enter 1 - Guess the Number\n"
           "\t Enter 2 - Guess the Card\n"
           "\t Enter 3 - Black Jack\n"
           "\t Enter 4 - Tic Tac Toe\n"
           "\t Enter 5 - HangMan\n"
           "\t Enter 6 - Four In A Row\n"
           "\t Enter 7 - Drunk Tic Tac Toe *Not Working*\n"
           "\t Enter 8 - Master Mind\n"
           "\t Enter 9 - Mine Sweeper *Not Working*\n"
           "\n\t Enter 0 - Back\n");
    
    int choice = getChoice(0, 9);
    switch (choice)
    {
    case 1:
        guessNumber();
        break;

    case 2:
        guessCard();
        break;

    case 3:
        blackjack();
        break;

    case 4:
        tictactoe();
        break;

    case 5:
        HangMan();
        break;

    case 6:
        connectfour();
        break;

    case 8:
        masterMind();
        break;

    case 0:
        mainMenu();
        break;

    default:
        printf("\n\t//Invalid Option//\n\n");
        selectGame();
        break;
    }
}

/**
 * @brief Scoreboard Menu is the Menu that allows the User see the Scores
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void scoreboardMenu() {

    printf("\t\tScoreboard\n\n"
           "\t Enter 1 - Guess the Number\n"
           "\t Enter 2 - Guess the Card\n"
           "\t Enter 3 - Black Jack\n"
           "\t Enter 4 - Tic Tac Toe\n"
           "\t Enter 5 - Four In A Row\n"
           "\n\t Enter 0 - Back\n");

    int choice = getChoice(0, 5);
    switch (choice) {
        case 1:
            ScoreboardPrint(choice);
            break;
        
        case 2:
            ScoreboardPrint(choice);
            break;

        case 3:
            ScoreboardPrint(choice);
            break;

        case 4:
            ScoreboardPrint(choice);
            break;

        case 5:
            ScoreboardPrint(choice);
            break;

        case 0:
            mainMenu();
            break;
        
        default:
            printf("\n\t//Invalid Option//\n\n");
            scoreboardMenu();
            break;
    }

}

/**
 * @brief Play Again Menu is a Menu that Ask's if the User wants to play again
 * 
 * @param [in] Game The Number of the Game 
 */
void playAgainMenu(int numberGame) {

    system("cls");

    printf("\t\tDo you Wanna Play Again?\n\n"
           "\t Enter 1 - Play Again\n\n"
           "\t Enter 0 - Back\n");

    int choice = getChoice(0, 1);
    switch (choice)
    {
    case 1:

        switch (numberGame) {

        case 1:
            guessNumber();
            break;

        case 2:
            guessCard();
            break;

        case 3:
            blackjack();
            break;   

        case 4:
            tictactoe();
            break;

        case 5:
            connectfour();
            break;

        default:
            selectGame();
            break;

        }
    
    case 0:
        selectGame();
        break;

    default:
        selectGame();
        break;

    }
}

/**
 * @brief End Game Menu Ask's the Name and Inserts the Score in the Scoreboard 
 *
 * @param [in] Game The Number of the Game
 * @param [in] Points The Points Earned
 * @param [out] Nothing 
 */
void endGameMenu(int numberGame, int points) {

    printf("\t\t Score \n\n\t Your Score is %d\n\n", points);
    
    char* name = getName();

    system("cls");

    printf("You played Game %d, won %d points, and you are %2s", numberGame, points, name);

    ScoreGameAdd(numberGame, name, points);
    playAgainMenu(numberGame);

}

/**
 * @brief End Game Menu Dounble Ask's the Name and Inserts the Score in the Scoreboard of two Players 
 *
 * @param [in] Game The Number of the Game
 * @param [in] wonPoints The Points Earned by the Person that Won
 * @param [in] losePoints The Poist Lost by the Person that Lost
 * @param [in] wonPlayer The PLayer that Won the Game
 * @param [in] losePlayer The PLayer that Lost the Game
 * @param [out] Nothing 
 */
void endGameMenuDouble(int numberGame, int wonPoints, int losePoints, int wonPlayer, int losePlayer) {

    printf("\t\t Player %d won the game receiving %d Points\n\n", wonPlayer, wonPoints);
    char* wonName = getName();
    ScoreGameAdd(numberGame, wonName, wonPoints);

    system("cls");

    printf("\t\t Player %d lost the game losing %d Points\n\n", losePlayer, losePoints);
    char* loseName = getName();
    ScoreGameAdd(numberGame, loseName, losePoints);

    playAgainMenu(numberGame);

}

/**
 * @brief Menu to choose what Global Score you want to see
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void globalScoreMenu() {

    system("cls");

    ScoreGlobalReadInitial();

    printf("\t\tGlobal Score\n\n"
           "\t Enter 1 - Your Global Score\n"
           "\t Enter 2 - Global Score\n"
           "\t Enter 0 - Back\n");

    int choice = getChoice(0, 2);
    switch (choice) {
        case 1:
            GlobalPrintOne();
            break;

        case 2:
            GlobalPrint();
            break;

        case 0:
            mainMenu();
            break;

        default:
            printf("\n\t//Invalid Option//\n\n");
            globalScoreMenu();
            break;       

    }

}

#pragma endregion

#pragma endregion