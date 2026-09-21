#include <iostream>
#include <vector>
#include <typeinfo>
#include <stdexcept>

using namespace std;

class DepositOnlyAccount {
  public:
  	virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public DepositOnlyAccount{
  public:
  	virtual void withdraw(double amount) = 0;
};


class SavingAccount : public WithdrawableAccount {
private:
    double balance;

public:
    SavingAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Savings Account!\n";
        }
    }
};

class CurrentAccount : public WithdrawableAccount {
private:
    double balance;

public:
    CurrentAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Current Account!\n";
        }
    }
};

class FixedTermAccount : public DepositOnlyAccount {
private:
    double balance;

public:
    FixedTermAccount() { 
        balance = 0;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }
};

//Client class
class BankClient {
private:
	vector<WithdrawableAccount*> withDrawableAccount;
	vector<DepositOnlyAccount*> depositOnlyAccount;
public:
    BankClient(vector<WithdrawableAccount*> withDrawableAccount, vector<DepositOnlyAccount*> depositOnlyAccount) { 
        this->withDrawableAccount = withDrawableAccount; 
        this->depositOnlyAccount = depositOnlyAccount; 
    }

    void processTransactions() {
        for (WithdrawableAccount* acc : withDrawableAccount) {
            acc->deposit(1000);
            acc->withdraw(500);
         }
         for (DepositOnlyAccount* acc : depositOnlyAccount) {
            acc->deposit(1000);
         }
     }
};

int main() {
    vector<WithdrawableAccount*> withDrawableAccount;
    withDrawableAccount.push_back(new SavingAccount());
    withDrawableAccount.push_back(new CurrentAccount());
    
    vector<DepositOnlyAccount*> depositOnlyAccount;
    depositOnlyAccount.push_back(new FixedTermAccount());

    BankClient* client = new BankClient(withDrawableAccount, depositOnlyAccount);
    client->processTransactions();

    return 0;
}