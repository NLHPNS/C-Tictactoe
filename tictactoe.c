#include <stdio.h>
#include <stdlib.h>

#include "tictactoe.h"

void PrintGrid(struct board *the_board) {
    printf("     -------------\n");
    int rows = 3;
    for (int i = 0; i < BOARDSIZE; i++) {
        printf("   %d |", rows);
        for (int j = 0; j < BOARDSIZE; j++) {
            if (the_board->board[i][j].block_status == PLAYERX) {
                printf(" X ");
            } else if (the_board->board[i][j].block_status == PLAYERO) {
                printf(" O ");
            } else if (the_board->board[i][j].block_status == EMPTY) {
                printf("   ");
            }
            printf("|");
        }
        printf("\n");
        rows--;
    }
    printf("     -------------\n");
    printf("       A   B   C\n");

}

struct board *InitializeBoard() {
    struct board *new_board = malloc(sizeof(struct board));
    new_board->board = malloc(BOARDSIZE * sizeof(struct block *));

    // allocate each value in pointer
    for (int i = 0; i < BOARDSIZE; i++) {
        new_board->board[i] = malloc(BOARDSIZE * sizeof(struct block));
    }

    for (int i = 0; i < BOARDSIZE; i++) {
        for (int j = 0; j < BOARDSIZE; j++) {
            new_board->board[i][j].block_status = EMPTY;
        }
    }

    return new_board;
}