/*
    (Algebra: solve linear equations)
    Write a function that solves the following 2 x 2 system of linear 
    equations. 

    a00x + a01y = b0   
    a10x + a11y = b1

    x = b0a11  -  b1a01
        ---------------
        a00a11 - a01a10

    y = b1a00  -  b0a10
        ---------------
        a00a11 - a01a10


    The function header is 

    const int SIZE = 2;

    bool linearEquation(
            const double a[][SIZE], 
            const double b[], 
            double result[]);

    The function results false if a00a11 - a01a10 is 0; 
    otherwise, returns true. 

    Write a test program that prompts the user to enter 
    a00, a01, a10, a11, b0, b1, and display the result.

    If a00a11 - a01a10 is 0, report that "The equation has no solution".
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 2;
bool linearEquation(const double a[][SIZE], const double b[], double result[]);

int main() {
    double a[SIZE][SIZE];
    double b[SIZE];
    double result[SIZE];

    cout << "Enter a00, a01, a10, a11, b0, b1: ";
    
    for (short i = 0; i < SIZE; i++) 
        for (short j = 0; j < SIZE; j++)
            cin >> a[i][j];

    for (short i = 0; i < SIZE; i++)
        cin >> b[i];

    bool check = linearEquation(a, b, result);

    cout << fixed << setprecision(1);
    (check)
        ? cout << "x is " << result[0] << " and y is " << result[1]
        : cout << "The equation has no solution";
    
    cout << endl;

    return 0;
}

bool linearEquation(const double a[][SIZE], const double b[], double result[]) {
    
    const double denominator = (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);

    if (denominator == 0) 
        return false;
    
    result[0] = ((b[0] * a[1][1]) - (b[1] * a[0][1])) / denominator;
    result[1] = ((b[1] * a[0][0]) - (b[0] * a[1][0])) / denominator;

    return true;

}

