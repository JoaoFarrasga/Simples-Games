#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "code.h"

#pragma endregion

#pragma region Code

#pragma region Menus

//Main Menu is a Function to start the App, giving the Player Choice between games
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
            //Score Select
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

//Game Select Menu to Select the Game to Play
void selectGame()
{
    printf("\t\t Select Game \n"
           "\t Enter 1 - Guess the Number\n"
           "\t Enter 2 - Guess the Card\n"
           "\n\t Enter 0 - Back\n");
    
    int choice = getChoice(0, 2);
    switch (choice)
    {
    case 1:
        guessNumber();
        break;

    case 2:
        guessCard();
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

#pragma endregion

#pragma endregion