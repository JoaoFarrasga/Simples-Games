#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "code.h"

#pragma endregion

#pragma region Code

int scoreCount = 0;

/**
 * @brief It reads the File and puts everything in the Header
 * 
 * @param [in] Header The Header to add the new Scoreboards
 * @param [out] Header The Header with the new Scoreboardsw
 */
Scoreboard* scoreboardRead(Scoreboard* header) {

    int score, game;
    char name[4];
    FILE *file;
    
    struct Scoreboard *res = NULL;

    file = fopen("scoreboard.txt", "r");

    if (file == NULL) {
        printf("Sorry but the Scoreboard is not Working right Now");
        return NULL;
    }

    while (fscanf(file, "%d %3s %d", &game, name, &score) == 3) {

        res = scoreboardAdd(game, name, score);

        header = scoreboardInsert(header, res);

        scoreCount++;

        if (fgetc(file) == '\n') {

            continue;

        }

    }

    header = scoreboardReversed(header);

    return header;

}

void scoreboardWrite() {

}

void scoreboardPrint(Scoreboard* header, int numberGame) {

    Scoreboard* node = header;

    while (node != NULL) {

        if (node->game == numberGame) {

            printf("Game: %d\t\t", node->game);
            printf("Name: %s\t", node->name);
            printf("Score: (%d)\n", node->score);

        }

        node = node->next;

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

    if ( newScoreboard == NULL) {
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
 * @brief Inserts a Scoreboard in the Header
 * 
 * @param [in] Header The Header with everything
 * @param [out] newScoreboard The newScoreboard to add to the Header
 */
Scoreboard* scoreboardInsert(Scoreboard* header, Scoreboard* newScoreboard) {

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

    return header;

}

Scoreboard* scoreboardReversed(Scoreboard* header) {

    if (header == NULL) {

        printf("Sorry but the Scoreboard is not Working right Now");
        return NULL;

    }

    Scoreboard* node = header;
    Scoreboard* newHeader = NULL;

    while (node != NULL) {

        Scoreboard* newNode = scoreboardAdd(node->game, node->name, node->score);
        newNode->next = newHeader;
        newHeader = newNode;
        node = node->next;

    }

    return newHeader;

}

#pragma endregion