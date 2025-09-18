#pragma region Includes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "code.h"

#pragma endregion

#pragma region Code

// Lista fixa de símbolos
const char* allSymbols[4] = {"Red", "Green", "Blue", "Yellow"};

// Pontuação global do jogador
int mastermindScore = 0;

/**
 * @brief Gera a sequência aleatória do computador
 */
char** computerSymbols() {
    char** result = (char**)malloc(4 * sizeof(char*));

    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        int randomNumber = rand() % 4;
        result[i] = strdup(allSymbols[randomNumber]);
    }

    return result;
}

/**
 * @brief Pergunta ao jogador a sua sequência
 */
char** playerSymbols() {
    char** guess = (char**)malloc(4 * sizeof(char*));   

    printf("\n\nKnowing that Red=1, Green=2, Blue=3, Yellow=4\n");

    for (int i = 0; i < 4; i++) {
        printf("\tEnter your guess for position %d: ", i + 1);
        int choice = getChoice(1, 4);
        guess[i] = strdup(allSymbols[choice - 1]);
    }

    return guess;
}

/**
 * @brief Compara a sequência do jogador com a do computador
 * @return 1 se ganhou, 0 caso contrário
 */
int checkSymbols(char** player, char** computer) {
    int correctPosition = 0;
    int correctColor = 0;

    int usedComp[4] = {0};
    int usedPlayer[4] = {0};

    // Primeiro: símbolos na posição correta
    for (int i = 0; i < 4; i++) {
        if (strcmp(player[i], computer[i]) == 0) {
            correctPosition++;
            usedComp[i] = 1;
            usedPlayer[i] = 1;
        }
    }

    // Depois: símbolos corretos mas na posição errada
    for (int i = 0; i < 4; i++) {
        if (usedPlayer[i]) continue;
        for (int j = 0; j < 4; j++) {
            if (usedComp[j]) continue;
            if (strcmp(player[i], computer[j]) == 0) {
                correctColor++;
                usedComp[j] = 1;
                break;
            }
        }
    }

    printf("\nFeedback: %d in correct position, %d correct color but wrong position\n",
           correctPosition, correctColor);

    return (correctPosition == 4) ? 1 : 0;
}

/**
 * @brief Função principal do MasterMind
 */
void masterMind() {
    char** symbolsComputer = computerSymbols();
    int win = 0;
    int attempts = 0;

    printf("\n\tWelcome to MasterMind!\n");

    do {
        char** symbolsPlayer = playerSymbols();
        win = checkSymbols(symbolsPlayer, symbolsComputer);
        attempts++;

        // Liberta a memória do input do jogador
        for (int i = 0; i < 4; i++) free(symbolsPlayer[i]);
        free(symbolsPlayer);

    } while (!win);

    printf("\n\tYou Win in %d attempts!\n", attempts);

    // Atualizar pontuação
    mastermindScore += 20;
    if (mastermindScore < 0) mastermindScore = 0;

    endGameMenu(8, 20, 1);
}

#pragma endregion
