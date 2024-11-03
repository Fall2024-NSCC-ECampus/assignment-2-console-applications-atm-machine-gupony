// main.cpp
#include <iostream>
#include <string>
#include "BankAccount.h"
using namespace std;

void printIntroMenu();
void start();
void createAccount();
void login();
void printATMMenu();
void atmMenu();
void depositMoney();
void withdrawMoney();
void checkBalance();

char menuInput;
BankAccount account;

void printIntroMenu() {
    cout << "\nWelcome! Please choose an option to get started:\n";
    cout << "l -> Log in to your account\n";
    cout << "c -> Create a new account\n";
    cout << "q -> Quit\n";
    cout << "> ";
}

void printATMMenu() {
    cout << "\nPlease choose an option:\n";
    cout << "d -> Deposit Money\n";
    cout << "w -> Withdraw Money\n";
    cout << "r -> Request Balance\n";
    cout << "q -> Log Out\n";
    cout << "> ";
}

void start() {
    while (true) {
        printIntroMenu();
        cin >> menuInput;

        switch (menuInput) {
            case 'l':
                login();
                break;
            case 'c':
                createAccount();
                break;
            case 'q':
                cout << "Thanks for stopping by! Have a great day!\n";
                exit(0);
            default:
                cout << "Hmm, that's not a valid option. Give it another try!\n";
        }
    }
}

void createAccount() {
    string id, pwd;
    cout << "Let's set up your new account.\n";
    cout << "Choose a user ID: ";
    cin >> id;
    cout << "Now set a password: ";
    cin >> pwd;

    account.setAccount(id, pwd);
    cout << "All set! Your account has been created.\n";
}

void login() {
    string id, pwd;
    cout << "Welcome back! Let’s log in.\n";
    cout << "Enter your user ID: ";
    cin >> id;
    cout << "Enter your password: ";
    cin >> pwd;

    if (account.validateLogin(id, pwd)) {
        cout << "Access granted. Nice to see you again!\n";
        atmMenu();
    } else {
        cout << "Oops! Login failed. Double-check your ID and password.\n";
    }
}

void atmMenu() {
    char atmChoice;

    while (true) {
        printATMMenu();
        cin >> atmChoice;

        switch (atmChoice) {
            case 'd':
                depositMoney();
                break;
            case 'w':
                withdrawMoney();
                break;
            case 'r':
                checkBalance();
                break;
            case 'q':
                cout << "Logging out. See you next time!\n";
                return;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }
}
#include <limits>

void depositMoney() {
    double amount;
    cout << "Enter amount to deposit: $";
    try {
        if (!(cin >> amount)) {  // Check if input is not a number
            throw runtime_error("Invalid input. Please enter a numeric value.");
        }
        account.deposit(amount);
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void withdrawMoney() {
    double amount;
    cout << "Enter amount to withdraw: $";
    try {
        if (!(cin >> amount)) {  // Check if input is not a number
            throw runtime_error("Invalid input. Please enter a numeric value.");
        }
        account.withdraw(amount);
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


void checkBalance() {
    cout << "Your current balance is: $" << account.getBalance() << "\n";
}

int main() {
    cout << "Hello! Welcome to your ATM.\n";
    start();
    return 0;
}
