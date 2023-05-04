#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "code.h"

#pragma endregion

#pragma region Code

Scoreboard* header = NULL;
int scoreCount = 0;

/**
 * @brief It reads the File and puts everything in the Header
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void scoreboardRead() {

    int score, game;
    char name[4];
    FILE *file;
    
    struct Scoreboard *res = NULL;

    file = fopen("scoreboard.txt", "r");

    if (file == NULL) {
        printf("Sorry but the Scoreboard is not Working right Now\n\n");
    }

    header == NULL;

    while (fscanf(file, "%d %3s %d", &game, name, &score) == 3) {

        int check = scoreExists(game, name);

        if (check == 0) {

            res = scoreboardAdd(game, name, score);
            scoreboardInsert(res);

            scoreCount++;

        }

        if (fgetc(file) == '\n') {

            continue;

        }

    }

    scoreboardReversed();

}

/**
 * @brief It prints the Linked List in the File
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void scoreboardWrite() {

    FILE *file;

    file = fopen("scoreboard.txt", "w");

    if (file == NULL) {
        printf("Sorry but the Scoreboard is not Working right Now");
    }

    Scoreboard* node = header;

    while (node) {
        
        fprintf(file, "%d %s %d\n", node->game, node->name, node->score);
        node = node->next;

    }

    fclose(file);

}

/**
 * @brief Scoreboard Print, after given a Number it prints the Users with Scores on that Games
 * 
 * @param [in] Game The Number of the Game that the User choose to see
 * @param [out] Nothing 
 */
void scoreboardPrint(int numberGame) {

    int max = 0;
    Scoreboard* node = header;

    printf("\t\tScoreboard \n\n");

    while (node != NULL) {

        if (node->game == numberGame) {

            printf("Place: %d\t", max + 1);
            printf("Name: %s\t", node->name);
            printf("Score: (%d)\n", node->score);

            max++;

        }

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

        scoreboardMenu();

    }

}

/**
 * @brief Creates a Scoreboard with the things Added
 * 
 * @param [in] numberGame Number Given to put in the newScoreboard->game
 * @param [in] gamerName Name Given to put in the newScoreboard->name
 * @param [in] gamerScore Score Given to put in the newScoreboard->score
 * @param [out] Scoreboard Scoreboard with the things added 
 */
Scoreboard* scoreboardAdd(int numberGame, char* gamerName, int gamerScore) {

    Scoreboard* newScoreboard = (Scoreboard*)malloc(sizeof(Scoreboard));

    if (newScoreboard == NULL) {

        printf("Sorry but the Scoreboard is not Working right Now");
        return NULL;
        
    }

    newScoreboard->game = numberGame;
    strcpy(newScoreboard->name, gamerName);
    newScoreboard->score = gamerScore;
    newScoreboard->next = NULL;

    return newScoreboard;

}

/**
 * @brief Score Exists check if there is already a Scoreboard with that name
 * 
 * @param [in] Game Game to see if it exists
 * @param [in] Name Name to see if it exists 
 * @param [out] Int 0 == False, 1 == True 
 */
int scoreExists(int numberGame, char* gamerName) {

    if (header == NULL) {

        return 0;

    }

    Scoreboard* aux = header;

    while (aux != NULL) {

        if (aux->game == numberGame) {

            if (strcmp(aux->name, gamerName) == 0) {

                return 1;

            }

        }

        aux = aux->next;

    }

    return 0;

}

/**
 * @brief Inserts a Scoreboard in the Header
 * 
 * @param [out] newScoreboard The newScoreboard to add to the Header
 */
void scoreboardInsert(Scoreboard* newScoreboard) {

    if (header == NULL) {

        header = newScoreboard;

    } else {

        Scoreboard* aux = header;
        Scoreboard* auxPrev = NULL;

        while (aux && aux->score < newScoreboard->score) {

            auxPrev = aux;
            aux = aux->next;

        }

        if (auxPrev == NULL) {

            newScoreboard->next = header;
            header = newScoreboard;

        } else {

            auxPrev->next = newScoreboard;
            newScoreboard->next = aux;

        }

    }

}

/**
 * @brief Scoreboard Reversed is used to reverse a List
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void scoreboardReversed() {

    if (header == NULL) {

        printf("Sorry but the Scoreboard is not Working right Now");

    }

    Scoreboard* node = header;
    Scoreboard* newHeader = NULL;

    while (node != NULL) {

        Scoreboard* newNode = scoreboardAdd(node->game, node->name, node->score);
        newNode->next = newHeader;
        newHeader = newNode;
        node = node->next;

    }

    header = newHeader;

}

/**
 * @brief Score Game Add is a function used in the Games to add in the Header
 * 
 * @param [in] numberGame Number Given to put in the newScoreboard->game
 * @param [in] gamerName Name Given to put in the newScoreboard->name
 * @param [in] gamerScore Score Given to put in the newScoreboard->score
 */
void scoreGameAdd(int numberGame, char* gamerName, int gamerScore) {

    Scoreboard* newScoreboard = scoreboardAdd(numberGame, gamerName, gamerScore);
    Scoreboard* aux = header;

    while (aux != NULL) {

        if (aux->game == newScoreboard->game && (strcmp(aux->name, newScoreboard->name) == 0)) {
            
            if (aux->score < newScoreboard->score) {
            
            aux->score = aux->score + newScoreboard->score;

            } 

            return;

        }

        aux = aux->next;

    }

    scoreboardInsert(newScoreboard);

}

/**
 * @brief Score Global is a function that calculates the Global Score
 * 
 * @param [in] Name The Name of the User to give Global Score 
 * @param [out] GlobalScore The Global Score of the User
 */
int scoreGlobal(char* gamerName) {

    int scoreGlobal = 0;
    Scoreboard* aux = header;

    while (aux != NULL) {

        if (strcmp(aux->name, gamerName) == 0) {

            scoreGlobal = scoreGlobal + aux->score;

        }

        aux = aux->next;

    }

    return scoreGlobal;

}

/**
 * @brief Starts Global Score Read
 * 
 * @param [in] Nothing
 * @param [out] Nothing
 */
void scoreGlobalRead() {

    globalRead(header);

}

#pragma endregion