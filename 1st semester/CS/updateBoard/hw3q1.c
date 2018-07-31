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
#define EMPTY               ' '

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
/*
 * Checks for diagonals/rows/columns in board.
 *
 * board - board array
 * board_side - board dimensions
 */
int checkBoard(char board[][BOARD_MAX_SIDE], int board_side[]);
/*
 * Insert new piece into board
 *
 * board - board array
 * board_side - board dimensions
 * column - index for column
 *color - current player's column
 */
int updateBoard(char board[][BOARD_MAX_SIDE], int board_side[], int column, char color);
int checkRC(char board[][BOARD_MAX_SIDE], int board_side[]);
/*
 * These functions get indexes for certain board spot. Check for winner
 *
 * board - board array
 * i, j - indexes from for loop
 *
 */
int checkSubSquares(char board[][BOARD_MAX_SIDE], int i, int j);
int checkSubSquares2(char board[][BOARD_MAX_SIDE], int i, int j);
int checkRows(char board[][BOARD_MAX_SIDE], int i, int j);
int checkColumns(char board[][BOARD_MAX_SIDE], int i, int j);
/*
 * Checks array for uniformity in coloe
 *
 * array - colors of diagonal/row/column
 */
int checkAllColor(char arr[SIZE]);
/*
 * Check if the board is full (no winner)
 *
 * board - board array
 * board_side - board dimensions
 */
int checkBoardFull(char board[][BOARD_MAX_SIDE], int board_side[]);
//--------------------------- Main Program -----------------------------//

int main()
{
    /**Initialize variables **/
    char board[BOARD_MAX_SIDE][BOARD_MAX_SIDE], color=EMPTY;
    for(int i=0; i<BOARD_MAX_SIDE; i++)
    {
        for(int j=0; j<BOARD_MAX_SIDE; j++)
        {
            board[i][j] = EMPTY;
        }
    }
    int player_id=0, board_side[2]={0,0}, column, win=0;
	printf(game_messages[0]);
    do{/*Receive input until correct input*/
        printf(game_messages[MSG_GET_COLOR]);
        scanf(" %c",&color);
    } while(color!='R' && color!='Y');
    do{
    printf(game_messages[MSG_GET_BOARD_ROWS]);
    scanf("%d",&board_side[0]);
    }while(board_side[0]<=3 || board_side[0]>BOARD_MAX_SIDE);
    do{
    printf(game_messages[MSG_GET_BOARD_COLS]);
    scanf("%d",&board_side[1]);
    }while(board_side[1]<=3 || board_side[1]>BOARD_MAX_SIDE);
    print_board(board, board_side);
    do{
            printf(game_messages[MSG_PLAYER_MOVE], player_id+1);
            do{
            printf(game_messages[MSG_GET_COLUMN]);
            scanf("%d", &column);
            }while(column<=0 || column>board_side[1]);
            if(board[0][column-1]=='Y' || board[0][column-1]=='R')
            {
                printf(game_messages[MSG_COLUMN_FULL]);
                do{
                printf(game_messages[MSG_GET_COLUMN]);
                scanf("%d", &column);
                }while(column<=0 || column>board_side[1]);
            }
            /*Insert color into available spot at player-chosen column*/
            updateBoard(board, board_side, (column-1), color);
            print_board(board, board_side);
            if( checkBoard(board, board_side) == 1 )
            {
                printf(game_messages[MSG_WINNER], player_id+1);
                win=1;
            }
            /*if board full but player already won then dont enter*/
            if(checkBoardFull(board, board_side) == 1 && win==0)
            {
                printf(game_messages[MSG_NO_WINNER]);
                win=1;
            }
            player_id = !player_id;
            if(color == 'R')
                color = 'Y';
            else if(color == 'Y')
                color='R';
    }while( win==0 );
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
{/*7 lines*/
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
int checkBoard(char board[][BOARD_MAX_SIDE], int board_side[])
{/*10 lines*/
    int i, j;
    /*check diagonal from left to right*/
    for(i=0; i<(board_side[0]-3); i++)
    {
        for(j=0; j< (board_side[1]-3); j++)
        {
        if(checkSubSquares(board, i, j))
            {
                return 1;
            }
        }
    }
    /*Check other diagonal r-l*/
    for(i=0; i<(board_side[0]-3); i++)
    {/*start from rightmost column*/
        for(j=(board_side[1]-1); j>2; j--)
        {
        if(checkSubSquares2(board, i, j))
            {
                return 1;
            }
        }
    }
    if(checkRC(board, board_side)==1)
        return 1;
    return 0;
}
int checkRC(char board[][BOARD_MAX_SIDE], int board_side[])
{/*10 lines*/
    int i,j;
    /*Check rows*/
    for(i=0; i<(board_side[0]); i++)
    {
        for(j=0; j< (board_side[1]-3); j++)
        {
        if(checkRows(board, i, j))
            {
                return 1;
            }
        }
    }
    /*Check columns*/
    for(i=0; i<(board_side[0]-3); i++)
    {
        for(j=0; j< (board_side[1]); j++)
        {
        if(checkColumns(board, i, j))
            {
                return 1;
            }
        }
    }
    return 0;
}
int checkSubSquares(char board[][BOARD_MAX_SIDE], int i, int j)
{/*10 lines*/
            int l;
            char arr[SIZE] = {EMPTY};
            /*Check each square*/
            for(l=0; l<SIZE; l++)
            {
                /*Increment both rows and columns*/
                if( board[i+l][j+l] == 'Y')
                {
                    arr[l] = 'Y';
                }
                else if( board[i+l][j+l] == 'R')
                {
                    arr[l] = 'R';
                }
            }
            if(checkAllColor(arr))
                return 1;
            return 0;
}
int checkSubSquares2(char board[][BOARD_MAX_SIDE], int i, int j)
{/*10 lines*/
            int l;
            char arr[SIZE] = {EMPTY};
            /*Check each square*/
            for(l=0; l<SIZE; l++)
            {
                /*Increment row& decrease column*/
                if( board[i+l][j-l] == 'Y')
                {
                    arr[l] = 'Y';
                }
                else if( board[i+l][j-l] == 'R')
                {
                    arr[l] = 'R';
                }
            }
            if(checkAllColor(arr))
                return 1;
            return 0;
}
int checkRows(char board[][BOARD_MAX_SIDE], int i, int j)
{/*10 lines*/
            int l;
            char arr[SIZE] = {EMPTY};
            /*Check each square*/
            for(l=0; l<SIZE; l++)
            {
                /*Increment columns*/
                if( board[i][j+l] == 'Y')
                {
                    arr[l] = 'Y';
                }
                else if( board[i][j+l] == 'R')
                {
                    arr[l] = 'R';
                }
            }
            if(checkAllColor(arr))
                return 1;
            return 0;
}
int checkColumns(char board[][BOARD_MAX_SIDE], int i, int j)
{/*10 lines*/
            int l;
            char arr[SIZE] = {EMPTY};
            /*Check each square*/
            for(l=0; l<SIZE; l++)
            {
                /*Increment until index+root value*/
                if( board[i+l][j] == 'Y')
                {
                    arr[l] = 'Y';
                }
                else if( board[i+l][j] == 'R')
                {
                    arr[l] = 'R';
                }
            }
            if(checkAllColor(arr))
                return 1;
            return 0;
}
int checkAllColor(char arr[SIZE])
{/*13 lines*/
    int i;
    /*If an element is empty-exit*/
    for(i=0; i<4; i++)
    {
        if(arr[i]==EMPTY)
            return 0;
    }
    if(arr[0]=='Y')//'Y' or 'R'
    {
        for(i=0; i<4; i++)
        {
            if(arr[i]!='Y')
                return 0;
        }
    }
    else if (arr[0]=='R')
    {
        for(i=0; i<4; i++)
        {
            if(arr[i]!='R')
                return 0;
        }
    }
    return 1;
}
int checkBoardFull(char board[][BOARD_MAX_SIDE], int board_side[])
{/*6 lines*/
    int i,j;
    for(i=0; i<board_side[0]; i++)
    {
        for(j=0; j<board_side[1]; j++)
        {/*If one spot is empty return board not full*/
            if(board[i][j]!='Y' && board[i][j]!='R')
                return 0;
        }
    }
    return 1;
}
