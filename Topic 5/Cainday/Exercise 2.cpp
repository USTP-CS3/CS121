/*
    (Longest common prefix)
    Write a program that prompts the user to enter two strings and display the
    largest common prefix of the two strings.

*/

#include <iostream>
#include <string>
using namespace std;

int main() {

    string s1, s2;

    cout << "Enter s1: ";
    getline(cin, s1);
    cout << "Enter s2: ";
    getline(cin, s2);

    string sw1 = "";
    string sw2 = ""; 
    string bucket = "";
    string longest = "";

    for (short i = 0; i <= s1.size(); i++) {
    
        if (i == s1.size() || s1[i] == ' ') {
    
            for (short j = 0; j <= s2.size(); j++) {
                if (j == s2.size() || s2[j] == ' ') {
                    
                    cout << sw1 << " <=> " << sw2 << endl;

                    for (short k = 0; k < sw1.size() && k < sw2.size(); k++) {
                        if (sw1[k] == sw2[k]) {
                            bucket += sw1[k];
                        }
                        else {
                            if (bucket.size() > longest.size()) {
                                longest = bucket;
                            }
                            bucket = "";
                        }
                    }

                    sw2 = "";
                }
                else
                    sw2 += s2[j];        
            }

            sw1 = "";
        }
        else
            sw1 += s1[i];        
    }

    (longest.size() > 0) 
        ? cout << "The common prefix is " << longest
        : cout << s1 << " and " << s2 << " have no common prefix";

    cout << endl;
    
    return 0;
}