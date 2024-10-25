
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
