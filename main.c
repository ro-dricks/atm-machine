#include <stdio.h>
#include <stdlib.h>
//variables used
char  card;
int pin;
int trials = 4;
int activity;
float balance = 1000;
float withdrawal_amount;
int status;
//function definition
char insertCard();
void userActivity();
void checkPin();//validate user pin
void checkBalance();
void makeWithdrawal();
void go_on();// continue using the atm or exit

int main() {
    printf("WELCOME.\n");
    printf("===============================\n");
    insertCard();
    printf("Welcome Rodricks\n");

    return 0;
}

char insertCard() {
    printf("PLEASE INSERT YOUR ATM CARD\n");
    scanf("%c", &card); //use the character k as input
    //check if user has inserted card
    while(card != 'k') {
        printf("Invalid!\n");
        insertCard();
    }
    checkPin();//call function to check the pin to the card
}

void checkPin() {
    printf("Please enter your 4 digit PIN: ");
    scanf("%d", &pin);
    if(pin > 1000 && pin < 9999) {
        while(pin != 8787) {
            for(int i = 0; i < trials; i++) {
                printf("PIN you entered is incorrect.\n");
                printf("You have %d trials remaining\n", trials);
                trials--;
                checkPin();
            }
            printf("Too many attempts! Contact your bank to access your account.\n");
            exit(0);
        }
        userActivity();
    } else {
        printf("PIN is a four digit number, try again\n");
        checkPin();
    }

}

void userActivity() {
    printf("What would you like to do:\n");
    printf("1. Check balance\n");
    printf("2. Make a withdrawal\n");

    scanf("%d", &activity);

    if(activity == 1) {
        checkBalance();
    } else if(activity == 2) {
        makeWithdrawal();
    } else {
        printf("Please enter the correct input");
        userActivity();

    }
}

void checkBalance() {
    printf("Current balance is %.2f\n", balance);
    go_on();
}

void makeWithdrawal() {
    printf("Enter amount to withdraw: \n");
    scanf("%f", &withdrawal_amount);

    while(withdrawal_amount > balance) {
        printf("Not enough amount in your account to make a withdrawal. Current account balance is: %.2f\n", balance);
        go_on();
        break;
    }
    balance -= withdrawal_amount;
    printf("You have withdrawn %.2f your new balance is %.2f\n", withdrawal_amount, balance);
    go_on();
}

void go_on() {
    printf("1. Go back to menu\n");
    printf("2. exit\n");

    scanf("%d", &status);
    if(status == 1) {
        userActivity();
    } else {
        exit(0);
    }
}
