#include <iostream>
#include <stdexcept>
using namespace std;
class account
{
    double balance;

public:
    account() : balance(0.0) {}

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            throw std::invalid_argument("Invalid amount deposited");
        }
        balance += amount;
    }
    
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            throw std::invalid_argument("Invalid withdrawal amount");
        }
        if (amount > balance)
        {
            throw std::runtime_error("Insufficient funds");
        }
            cout << "You withdrew Rs." << amount << endl;
            balance -= amount;
    }

    double getBalance()
    {
        return balance;
    }
};

int main()
{

    account a1;
    cout << "this is the error handling for negative deposit" << endl;
    try
    {
        a1.deposit(-80.0);
    }
    catch (const std::exception &e)
    {
        cerr << "Exception occurred: " << e.what() << endl;
    }
    cout << " " << endl;
    a1.deposit(300);
    cout << " this is the error for withdrawal" << endl;
    try
    {
        a1.withdraw(1000);
    }
    catch (const std::exception &e)
    {
        cerr << "Exception occurred: " << e.what() << endl;
    }
    cout << " " << endl;
    a1.withdraw(300);
    cout << "this is the error for negative withdrawal" << endl;
    try
    {
        a1.withdraw(-500);
    }
    catch (const std ::exception &e)
    {
        cerr << "Exception occurred :" << e.what() << endl;
    }
    cout << " " << endl;
    cout << "Balance is " << a1.getBalance() << endl;

    return 0;
}