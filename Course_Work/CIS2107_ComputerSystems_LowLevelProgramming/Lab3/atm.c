/*
 *  Zachary Sonntag
 *  915640716
 *  9/9/25
 *  CIS2107_003
 *
 *              Lab 03 ATM
 * This program simulates an ATM. It first prompts the user to input their pin,
 * in this case 3014. If the user fails to input the correct pin 3 times, it will
 * "lock" them out of their account and end the program. On success, the user is
 * brought to their "bank account's" main menu in which they are continuously prompted with
 * 4 actions to take. They can choose balance, withdraw, deposit, or quit. Balance simply
 * displays their current balance. Withdraw will allow the user to enter an integer that is
 * a multiple of 20 to take out from their balance. Deposit will allow the user to deposit
 * a given amount into their balance. Quit will log the user out of the ATM and display
 * the number of transactions they took over their session.
 *
 * Transactions are a withdrawal or deposit. After each transaction, the user is prompted
 * on whether they'd like a receipt.
 *
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//Function Prototypes
int check_balance(double balance);
int cash_withdraw(double balance);
int cash_deposit(double balance);
int atm(void);

//Global Variables
double withdrawal_limit = 1000;
double deposit_limit = 10000;
int transactions = 0;
int invalid_transactions = 3;

//Start of check_balance function
//Prints the user's balance
int check_balance(double balance) {
 printf("\n\tYour balance is: $%.2lf",balance);
 return 0;
}
//Start of cash_withdraw function
//Allows user to withdraw money from their account, given they have not exceeded their daily
//withdraw limit or their account balance.
int cash_withdraw(double balance) {
 double withdrawal = 0;
 double ui = 0;
 if (withdrawal_limit>0) {
  printf("\n\tYou can withdrawal up to $%.2lf today.",withdrawal_limit);
  puts("\n\tPlease enter how much you'd like to withdraw. \n\tREMINDER: You can only withdraw in multiples of 20s.");
  scanf("%lf",&withdrawal);

  if (withdrawal<=0||withdrawal>withdrawal_limit||fmod( withdrawal,20)!=0||withdrawal>balance) {
   puts("\n\tERROR: You cannot withdrawal that amount.\n\tREMINDER: You can only withdrawal in multiples of 20s.");
   invalid_transactions--;
   printf("\n\tYour number of attempts left before termination is %d", invalid_transactions);
  }else {
   withdrawal_limit-=withdrawal;
   balance-=withdrawal;
   printf("\n\tYour new withdrawal limit is $%.2lf.",withdrawal_limit);

   puts("\n\n\tWould you like your receipt?\n\t\t1. Yes.\n\t\t2. No.");
   scanf("%lf",&ui);

   transactions++;

   if (fmod(ui,1)!=0) {
    puts("\n\tInvalid option.");
   }else if(ui==1){
    puts("\n\tYour receipt has been sent to your email.");
   }else {
    puts("\n\tNo receipt will be sent.");
   }
  }
 }else {
  puts("\n\tYou have reached your withdrawal limit for the day.");
 }


 return balance;
}
//Start of cash_deposit function
//Allows user to deposit money into their account, given they have not exceeded their
//deposit limit.
int cash_deposit(double balance) {
 double deposit = 0;
 double ui = 0;
 if (deposit_limit>0) {
  printf("\tYou may deposit up to $%.2lf today.\n\tHow much would you like to deposit?",deposit_limit);
  scanf("%lf",&deposit);


  if (fmod(deposit,1)!=0) {
   puts("\n\tThis ATM does not accept coins.");
   invalid_transactions--;
   printf("\n\tYour number of attempts left before termination is %d", invalid_transactions);
  }else if (deposit<=0 || deposit>deposit_limit) {
   puts("\n\tERROR: Invalid deposit amount.");
   invalid_transactions--;
   printf("\n\tYour number of attempts left before termination is %d", invalid_transactions);
  }else{
   deposit_limit-=deposit;
   balance+=deposit;

   printf("\n\tYou have successfully deposited $%.2lf to your account.\n\t",deposit);

   puts("\n\n\tWould you like your receipt?\n\t\t1. Yes.\n\t\t2. No.");

   scanf("%lf",&ui);

   transactions++;

   if (fmod(ui,1)!=0) {
    puts("\n\tInvalid option.");
   }else if (ui==1){
    puts("\n\tYour receipt has been sent to your email.");
   }else {
    puts("\n\tNo receipt will be sent.");
   }
  }
 }else {
  puts("\n\tYou have reached your deposit limit for the day.");
 }
 return balance;
}

//Start of ATM function
//Runs a continuous loop that asks for user input on actions they'd like to take
//with their bank account.
int atm(void) {
 bool entry = 0;
 double user_pin,ui=0;
 double balance = 5000;
 int pin = 3014;
 int attempts=3;


 while (entry==0) { // Pin entry: User must enter the correct pin to gain access to their bank account
  puts("\nPlease enter your pin number now: ");

  scanf("%lf",&user_pin);

  if (fmod(user_pin,1)!=0 || (int) user_pin!=pin) {
   puts("\n\tIncorrect pin, try again.");
   attempts--;
   printf("\n\tAttempts remaining: %d",attempts);
  }else{
   puts("\n\tConnecting... One moment...");
   entry=1;
  }

  if (attempts==0) {
   puts("\n\t***Your account has been locked.*** \n\tGoodbye.");
   exit(1);
  }

 }

 puts("\n\tSuccess: Logged in.\n\tWelcome Nana!");

 while (entry==1) { // Main menu for the ATM. Displays 4 options: Balance, Cash Withdrawal, Cash deposition, or Quit.
  puts("\n\tNana's Bank Account\n\t#################################\n\t1. Balance\n\t2. Cash withdrawal\n\t3. Cash deposition\n\t4. Quit\n\t#################################");
  scanf("%lf",&ui);

  switch ((int) ui) {

    case 1: // Balance

    check_balance(balance);

    break;

    case 2: //Cash Withdrawal

     balance = cash_withdraw(balance);

     break;

    case 3: //Cash Deposition

     balance = cash_deposit(balance);

     break;

    case 4: //Quit

     return transactions;

    default: //Invalid user input
     puts("Incorrect input.");


  }
  if (invalid_transactions==0) {
   puts("\n\tTransaction canaceled. Goodbye.");
   exit(1);
  }


 }



 return transactions;
}


int main(void) {

 puts("***STATUS*** CONNECTED\nWelcome to your own personal ATM!");

 transactions = atm();
 printf("\tUser Nana: Logging out...\n");
 printf("\tLogout successful. The number of transactions you've made is %d. Goodbye.",transactions);

 exit(0);
 return 0;
}