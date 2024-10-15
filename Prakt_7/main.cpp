#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;
    static double percentPerYear;
    static double totalBalance;

public:
    BankAccount(double initialBalance = 0) {
        balance = initialBalance;
        totalBalance += balance;
    }

    void deposit(double amount) {
        balance += amount;
        totalBalance += amount;
    }

    void withdraw(double amount) {
        balance -= amount;
        totalBalance -= amount;
    }

    double getBalance() const {
        return balance;
    }

    void addPercent() {
        double percent = balance * (percentPerYear / 100);
        balance += percent;
        totalBalance += percent;
    }

    static void serPercentPerYear(double newProcent) {
        percentPerYear = newProcent;
    }

    static double getTotalBalance() {
        return totalBalance;
    }
};

double BankAccount::percentPerYear = 5.0;
double BankAccount::totalBalance = 0.0;

int main() {
    BankAccount account1(1000);
    BankAccount account2(500);

    cout << "Загальний рахунок після ініціалізації: " << BankAccount::getTotalBalance() << endl;

    cout << "Баланс рахунку 1 до: " << account1.getBalance() << endl;

    account1.deposit(200);
    account1.withdraw(150);
    account1.addPercent();

    cout << "Баланс рахунку 1 після: " << account1.getBalance() << endl;

    cout << "Баланс рахунку 2 до: " << account2.getBalance() << endl;
    account2.deposit(300);
    account2.withdraw(100);
    account2.addPercent();

    cout << "Баланс рахунку 2 після: " << account2.getBalance() << endl;

    BankAccount::serPercentPerYear(7.0);

    account2.addPercent();
    account1.addPercent();
    cout << "Баланс рахунку 1 після зміни проценту: " << account1.getBalance() << endl;
    cout << "Баланс рахунку 2 після зміни проценту: " << account2.getBalance() << endl;

    cout << "Загальний баланс по всіх рахунках після роботи з двома рахунками та процентом: " <<
            BankAccount::getTotalBalance() << endl;

    return 0;
}
