#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


//------------------------------- Constants ----------------------------//
#define BOARD_MAX_SIDE  25

#define MSG_WELCOME_MESSAGE  0
#define MSG_GET_BOARD_ROWS   1
#define MSG_GET_BOARD_COLS   2
#define MSG_GET_COLOR        3
#define MSG_PLAYER_MOVE      4
#define MSG_WINNER           5
#define MSG_GET_COLUMN       6
#define MSG_COLUMN_FULL      7
#define MSG_NO_WINNER        8
#define SIZE                 4

char const* const game_messages[];
//---------------------------- Predeclarations -------------------------//

/*
 * Outputs game board.
 *
 * board - contains spaces for empty cells, 'Y' or 'R' for
 *         respective player cells.
 * board_side - contains board dimensions {rows, cols}
 */
void print_board(char board[][BOARD_MAX_SIDE], int board_side[]);

/*
 * Outputs winner or tie message.
 *
 * player_id - the id to be output. Pass <0 for tie.
 */
void print_winner(int player_id);
int checkBoard(char board[][BOARD_MAX_SIDE], int board_side[]);
int updateBoard(char board[][BOARD_MAX_SIDE], int board_side[], int column, char color);

//--------------------------- Main Program -----------------------------//

int main()
{
    /**Manage User Input**/
    char board[BOARD_MAX_SIDE][BOARD_MAX_SIDE]={{'\0'}}, color;
    int player_id=0, board_side[2], column, win=0;
	printf(game_messages[0]);
    printf(game_messages[MSG_GET_BOARD_COLS]);
    scanf("%d",&board_side[0]);
    printf(game_messages[MSG_GET_BOARD_ROWS]);
    scanf("%d",&board_side[1]);
    printf(game_messages[MSG_GET_COLOR]);
    scanf("%c",&color);
    while( win==0 )
    {
            printf(game_messages[MSG_PLAYER_MOVE], &player_id);
            // send to check function
            printf(game_messages[MSG_GET_COLUMN]);
            scanf("%d", &column);
            //check if column full
            if(updateBoard(board, board_side, column, color)==1)
            {
                printf(game_messages[MSG_COLUMN_FULL]);
            }
            //checkBoard(char board[][BOARD_MAX_SIDE], int board_side[])
            print_board(board, board_side);
            player_id = !player_id;
            if(color == 'R')
                color = 'Y';
            else if(color == 'Y')
                color='R';
    }
    return 0;
}


//---------------------- Printing Functions ----------------------------//

// Inclusive check in range
#define IS_IN_RANGEI(VAL, MIN, MAX) (((VAL)>=(MIN)) && ((VAL)<=(MAX)))

char const* const game_messages[] = {
        "Welcome to 4-in-a-row game! \n",
        "Please enter number of rows: ",
        "Please enter number of columns: ",
        "Please choose starting color (Y)ellow or (R)ed: ",
        "Your move, player %d. ",
        "Player %d won! \n",
        "Please enter column: ",
        "Column full. ",
        "That's a tie. \n"
};

enum {BOARD_VERT_SEP=(int)'|',
    BOARD_LEFT_ANG=(int)'\\',
    BOARD_RIGHT_ANG=(int)'/',
    BOARD_BOTTOM=(int)'-',
    BOARD_BOTTOM_SEP=(int)'-'};

void print_board(char board[][BOARD_MAX_SIDE], int board_side[])
{
    assert(IS_IN_RANGEI(board_side[0], 0, BOARD_MAX_SIDE)
           && IS_IN_RANGEI(board_side[1], 0, BOARD_MAX_SIDE));

    for (int row=0; row<board_side[0]; ++row)
    {
        printf("\n%c", (char)BOARD_VERT_SEP);
        for (int col = 0; col < board_side[1]; ++col)
            printf("%c%c", board[row][col], (char)BOARD_VERT_SEP);
    }
    printf("\n%c", (char)BOARD_LEFT_ANG);
    for (int ii=0; ii<board_side[1]-1; ++ii)
        printf("%c%c", (char)BOARD_BOTTOM, (char)BOARD_BOTTOM_SEP);
    printf("%c%c\n", (char)BOARD_BOTTOM, (char)BOARD_RIGHT_ANG);
}

void print_winner(int player_id)
{
    if (player_id >= 0)
        printf(game_messages[MSG_WINNER], player_id);
    else
        printf(game_messages[MSG_NO_WINNER]);
}
int updateBoard(char board[][BOARD_MAX_SIDE], int board_side[], int column, char color)
{
    int i, fill=0;
    //iterate column until empty spot
    for(i=(board_side[1]-1); i>=0 && fill==0; i--)
    {
        //insert to empty spot
        if(board[i][column]!='Y' && board[i][column]!='R')
        {
            board[i][column] = color;
            fill=1;
            return 1;
        }
    }
    return 0;
}
