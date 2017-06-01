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

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// prototypes
void clearScreen(void);
void greet(void);
int *initBoard(int boardLength);
void draw(int *board, int boardLength);
void logBoard(FILE *file, int *board, int boardLength);
int get_random(int max);
int get_int(void);
int move(int tile);
int won(void);

int main(int argc, char *argv[]) {
    int *board;
    int boardLength;
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

    // open log
    file = fopen("log.txt", "w");
    if (file == NULL) { return 3; }

    greet();
    board = initBoard(boardLength);

    // game loop
    while (1) {
        clearScreen();
        draw(board, boardLength);
        logBoard(file, board, boardLength);
        // check for win
        if (won()) {
            printf("So easy for you.\n");
            break;
        }

        printf("Move tile: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0) { break; }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile)) {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
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
    usleep(2000000);
}

int *initBoard(int boardLength) {
    int *board = malloc(sizeof(int) * boardLength + 1);
    int i, swap;
    for (i = 0; i < boardLength; i++) board[i] = i;
    
    // Fisher-Yates shuffle
    for (i = boardLength -1; i > 1; i--) {
        swap = get_random();
        
    }
    return board;
}

void draw(int *board, int boardLength) {
    // TODO
}

int get_random(int max) {
    int x;
    // Skips integers which would otherwise infer a net non-uniform distribution of integers
    do { x = rand(); }
    while ((long) x >= max * (int) (((long) RAND_MAX + 1) / (max)));
    x /= (long) (((long) RAND_MAX + 1) / (max));
    return x;
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
int move(int tile) {
    // TODO
    return 0;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
int won(void) {
    // TODO
    return 0;
}

int get_int() {
    int c = getchar();
    while(getchar() != '\n' && getchar() != EOF);
    return c;
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