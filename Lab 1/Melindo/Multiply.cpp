#include <iostream>
using namespace std;

int main(){
    int num1, num2, count, i;
    
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    while (i < num2){
        i++;
        count += num1;
    }
    cout << num1 << " x " << num2 <<" = " << count  << endl;
}