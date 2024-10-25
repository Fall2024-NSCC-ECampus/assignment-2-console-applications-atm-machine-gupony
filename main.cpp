// main.cpp
#include <iostream>
#include <string>
#include "BankAccount.h"
using namespace std;

void printIntroMenu();
void start();
void createAccount();
void login();

char menuInput;
BankAccount account;

void printIntroMenu() {
    cout << "\nWelcome! Please choose an option to get started:\n";
    cout << "l -> Log in to your account\n";
    cout << "c -> Create a new account\n";
    cout << "q -> Quit\n";
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
    cout << "Welcome back! Let's log in.\n";
    cout << "Enter your user ID: ";
    cin >> id;
    cout << "Enter your password: ";
    cin >> pwd;

    if (account.validateLogin(id, pwd)) {
        cout << "Access granted. Nice to see you again!\n";
        // Future: Call main ATM menu (Part B)
    } else {
        cout << "Oops! Login failed. Double-check your ID and password.\n";
    }
}

int main() {
    cout << "Hello! Welcome to your ATM.\n";
    start();
    return 0;
}
