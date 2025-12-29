#include <iostream>
using namespace std;

int main()
{   
    cout << "Name: M.Areeb" << endl;
    cout << "Roll No: 25i-3056" << endl;
    cout << "Task 01: Diagonal Swap Puzzle\n"<< endl;

    int n;
    cout << "Enter the size of square matrix (N x N): ";
    cin >> n;

    int matrix[10][10]; // Max size 10x10
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    cout << "\nBefore swap:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        int temp = matrix[i][i];
        matrix[i][i] = matrix[i][n - 1 - i];
        matrix[i][n - 1 - i] = temp;
    }

    // Display matrix after swap
    cout << "\nAfter swap:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}