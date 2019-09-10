#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "hangman.h"

#define MAX_GUESSES 10
#define MAX_CHARACTERS 100

void play();
char readLetter();
int readNumber();
int calculateDictionarySize(FILE *dictionary);
char* pickRandomWord(FILE *dictionary);
char* generateObfuscatedWord(int length);
int askPlayAgain();
int askNumberOfPlayers();
void clearBuffer();

int main(int argc, char *argv[])
{
    printf("Welcome to Hangman!\n");
    FILE *dictionary = fopen("dictionary.txt", "r");
    int playing = 1,
        numberOfPlayers = 0;

    if (dictionary != NULL) {
        while (playing) {
            numberOfPlayers = askNumberOfPlayers();
            play(dictionary, numberOfPlayers);
            playing = askPlayAgain();
        }
        fclose(dictionary);
    } else {
        printf("Unable to open dictionary file");
    }

    return 0;
}

void play(FILE *dictionary, int numberOfPlayers)
{
    srand(time(NULL));
    int guessesLeft = MAX_GUESSES,
        i = 0,
        letterFound = 0,
        wordFound = 0;

    char secretWord[MAX_CHARACTERS],
         revealedWord[MAX_CHARACTERS],
         myLetter = 0;

    Drawing hangman;
    resetHangman(&hangman);

    if (numberOfPlayers == 2) {
        printf("Player 1: What will the secret word be? ");
        scanf("%s", secretWord);
        clearBuffer();
        strcpy(secretWord, strupr(secretWord));
    } else {
        strcpy(secretWord, pickRandomWord(dictionary));
    }

    strcpy(revealedWord, generateObfuscatedWord(strlen(secretWord)));

    while (guessesLeft > 0 && !wordFound) {
        printf("\n");

        if (numberOfPlayers == 2) {
            printf("Player 2: ");
        }

        printf("\nYou have %d guesses left\n", guessesLeft);
        printf("What is the secret word? %s\n", revealedWord);
        printf("Guess a letter: ");

        myLetter = readLetter();
        letterFound = 0;

        for (i = 0; secretWord[i] != '\0'; i++) {
            if (myLetter == secretWord[i]) {
                revealedWord[i] = myLetter;
                letterFound = 1;
            }
        }

        if (!letterFound) {
            guessesLeft--;
            setMistakeCount(&hangman, guessesLeft);
            printHangman(&hangman);
        }

        if (strcmp(secretWord, revealedWord) == 0) {
            wordFound = 1;
        }
    }

    if (wordFound) {
        printf("\nYou won! The secret word was indeed: %s", secretWord);
    } else {
        printf("\nYou lost. The secret word was: %s", secretWord);
    }
}

char readLetter()
{
    char character = 0;
    character = getchar();
    character = toupper(character);
    while (getchar() != '\n');
    return character;
}

int readNumber()
{
    int number = 0;
    scanf("%d", &number);
    clearBuffer();
    return number;
}

int calculateDictionarySize(FILE *dictionary)
{
    int size = 0;
    char currentCharacter = 0;

    while (currentCharacter != EOF) {
        currentCharacter = fgetc(dictionary);
        if (currentCharacter == '\n') {
            size++;
        }
    }

    rewind(dictionary);
    return size;
}

char* pickRandomWord(FILE *dictionary)
{
    int dictionarySize = calculateDictionarySize(dictionary),
        randomRow = rand() % (dictionarySize),
        i = 0;
    char *word = malloc(sizeof(char) * MAX_CHARACTERS);

    for (i = 0; i <= randomRow; i++) {
        fgets(word, MAX_CHARACTERS, dictionary);
    }

    word[strlen(word) - 1] = '\0';
    return word;
}

char* generateObfuscatedWord(int length)
{
    int i = 0;
    char *word = malloc(sizeof(char) * length + 1);

    for (i = 0; i < length; i++) {
        word[i] = '*';
    }

    word[i] = '\0';
    return word;
}

int askPlayAgain()
{
    char playAgain = 0;
    int playing = 1;

    do {
        printf("\nDo you want to play again? (Y/N) ");
        playAgain = readLetter();
    } while (playAgain != 'Y' && playAgain != 'N');

    if (playAgain == 'N') {
        playing = 0;
    }

    return playing;
}

int askNumberOfPlayers()
{
    int numberOfPlayers = 0;

    do {
        printf("\nHow many players? (1/2) ");
        numberOfPlayers = readNumber();
    } while (numberOfPlayers != 1 && numberOfPlayers != 2);

    return numberOfPlayers;
}

void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
