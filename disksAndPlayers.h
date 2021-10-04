
    #define SIZE 8

//enumeration for colour
    enum colour{
        WHITE,
        BLACK,
        NONE
    };

    //structs for position disk and player
    typedef struct position{
        int row;
        int col;
    } position;

    typedef struct disk{
        enum colour type;
        position pos;
    } disk;

    typedef struct player{
        char name[20];
        enum colour type;
        int points;
    } player;

    //function prototypes
    void initializePlayers(player player1, player player2);

    void initializeBoard(disk board[SIZE][SIZE]);

    void printBoard(disk board [SIZE][SIZE]);

    int computeMoves(size_t turnCounter, size_t turn, disk board[SIZE][SIZE]);

    int askPlayer(size_t turn, player user, disk board[SIZE][SIZE]);

    void diskflip(size_t turn, disk board[SIZE][SIZE]);

    void printResult(player player1, player player2, disk board[SIZE][SIZE]);

