#include <iostream>
using namespace std;
int main()
{
    int matrix[3][3];
    int r1 = 0, r2 = 0, r3 = 0, c1 = 0, c2 = 0, c3 = 0, maindiagonal = 0, secondarydiagonal = 0, overallsum = 0;
    int sum = 0;
    cout<<"ENTER ELEMENTS DEAR SIR"<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {   
        cout<<"[";
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout<<"]"<<endl;
    }
    cout << endl;
    for (int j = 0; j < 3; j++)
    {
        r1 += matrix[0][j];
    }

    for (int j = 0; j < 3; j++)
    {
        r2 += matrix[1][j];
    }

    for (int j = 0; j < 3; j++)
    {
        r3 += matrix[2][j];
    }
    for (int i = 0; i < 3; i++)
    {
        c1 += matrix[i][0];
    }
    for (int i = 0; i < 3; i++)
    {
        c2 += matrix[i][1];
    }
    for (int i = 0; i < 3; i++)
    {
        c3 += matrix[i][2];
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            overallsum += matrix[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                maindiagonal += matrix[i][j];
            }
            if (i + j == 2)
            {
                secondarydiagonal += matrix[i][j];
            }
        }
    }
    cout << "ROW 1" << "=" << r1 << endl;
    cout << "ROW 2" << "=" << r2 << endl;
    cout << "ROW 3" << "=" << r3 << endl;
    cout << "COLUMN 1" << "=" << c1 << endl;
    cout << "COLUMN 2" << "=" << c2 << endl;
    cout << "COLUMN 3" << "=" << c3 << endl;
    cout << "MAIN DIAGONAL" << "=" << maindiagonal << endl;
    cout << "SECONDARY DIAGONAL" << "=" << secondarydiagonal << endl;
    cout << "OVERALL SUM " << "=" << overallsum << endl;

    return 0;
}
