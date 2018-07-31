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
int checkBoard(char board[4][4], int board_side[]);
void updateBoard(char board[][BOARD_MAX_SIDE], int board_side[], int column);
int checkSubSquares(char board[4][4], int i, int j);
int checkAllColor(char arr[SIZE]);
int checkBoardFull(char board[4][4], int board_size[]);

//--------------------------- Main Program -----------------------------//

int main()
{
    /**Check board 4 in a row**/
    char arr[4]={'\0', '\0','\0','\0'};
    char board[4][4]={{'Y', 'R','R','R'},{'R', 'Y','R','R'},{'R', 'R','Y','Y'},{'Y', 'Y','Y','Y'}};
    int board_side[2]={0};
    printf(game_messages[MSG_GET_BOARD_COLS]);
    scanf("%d",&board_side[0]);
    printf(game_messages[MSG_GET_BOARD_ROWS]);
    scanf("%d",&board_side[1]);
    if(( board_side[0]>BOARD_MAX_SIDE) || (board_side[1]>BOARD_MAX_SIDE))
        printf("Invalid board dimensions");
    //check AllColor
    printf("%d", checkAllColor(arr));
    //checkSubSquares
    printf("%d", checkBoardFull(board, board_side));
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
int checkBoard(char board[4][4], int board_side[])
{
    int i, j;
    for(i=0; i<(board_side[0]-3); i++)
    {
        for(j=0; j< (board_side[1]-3); j++)
        {
        if(checkSubSquares(board, i, j))
            return 1;
        }
    }
    return 0;
}
int checkSubSquares(char board[4][4], int i, int j)
{
            int l;
            char arr[SIZE] = {0};
            /*Check each square*/
            for(l=0; l<SIZE; l++)
            {
            /*Increment until index+root value*/
                if( board[i+l][j+l] == 'Y')
                {
                    arr[l] = 'Y';
                }
                else
                {
                    arr[l] = 'R';
                }
            }
            if(checkAllColor(arr))
                return 1;
            return 0;
}
int checkAllColor(char arr[SIZE])
{
    int i;
    for(i=0; i<4; i++)
    {
        if(arr[i]=='\0')
            return 0;
    }
    if(arr[0]=='Y')//'Y' or 'R'
    {
    for(i=0; i<4; i++)
    {
        if(arr[i]!='Y')
            return 0;
    }
    }else if (arr[0]=='R')
    {
    for(i=0; i<4; i++)
    {
        if(arr[i]!='R')
            return 0;
    }
    }
    return 1;
}
int checkBoardFull(char board[4][4], int board_size[])
{
    int i,j;
    for(i=0; i<board_size[0]; i++)
    {
        for(j=0; j<board_size[1]; j++)
        {
            if(board[i][j]!='Y' && board[i][j]!='R')
                return 0;
        }
    }
    return 1;
}
