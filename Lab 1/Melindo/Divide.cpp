#include <iostream>
using namespace std;

int main()
{
    int num1 = 0;
    int num2 = 0;
    int count = 0;
    
    cout << "Input num1: ";
    cin >> num1;
    cout << "Input num2: ";
    cin >> num2;
    
    while (num1 >= num2){
        num1 -= num2;
        count += 1;
    }
    cout << count << endl;
}