#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "code.h"

#pragma endregion

#pragma region Code

Game* header = NULL;

void ScoreboardRead() {
    int game, score;
    char name[4];
    FILE* file = fopen("scoreboard.txt", "r");

    if (file == NULL) {
        printf("Sorry but the Scoreboard is not Working right Now\n\n");
        return;
    }

    while (fscanf(file, "%d %3s %d", &game, name, &score) == 3) {
        Game* currentGame = header;

        while (currentGame != NULL && currentGame->game != game) {
            currentGame = currentGame->next;
        }

        if (currentGame == NULL) {
            currentGame = GameAdd(game);
            GameInsert(currentGame);
        }

        if (ScoreExists(currentGame->game, name) == 0) {
            Scoreboard* newScoreboard = ScoreboardAdd(name, score);
            ScoreboardInsert(currentGame, newScoreboard);
        }

        if (fgetc(file) == '\n') continue;
    }

    fclose(file);
}

void ScoreboardWrite() {
    FILE* file = fopen("scoreboard.txt", "w");

    if (file == NULL) {
        printf("Sorry but the Scoreboard is not Working right Now\n\n");
        return;
    }

    Game* currentGame = header;
    while (currentGame != NULL) {
        Scoreboard* scoreboard = currentGame->scoreboard;
        while (scoreboard != NULL) {
            fprintf(file, "%d %s %d\n", currentGame->game, scoreboard->name, scoreboard->score);
            scoreboard = scoreboard->next;
        }
        currentGame = currentGame->next;
    }

    fclose(file);
}

Game* GameAdd(int numberGame) {
    Game* newGame = (Game*)malloc(sizeof(Game));
    if (newGame == NULL) {
        printf("Memory allocation failed.");
        return NULL;
    }

    newGame->game = numberGame;
    newGame->scoreboard = NULL;
    newGame->next = NULL;

    return newGame;
}

void GameInsert(Game* newGame) {
    if (header == NULL) {
        header = newGame;
    } else {
        Game* aux = header;
        Game* auxPrev = NULL;

        while (aux && aux->game > newGame->game){
            auxPrev = aux;
            aux = aux->next;
        }

        if (auxPrev == NULL) {
            newGame->next = header;
            header = newGame;
        } else {
            auxPrev->next = newGame;
            newGame->next = aux;
        }
    }
}

Scoreboard* ScoreboardAdd(char* name, int score) {
    Scoreboard* newScoreboard = (Scoreboard*)malloc(sizeof(Scoreboard));
    if (newScoreboard == NULL) {
        printf("Memory allocation failed.");
        return NULL;
    }

    strcpy(newScoreboard->name, name);
    newScoreboard->score = score;
    newScoreboard->next = NULL;

    return newScoreboard;
}

void ScoreboardInsert(Game* game, Scoreboard* newScoreboard) {
    if (game->scoreboard == NULL) {
        game->scoreboard = newScoreboard;
    } else {
        Scoreboard* aux = game->scoreboard;
        Scoreboard* auxPrev = NULL;

        while (aux && aux->score < newScoreboard->score) {
            auxPrev = aux;
            aux = aux->next;
        }

        if (auxPrev == NULL) {
            newScoreboard->next = game->scoreboard;
            game->scoreboard = newScoreboard;
        } else {
            auxPrev->next = newScoreboard;
            newScoreboard->next = aux;
        }
    }
}

void ScoreboardPrint(int numberGame) {
    
    Game* currentGame = header;

    while (header != NULL && header->game != numberGame) {
        currentGame = currentGame->next;
    }

    Scoreboard* node = currentGame->scoreboard;

    printf("\t\tScoreboard\n\n");
    int max = 0;

    while (node != NULL) {
        printf("Place: %d\tName: %s\tScore: %d\n", max + 1, node->name, node->score);
        node = node->next;
        max++;
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

int ScoreExists(int numberGame, char* name) {
    Game* currentGame = header;
    while (currentGame != NULL && currentGame->game != numberGame) {
        currentGame = currentGame->next;
    }

    while (currentGame->scoreboard != NULL) {
        if (strcmp(currentGame->scoreboard->name, name) == 0) return 1;
        currentGame->scoreboard = currentGame->scoreboard->next;
    }   

    return 0;
}

void ScoreGameAdd(int numberGame, char* name, int score) {

    Game* currentGame = header;
    while (currentGame != NULL && currentGame->game != numberGame) {
        currentGame = currentGame->next;
    }

    if (currentGame == NULL) {
        currentGame = GameAdd(numberGame);
        GameInsert(currentGame);
    }

    Scoreboard* newScoreboard = ScoreboardAdd(name, score);
    ScoreboardInsert(currentGame, newScoreboard);
}

int GiveScoreGlobal(char* name) {

    int scoreGlobal = 0;
    Game* currentGame = header;

    while (currentGame != NULL) {
        Scoreboard* currentScoreboard = currentGame->scoreboard;
        
        while (currentScoreboard!= NULL) {
            if(strcmp(currentScoreboard->name, name) == 0) {
                scoreGlobal = scoreGlobal + currentScoreboard->score;
            }

            currentScoreboard = currentScoreboard->next;
        }

        currentGame = currentGame->next;
    }

    return scoreGlobal;
}

void ScoreGlobalReadInitial() {
    ScoreGlobalRead(header);
}

#pragma endregion