/*
    Write a program that reads integers from the file and
    displays their sum, average, and product
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream ReadFile("input.txt");

    int num,
        sum = 0,
        average = 0, 
        product = 1, 
        counter = 0;
    
    while(ReadFile >> num) {
        counter++;
        sum += num;
        product *= num;
        cout << product << endl;
    }
    average = sum / counter;

    cout << "Sum: "      << sum     << endl
         << "Average: "  << average << endl
         << "Product: "  << product << endl;

    ReadFile.close();
    return 0;
}