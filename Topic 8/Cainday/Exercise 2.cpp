/*
    (Algebra: add two matrices)
    Write a function to add two matrices a and b and save the result in c.

    | a11 a12 a13 |     | b11 b12 b13 |     | a11+b11 a12+b12 a13+b13 |
    | a21 a22 a23 |  +  | b21 b22 b23 |  +  | a21+b21 a22+b22 a23+b23 |
    | a31 a32 a33 |     | b31 b32 b33 |     | a31+b31 a32+b32 a33+b33 |

    The header of the function is 

    const int N = 3;

    void addMatrix(const double a[][N], const double b[][N], double c[][N]);

    Each element cij is aij + bij. Write a test program that prompts the user to
    enter two 3 x 3 matrices and displays their addition.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int N = 3;
void addMatrix(const double a[][N], const double b[][N], double c[][N]);

int main() {
    double mat1[N][N] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    double mat2[N][N] = {
        {0,2,4},
        {1,4.5,2.2},
        {1.1,4.3,5.2}
    };

    double res[N][N];

    // cout << "Enter matrix1: ";
    // for (float (&m)[N] : mat1) {
    //     cin >> m[0];
    //     cin >> m[1];
    //     cin >> m[2];
    // }

    // cout << "Enter matrix2: ";
    // for (float (&m)[N] : mat2) {
    //     cin >> m[0];
    //     cin >> m[1];
    //     cin >> m[2];
    // }


    cout << "The addition of the matrices is: \n";

    cout << left << setprecision(3);

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) 
            cout << setw(6) << mat1[r][c];
        
        (r == 1) 
            ? cout << setw(6) << "+"
            : cout << setw(6) << " ";

        for (int c = 0; c < N; c++) 
            cout << setw(6) << mat2[r][c];
        
        (r == 1) 
            ? cout << setw(6) << "="
            : cout << setw(6) << " ";

        addMatrix(mat1, mat2, res);

        for (int c = 0; c < N; c++) 
            cout << setw(6) << res[r][c];

        cout << endl;
    }

    return 0;
}


void addMatrix(const double a[][N], const double b[][N], double c[][N]) {
    for (int r = 0; r < N; r++) {
        for (int s = 0; s < N; s++) {
            c[r][s] = a[r][s] + b[r][s];
        }
    }
}
