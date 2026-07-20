
#define PLAYERX 0
#define PLAYERO 1
#define EMPTY -1
#define BOARDSIZE 3

struct block {
    // This can either be plyer x, y or Empty 
    int block_status;
};

struct board {
    struct block **board;   // 2D array shows board.
};

struct board *InitializeBoard();
void PrintGrid(struct board *the_borad);