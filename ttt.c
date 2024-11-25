#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

// Function to reset the board
void board_reset() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the board
void print_board() {
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

// Function to check the number of free spaces
int check_freespaces() {
    int free_spaces = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                free_spaces++;
            }
        }
    }
    return free_spaces;
}

// Function for the player's move
void player_move() {
    int x, y;
    do {
        printf("Enter your move (row [1-3] and column [1-3]): ");
        scanf("%d %d", &x, &y);
        x--; // Adjusting for 0-based indexing
        y--;
        if (board[x][y] != ' ' || x < 0 || x > 2 || y < 0 || y > 2) {
            printf("Invalid move! Try again.\n");
        }
    } while (board[x][y] != ' ');
    board[x][y] = PLAYER;
}

// Function for the computer's move
void computer_move() {
    srand(time(0));
    int x, y;
    if (check_freespaces() > 0) {
        do {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }
}

// Function to check if there's a winner
char check_win() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }
    return ' '; // No winner yet
}

// Function to declare the winner
void print_winner(char winner) {
    if (winner == PLAYER) {
        printf("You win! Congratulations!\n");
    } else if (winner == COMPUTER) {
        printf("You lose! Better luck next time.\n");
    } else {
        printf("It's a draw!\n");
    }
}

// Main function
int main() {
    char winner = ' ';
    board_reset();

    while (winner == ' ' && check_freespaces() > 0) {
        print_board();
        player_move();
        winner = check_win();
        if (winner != ' ' || check_freespaces() == 0) {
            break;
        }
        computer_move();
        winner = check_win();
    }
    print_board();
    print_winner(winner);

    return 0;
}
