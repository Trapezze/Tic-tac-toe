#include <iostream>
#include <vector>

// Отрисовка игрового поля
void drawBoard(const std::vector<char>& board) {
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
}

// Проверка условия победы
bool checkWin(const std::vector<char>& board, char player) {
    return ((board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player));
}

int main() {
    setlocale (LC_ALL, "Russian");
    std::vector<char> board = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int currentPlayer = 1;
    bool gameWon = false;

    while (!gameWon) {
        drawBoard(board);

        int move;
        if (currentPlayer == 1) {
            std::cout << "Ходит игрок 1 (крестики). Ваш ход: ";
            std::cin >> move;
            board[move - 1] = 'X';
        }
        else {
            std::cout << "Ходит игрок 2 (нолики). Ваш ход: ";
            std::cin >> move;
            board[move - 1] = 'O';
        }

        gameWon = checkWin(board, currentPlayer == 1 ? 'X' : 'O');
        currentPlayer = currentPlayer == 1 ? 2 : 1;
    }

    drawBoard(board);
    std::cout << "Игрок " << (currentPlayer == 1 ? 2 : 1) << " победил!" << std::endl;

    return 0;
}
