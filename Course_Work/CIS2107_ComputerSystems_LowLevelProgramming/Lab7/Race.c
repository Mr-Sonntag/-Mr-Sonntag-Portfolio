//CIS2017 Lab7: Race


/*
*  Zachary Sonntag
*  915640716
*  10/06/25
*  CIS2107_003
*
*                  Lab 07 Race
*              The purpose of this program is to simulate and display the race between the tortoise and the hare using a random number
*              generator and preset move types. The animal positions are accessed and modified using pointers, and the display is
*              controlled using the sleep() function. Sometimes it takes a while due to slippage.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define INT_MIN 1
#define INT_MAX 10
#define RACE 71


int randomNumberGenerator();
void tortMove(int *const tPtr);
void hareMove(int *const hPtr);
void printRace(const int hPos,const int tPos);
int min(int hMin, int tMin);

int main(){
    srand((unsigned)time(NULL));

    int hPos =1;						//hare start position is 1, cannot slip past 1
    int tPos = 1;						//tortoise start position is 1, cannot slip past 1

    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG               !!!!");	//the spacing is modeled after the sample
    puts("\tAND THEY'RE OFF    !!!!");	//the spacing is modeled after the sample

    while(hPos != 70 && tPos!=70){
        //sleep(1);						//slows down the race
        hareMove(&hPos);
        tortMove(&tPos);
        printRace(hPos,tPos);
        puts("");
    }

}

//Finds minimum of hare or tortoise position to decide which position to print first
int min(int hMin, int tMin){
    int loser = 0;

    if (hMin < tMin) {
        loser = 1;
        return loser;
    }

    return loser;
}

//Prints the position of the H and T
void printRace(const int hPos,const int tPos){
    if (hPos > 69 && tPos < 70){            //If Hare wins
        puts("Hare wins. Yuch.");
        exit(0);
    }else if (tPos > 69 && hPos < 70) {     //If Turtle wins
        puts("TORTOISE WINS!!! YAY!!");
        exit(0);
    }else if (hPos > 69 && tPos > 69) {     //If Tie
        puts("ITS A... TIE!?!?!?!? NO... WE DECLARE THE TORTOISE AS THE WINNER!!! HOORAY!");
        exit(0);
    }else{
        size_t i = 0;
        //Checks if turtle and hair is on same pos
        if (hPos == tPos) {
            while (i<RACE) {
                if (i == hPos) {
                    printf("%s", "OUCH!!!");
                }else {
                    printf("%s"," ");
                }
                i++;
            }
        }else {
            while (i<RACE) {
                if (i == hPos-1) {
                    printf("%s","H");
                }else if ( i == tPos-1) {
                    printf("%s","T");
                }else {
                    printf("%s"," ");
                }
                i++;
            }
        }

    }
}

//Controls the tortoise movement
void tortMove(int *const tPtr){
    //Randomly determines turtles move
    int tort_move = randomNumberGenerator();

    if (tort_move < 6) {
        *tPtr+=3;           //Fast plod
    }else if (tort_move < 8) {
        *tPtr+=-6;          //Slip
    }else {
        *tPtr+=1;           //Slow plod
    }

    if (*tPtr < 1) {
        *tPtr = 1;          //If slipped past 1, return to 1
    }
}

//Controls the hare movement
void hareMove(int *const hPtr){
    //Randomly determines hare move
    int hare_move = randomNumberGenerator();

    if (hare_move < 3) {
                            //Sleep, hare doesnt move
    }else if(hare_move < 5) {
        *hPtr+=9;           //Big hop
    }else if (hare_move < 6) {
        *hPtr+=-12;         //Big slip
    }else if (hare_move < 9) {
        *hPtr+=1;           //Small hop
    }else {
        *hPtr+=-2;          //Small slip
    }

    if (*hPtr < 1) {
        *hPtr = 1;          //If slipped past 1, return to 1
    }
}

//Generates random number from 1-10
int randomNumberGenerator(){
    const int rand_movement = (rand() % (INT_MAX-INT_MIN+1))+INT_MIN;
    return rand_movement;
}
