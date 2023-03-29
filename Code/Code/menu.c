#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
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
    
    printf("\t\t Main Menu \n"
           "\t 1 - Select Game\n"
           "\t 2 - Scoreboard\n"
           "\n\t 0 - Quit\n");

    int choice = getChoice(0, 2);
    switch (choice) {
        case 1:
            selectGame();
            break;
        
        case 2:
            scoreboardMenu();
            break;

        case 0:
            //Quit
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
    printf("\t\t Select Game \n"
           "\t Enter 1 - Guess the Number\n"
           "\t Enter 2 - Guess the Card\n"
           "\t Enter 3 - Tic Tac Toe\n"
           "\n\t Enter 0 - Back\n");
    
    int choice = getChoice(0, 3);
    switch (choice)
    {
    case 1:
        guessNumber();
        break;

    case 2:
        guessCard();
        break;

    case 3:
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

    Scoreboard* header = NULL;

    header = scoreboardRead(header);

    printf("\t\t Scoreboard\n"
           "\t\tSelect Game\n"
           "\t 1 - Guess the Number\n"
           "\t 2 - Guess the Card\n"
           "\t 3 - Tic Tac Toe"
           "\n\t 0 - Back\n");

    int choice = getChoice(0, 3);
    switch (choice) {
        case 1:
            scoreboardPrint(header, choice);
            break;
        
        case 2:
            scoreboardPrint(header, choice);
            break;

        case 3:
            scoreboardPrint(header, choice);
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

#pragma endregion

#pragma endregion