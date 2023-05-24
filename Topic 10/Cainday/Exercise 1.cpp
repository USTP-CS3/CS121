/*
    (Anagrams)
    Write a function that checks whether two words are anagrams.
    Two words are anagrams if they contain the same letters in any order.
    For example, "silent" and "listen" are anagrams. The header of the
    function is as follows:

    bool isAnagram(const string& s1, const string& s2)

    Write a test program that prompts the user to enter two strings and
    checks whether they are anagrams.
*/

#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;


bool isAnagram(const string& s1, const string& s2);

int main() {
    string str1, str2;
    cout << "Input two strings: " << endl;
    getline(cin, str1);
    getline(cin, str2);
    cout << isAnagram(str1, str2) << endl;
    return 0;
}


bool isAnagram(const string& s1, const string& s2) {
    string sortedS1 = s1;
    string sortedS2 = s2;
    
    sort(sortedS1.begin(), sortedS1.end());
    sort(sortedS2.begin(), sortedS2.end());

    return strcmp(sortedS1.c_str(), sortedS2.c_str()) == 0;
}