#include <iostream>
#include <vector>
using namespace std;

void display_board(vector<vector<char>> &board) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "--+---+--\n";
    }
    cout << "\n";
}

bool check_row(vector<vector<char>> &board) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;
    }
    return false;
}

bool check_col(vector<vector<char>> &board) {
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j])
            return true;
    }
    return false;
}

bool check_diag(vector<vector<char>> &board) {
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

bool check_winner(vector<vector<char>> &board) {
    return check_row(board) || check_col(board) || check_diag(board);
}

bool board_full(vector<vector<char>> &board) {
    for (auto &row : board)
        for (auto &cell : row)
            if (cell == ' ')
                return false;
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));

    char player = 'X';
    int row, col;

    cout << "Tic Tac Toe Game\n";
    cout << "Player X vs Player O\n";

    while (true) {
        display_board(board);

        cout << "Player " << player << " enter row and column (1-3): ";
        cin >> row >> col;

        row--; 
        col--;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[row][col] = player;

        if (check_winner(board)) {
            display_board(board);
            cout << "Player " << player << " wins!\n";
            break;
        }

        if (board_full(board)) {
            display_board(board);
            cout << "It's a draw!\n";
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}