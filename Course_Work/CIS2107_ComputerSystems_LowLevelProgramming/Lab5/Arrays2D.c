/*
*  Zachary Sonntag
*  915640716
*  9/22/25
*  CIS2107_003
*
*                  Lab 05 Processing 2D Arrays
*              This lab creates a user generated 2D array and provides numerous calculations
*              and manipulations on it. This program consists of 6 functions, 5 of which are
*              required in the lab manual and 1 is added for readability and functionality of
*              the program.
*
*              FillArray prompts the user to enter a value for each element within the array
*              and fills the array with those values.
*
*              Max finds the largest value within the array and returns that value. Returns
*              an int max.
*
*              RowSum takes a given row and the array to then find the sum of that given row
*              within the array. Returns an int sum.
*
*              ColSum takes a given column and the array to then find the sum of that given
*              column within the array. Returns an int sum.
*
*              IsSquare returns a boolean, determines whether the array is a square array or
*              rectangular. A square array will have nxn rows and columns while a
*              rectangular array will have mxn rows and columns.
*
*              DisplayOuputs simply prints all the elements of the array out through the
*              system output.
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//Global Variables
int rows, cols = 0;


//Function Prototypes
void fillArray(int array[][cols]);
int max(const int array[][cols]);
int rowSum(const int array[][cols], int row_num);
int colSum(const int array[][cols], int col_num);
bool isSquare(void);
void displayOutputs(const int array[][cols]);


int main(void) {
    printf("%s", "Let's create a 2Dim array!");

    puts("\n\tHow many rows?");
    scanf("%d",&rows);

    puts("\tHow many columns?");
    scanf("%d",&cols);

    int array[rows][cols];
    printf("\tArray of %dx%x made.", rows, cols);
    fillArray(array);

    puts("");

    int largest = max(array);
    printf("\n\tThe largest element in the array is: %d", largest);

    puts("");

    for (size_t i = 0; i < rows; i++) {
        const int sum = rowSum(array, i);
        const int real_row = 1+i;
        printf("\n\tSum of row %d = %d", real_row, sum);
    }

    puts("");

    for (size_t i = 0; i < cols; i++) {
        const int sum = colSum(array, i);
        const int real_col = 1+i;
        printf("\n\tSum of column %d = %d", real_col, sum);
    }

    puts("");

    const bool square = isSquare();

    if (square) {
        puts("\n\tIt is a square array.");
    }else {
        puts("\n\tIt is not a square array.");
    }

    puts("");

    puts("Here is your 2Dim array: ");
    displayOutputs(array);

    exit(0);

    return 0;
}

//fillArray will prompt user to fill each element in the array and populate it with those values.
void fillArray(int array[][cols]) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            int element = 0;
            printf("\n\tEnter element the element for [%lu][%lu]: ", i, j);
            scanf("%d",&element);
            array[i][j] = element;
        }
    }
}

//max will scan the entire array and find the largest value and return it.
int max(const int array[][cols]) {

    int max = 0;

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (array[i][j] > max) {
                max = array[i][j];
            }
        }
    }

    return max;
}

//rowSum returns the sum of the given row.
int rowSum(const int array[][cols], int row_num) {

    int sum = 0;

    for (size_t i = 0; i < cols; i++) {
        sum += array[row_num][i];
    }

    return sum;
}

//colSum return the sum of the given column.
int colSum(const int array[][cols], int col_num) {

    int sum = 0;

    for (size_t i = 0; i < rows; i++) {
        sum += array[i][col_num];
    }

    return sum;
}

//isSquare determines if the 2D array is an nxn matrix or mxn matrix.
bool isSquare(void) {

    bool square = rows == cols;

    return square;
}

//displayOutputs will print all the elements within the 2D array.
void displayOutputs(const int array[][cols]) {
    for (size_t i = 0; i < rows; i++) {
        printf("%s", "[");
        for (size_t j = 0; j < cols; j++) {
            if (j<cols - 1) {
                printf("%d, ", array[i][j]);
            }else {
                printf("%d]", array[i][j]);
            }
        }
        puts("");
    }
}