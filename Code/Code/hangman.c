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

char* RandomWord(char* words[], int length) {
    int randomNumber = randomInt(0, length - 1);
    return words[randomNumber];
}

int IsLetterInWord(char* word, char letter) {
    int lengthWord = strlen(word);

    for (int i = 0; i < lengthWord; i++) {
        if (word[i] == letter) {
            return 1;
        }
    }

    return 0;
}

int IsWordCorrect(char* word, char letters[]) {
    
    for (int i = 0; i < strlen(word); i++) {
        int letterFound = 0;
        for (int j = 0; j < strlen(letters); j++) {
            if (word[i] == letters[j]) {
                letterFound = 1;
                break;
            }
        }
        if (letterFound == 0) {
            return 0;
        }
    }

    return 1;
}

void DisplayWord(char* word, char letters[]) {

    for (int i; i < strlen(word); i++) {
        
        char letter = word[i];
        int letterFound = 0;

        for (int j = 0; j < strlen(letters); j++) {
            if (letters[j] == letter) {
                letterFound = 1;
                break;
            }
        }

        if (letterFound) {
            printf("%c ", letter);
        } else {
            printf("_ ");
        }

    }
}

void HangMan() {

    char* words[] = {
    "abruptly", "absurd", "abyss", "affix", "askew", "avenue", "awkward", "axiom", "azure", "bagpipes",
    "bandwagon", "banjo", "bayou", "beekeeper", "bikini", "blitz", "blizzard", "boggle", "bookworm", "boxcar",
    "boxful", "buckaroo", "buffalo", "buffoon", "buxom", "buzzard", "buzzing", "buzzwords", "caliph", "cobweb",
    "cockiness", "croquet", "crypt", "curacao", "cycle", "daiquiri", "dirndl", "disavow", "dizzying", "duplex",
    "dwarves", "embezzle", "equip", "espionage", "euouae", "exodus", "faking", "fishhook", "fixable", "fjord",
    "flapjack", "flopping", "fluffiness", "flyby", "foxglove", "frazzled", "frizzled", "fuchsia", "funny", "gabby",
    "galaxy", "galvanize", "gazebo", "giaour", "gizmo", "glowworm", "glyph", "gnarly", "gnostic", "gossip",
    "grogginess", "haiku", "haphazard", "hyphen", "iatrogenic", "icebox", "injury", "ivory", "ivy", "jackpot",
    "jaundice", "jawbreaker", "jaywalk", "jazziest", "jazzy", "jelly", "jigsaw", "jinx", "jiujitsu", "jockey",
    "jogging", "joking", "jovial", "joyful", "juicy", "jukebox", "jumbo", "kayak", "kazoo", "keyhole",
    "khaki", "kilobyte", "kiosk", "kitsch", "kiwifruit", "klutz", "knapsack", "larynx", "lengths", "lucky",
    "luxury", "lymph", "marquis", "matrix", "megahertz", "microwave", "mnemonic", "mystify", "naphtha", "nightclub",
    "nowadays", "numbskull", "nymph", "onyx", "ovary", "oxidize", "oxygen", "pajama", "peekaboo", "phlegm", "pixel",
    "pizazz", "pneumonia", "polka", "pshaw", "psyche", "puppy", "puzzling", "quartz", "queue", "quips", "quixotic",
    "quiz", "quizzes", "quorum", "razzmatazz", "rhubarb", "rhythm", "rickshaw", "schnapps", "scratch", "shiv",
    "snazzy", "sphinx", "spritz", "squawk", "staff", "strength", "strengths", "stretch", "stronghold", "stymied",
    "subway", "swivel", "syndrome", "thriftless", "thumbscrew", "topaz", "transcript", "transgress", "transplant", "triphthong",
    "twelfth", "twelfths", "unknown", "unworthy", "unzip", "uptown", "vaporize", "vixen", "vodka", "voodoo",
    "vortex", "voyeurism", "walkway", "waltz", "wave", "wavy", "waxy", "wellspring", "wheezy", "whiskey", "whizzing",
    "whomever", "wimpy", "witchcraft", "wizard", "woozy", "wristwatch", "wyvern", "xylophone", "yachtsman", "yippee", "yoked",
    "youthful", "yummy", "zephyr", "zigzag", "zigzagging", "zilch", "zipper", "zodiac", "zombie"
    };

    int length = sizeof(words) / sizeof(words[0]);
    char* word = RandomWord(words, length);

    printf("\n%s\n\n", word);

    int attempts = 6;
    char guessedLetters[26] = {0};

    while (attempts > 0 || IsWordCorrect(word, guessedLetters) == 0) {
        printf("\nAttempts left: %d\n", attempts);
        
        DisplayWord(word, guessedLetters);

        char guess;
        printf("\nEnter a Letter: ");
        scanf(" %c", &guess);

        guessedLetters[strlen(guessedLetters)] = guess;

        if (IsLetterInWord(word, guess) == 1) {
            printf("\nYou guessed %c correctly!\n", guess);
        } else {
            attempts--;
            printf("\nYou guessed %c incorrectly!\n", guess);
        }
        
    }

    if (attempts == 0) {
        printf("\nYou ran out of attempts!\n");
    } else {
        printf("\nYou won!\n");
    }
}

#pragma endregion