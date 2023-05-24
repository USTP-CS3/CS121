/*
    (The Location class)
    Design a class named Location for locating a maximum value and its location
    in a two-dimensional array. The class contains public data fields, row, column,
    and maxValue that store the maximal value and its indices in a two-dimensional
    array with row and column as int type and maxValue as double type.

    Write the following function that returns the location of the largest element
    in a two-dimensioal array. Assume that the column size is fixed.

    const int ROW_SIZE = 3;
    const int COLUMN_SIZE = 4;
    Location locateLargest(const double a[][COLUMN_SIZE]);

    The return value is an instance of Location. Write a test program that prompts
    the user to enter a two-dimensional array and displays the location of the 
    largest element in the array. Here is a sample run:
*/

#include <iostream>
#include "Location.h"
using namespace std;


const int ROW_SIZE = 3;
const int COLUMN_SIZE = 4;
Location locateLargest(const double a[][COLUMN_SIZE]);

int main() {

    double vertices[ROW_SIZE][COLUMN_SIZE] = {
        {23.5, 35, 2, 10},
        {4.5, 3, 45, 3.5},
        {35, 44, 5.5, 9.6}
    };

    // manual user input
    // for (int r = 0; r < ROW_SIZE; r++) {
    //     for (int c = 0; c < COLUMN_SIZE; c++) {
    //         cout << "Enter value at [" << r << "]["<< c << "]: ";
    //         cin >> vertices[r][c];
    //     }
    // }

    Location maxLoc = locateLargest(vertices);

    cout << "The location of the largest element is "
         << maxLoc.maxValue << " at "
         << "(" << maxLoc.row << ", " << maxLoc.column << ")"
         << endl;

    return 0;
}

Location locateLargest(const double a[][COLUMN_SIZE]) {
    Location maxLoc;
    for (int r = 0; r < ROW_SIZE; r++) {
        for (int c = 0; c < COLUMN_SIZE; c++) {
            if (a[r][c] > maxLoc.maxValue) {
                maxLoc.maxValue = a[r][c];
                maxLoc.column = c;
                maxLoc.row = r;
            }
        }
    }

    return maxLoc;
}