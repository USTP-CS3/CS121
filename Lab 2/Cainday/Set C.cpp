/*
    Write a program that prompts the user to enter two
    characters and displays the course, program, and year
    level represented in the characters. The first
    character indicates the course program and the second
    is number character 1, 2, 3, 4, which indicates 
    whether a student is a freshman, sophomore, junior,
    or senior. 
    
    Suppos the following characters are use to denote the
    majors:

    D: Data Science
    C: Computer Science
    I: Information Technology
*/

#include <iostream>
#include <map>
using namespace std;

int main() {
    char course;
    int  year;

    cout << "D: Data Science\n"           
         << "C: Computer Science\n"       
         << "I: Information Technology\n\n" 
         << "Enter Course & Year: ";

    cin >> course >> year;

    map<char, string> Course;
    Course['D'] = "Data Science";
    Course['C'] = "Computer Science";
    Course['I'] = "Information Technology";

    map<int, string> Year;
    Year[1] = "Freshman";
    Year[2] = "Sophomore";
    Year[3] = "Junior";
    Year[4] = "Senior";

    cout << endl
         << "Course: " << Course[course] << endl
         << "Year: "   << Year[year]     << endl;

    return 0;
}