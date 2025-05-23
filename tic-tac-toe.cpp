#include <stdio.h>

char board[3][3];  // 3x3 game board
char currentPlayer;  // 'X' or 'O'

// Function to initialize the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Function to display the current state of the board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin() {
    for (int i = 0; i < 3; i++) {
        // Rows
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return 1;
        // Columns
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return 1;
    }
    // Diagonals
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return 1;
    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return 1;
    return 0;
}

// Function to check for a draw (no empty spaces)
int checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to make a move
int makeMove() {
    int row, col;
    printf("Player %c, enter row and column (1-3 for both): ", currentPlayer);
    scanf("%d %d", &row, &col);
    row--; col--;  // Adjust for 0-indexing

    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            return 1;
        } else {
            printf("Cell already taken! Try again.\n");
        }
    } else {
        printf("Invalid input! Try again.\n");
    }
    return 0;
}

// Main function
int main() {
    initializeBoard();
    currentPlayer = 'X';

    while (1) {
        displayBoard();
        if (!makeMove()) continue;

        if (checkWin()) {
            displayBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (checkDraw()) {
            displayBoard();
            printf("It's a draw!\n");
            break;
        }

        switchPlayer();
    }

    return 0;
}

