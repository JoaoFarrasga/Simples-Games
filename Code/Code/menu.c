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

    scoreboardWrite();

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
void selectGame()
{
    printf("\t\t Select Game \n\n"
           "\t Enter 1 - Guess the Number\n"
           "\t Enter 2 - Guess the Card\n"
           "\t Enter 3 - Black Jack\n"
           "\t Enter 4 - Tic Tac Toe\n"
           "\n\t Enter 0 - Back\n");
    
    int choice = getChoice(0, 4);
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
           "\n\t Enter 0 - Back\n");

    int choice = getChoice(0, 4);
    switch (choice) {
        case 1:
            scoreboardPrint(choice);
            break;
        
        case 2:
            scoreboardPrint(choice);
            break;

        case 3:
            //scoreboardPrint(choice);
            break;

        case 4:
            scoreboardPrint(choice);
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
            //blackjack();
            break;

        case 4:
            tictactoe();
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

    scoreGameAdd(numberGame, name, points);
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

    scoreGlobalRead();

    printf("\t\tGlobal Score\n\n"
           "\t Enter 1 - Your Global Score\n"
           "\t Enter 2 - Global Score\n"
           "\t Enter 0 - Back\n");

    int choice = getChoice(0, 2);
    switch (choice) {
        case 1:
            globalPrintOne();
            break;

        case 2:
            globalPrint();
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