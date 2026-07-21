#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// #include <string.h>


#include "tictactoe.h"

void PrintGrid(struct board *the_board) {
    char player;
    if (the_board->player == PLAYERX) {
        player = 'X';
    } else if (the_board->player == PLAYERO) {
        player = 'O';
    } else {
        player = '?';
    }
    printf("\033[2J\033[H"); // Clear the screen
    printf("--------------------------------------------\n");
    printf("             Term for [%c]\n", player);
    printf("             -------------\n");
    int rows = 3;
    for (int i = 0; i < BOARDSIZE; i++) {
        printf("           %d |", rows);
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
    printf("             -------------\n");
    printf("               A   B   C\n\n");
    printf("--------------------------------------------\n");

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
    new_board->player = PLAYERX;

    return new_board;
}

void FreeBoard(struct board *the_board) {
    for (int i = 0; i < BOARDSIZE; i++) {
        free(the_board->board[i]);
    }
    free(the_board->board);
    free(the_board);
}

int PlaceMark(struct board *the_board, char input_one, char input_two) {
    if (((input_one >= 'A' && input_one <= 'C') ||
        (input_one >= 'a' && input_one <= 'c') )&&
        (input_two >= '1' && input_two <= '3')
    ) {
        int col = 2;
        if (toupper(input_one) == 'A') {
            col = 0;
        } else if (toupper(input_one) == 'B') {
            col = 1;   
        }
        int row = 2 - (input_two - '1');
        the_board->board[row][col].block_status = the_board->player;
        SwapPlayer(the_board);
    } else {
        return 1;
    }

    return 0;
}

void SwapPlayer(struct board *the_board) {
    if (the_board->player == PLAYERX) {
        the_board->player = PLAYERO;
    } else {
        the_board->player = PLAYERX;
    }
}
