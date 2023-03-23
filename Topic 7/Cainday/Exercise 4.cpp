/*
    (Statistics: Compute Deviation)
    Programming Exercise 5.47 computes the standard deviation of numbers.
    This exercise uses a different but equivalent formulat to compute
    the standard deviation of n numbers.

    mean = (x1 + x2 + . . . + xn) / n
    deviation = √ ( nΣ(xi - mean)^2 / n - 1 ) 

    To compute deviation with this formula, you have to store the
    individual numbers using an array, so that they can be used after
    the mean is obtained.

    Your program should contain the following functions:

    // compute the mean of an array of double values
    double mean(const double x[], int size)

    // compute the deviation of double values
    double deviation(const double x[], int size)

    Write a program that prompts the user to enter 10 numbers and dispalys
    the mean and deviation, as shown in the following sample run:
*/

#include <iostream>
#include <math.h>
using namespace std;

// compute the mean of an array of double values
double mean(const double x[], int size);

// compute the deviation of double values
double deviation(const double x[], int size);


int main() {

    const short size = 10;
    double numbers[size];
    
    cout << "Enter ten numbers: ";

    for (double &num : numbers) 
        cin >> num;

    double m = mean(numbers, size);
    double d = deviation(numbers, size);

    cout << "The mean is: "               << m << endl
         << "The standard deviation is: " << d << endl;

    return 0;
}

double mean(const double x[], int size) {    
    double sum = 0;
    
    for (int i = 0; i < size; i++) 
        sum += x[i];    

    return (sum / size);
}

double deviation(const double x[], int size) {
    const double m = mean(x, size);

    double sum = 0;
    
    for (int i = 0; i < size; i++) {
        sum += pow(x[i] - m, 2);
    }

    return sqrt( sum / (size - 1) );
}