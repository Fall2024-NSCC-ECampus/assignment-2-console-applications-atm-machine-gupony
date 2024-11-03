
#include "BankAccount.h"
#include <iostream>
using namespace std;

BankAccount::BankAccount() : balance(0.0) {}

void BankAccount::setAccount(const string& id, const string& pwd) {
    userId = id;
    password = pwd;
    cout << "Thank you! Your account has been created!\n";
}

bool BankAccount::validateLogin(const string& id, const string& pwd) const {
    return (id == userId && pwd == password);
}

double BankAccount::getBalance() const {
    return balance;
}
void BankAccount::setBalance(double amount) {
    balance = amount;
}
// Deposits money into the account
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposited $" << amount << " successfully.\n";
    } else {
        cout << "Invalid amount. Deposit must be more than $0.\n";
    }
}

// Withdraws money from the account if balance is sufficient
bool BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrew $" << amount << " successfully.\n";
        return true;
    } else if (amount > balance) {
        cout << "Insufficient funds. You only have $" << balance << ".\n";
        return false;
    } else {
        cout << "Invalid amount. Withdrawal must be more than $0.\n";
        return false;
    }
}
