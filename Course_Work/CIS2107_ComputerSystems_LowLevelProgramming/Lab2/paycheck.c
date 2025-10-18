/*
 *  Zachary Sonntag
 *  915640716
 *  9/4/25
 *  CIS2107_003
 *
 *              Lab 02 Paycheck
 *      This C program calculates the paycheck of a "Temple employee" using their employee ID,
 *      hourly pay, and work time. It considers invalid input, overtime pay, and uses proper
 *      formatting/heading/closing.
 *
 *      Inputs:     Employee ID - integer/double/non-negative
 *                  Hourly Salary - integer/double/non-negative
 *                  Weekly Time - integer/double/non-negative
 *
 *      Output:     Employee #
 *                  Hourly Salary
 *                  Weekly Time
 *                  Regular Pay
 *                  Overtime Pay
 *                  Net Pay
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void paycheck(void) {

    double employee,decimal,hourly_salary,work_time,total,overtime,overtime_pay;

    printf("\n\tEnter Employee Number: ");
    scanf("%lf",&employee);

    //Error handling for user input on Employee ID.
    decimal = fmod(employee,1);
    if (decimal != 0 || employee < 1) {
        puts("\tERROR: Invalid Employee #.");
        puts("\n\tPlease run the program again");
        puts("\n\t==============================");
        puts("Thank you for using \"TEMPLE HUMAN RESOURCES\"");
        exit(1);
    }

    printf("\tEnter Hourly Salary: ");
    scanf("%lf", &hourly_salary);

    //Error handling for user input on Hourly Salary.
    if (hourly_salary <= 0) {
        puts("\tERROR: Invalid Hourly Salary.");
        puts("\n\tPlease run the program again");
        puts("\n\t==============================");
        puts("Thank you for using \"TEMPLE HUMAN RESOURCES\"");
        exit(1);
    }


    printf("\tEnter Weekly Time: ");
    scanf("%lf", &work_time);

    //Error handling on user input on Weekly Time
    if (work_time <= 0) {
        puts("\tERROR: Invalid Weekly Time.");
        puts("\n\tPlease run the program again");
        puts("\n\t==============================");
        puts("Thank you for using \"TEMPLE HUMAN RESOURCES\"");
        exit(1);
    }
    printf("\t==============================");
    if (work_time>40) {
        overtime = work_time - 40;
    }else {
        overtime = 0;
    }

    printf("\n\tEmployee #: \t%.0f",employee);
    printf("\n\tHourly Salary: \t$%.2f",hourly_salary);
    printf("\n\tWeekly Time: \t%.1f",work_time);

    if (overtime>0) {
        total += 40*hourly_salary;
        printf("\n\tRegular Pay: \t$%.2f",total);
        overtime_pay = overtime * (hourly_salary*1.5);
        printf("\n\tOvertime Pay: \t$%.2f",overtime_pay);
        total += overtime_pay;
    }else {
        total = work_time*hourly_salary;
        printf("\n\tRegular Pay: \t$%.2f",total);
        printf("\n\tOvertime Pay: \t$0");
    }

    printf("\n\tNet Pay: \t$%.2f",total);


}

int main(void) {
    puts("Welcome to \"TEMPLE HUMAN RESOURCES\"");
    paycheck();
    puts("\n\t==============================");
    puts("Thank you for using \"TEMPLE HUMAN RESOURCES\"");
    exit(0);
    return 0;
}