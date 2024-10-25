// BankAccount.h
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
using namespace std;

class BankAccount {
private:
    string userId;
    string password;
    double balance;

public:
    BankAccount();
    void setAccount(const string& id, const string& pwd);
    bool validateLogin(const string& id, const string& pwd) const;
    double getBalance() const;
    void setBalance(double amount);
};
#endif
