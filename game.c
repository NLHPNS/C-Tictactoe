#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "tictactoe.h"
#include "game.h"

void GameIntro() {
    printf("\033[2J\033[H"); // Clear the screen
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
    int play = 0;

    while (scanf(" %c", &input) != EOF && input != 'q' && input != 'Q') {
        if (toupper(input) == 'A') {
            play = 1;
            break;
        } else if (toupper(input) == 'B') {
            GameIntro();
            printf("Feature not yet implemented.\n");
        } else {
            GameIntro();
            printf("Invalid input, please try again.\n");
        }
        
        
    }

    if (play == 1) {
        fgetc(stdin);
        GameLocal();
    }
    printf("Game Quit.\n");
}

void GameLocal() {
    struct board *new_board = InitializeBoard();
    PrintGrid(new_board);

    char input[STRMAX];
    char input_one;
    char input_two;

    // input
    while (1) {
        fgets(input, STRMAX, stdin);
        if (strlen(input) == 3) {   // A2\n \0
            sscanf(input, "%c%c", &input_one, &input_two);
            int place_return = PlaceMark(new_board, input_one, input_two);
            PrintGrid(new_board);
            if (place_return == 1) {
                PrintGrid(new_board);
                printf("Invalid input, type 'H' for help.67\n");
                continue;
            }
        } else if (strlen(input) == 2) {
            sscanf(input, "%c", &input_one);
            if (toupper(input_one) == 'H') {
                PrintGrid(new_board);
                
            }
            printf("Invalid input, type 'H' for help.676767\n");
            continue;
        } else {
            PrintGrid(new_board);
            printf("Invalid input, type 'H' for help.\n");
            
        }

        
    }


    FreeBoard(new_board);

}