/*
    Design a flowchart and write a program that prompts the user to 
    enter a word or statement and displays the number of vowels in the 
    file.
*/

#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

int main() {
    const char vowels[] = {'a', 'e', 'i', 'o', 'u'};

    ofstream MyFile("output.txt");
    string text;
 
    cout << "Enter a word: ";
    getline(cin, text);

    int counter = 0;
    for (auto &letter : text) {
        for (auto &vowel : vowels) {
            if (letter == vowel || letter-32 == vowel) {
                counter++;
                break;
            }  
        }
    }

    MyFile << "There are " << counter << " vowels in the file.\n";
    MyFile.close();

    return 0;
}