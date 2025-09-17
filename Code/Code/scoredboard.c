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

/**
 * @brief ScoreBoard Read is the Function that reads the File of the ScoreBoard, and puts the Data into the Structs.
 * 
 * @param [in] Nothing
 * @param [out] Nothing
*/
void ScoreboardRead() {
    int game, score;
    char name[4];
    FILE* file = fopen("Code/scoreboard.txt", "r");

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

/**
 * @brief ScoreBoard Write is the Function that writes the Data of the ScoreBoard into the File.
 * 
 * @param [in] Nothing
 * @param [out] Nothing
*/
void ScoreboardWrite() {
    FILE* file = fopen("Code/scoreboard.txt", "w");

    if (file == NULL) {
        printf("Sorry but the Scoreboard is not Working right Now\n\n");
        return;
    }

    Game* currentGame = header;
    while (currentGame) {
        Scoreboard* scoreboard = currentGame->scoreboard;
        while (scoreboard) {
            fprintf(file, "%d %s %d\n", currentGame->game, scoreboard->name, scoreboard->score);
            scoreboard = scoreboard->next;
        }
        currentGame = currentGame->next;
    }

    fclose(file);
}

/**
 * @brief GameAdd is the Function that creates a new Game.
 * 
 * @param [in] NumberGame Is The Number of the Game that needs to be created.
 * @param [out] NewGame The Game that was Created.
*/
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

/**
 * @brief GameInsert is the Function that inserts a new Game into the Game List.
 * 
 * @param [in] NewGame The Game that needs to be inserted.
 * @param [out] Nothing
*/
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


/**
 * @brief ScoreboardAdd is the Function that creates a new ScoreBoard.
 * 
 * @param [in] Name Is The Name of the Player of the Score that needs to be created.
 * @param [in] Score Is The Score of the Player of the Score that needs to be created
 * @param [out] NewScoreBoard The ScoreBoard that was Created.
*/
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

/**
 * @brief ScoreboardInsert is the Function that inserts a new ScoreBoard into the List.
 * 
 * @param [in] Game The Game of the ScoreBoard that needs to be inserted.
 * @param [in] NewScoreBoard The ScoreBoard that needs to be inserted.
 * @param [out] Nothing
*/
void ScoreboardInsert(Game* game, Scoreboard* newScoreboard) {
    if (game->scoreboard == NULL) {
        game->scoreboard = newScoreboard;
    } else {
        Scoreboard* aux = game->scoreboard;
        Scoreboard* auxPrev = NULL;

        while (aux && aux->score > newScoreboard->score) {
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

/**
 * @brief ScoreBoard Print is the Function that Prints the Data of the Scoreboard.
 * 
 * @param [in] NumberGame The Number of the Game that has ScoreBoard that needs to be printed.
 * @param [out] Nothing
*/
void ScoreboardPrint(int numberGame) {

    Game* currentGame = header;

    while (currentGame != NULL && currentGame->game != numberGame) {
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

/**
 * @brief Score Exists is the Function that Checks if the Score of a Player Already Exists.
 * 
 * @param [in] NumberGame The Number of the Game that has the ScoreBoard that needs to be checked.
 * @param [in] Name Is The Name of the Player that needs to be checked.
 * @param [out] Check 1 If the Score of the Player Exists, 0 If the the Score of the Player does not Exists.
*/
int ScoreExists(int numberGame, char* name) {
    Game* currentGame = header;
    while (currentGame != NULL && currentGame->game != numberGame) {
        currentGame = currentGame->next;
    }

    Scoreboard* node = currentGame->scoreboard;
    while (node) {
        if (strcmp(node->name, name) == 0) return 1;
        node = node->next;
    }   

    return 0;
}

/**
 * @breif Score Game Add is the Function that Adds a new Score to the ScoreBoard of a Game.
 * 
 * @param [in] NumberGame The Number of the Game that has the ScoreBoard that will be used.
 * @param [in] Name Is The Name of the Player that will be used.
 * @param [in] Score Is The Score of the Player that will be used.
 * @param [out] Nothing
*/
void ScoreGameAdd(int numberGame, char* name, int score) {

    Game* currentGame = header;
    while (currentGame != NULL && currentGame->game != numberGame) {
        currentGame = currentGame->next;
    }

    if (currentGame == NULL) {
        currentGame = GameAdd(numberGame);
        GameInsert(currentGame);
    }

    if (!ScoreAddPointsIfExists(currentGame, name, score)) {
        Scoreboard* newScoreboard = ScoreboardAdd(name, score);
        ScoreboardInsert(currentGame, newScoreboard);
    }

    ScoreboardReorder(currentGame);
}

/**
 * @brief Adds points to a player if they already exist in the scoreboard
 * 
 * @param [in] currentGame The Game whose scoreboard should be checked
 * @param [in] name The name of the player
 * @param [in] score The points to add
 * @return 1 if the player exists and score was updated, 0 otherwise
 */
int ScoreAddPointsIfExists(Game* currentGame, char* name, int score) {
    if (currentGame == NULL) return 0;

    Scoreboard* node = currentGame->scoreboard;
    while (node != NULL) {
        if (strcmp(node->name, name) == 0) {
            node-> score += score;
            return 1; // Player found & updated
        }
        node = node->next;
    }

    return 0; // Player not found
}

/**
 * @brief Reordes the scorebaord of a game in descending score order.
 * 
 * @param [in] currentGame The Game whose scoreboard should be reordered
 * @return Nothing
 */
void ScoreboardReorder(Game* currentGame) {
    if (currentGame == NULL || currentGame->scoreboard == NULL) return;

    Scoreboard* sorted = NULL;

    while (currentGame->scoreboard != NULL) {
        Scoreboard* node = currentGame->scoreboard;
        currentGame->scoreboard = node->next;

        if (sorted == NULL || node->score > sorted->score){
            node->next = sorted;
            sorted = node;
        } else {
            Scoreboard* aux = sorted;
            while (aux->next != NULL && aux->next->score >= node->score) {
                aux = aux->next;
            }
            node->next = aux->next;
            aux->next = node;
        }
    }

    currentGame->scoreboard = sorted;
}

/**
 * @brief Give ScoreGlobal is the Function that Gives the Global Score of a Player.
 * 
 * @param [in] Name The name of the Player that needs the Global Score.
 * @param [out] GlobalScore The Global Score of the Player wanted.
*/
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

/**
 * @brief ScoreGlobal Read Initial is the Function that Initializes the Global Score Functions.
 * 
 * @param [in] Nothing
 * @param [out] Nothing
*/
void ScoreGlobalReadInitial() {
    ScoreGlobalRead(header);
}

#pragma endregion