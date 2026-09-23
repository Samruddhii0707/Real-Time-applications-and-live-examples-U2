#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    string accountNumber;
    string holderName;
    double balance;

public:
    Account(string accNo, string name, double bal)
        : accountNumber(accNo), holderName(name), balance(bal)
    {
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: Rs. " << amount << endl;
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: Rs. " << amount << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual double calculateInterest() const = 0;

    virtual void displayInfo() const
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    virtual ~Account() = default;
};

class SavingsAccount : public Account
{
public:
    SavingsAccount(string accNo, string name, double bal)
        : Account(accNo, name, bal)
    {
    }

    double calculateInterest() const override
    {
        return balance * 0.04;
    }

    void displayInfo() const override
    {
        cout << "\n=== Savings Account ===" << endl;
        Account::displayInfo();
        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }
};

class CurrentAccount : public Account
{
public:
    CurrentAccount(string accNo, string name, double bal)
        : Account(accNo, name, bal)
    {
    }

    double calculateInterest() const override
    {
        return balance * 0.02;
    }

    void displayInfo() const override
    {
        cout << "\n=== Current Account ===" << endl;
        Account::displayInfo();
        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }
};

class FixedDepositAccount : public Account
{
private:
    int duration;

public:
    FixedDepositAccount(
        string accNo,
        string name,
        double bal,
        int years
    )
        : Account(accNo, name, bal), duration(years)
    {
    }

    double calculateInterest() const override
    {
        return balance * 0.07 * duration;
    }

    void displayInfo() const override
    {
        cout << "\n=== Fixed Deposit Account ===" << endl;
        Account::displayInfo();
        cout << "Duration: " << duration << " years" << endl;
        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }
};

int main()
{
    SavingsAccount savings(
        "SA001", "Amit", 50000
    );

    CurrentAccount current(
        "CA001", "Sneha", 75000
    );

    FixedDepositAccount fixedDeposit(
        "FD001", "Rohan", 100000, 3
    );

    cout << "=== Banking System ===" << endl;

    savings.deposit(5000);
    savings.withdraw(2000);
    savings.displayInfo();

    current.deposit(10000);
    current.withdraw(5000);
    current.displayInfo();

    fixedDeposit.displayInfo();

    return 0;
}
