/*
    (Financial application: compute future apartment rent)
    Suppose that the rent for an apartment is $1000 this year and increases
    3% every year. Write a program that computes the rent in 5 years and the 
    total rent for one year starting 5 years from now.
*/

#include <iostream>
using namespace std;

int main() {

    float rent = 1000;
    const float rate = 0.03;
    const short numYears = 5;

    float total = rent;
    for (short i = 0; i <= numYears; i++) {
        
        cout << "rent: " << rent << " total: " << total;
        cout << endl;

        rent += rent * rate;
        total += rent;
    }

    return 0;
}