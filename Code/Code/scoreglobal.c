#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "code.h"

#pragma endregion

#pragma region Code

ScoreGlobal* globalHeader = NULL;

/**
 * @brief Initialize the Global Score of the Players.
 * 
 * @param [in] GameHeader The Main List of the Games.
 * @param [out] Nothing
*/
void ScoreGlobalRead(Game* header) {

    int globalScore;

    if (header == NULL) {
        printf("Sorry but the Global Score is not Working Right Now");
    }
    globalHeader = NULL;

    Game* currentGame = header;
    while (currentGame != NULL) {
        Scoreboard* currentScoreboard = currentGame->scoreboard;
        while (currentScoreboard != NULL) {
            if (GlobalExists(currentScoreboard->name) == 0) {
                globalScore = GiveScoreGlobal(currentScoreboard->name);

                ScoreGlobal* newScoreGlobal = GlobalAdd(currentScoreboard->name, globalScore);
                GlobalInsert(newScoreGlobal);
            }

            currentScoreboard = currentScoreboard->next;
        }

        currentGame = currentGame->next;
    }
}

/**
 * @brief Checks the If the Global Score of a Player Already Exists in the Global Score List.
 * 
 * @param [in] Name The Name of the Player.
 * @param [out] Check 1 if the Global Score of a Player Already Exists in the Global Score List, 0 otherwise.
*/
int GlobalExists(char* name) {
    
    if (globalHeader == NULL) {
        return 0;
    }
    
    ScoreGlobal* aux = globalHeader;

    while (aux != NULL) {
        if (strcmp(aux->name, name) == 0) {
            return 1;
        }
        aux = aux->next;
    }

    return 0;
}

/**
 * @brief Creates a Global Score.
 * 
 * @param [in] Name The Name of the Player.
 * @param [in] Score The Global Score of the Player.
 * @param [out] NewScoreGlobal The Global Score of the Player.
*/
ScoreGlobal* GlobalAdd(char* name, int scoreGlobal) {
    ScoreGlobal* newScoreGlobal = (ScoreGlobal*)malloc(sizeof(ScoreGlobal));

    if (newScoreGlobal == NULL) {
        printf("Sorry but the Global Score is not Working right now");
        return NULL;
    }

    strcpy(newScoreGlobal->name, name);
    newScoreGlobal->score = scoreGlobal;
    newScoreGlobal->next = NULL;

    return newScoreGlobal;
}

/**
 * @brief Inserts a Global Score in the Global Score List.
 * 
 * @param [in] NewScoreGlobal Adds the New Score Global to the Global Score List.
 * @param [out] Nothing
*/
void GlobalInsert(ScoreGlobal* newScoreGlobal) {
    if (globalHeader == NULL) {
        globalHeader = newScoreGlobal;
    } else {
        ScoreGlobal* aux = globalHeader;
        ScoreGlobal* auxPrev = NULL;

        while (aux && aux->score > newScoreGlobal->score) {
            auxPrev = aux;
            aux = aux->next;
        }

        if (auxPrev == NULL) {
            newScoreGlobal->next = globalHeader;
            globalHeader = newScoreGlobal;
        } else {
            auxPrev->next = newScoreGlobal;
            newScoreGlobal->next = aux;
        }
    }
}

/**
 * @brief Prints the Global Score List.
 * 
 * @param [in] Nothing
 * @param [out] Nothing
*/
void GlobalPrint() {
    int max = 0;
    ScoreGlobal* node = globalHeader;

    while (node != NULL) {
        printf("Place: %d\tName: %s\tScore: %d\n", max + 1, node->name, node->score);
    
        max++;
        node = node->next;

        if (max == 10) {
            break;
        }
    }

    while (max < 10) {
        printf("Place: %d\tName: XXX\tScore: (0)\n", max + 1);
        max++;
    }

    printf("\n\tEnter 0 - Back\n");
    int choide = getChoice(0, 0);
    if (choide == 0) {
        globalScoreMenu();
    }
}

/**
 * @brief Prints the Global Score of a Player.
 * 
 * @param [in] Nothing
 * @param [out] Nothing
*/
void GlobalPrintOne() {
    char* name = getName();
    int globalScore = GiveScoreGlobal(name);
    system("cls");

    printf("\n\n\tYour Global Points are: %d\n\n", globalScore);

    printf("\n\tEnter 0 - Back\n");
    int choide = getChoice(0, 0);
    if (choide == 0) {
        globalScoreMenu();
    }
}

#pragma endregion