#include <stdio.h>
// #include <string.h>
#include <ctype.h>

#include "tictactoe.h"
#include "game.h"

void GameStart() {
    struct board *new_board = InitializeBoard();
    PrintGrid(new_board);
}

void GameIntro() {
    // printf("\033[2J\033[H"); // Clear the screen
    printf("\nWelcome to NL-Tictactoe!\n");
    printf("--------------------------------------------\n");
    printf("Please select game mode:\n");
    printf("(A) Local Game\n");
    printf("(B) Online Game\n");
    printf("(Q) Quit\n");
    printf("--------------------------------------------\n");
}

void GameLoop() {
    char input;

    while (scanf(" %c", &input) != EOF && input != 'q' && input != 'Q') {
        if (toupper(input) == 'A') {
            GameLocal();
            break;
        } else if (toupper(input) == 'B') {
            GameIntro();
            printf("Feature not yet implemented.\n");
        } else {
            GameIntro();
            printf("Invalid input, please try again.\n");
        }
        
        
    }
    printf("Game Quit.\n");
}

void GameLocal() {
    printf("67676767\n");
}
