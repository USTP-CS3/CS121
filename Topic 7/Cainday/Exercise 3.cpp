/*
    (Strictly Identical Arrays)
    Two arrays list1 and list2 are strictly identical if
    they have the same length and list[i] is equal to 
    list2[i] for each i. Write a function that returns true
    if list1 and list2 are strictly identical using the 
    following header:

    bool strictlyEqual(const int list1[], const int list2[], 
        int size)

    Write a test program that prompts the user to enter two 
    lists of integers and displays whether the two are 
    strictly identical. The sample runs follow. Note that
    the first number in the input indicates the number of 
    the elements in the list. This number is not part of
    the list. Assume the list size maximum is 20.
*/

#include <iostream>
using namespace std;

bool strictlyEqual(const char list1[], const char list2[], int size);

int main() {
    const int size = 20;
    char list1[size] = {};
    char list2[size] = {};

    cout << "Enter list1: ";
    cin.getline(list1, size);

    cout << "Enter list2: ";
    cin.getline(list2, size);
    
    const bool result = strictlyEqual(list1, list2, size);

    (result)
        ? cout << "Two lists are strictly identical\n"
        : cout << "Two lists are not strictly identical\n"; 

    return 0;
}

bool strictlyEqual(const char list1[], const char list2[], int size) {
    for (int i = 0; i < size; i++) {
        if (list1[i] != list2[i])
            return false; 
    }
    return true;
}