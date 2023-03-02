/*
    Check if letter is a palindrome
*/

#include <iostream>
using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    bool result = true;
    string word = "";


    for (int i = 0; i < sentence.length(); i++) {
        char letter = sentence[i];
        
        // skip a space
        if ((char)sentence[i] == 32) {
            continue;
        }
        // if next is ' ' or is last
        else if ((char)sentence[i+1] == 32 || i+1 == sentence.length()) {
            word += letter;
            result = true;

            for (int i = 0; i < word.length(); i++) {
                if (word[i] != word[word.length() - (i+1)]) {
                    result = false;
                    break;
                }
            }

            (result) 
                ? cout << word << " is a palindrome\n"
                : cout << word << " is not a palindrome\n"; 

            // reset word
            word = "";
        }
        // increment letter to word
        else {
            word += letter;
        }
    }
    return 0;
}