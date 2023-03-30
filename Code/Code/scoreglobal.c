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
int userCount;

void globalRead(Scoreboard* header) {

}

/**
 * @brief Global Print, after oppening this function it will print the first 10 places in the Global Score
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void globalPrint() {

    int max = 0;
    ScoreGlobal* node = header;

    printf("\t\tGlobal Score \n\n");

    while (node != NULL) {

        printf("Place: %d\t", max + 1);
        printf("Name: %s\t", node->name);
        printf("Score: (%d)\n", node->score);

        max++;
        node = node->next;

        if (max == 10) {

            break;

        }

    }

    while (max < 10) {

        printf("Place: %d\tName: XXX\tScore: (0)\n", max + 1);
        max++

    }

    printf("\n\t\tEnter 0 - Back\n");
    int choice = getChoice(0, 0);
    if (choice == 0) {

        //Global Score Menu

    }

}

/**
 * @brief Creates a Global Score with the things Added
 * 
 * @param [in] gamerName Name of the User to insert in to the new Global Score
 * @param [in] globalScore Global Score of the User to insert as well
 * @param [out] ScoreGlobal Global Score with the things added
 */
ScoreGlobal* globalAdd(char* gamerName, int globalScore) {

    ScoreGlobal* newGlobal = (ScoreGlobal*)malloc(sizepf(ScoreGlobal));

    if (newGlobal == NULL) {

        printf("Sorry but the Global Score is not Working right now");
        return NULL;

    }

    strcpy(newGlobal->name, gamerName);
    newGlobal->score = globalScore;
    newGlobal->next = NULL;

    return newGlobal;

}

void globalExists(char* gamerName) {
    
} 

/**
 * @brief Inserts a Global Score in the Header
 * 
 * @param [in] newGlobal The newGlobal to add to the Header
 */
void globalInsert(ScoreGlobal* newGlobal) {

    if (globalHeader == NULL) {

        globalHeader = newGlobal;

    } else {

        ScoreGlobal* aux = globalHeader;
        ScoreGlobal* auxPrev = NULL;

        while (aux && aux->score < newGlobal->score) {

            auxPrev = aux;
            aux = aux->next;

        }

        if (auxPrev == NULL) {

            newGlobal->next = globalHeader;
            globalHeader = newGlobal;

        } else {

            auxPrev->next = newGlobal;
            newGlobal->next = aux;

        }

    }

}

void globalReversed() {

    if (globalHeader == NULL) {

        printf("Sorry but the Global Score in not Working right now");

    }

    ScoreGlobal* node = globalHeader;
    ScoreGlobal* newHeader = NULL;

    while (node != NULL) {

        ScoreGlobal* newNode = scoreboardAdd(node->name, node->score);
        newNode->next = newHeader;
        newHeader = newNode;
        node = node->next;

    }

    header = newHeader;

}

#pragma endregion