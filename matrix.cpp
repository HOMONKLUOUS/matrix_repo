#include <iostream>
using namespace std;

int trace(int matrix[20][20], int n)
{
    int trace = 0;
    for (int i = 0; i < n; i++)
    {
        trace += matrix[i][i];
    }
    return trace;
}

void mini_matrix(int matrix[20][20], int temp[20][20], int p, int q, int n)
{
    int row = 0, col = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != p && q != j)
            {
                temp[row][col++] = matrix[i][j];
                if (col == n - 1)
                {
                    col = 0;
                    row ++;
                }
            }
        }
    }
}


int determinal(int matrix[20][20], int n)
{
    if (n == 1)
        return matrix[0][0];
    if (n == 2)
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        
    int det = 0;
    int temp[20][20];
    int sign;
    
    for (int col = 0; col < n; col++)
    {
        if (col % 2 == 0)
            sign = 1;
        else
            sign = -1;
            
            
        mini_matrix(matrix, temp, 0, col, n);
        
        det += sign * matrix[0][col] * determinal(temp, n - 1);
    }
    
    return det;
}

void tra(int new_matrix[20][20], int n) {
    
    cout << "tranahade: " << endl;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << new_matrix[j][i] << " ";
        }
        cout << endl;
    }
}

void make(int n) {
    int matrix[20][20]; 

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Element: ";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    tra(matrix, n); 
    cout << "determinal is: " << determinal(matrix, n) << endl;
    cout <<" trace is: " << trace(matrix, n);
}


int main()
{
    int n;
    cout <<"row and col: ";
    cin >> n;

    make(n);
    
    return 0;
    
}