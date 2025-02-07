#include <iostream>
using namespace std;

const int N = 8; // Размер доски

// Доска будет представлена двумерным массивом
char board[N][N];

// Функция для печати доски
void printBoard() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

// Проверка безопасности размещения ферзя
bool isSafe(int row, int col) {
    // Проверка по вертикали
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Проверка по левой диагонали
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Проверка по правой диагонали
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

// Рекурсивная функция для размещения ферзей
bool solveNQueens(int row) {
    if (row == N) {
        printBoard();
        return true;
    }

    bool result = false;
    for (int col = 0; col < N && !result; ++col) {
        if (isSafe(row, col)) {
            board[row][col] = 'Q';
            result = solveNQueens(row + 1);
            if (!result) {
                board[row][col] = '*'; // Сброс ячейки при неудаче
            }
            else {
                break; // Решение найдено, прерываем цикл
            }
        }
    }
    return result;
}

int main() {
    // Инициализация доски звездочками
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            board[i][j] = '*';
        }
    }

    if (solveNQueens(0)) {
        cout << "Решение найдено!" << endl;
    }
    else {
        cout << "Нет решений." << endl;
    }

    return 0;
}