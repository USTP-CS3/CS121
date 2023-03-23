/*
    (Sum of Even random numbers)
    Write a program that generates twenty five random
    integers between 0 and 25 and displays the sum of
    even integers. (Hint: Use rand() % 25) to generate
    a random integer between 0 and 25. Use an array of
    25 integers, say num, to store the random integers
    generated between 0 and 25
*/

#include <iostream>
#include <time.h>
#include <random>
using namespace std;

int main() {
    srand(time(0));

    // generate random numbers from 0 - 25
    int random[25];

    cout << "The array is: ";
    for (int i = 0; i < 25; i++) {
        const int r = rand() % 25;
        random[i] = r;

        cout << r << ", ";
    }
    cout << endl;

    // sum of even integers
    int sum = 0;
    for (int &r : random) {
        if (r % 2 == 0) {
            sum += r;
        }
    }

    cout << "The sum is: " << sum << endl;

    return 0;
}