#include <iostream>
using namespace std;

class BankAccount {
    private:
        float balance;
    public:
        BankAccount() { // Defualt Coonstructor
            balance = 0;  // initializes to 0 (no current balance)
        }
        BankAccount(float bal) {  // Parameterized Constructor
            balance = bal;  // initializes to the amount entered in main
        }
        BankAccount (const BankAccount& obj) {  // Copy Constructor
            balance = obj.balance;  // creates a deep copy 
        }
        void withdraw (float amount) {  // function to withdraw amount from account
            balance -= amount;  // deducts the amount from current balance
        }
        void printBalance() {  // method to print the current balance
            cout << "Current Balance: $" << balance << endl;
        }
};

int main() {
    // Creates an account using default constructor
    BankAccount account1;
    cout << "Account 1: ";
    account1.printBalance();

    // Creates an account using Parameterized constructor
    BankAccount account2(1000);
    cout << "Account 2: ";
    account2.printBalance();

    // Creates an account using copy constructor
    BankAccount account3 = account2;
    account3.withdraw(200);
    cout << "Account 3: ";
    account3.printBalance();

    // Prints the balance of account 2 (shows deep copy as account 2 is not affected by the transaction)
    cout << "Account 2 after withdrawing $200 from account3: ";
    account2.printBalance();

    return 0;
}