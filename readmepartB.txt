***ATM Program***

*Overview*

This is Part B of the C++ Assignment 2. In this part, I expanded the ATM program to include:

*Creating a new bank account with a user ID and password.
*Logging in to an account.
*Depositing money, withdrawing money, and checking the account balance.
*Exception handling for user input to prevent invalid entries.
*Quitting the program.

**How It Works**

*Create Account: The user enters a user ID and password to create an account.
*Log In: The user logs in using the same ID and password.
*Deposit Money: Users can deposit a chosen amount into their account. The input is validated to ensure it’s numeric.
*Withdraw Money: Users can withdraw a chosen amount if there’s enough balance. The input is validated to ensure it’s numeric.
*Request Balance: Users can view their current balance.
*Exception Handling: Ensures that non-numeric input for deposits and withdrawals is handled gracefully.
*Quit: Exits the program.

**File Structure**

*BankAccount.h - Declares the BankAccount class, including user ID, password, and balance.

*BankAccount.cpp - Defines the functions for the BankAccount class, including deposit, withdraw, and balance checking.

*main.cpp - Manages the main menu, user interaction, ATM operations, and exception handling.