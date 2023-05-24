/*
    (Game: hangman)
    Write a hangman game that randomly generates a word and prompts the user to
    guess one letter at a time, as shown in the sample run. Each letter in the
    word is displayed in an asterisk. When the user makes a correct guess, the
    actual letter is then displayed. When the user finishes a word, display the 
    number of misses and ask the user whether to continue for another word. 

    Declare an array to store words, as follows:

    // Use any words you wish
    string words[] = {"write", "that", ...}
*/

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main() {

    srand(time(NULL));

    const string words[] = {"write", "that", "program"};
    const int wordsLength = (sizeof(words) / sizeof(string));
    
    string guessed;
    string chosen(words[rand() % wordsLength]);
    
    for (char c : chosen) guessed += "*";

    int missed = 0;
    bool gameover = false;

    while (!gameover) {

        cout << "(Guess) Enter a letter in word " << guessed << " > ";        

        char letter;
        cin >> letter;

        // check if letter in word
        bool isAvailable = false;
        bool isDuplicate = false;

        for (int i = 0; i < chosen.length(); i++) {
            // duplicate found
            if (guessed[i] == letter) {
                isDuplicate = true;
                break;
            }
            // replace asterisk on chosen index
            else if (chosen[i] == letter) {
                isAvailable = true;
                guessed[i] = letter;
            }
        }
        
        if (isDuplicate) {
            cout << "\t" << letter << " is already in the word\n";
            missed++;
        }
        else if (!isAvailable) {
            cout << "\t" << letter << " is not in the word\n"; 
            missed++;
        }
        
        
        if (guessed == chosen) {
            cout << "The word is " << chosen; 
            cout << ". You missed " << missed << " time";
            cout << endl; 
            
            char choice;
            cout << "Do you want to guess for another word? Enter y or n> ";
            cin >> choice;

            gameover = (choice == 'y' || choice == 'Y') ? false : true; 
            
            if (!gameover) {
                chosen.assign(words[rand() % wordsLength]);
                guessed.clear();
                missed = 0;

                for (char c : chosen) guessed += "*";
            }
            else cout << " -- Game Over -- " << endl;
        }; 
    }

    return 0;
}