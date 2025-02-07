#include <iostream>
#include <clocale>
using namespace std;

const int n = 8;
int queens[n];
int counter = 0;


void printSolution()
{
    counter++;
    cout << "Решение " << counter << ":" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (queens[i] == j)
            {
                cout << "Q ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
    cout << endl;
    return;
}


bool check(int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        if (queens[i] == col)
        {
            return false;
        }
        if (abs(queens[i] - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}


void searchSolution(int row)
{
    if (row == n)
    {
        printSolution();
    }
    else {
        for (int col = 0; col < n; ++col)
        {
            if (check(row, col))
            {
                queens[row] = col;
                searchSolution(row + 1);
            }
        }
    }
    return;
}

int main()
{
    setlocale(LC_ALL, "ru");
    searchSolution(0);
    cout << "Всего решений: " << counter << endl;
    return 0;
}
