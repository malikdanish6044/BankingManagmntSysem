#include <iostream>
    #include <random>
        //   >>>>>Banking system<<<<<<
using namespace std; //std::

const int MAX_ACCOUNTS = 100; // limits of account--->100
int accountNumbers[MAX_ACCOUNTS];
string accountHolders[MAX_ACCOUNTS];
double balances[MAX_ACCOUNTS];
int accountCount = 0;

int generateRandomAccountNumber() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1000000000, 9999999999); // Generates 10-digit account numbers
    return distr(gen);
}

void createAccount() {
    if (accountCount < MAX_ACCOUNTS) {
        accountNumbers[accountCount] = generateRandomAccountNumber();
        cin.ignore(); // Ignore newline character left in the buffer
        cout << "Enter account holder name: ";
        getline(cin, accountHolders[accountCount]);
        cout << "Enter initial balance: ";
        cin >> balances[accountCount];
        cout << "Account created successfully! Account Number: " << accountNumbers[accountCount] << endl;
        accountCount++;
    } else {
        cout << "Account limit reached!" << endl;
    }
}

void deposit() {
    int accountNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    for (int i = 0; i < accountCount; ++i) {
        if (accountNumbers[i] == accountNumber) {
            balances[i] += amount;
            cout << "Deposited: Rs" << amount << " | New Balance: Rs" << balances[i] << endl;
            return;
        }
    }
    cout << "Account not found!" << endl;
}

void withdraw() {
    int accountNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    for (int i = 0; i < accountCount; ++i) {
        if (accountNumbers[i] == accountNumber) {
            if (balances[i] >= amount) {
                balances[i] -= amount;
                cout << "Withdrawn: Rs" << amount << " | New Balance: Rs" << balances[i] << endl;
            } else {
                cout << "Insufficient funds!" << endl;
            }
            return;
        }
    }
    cout << "Account not found!" << endl;
}

void displayAccount() {
    int accountNumber;
    cout << "Enter account number: ";
    cin >> accountNumber;

    for (int i = 0; i < accountCount; ++i) {
        if (accountNumbers[i] == accountNumber) {
            cout << "Account Number: " << accountNumbers[i] << endl;
            cout << "Account Holder: " << accountHolders[i] << endl;
            cout << "Balance: Rs" << balances[i] << endl;
            return;
        }
    }
    cout << "Account not found!" << endl;
}

int main() {
    int choice;
    do {
        cout << "\nBanking System Menu" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display Account" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                displayAccount();
                break;
            case 5:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
//>>>Banking manement system<<<