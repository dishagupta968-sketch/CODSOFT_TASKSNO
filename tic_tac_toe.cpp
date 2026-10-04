#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Display the board
void printBoard(const vector<char>& board) {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
    cout << "\n";
}

// Check whether a player has won
bool checkWin(const vector<char>& board, char player) {
    int winningPatterns[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    for (auto &pattern : winningPatterns) {
        if (board[pattern[0]] == player &&
            board[pattern[1]] == player &&
            board[pattern[2]] == player) {
            return true;
        }
    }

    return false;
}

// Check if board is full
bool isBoardFull(const vector<char>& board) {
    for (char cell : board) {
        if (cell != 'X' && cell != 'O')
            return false;
    }
    return true;
}

// Minimax with Alpha-Beta Pruning
int minimax(vector<char>& board, int depth, bool isMaximizing,
            int alpha, int beta) {

    // AI wins
    if (checkWin(board, 'O'))
        return 10 - depth;

    // Human wins
    if (checkWin(board, 'X'))
        return depth - 10;

    // Draw
    if (isBoardFull(board))
        return 0;

    if (isMaximizing) {
        int bestScore = -1000;

        for (int i = 0; i < 9; i++) {
            if (board[i] != 'X' && board[i] != 'O') {

                board[i] = 'O';

                int score = minimax(board, depth + 1, false,
                                    alpha, beta);

                board[i] = '1' + i;

                bestScore = max(bestScore, score);
                alpha = max(alpha, bestScore);

                // Alpha-Beta pruning
                if (beta <= alpha)
                    break;
            }
        }

        return bestScore;
    }

    else {
        int bestScore = 1000;

        for (int i = 0; i < 9; i++) {
            if (board[i] != 'X' && board[i] != 'O') {

                board[i] = 'X';

                int score = minimax(board, depth + 1, true,
                                    alpha, beta);

                board[i] = '1' + i;

                bestScore = min(bestScore, score);
                beta = min(beta, bestScore);

                // Alpha-Beta pruning
                if (beta <= alpha)
                    break;
            }
        }

        return bestScore;
    }
}

// Find the best move for AI
int findBestMove(vector<char>& board) {
    int bestScore = -1000;
    int bestMove = -1;

    for (int i = 0; i < 9; i++) {

        if (board[i] != 'X' && board[i] != 'O') {

            board[i] = 'O';

            int score = minimax(board, 0, false,
                                -1000, 1000);

            board[i] = '1' + i;

            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }

    return bestMove;
}

// Main function
int main() {

    vector<char> board = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9'
    };

    cout << "=================================\n";
    cout << "       TIC-TAC-TOE AI GAME       \n";
    cout << "=================================\n";

    cout << "\nYou are X\n";
    cout << "AI is O\n";

    cout << "\nBoard positions:\n";
    printBoard(board);

    while (true) {

        // Human's turn
        int playerMove;

        cout << "Enter your move (1-9): ";
        cin >> playerMove;

        if (playerMove < 1 || playerMove > 9) {
            cout << "Invalid move! Enter a number from 1 to 9.\n";
            continue;
        }

        int index = playerMove - 1;

        if (board[index] == 'X' || board[index] == 'O') {
            cout << "That position is already occupied!\n";
            continue;
        }

        board[index] = 'X';

        printBoard(board);

        // Check human win
        if (checkWin(board, 'X')) {
            cout << "Congratulations! You won!\n";
            break;
        }

        // Check draw
        if (isBoardFull(board)) {
            cout << "It's a draw!\n";
            break;
        }

        // AI's turn
        cout << "AI is thinking...\n";

        int aiMove = findBestMove(board);

        board[aiMove] = 'O';

        cout << "AI selected position: " << aiMove + 1 << "\n";

        printBoard(board);

        // Check AI win
        if (checkWin(board, 'O')) {
            cout << "AI wins! Better luck next time.\n";
            break;
        }

        // Check draw
        if (isBoardFull(board)) {
            cout << "It's a draw!\n";
            break;
        }
    }

    cout << "\nGame Over!\n";

    return 0;
}