
#define PLAYERX 0
#define PLAYERO 1
#define EMPTY -1
#define BOARDSIZE 3
#define STRMAX 10000

struct block {
    // This can either be plyer x, y or Empty 
    int block_status;
};

struct board {
    int player;
    struct block **board;   // 2D array shows board.
};

struct board *InitializeBoard();
void FreeBoard(struct board *the_board);
void PrintGrid(struct board *the_board);
int PlaceMark(struct board *the_board, char input_one, char input_two);
void SwapPlayer(struct board *the_board);