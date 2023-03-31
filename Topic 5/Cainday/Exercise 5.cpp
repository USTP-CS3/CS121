/*
    (Occurence of max numbers)
    Write a program that reads integers, finds the largest of them, and counts
    its occurences. Assume that the input ends with number 0. Suppose that you 
    entered 3 5 2 5 5 5 0; the programs finds that the largest is 5 and the 
    occurecne count for 5 is 4.

    (Hint: Maintain two variables, max and count.)
    max stores the current max number, and count stores its occurences. Initially,
    assign the first number to max and 1 count. Compare each subsequent number with
    max. If the number is greater than max, assign it to max and reset count to 1.
    If the number is equal to max, increment count by 1.
*/

#include <iostream>
using namespace std;

int main() {

    short max = 0;
    short count = 0;
    
    cout << "Enter numbers: ";
    
    while (true) {
        float input;
        cin >> input;
        
        if (input == 0) break;

        if (input > max) {
            max = input;
            count = 0;
        }

        if (input == max) count++;
    }

    cout << "The largest number is " << max << endl;           
    cout << "The occurence count of the largest number is " << count << endl;

    return 0;
}