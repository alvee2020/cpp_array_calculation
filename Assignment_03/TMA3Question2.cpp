//: TMA3Question2.cpp

/*
 Title: TMA3Question2.cpp
 Description: Calculating array multiplication with time const Inline function with C++
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

 Compile (Assuming GCC compiler istalled): g++ -o TMA3Question2 TMA3Question2.cpp
 Execution (assuming Cygwin is running): ./TMA3Question2

 Notes: in g++, main return type int

  Classes: none

 Variables:
 start_time - const clock_t - used to take the system current time.
 end_time - const clock_t - used to take the system end time.

 */

/*
 TEST PLAN

 Normal case:
 Start time : 0.285219
 100    10099    1.0099e+06
 101    10098    1.0199e+06
 .
 .
 .
 10098    101    1.0199e+06
 10099    100    1.0099e+06
 End time : 0.362287
 Elapsed time to multiply two arrays is : 0.077068


 Start time : 0.306194
 100    10099    1.0099e+06
 101    10098    1.0199e+06
 .
 .
 10098    101    1.0199e+06
 10099    100    1.0099e+06
 End time : 0.36711
 Elapsed time to multiply two arrays is : 0.060916


 Bad case (N/A for every system):
 memory allocation problem occured once in my system.

 Discussion:
 This program creates two arrays and multiply them, show their results on the screen. it also detects the time taking for this calculation and shows on the screen. Mostly it does time to show the result on the screen. Inline function makes it a little fast than the non-inline function program.

 Important Note: After a number of tests, I realized that the time changes can be seen because inline function makes it a little faster, it is not too noticeable if we use 10000. If I increase the array size, it increases a little more time difference in my computer. It makes big difference in other systems. I tested my code in Windows which has less configuartion than my MacBook Pro. It seemed that it was more noticeable time difference. MacBook Pro(i7, 3.5 GHz), Windows(i5, 1.8 GHz)
*/

// Header files
#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;

// functions initialize
double * first_Array();
double * second_Array();

// const value initialize
const int ARRAY_SIZE = 10000;
const double STARTING_NUMBER = 100;
const double LOOP_COUNTER = ARRAY_SIZE + STARTING_NUMBER;


// inline function to call inside the for loop
inline double multiply(double first_array_number, double second_array_number){return first_array_number * second_array_number;}

int main(int argc, const char * argv[]) {
    // Initializing two arrays
    double *first_Array_Storage;
    double *second_Array_Storage;

    // const Time taker for starting time
    const clock_t start_time = clock();
    cout << "Start time : " << ((float) start_time) / CLOCKS_PER_SEC << endl;

    // Storing two Arrays from the functions here
    first_Array_Storage = first_Array();
    second_Array_Storage = second_Array();

    // calculating both arrays multiplications
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << first_Array_Storage[i] << "\t"<<second_Array_Storage[i] <<"\t"<< multiply(first_Array_Storage[i], second_Array_Storage[i]) << endl;
    }// for

    // const Time taker for ending time
    const clock_t end_time = clock();
    cout << "End time : " << ((float) end_time) / CLOCKS_PER_SEC << endl;

    // Calculating the elapsed time for the multiplications
    clock_t elapsed = end_time - start_time;
    cout << "Elapsed time to multiply two arrays is : ";
    cout << ((float) elapsed ) / CLOCKS_PER_SEC << endl;
    
    return 0;
} ///:~

// function for first array initialization
double * first_Array(){
    static double array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i + STARTING_NUMBER;
    }
    return array;
} // first_array

// function for second array initialization
double* second_Array(){
    static double array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = LOOP_COUNTER - i - 1;
        //cout << array[i];
    }
    return array;
} // second_Array
