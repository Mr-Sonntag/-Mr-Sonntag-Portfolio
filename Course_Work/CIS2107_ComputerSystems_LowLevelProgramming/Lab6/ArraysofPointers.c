/*
*  Zachary Sonntag
*  915640716
*  9/29/25
*  CIS2107_003
*
*                  Lab 06 Arrays of Pointers to Functions
*              This lab consists of creating a UI that the user can interact with
*              to display the contents of the array, the min of the array, the max
*              of the array, the average of the array, and terminate the program.
*
*              This program takes advantages of pointers and uses their capabilities
*              to access the 2D array and access the functions within this program,
*              optimzing space, enhancing readability, and makes the code cleaner
*              and shorter.
*
*/


#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//Global Variables
int exams, students = 0;

//Function Prototypes
void fillArray(int (*gPtr)[exams]);
void userMenu (void);
void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);
void terminate(void);

//MAIN
int main(void) {

    puts("Welcome to the Array of Pointers to Functions!");


    puts("\nLoading user menu...");
    userMenu();

    return 0;
}

//UserMenu acts as the UI for the user to interact with and navigate the program
void userMenu(void) {
    const bool inMenu = true;
    puts("\nArrayOfPointers Main Menu");
    puts("\n\tCreate the Array!");
    puts("\n\tHow many rows(How many students)?");
    scanf("%d",&students);

    puts("\n\tHow many columns(How many exams)?");
    scanf("%d",&exams);

    int grades[students][exams];
    fillArray(grades);

    //Array of Pointers to Functions
    void (*processGrades[4])(int students, int exams, int grades[students][exams]) = { printArray, minimum, maximum, average };

    //Menu for user
    while (inMenu) {
        size_t input=0;
        puts("\n##################################################################");
        puts("\n\tEnter a choice:");
        puts("\n\t\t[1] Print the array of grades");
        puts("\n\t\t[2] Find the minimum grade");
        puts("\n\t\t[3] Find the maximum grade");
        puts("\n\t\t[4] Print the average test score for each student");
        puts("\n\t\t[5] Exit program");

        scanf("%lu",&input);

        if (input<5) {
            (*processGrades[input-1])(students, exams, grades);
        }else {
            terminate();
        }

    }

}

//FillArray takes a 2D array pointer and prompts the user to enter in the elements to their created array.
void fillArray(int (*gPtr)[exams]) {
    for (size_t x = 0; x < students; x++) {
        for (size_t y = 0; y < exams; y++) {
            int element = 0;
            printf("\n\tStudent[%lu]: Test[%lu]: ", x+1, y+1);
            scanf("%d",&element);
            gPtr[x][y] = element;
        }
    }
}

//PrintArray takes a 2D Array pointer as its parameter and prints the entire array
void printArray(int students, int exams, int grades[students][exams]) {
    puts("The array is:");
    printf("%s", "                 ");
    for (size_t i = 0; i < exams; i++) {
        printf("[%lu]  ", i);
    }
    puts("");
    for (size_t x=0; x<students; x++) {
        printf("StudentGrades[%lu] ", x);

        for (size_t y=0; y<exams; y++) {
            printf("%-5d", grades[x][y]);
        }
        puts("");
    }
}

//Minimum takes a 2D Array pointer as its parameter and prints the minimum value within the array.
void minimum(int students, int exams, int grades[students][exams]) {
    int min = grades[0][0];

    for (size_t x = 0; x < students; x++) {
        for (size_t y = 0; y < exams; y++) {
            if (min>grades[x][y]) {
                min = grades[x][y];
            }
        }
    }

    printf("\n\tLowest grade: %d", min);
    puts("");
}

//Maximum takes a 2D Array pointer as its parameter and prints the maximum value within the array
void maximum(int students, int exams, int grades[students][exams]) {
    int max = grades[0][0];

    for (size_t x = 0; x < students; x++) {
        for (size_t y = 0; y < exams; y++) {
            if (max<grades[x][y]) {
                max = grades[x][y];
            }
        }
    }

    printf("\n\tHighest grade: %d", max);
    puts("");
}

//Average takes a 2D Array pointer as its parameter and prints the average of each row
void average(int students, int exams, int grades[students][exams]) {
    for (size_t x = 0; x < students; x++) {
        double total = 0;

        for (size_t y = 0; y < exams; y++) {
            total += grades[x][y];
        }

        total/=exams;
        printf("\n\tAverage grade for student %lu: %.2f", x, total);
    }
    puts("");
}

//Terminate will end the program
void terminate(void) {
    puts("\n##################################################################");
    puts("Thanks for using Array of Pointers to Functions!\nGoodbye!");
    exit(0);
}