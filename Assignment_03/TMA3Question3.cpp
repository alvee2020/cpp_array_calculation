//: TMA3Question3.cpp

/*
 Title: TMA3Question3.cpp
 Description: Class, operator overloading with C++
 Date: January 25, 2020
 Author: Alvee H. Akash
 ID: 3433334
 Version: 1.0
 Copyright: 2020 Alvee H. Akash
 */


/*
 DOCUMENTATION

 Program Purpose:
 Documentation followed as GoodDocs.cpp,
 test plans are showed in the next paragraph,
 and comments are inline comments for better understanding.
 keyboard input N/A.

 Compile (Assuming GCC compiler istalled): g++ -o TMA3Question3 TMA3Question3.cpp
 Execution (assuming Cygwin is running): ./TMA3Question3

 Notes: in g++, main return type int

 Classes: DoStuff

 Variables:
 a - DoStuff - Instance of DoStuff class
 b - DoStuff - Instance of DoStuff class
 c - DoStuff - Instance of DoStuff class
 d - DoStuff - Instance of DoStuff class
 e - DoStuff - Instance of DoStuff class
 
 */

/*
 TEST PLAN

 Normal case:
 Printing a = 10, b = 5, c = 7
 10
 5
 7
 Creating d  = a + b - c
 Printing d from ostream
 8
 Creating g = --d
 7
 Creating w = g--
 7
 Creating w = --g
 5

 Discussion:
 This program creates a class of integer and does all types operator overloading like prefix ++ and --, postfix ++ and --, and operator + , - , and prints every calculation on the screen with proper comments so that it can be understood easily.
*/

// Header files
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

// DoStuff class
class DoStuff {
public:
    // class variable
    int integerVariable;
    
    // default constructor
    DoStuff(){}

    // Parameterized constructor
    DoStuff(int number){
        integerVariable = number;
    } // DoStuff

    // operator + overloading
    DoStuff operator+(DoStuff object){
        DoStuff newObject;
        newObject.integerVariable = integerVariable + object.integerVariable;
        return newObject;
    } // operator+

    // operator - overloading
    DoStuff operator-(DoStuff object){
        DoStuff newObject;
        newObject.integerVariable = integerVariable - object.integerVariable;
        return newObject;
    } // operator-

    // prefix ++ operator overloading
    DoStuff operator++(){
        DoStuff newObject;
        newObject.integerVariable = ++integerVariable;
        return newObject;
    } // operator++

    // prefix -- operator overloading
    DoStuff operator--(){
        DoStuff newObject;
        newObject.integerVariable = --integerVariable;
        return newObject;
    } // operator--

    // postfix ++ operator overloading
    DoStuff operator++(int){
        DoStuff newObject;
        newObject.integerVariable = integerVariable++;
        return newObject;
    } // operator++

    // postfix -- operator overloading
    DoStuff operator--(int){
        DoStuff newObject;
        newObject.integerVariable = integerVariable--;
        return newObject;
    } // operator--

    // print member function prints in ostream
    void print(ostream& stream){
        stream << integerVariable << endl;
    } // print

    // friend class helps to overload operator <<
    friend ostream& operator<< (ostream &out, const DoStuff &newObject);
}; // DoStuff

// prints ostream from class
ostream& operator<< (ostream &out, const DoStuff &newObject){
    out << newObject.integerVariable << endl;
    return out;
} // ostream&

int main(int argc, const char * argv[]) {

    //Self-documented program as it is describing in cout stream
    
    cout << "Printing a = 10, b = 5, c = 7\n";
    DoStuff a(10);
    DoStuff b(5);
    DoStuff c(7);

    // printing the values on the screen
    a.print(cout);
    b.print(cout);
    c.print(cout);
    
    DoStuff d = a + b - c;
    cout << "Creating d  = a + b - c\nPrinting d from ostream\n";
    cout << d;

    DoStuff g = --d;
    cout << "Creating g = --d\n";
    g.print(cout);
    
    DoStuff w = g--;
    cout << "Creating w = g--\n";
    w.print(cout);
    
    cout << "It will decrement 2 in here from previous calculation\n";
    
    w = --g;
    cout << "Creating w = --g\n";
    cout << w;

} ///:~
