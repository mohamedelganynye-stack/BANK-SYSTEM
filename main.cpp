#include <iostream>
#include <string>
using namespace std;

struct Account {
    int id;
    string pin;
    double balance;
};

int main() {
    Account accounts[100];
    int accountCount = 0;
    int nextId = 1;

    while (true) {
        cout << "\n1) Create Account  2) Login  0) Exit\nChoose: ";
        int choice;
        cin >> choice;
        if (choice == 0) break;

        if (choice == 1) {
            if (accountCount >= 100) {
                cout << "Bank is full. Cannot create more accounts.\n";
                continue;
            }
            Account a;
            a.id = nextId++;
            a.balance = 0;
            cout << "Choose a 4-digit PIN: ";
            cin >> a.pin;
            accounts[accountCount++] = a;
            cout << "Account created. Your Account ID: " << a.id << "\n";
        }
        else if (choice == 2) {
            int id; string pin;
            cout << "Enter Account ID: "; cin >> id;
            cout << "Enter PIN: "; cin >> pin;
            int idx = -1;
            for (int i = 0; i < accountCount; i++) {
                if (accounts[i].id == id && accounts[i].pin == pin) {
                    idx = i; break;
                }
            }
            if (idx == -1) {
                cout << "Invalid ID or PIN.\n";
                continue;
            }

            while (true) {
                cout << "\n[Account " << id << "] 1) Balance  2) Deposit  3) Withdraw  4) Logout\nChoose: ";
                int c; cin >> c;
                if (c == 1) {
                    cout << "Balance: " << accounts[idx].balance << "\n";
                }
                else if (c == 2) {
                    double x; cout << "Deposit amount: "; cin >> x;
                    if (x > 0) {
                        accounts[idx].balance += x;
                        cout << "Deposited. New balance: " << accounts[idx].balance << "\n";
                    }
                    else {
                        cout << "Invalid amount.\n";
                    }
                }
                else if (c == 3) {
                    double x; cout << "Withdraw amount: "; cin >> x;
                    if (x > 0 && x <= accounts[idx].balance) {
                        accounts[idx].balance -= x;
                        cout << "Withdrawn. New balance: " << accounts[idx].balance << "\n";
                    }
                    else {
                        cout << "Not enough balance or invalid amount.\n";
                    }
                }
                else break;
            }
        }
    }

    cout << "Goodbye!\n";
    return 0;
}
