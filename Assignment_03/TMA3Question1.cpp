//: TMA3Question1.cpp

/*
 Title: TMA3Question1.cpp
 Description: Calculating array multiplication with time const with C++
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

 Compile (Assuming GCC compiler istalled): g++ -o TMA3Question1 TMA3Question1.cpp
 Execution (assuming Cygwin is running): ./TMA3Question1

 Notes: in g++, main return type int

 Classes: none

 Variables:
 start_time - const clock_t - used to take the system current time.
 end_time - const clock_t - used to take the system end time.

 */

/*
 TEST PLAN

 Normal case:
 Start time : 0.278649
 100    10099    1.0099e+06
 101    10098    1.0199e+06
 .
 .
 10098    101    1.0199e+06
 10099    100    1.0099e+06
 End time : 0.359323
 Elapsed time to multiply two arrays is : 0.080674


 Start time : 0.289764
 100    10099    1.0099e+06
 101    10098    1.0199e+06
 .
 .
 10098    101    1.0199e+06
 10099    100    1.0099e+06
 End time : 0.359853
 Elapsed time to multiply two arrays is : 0.070089

 Bad case:
 memory allocation problem occured once in my system.

 Discussion:
 This program creates two arrays and multiply them, show their results on the screen. It also detects the time taking for this calculation and shows on the screen. Mostly the printing on the screen takes a lot of time for this time difference calculation.
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
        double result = first_Array_Storage[i] * second_Array_Storage[i];
        cout << first_Array_Storage[i] << "\t"<<second_Array_Storage[i] <<"\t"<< result << endl;
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
double * second_Array(){
    static double array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = LOOP_COUNTER - i - 1;
        //cout << array[i];
    }
    return array;
} // second_Array
