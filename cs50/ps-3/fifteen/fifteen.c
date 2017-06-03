/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// prototypes
void clearScreen(void);
void greet(void);
int *initBoard(int boardLength);
void draw(int *board, int boardLength);
void logBoard(FILE *file, int *board, int boardLength);
void swap(int *board, int indexA, int indexB);
int get_random(int max);
int get_int(void);
int move(int *board, int boardLength, int tile);
int won(int *board, int boardSize);

int main(int argc, char *argv[]) {
    int *board;
    int boardLength, boardSize;
    FILE *file;
    
    if (argc != 2) {
        printf("Usage: fifteen d <int>\n");
        return 1;
    }

    // ensure valid dimensions
    boardLength = atoi(argv[1]);
    if (boardLength < DIM_MIN || boardLength > DIM_MAX) {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }
    boardSize = boardLength * boardLength;

    // open log
    file = fopen("log.txt", "w");
    if (file == NULL) { return 3; }

    greet();
    board = initBoard(boardSize);

    // game loop
    while (1) {
        clearScreen();
        draw(board, boardLength);

        logBoard(file, board, boardLength);
        // check for win
        if (won(board, boardSize)) {
            printf("So easy for you.\n");
            break;
        }
        printf("Move tile: ");
        int tile = get_int();

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(board, boardLength, tile)) {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(200000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clearScreen(void) {
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

void greet(void) {
    clearScreen();
    printf("CS50's game of fifteen\nBY DANIEL\n");
}

int *initBoard(int boardSize) {
    int i, randomIndex, tempA, tempB;
    time_t t;

    int *board = malloc(sizeof(int) * boardSize);
    for (i = 0; i < boardSize; i++) board[i] = i;

    srand((unsigned) time(&t));

    // Fisher-Yates shuffle
    for (i = boardSize - 1; i > 0; i--) {
        randomIndex = get_random(i);
        tempA = board[i];
        tempB = board[randomIndex];
        board[randomIndex] = tempA;
        board[i] = tempB;
    }
    return board;
}

void draw(int *board, int boardLength) {
    int index;
    for(int i = 0; i < boardLength; i++) {
        for(int j = 0; j < boardLength; j++) {
            index = i * boardLength + j;
            if (board[index] == 0) printf("_");
            else printf("%i", board[index]);
            if (board[index] < 10) printf("   ");
            else printf("  ");
        }
        printf("\n");
    }
}

int get_random(int max) {
    int x;
    int limit = RAND_MAX - (RAND_MAX % max);
    // Skips integers which would otherwise infer a net non-uniform distribution of integers
    do { x = rand(); }
    while(x >= limit);
    return x % max;
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
int move(int *board, int boardLength, int tile) {
    if (tile == 0) return 0;
    int diff;
    int tileIndex = -1;
    int zeroIndex = -1;
    int valid = 0;
    for (int i = 0; i < boardLength * boardLength; i++) {
        if (board[i] == tile) tileIndex = i;
        if (board[i] == 0) zeroIndex = i;
    }
    printf("tileIndex: %i\n", tileIndex);
    if (tileIndex == -1) {
        printf("Couldn't find tile.\n");
        return 0;
    }
    diff = tileIndex - zeroIndex;
    // behind
    if (diff == 1 && (tileIndex % boardLength) != 0) valid = 1;
    // infront
    if (diff == -1 && (zeroIndex % boardLength) != 0) valid = 1;
    // above
    if (abs(diff) == 3) valid = 1;
    
    if(valid == 1) {
        swap(board, tileIndex, zeroIndex);
        return 1;
    }

    return 0;
}

void swap(int *board, int indexA, int indexB) {
    int tempA, tempB;
    tempA = board[indexA];
    tempB = board[indexB];
    board[indexA] = tempB;
    board[indexB] = tempA;
}

int won(int *board, int boardSize) {
    for(int i = 0; i < boardSize; i++) {
        if(i != board[i]) return 0;
    }
    return 1;
}

int get_int() {
    char str[2], c;
    char *strCur = str;
    while((c = getchar()) && c != '\n' && c != EOF) {
        if (strCur - str < 2) *strCur++ = c;
    }
    int x = atoi(str);
    return x;
}

void logBoard(FILE *file, int *board, int boardLength) {
    for (int i = 0; i < boardLength; i++) {
        for (int j = 0; j < boardLength; j++) {
            fprintf(file, "%i", board[i + j]);
            if (j < boardLength - 1) {
                fprintf(file, "|");
            }
        }
        fprintf(file, "\n");
    }
    fflush(file);
}