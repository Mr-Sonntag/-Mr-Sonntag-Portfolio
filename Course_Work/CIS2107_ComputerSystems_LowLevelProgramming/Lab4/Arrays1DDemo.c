/*
 *  Zachary Sonntag
 *  915640716
 *  9/17/25
 *  CIS2107_003
 *
 *                  Lab 04 Processing1DArrays
 *              This lab consists 5 functions for array manipulation on 1DArrays: fillArray, findWithRange, reverseArray,
 *              reverseSelectedRangeWithinArray, and findSequence.
 *
 *              fillArray receives user input on a range they'd like the array to be filled with. The array will then be
 *              filled randomly with integers in that range.
 *
 *              findWithRange receives user input on a range of indices within the array in which the function finds the
 *              largest integer found and returns it.
 *
 *              reverseArray will reverse the array.
 *
 *              reverseSelectedRangeWithinArray receives user input on a range of indices within the array in which the
 *              function will reverse the values within the selected range.
 *
 *              findSequence receives user input on two integer values a and b. The function will return the index at
 *              which the sequence a and b is found, else it will return -1, indicating no such sequence was found.
 *
 *
 */

//#include "Arrays1DDemo.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Global Variables
#define SIZE 40
#define MIN_INT (-2147483648)
#define MAX_INT 2147483647
bool accepted = false;


// Function Prototypes
void fillArray(int array[], int rand_min,int rand_max);
int findWithRange(int array[], int low, int high);
void reverseArray(int array[]);
void reverseSelectedRangeWithinArray(int array[], int startRange, int endRange);
int findSequence(int array[], int tom, int jerry);

//FillArray fills an array with random ints in range
//rand_min-rand_max
void fillArray(int array[], int rand_min,int rand_max) {

    srand(time(NULL));

    for (size_t i = 0; i < SIZE; i++) {
        array[i] = (rand() % (rand_max-rand_min+1))+rand_min;
        printf("\n\tArray[%d] = %d", i, array[i]);
    }

}

//FindWithRange returns largest int within the range
//of low-high
int findWithRange(int array[], int low, int high) {
    int max = 0;

    for (size_t i = low; i <= high; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}

//ReverseArray reverses a given array
void reverseArray(int array[]) {

    int y = SIZE - 1;
    int temp = 0;

    for (size_t i = 0; i < SIZE/2; i++) {
        temp = array[i];
        array[i] = array[y];
        array[y] = temp;
        y--;
    }

    puts("\n\tREVERSED ARRAY:");
    for (size_t i = 0; i < SIZE; i++) {
        printf("\n\tArray[%d] = %d", i, array[i]);
    }



}

/*
*ReverseSelectedRangeWithinArray reverse the elements
*within an array in the given range of indexes from
*startRange-endRange.
*/
void reverseSelectedRangeWithinArray(int array[], int startRange, int endRange) {
    int temp_array[SIZE];
    int y = endRange;
    puts("\n\tORIGINAL ARRAY:");
    for (size_t i = 0; i < SIZE; ++i) {
        printf("\n\tArray[%d]: %d ", i, array[i]);

    }

    printf("\n\tARRAY REVERSING FROM %d-%d:",startRange,endRange);
    for (size_t i = startRange; i <= endRange; i++) {
        temp_array[y] = array[i];
        y--;
    }

    for (size_t i = startRange; i <= endRange; i++) {
        array[i] = temp_array[i];
    }

    puts("\n\tREVERSED ARRAY:");
    for (size_t i = 0; i < SIZE; ++i) {
        printf("\n\tArray[%d]: %d ", i, array[i]);

    }

}

//FindSequence returns the start of the index sequence
//that the integers of tom and jerry are found
int findSequence(int array[], int tom, int jerry) {

    for (size_t i = 0; i < SIZE; i++) {
        i++;
        if (i>=SIZE) {
            break;
        }
        if (array[i] == jerry ) {
            if (array[i-1] == tom) {
                return i-1;
            }
        }else if (array[i] == tom) {
            if (array[i+1] == jerry) {
                return i;
            }
        }
    }
    return -1;
}


int main(void) {

    //Array initialized
    int array[SIZE];

    //Variables initialized
    int rand_min, rand_max, hi, lo, largest, start, end, tom, jerry, index=0;

    //Start
    puts("Welcome to Arrays1DDemo\n################################################################");

    printf("\n\tCreating an array of size %d...", SIZE);

    puts("\n\tInitializing first function...\n\t\t[fillArray]");
    puts("\n................................................................");

    //Input error catching
    while (accepted==false) {
        char c;

        puts("\n\n\tEnter a minimum and maximum now:");

        //User input for FillArray
        int valid = scanf("%d%c%d", &rand_min, &c ,&rand_max);

        if (valid<2 || c != ' ') {
            puts("\n\tInvalid Input.");
            while ((c = getchar()) != '\n' && c != EOF);
        }else if (rand_min<MIN_INT || rand_max>MAX_INT) {
            puts("\n\tInvalid Input: min must be greater than -2,147,483,648 and max must be less than 2,147,483,647.");
        }else if (rand_min>rand_max) {
            puts("\n\tInvalid Input: min must be less than max.");
        }else {
            accepted=true;
        }
    }

    printf("\n\tExecuting arrayFill...\n\tFilling array with random numbers from %d-%d...",rand_min,rand_max);

    //FillArray execution
    fillArray(array, rand_min, rand_max);

    puts("\n\t[arrayFill] complete.\n\n################################################################");

    puts("\n\tInitializing second function...\n\t\t[findWithRange]");
    puts("\n................................................................");

    //Input error catching
    while (accepted==true) {
        char c;
        puts("\n\n\tEnter the LOW range and the HIGH range now:");

        ////User input for FindWithRange
        int valid = scanf("%d%c%d", &lo, &c, &hi);

        if (valid<2 || c != ' ') {
            puts("\n\tInvalid Input.");
            while ((c = getchar()) != '\n' && c != EOF);
        }else if (lo<0) {
            puts("\n\tInvalid Input: low must be non-negative.");
        }else if (hi>SIZE-1) {
            puts("\n\tInvalid Input: high must be less than 40.");
        }else if (lo>hi) {
            puts("\n\tInvalid Input: low must be less than high.");
        }else {
            accepted=false;
        }
    }

    printf("\n\tExecuting findWithRange...\n\tLocating the largest element in the range of %d-%d...",lo,hi);

    //FindWithRange execution
    largest = findWithRange(array, lo, hi);

    printf("\n\n................................................................\n\n\tThe largest within the array indexes of %d-%d is %d",lo,hi,largest);
    puts("\n\t[findWithRange] complete.\n\n################################################################");

    puts("\n\tInitializing third function...\n\t\t[reverseArray]");
    puts("\n\tExecuting reverseArray...\n\tReversing all the elements in the array...");

    //ReverseArray Execution
    reverseArray(array);

    puts("\n\t[reverseArray] complete.\n\n################################################################");

    puts("\n\tInitializing fourth function...\n\t\t[reverseSelectedRangeWithinArray]");
    puts("\n................................................................");

    //Input error catching
    while (accepted==false) {
        char c;
        puts("\n\n\tEnter a start range and an end range now:");

        //User input for ReverseSelectedRangeWithinArray
        int valid = scanf("%d%c%d", &start, &c, &end);

        if (valid<2 || c != ' ') {
            puts("\n\tInvalid Input.");
            while ((c = getchar()) != '\n' && c != EOF);
        }else if (start<0) {
            puts("\n\tInvalid Input: start must be non-negative.");
        }else if (end>SIZE-1) {
            puts("\n\tInvalid Input: end must be lesser than 40.");
        }else if (start>end) {
            puts("\n\tInvalid Input: start must be lesser than end.");
        }else {
            accepted=true;
        }
    }

    printf("\n\tExecuting reverseSelectedRangeWithinArray...\n\tReversing the array indexes of %d-%d...",start,end);

    //ReverseSelectedRangeWithinArray execution
    reverseSelectedRangeWithinArray(array,start,end);

    puts("\n\t[reverseSelectedRangeWithinArray] complete.\n\n################################################################");

    puts("\n\tInitializing fifth function...\n\t\t[findSequence]");
    puts("\n................................................................");

    //User input for FindSequence
    while (accepted==true) {
        char c;

        puts("\n\n\tEnter tom and jerry now:");

        int valid = scanf("%d%c%d", &tom, &c, &jerry);

        if (valid<2 || c != ' ') {
            puts("\n\tInvalid Input.");
            while ((c = getchar()) != '\n' && c != EOF);
        }else {
            accepted=false;
        }
    }


    printf("\n\tExecuting findSequence...\n\tFinding the sequence where value %d is found before value %d...",tom,jerry);

    //FindSequence execution
    index = findSequence(array, tom, jerry);

    if (index==-1) {
        puts("\n\tSequence not found");
    }else{
        printf("\n\tSequence found at index %d",index);
    }



    puts("\n\t[findSequence] complete.\n\n################################################################");

    puts("Array1DDemo is complete. Goodbye");
    exit(0);


}