//defining libraries


#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>


char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

// declaring function prototypes

void board_reset()// reseting the board
{
    for (int i=0;i<3;i++ )
    {
        for(int j=0;j<3;j++)
        {
            board[i][j]=" ";
        }
    }
    

}
void print_board()//printing the board
{
    printf("   |   |  ", board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---\n");
    printf("   |   |  ", board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");
    printf("   |   |  ", board[2][0],board[2][1],board[2][2]);
   // printf("\n---|---|\n");
    printf("\n");

}
int check_freespaces()// checking the free spaces 
{

}
void player_move()// player's move
{

}
void computer_move()//computer's move
{

}
char check_win()// checking winning condition
{

}
char print_winner()// giving who is the winner
{

}

int main(){
    char winner=" ";
    board_reset();
    print_board();

    return 0; 
}