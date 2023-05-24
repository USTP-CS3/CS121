#include <iostream>
#include <string>
#include <math.h>
using namespace std;

/*
  UML DIAGRAM

  |-----------------------------------------------|
  |             Class Name: MyInteger             |
  |-----------------------------------------------|
  |                                               |    
  |     - int value;                              |
  |                                               |
  |------------------------------------------------
  |     + MyInteger()                             |
  |     + getValue ()     : int                   |
  |     + isEven   (int)  : bool                  |
  |     + isOdd    (int)  : bool                  |
  |     + isPrime  (int)  : bool                  |
  |     + equals   (int)  : bool                  |
  |     + equals   (const MyInteger&) : bool      |
  |                                               |
  |     + isEven   (const MyInteger&) : bool      |
  |       -----------------------------------     |
  |     + isOdd    (const MyInteger&) : bool      |
  |       -----------------------------------     |
  |     + isPrime  (const MyInteger&) : bool      |
  |       -----------------------------------     |
  |     + parseInt (const string&)    : int       |
  |       -----------------------------------     |
  |                                               |
  |-----------------------------------------------|

*/

class MyInteger {
  private:
    int value;

  public:
    MyInteger (int value) {
      this->value = value;
    }
    
    int getValue() {
      return value;
    }

    bool isEven(int val) {
      return val % 2 == 0;
    }

    bool isOdd(int val) {
      return val % 2 != 0;
    }

    bool isPrime(int val) {
      bool isPrime = true;
      for (int i = 2; i <= sqrt(val); i++) {
        if (val % i == 0) {
          isPrime = false;
          break;
        }
      }
      return isPrime;
    }

    bool equals(int val) {
      return val == this->value; 
    }

    bool equals(const MyInteger& ref) {
      return ref.value == this->value; 
    }

    static bool isEven(const MyInteger& ref) {
      return ref.value % 2 == 0;
    }

    static bool isOdd(const MyInteger& ref) {
      return ref.value % 2 != 0;
    }

    static bool isPrime(const MyInteger& ref) {
      bool isPrime = true;
      for (int i = 2; i <= sqrt(ref.value); i++) {
        if (ref.value % i == 0) {
          isPrime = false;
          break;
        }
      }
      return isPrime;
    }

    static int parseInt(const string& str) {
      return stoi(str);
    }
};

int main() {
  
    MyInteger myint1 = MyInteger(5);
    MyInteger myint2 = MyInteger(5);


     cout << "Value: "           << myint1.getValue()                  << endl;                       
     cout << "isEven: "          << myint1.isEven(  myint2.getValue()) << endl;                    
     cout << "isOdd: "           << myint1.isOdd(   myint2.getValue()) << endl;                    
     cout << "isPrime: "         << myint1.isPrime( myint2.getValue()) << endl;                    
     cout << "isEqual: "         << myint1.equals(  myint2.getValue()) << endl;  
     cout << "static_isEqual: "  << myint1.equals(  myint2)            << endl;
     cout << "static_isEven: "   << MyInteger::isEven(myint2)          << endl;
     cout << "static_isOdd: "    << MyInteger::isOdd(myint2)           << endl;
     cout << "static_isPrime: "  << MyInteger::isPrime(myint2)         << endl;
     cout << "static_parseInt: " << MyInteger::parseInt("432")         << endl;

  return 0;
}
