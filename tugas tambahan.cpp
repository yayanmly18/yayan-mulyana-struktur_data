#include <iostream>
using namespace std;

int main()
{
    int matrixA[2][2];
    int matrixB[2][2];

    // Input matrix A
    cout << "Masukkan nilai dari matrix A: " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Matrix A[" << i << "][" << j << "] = ";
            cin >> matrixA[i][j];
        }
    }

    // Input matrix B
    cout << "Masukkan nilai dari matrix B: " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Matrix B[" << i << "][" << j << "] = ";
            cin >> matrixB[i][j];
        }
    }

    // Multiply matrix A and matrix B
    int matrixC[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matrixC[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    // Output matrix C
    cout << "Matrix C (hasil perkalian matrix A x matrix B) = " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << matrixC[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
