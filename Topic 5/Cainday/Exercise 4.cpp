/*
    (Display pyramid)
    Write a program that prompts the user to enter an integer from 1 to 15
    and displays a pyramid
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    short n;
    cout << "Enter number of lines: ";
    cin >> n;
        
    for (short i = 0; i <= n; i++) {
        
        cout << right << setw(((n-i+1)*3));

        for (short j = i; j > 0; j--) {
            cout << "  " << j;
        }

        for (short j = 2; j < i+1; j++) {
            cout << "  " << j;
        }
        
        cout << endl;
    }



    return 0;
}