/*
 *  Zachary Sonntag
 *  915640716
 *  9/4/25
 *  CIS2107_003
 *
 *              Lab 02 Revenue
 *      This C program calculates the revenue from a sale from a user using the price per unit,
 *      number of units, and uses a discount system that applies a "discount" to the total price
 *      It considers unit quantity, invalid inputs, and uses proper formatting/headers/closing.
 *
 *      Inputs:          Item price - double/integer/non-negative
 *                       Quantity of units - integer/non-negative
 *
 *      Outputs:         Item price
 *                       Quantity of units
 *                       Initial cost
 *                       Discount applied
 *                       Discount price
 *                       Final total
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void revenue(void) {

    double quantity,price,cost,discount_amount,total,discount;

    printf("\tEnter item price: ");
    scanf("%lf",&price);

    //Error handling for user input on price
    if (price<=0) {
        puts("\tERROR: Invalid price.");
        puts("\n\tPlease run the program again");
        puts("\nThank You for using \"Temple\" store");
        exit(1);
    }

    printf("\n\tEnter quantity: ");
    scanf("%lf",&quantity);

    //Error handling for user input on quantity
    if (fmod(quantity,1)!=0 || quantity<=0) {
        puts("\tERROR: Invalid quantity.");
        puts("\n\tPlease run the program again");
        puts("\nThank You for using \"Temple\" store");
        exit(1);
    }

    printf("\n\tThe item price is: $%.2f",price);
    printf("\n\tThe order is: %.0f item(s)",quantity);

    cost = quantity*price;

    printf("\n\tThe cost is: $%.2f",cost);

    if (quantity>=150) {
        discount = 25;
        discount_amount = cost*discount/100;
    }else if (quantity>=100) {
        discount = 15;
        discount_amount = cost*discount/100;
    }else if (quantity>=50) {
        discount = 10;
        discount_amount = cost*discount/100;
    }else {
        discount = 0;
        discount_amount = 0;
    }
    printf("\n\tThe discount is: %.1f%%",discount);

    printf("\n\tThe discount amount is: $%.2f",discount_amount);
    total = cost-discount_amount;

    printf("\n\tThe total is: $%.2f",total);

}


int main(void) {
    puts("Welcome to \"Temple\" store\n");
    revenue();
    puts("\n\nThank You for using \"Temple\" store");
    exit(0);
    return 0;
}