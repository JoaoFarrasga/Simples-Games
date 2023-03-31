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
 * @brief It reads the Scoreboard and creates the Global Score
 * 
 * @param [in] Scoreboard The Header of the Scoreboards
 * @param [out] Nothing 
 */
void globalRead(Scoreboard* header) {

    int check, globalScore;

    if (header == NULL) {

        printf("Sorry but the Global Score is not Working right Now");

    }

    Scoreboard* node = header;
    
    while (node != NULL) {

        check = globalExists(node->name);

        if (check == 0 ) {

            globalScore = scoreGlobal(node->name);

            ScoreGlobal* newNode = globalAdd(node->name, globalScore);
            globalInsert(newNode);

        }

        node = node->next;

    }

    globalReversed();

}

/**
 * @brief Global Print, after oppening this function it will print the first 10 places in the Global Score
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void globalPrint() {

    int max = 0;
    ScoreGlobal* node = globalHeader;

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
        max++;

    }

    printf("\n\t\tEnter 0 - Back\n");
    int choice = getChoice(0, 0);
    if (choice == 0) {

        globalScoreMenu();

    }

}

/**
 * @brief It prints one Global Score after given the Name of the User
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void globalPrintOne() {

    int globalScore;
    char name[4];

    printf("\tPlease Insert your Name here: \n");
    printf("\n Select - ");
    scanf(" %s", name);

    globalScore = scoreGlobal(name);

    system("cls");

    printf("\n\n\tYour Global Points are: %d\n\n", globalScore);

    printf("\tEnter 0 - Back\n\n");

    int choice = getChoice(0, 0);
    if (choice == 0) {

        globalScoreMenu();

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

    ScoreGlobal* newGlobal = (ScoreGlobal*)malloc(sizeof(ScoreGlobal));

    if (newGlobal == NULL) {

        printf("Sorry but the Global Score is not Working right now");
        return NULL;

    }

    strcpy(newGlobal->name, gamerName);
    newGlobal->score = globalScore;
    newGlobal->next = NULL;

    return newGlobal;

}

/**
 * @brief Global Exists check if there is already a ScoreGlobal with that name
 * 
 * @param [in] Name Name to see if it exists 
 * @param [out] Int 0 == False, 1 == True 
 */
int globalExists(char* gamerName) {
    
    if (globalHeader == NULL) {

        return 0;

    }

    ScoreGlobal* aux = globalHeader;

    while (aux != NULL) {

        if (strcmp(aux->name, gamerName) == 0) {

            return 1;

        }

        aux = aux->next;

    }

    return 0;

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

/**
 * @brief Score Global Reversed is used to reverse a List
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void globalReversed() {

    if (globalHeader == NULL) {

        printf("Sorry but the Global Score in not Working right now");

    }

    ScoreGlobal* node = globalHeader;
    ScoreGlobal* newHeader = NULL;

    while (node != NULL) {

        ScoreGlobal* newNode = globalAdd(node->name, node->score);
        newNode->next = newHeader;
        newHeader = newNode;
        node = node->next;

    }

    globalHeader = newHeader;

}

#pragma endregion