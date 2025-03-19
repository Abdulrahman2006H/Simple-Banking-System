#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> usernames, passwords, emails;
vector<double> balances;

void search(string name) {
    for (size_t i = 0; i < usernames.size(); i++)
        if (usernames[i] == name)
            cout << "User found: " << usernames[i] << endl;
}

void create_account(string username, string password, string email) {
    usernames.push_back(username);
    passwords.push_back(password);
    emails.push_back(email);
    balances.push_back(0.0);
    cout << "Account created successfully!" << endl;
}

bool login(string username, string password) {
    for (size_t i = 0; i < usernames.size(); i++)
        if (usernames[i] == username && passwords[i] == password)
        {
            return true;
        }
    return false;
}

void show_account(string username) {
    for (size_t i = 0; i < usernames.size(); i++)
        if (usernames[i] == username)
        {
            cout << "Account: " << usernames[i] << "\n  Balance: " << balances[i] << endl;
        }
}

void deposit(string username, double amount) {
    for (size_t i = 0; i < usernames.size(); i++)
        if (usernames[i] == username) 
        {
            balances[i] += amount;
            cout << "Deposit successful! New Balance: " << balances[i] << endl;
        }
}

void withdrawal(string username, double amount) {
    for (size_t i = 0; i < usernames.size(); i++)
        if (usernames[i] == username && balances[i] >= amount)
        {
            balances[i] -= amount;
            cout << "Withdrawal successful! New Balance: " << balances[i] << endl;
        }
        else if (usernames[i] == username) {
            cout << "Insufficient balance!" << endl;
        }
}

double check_balance(string username) {
    for (size_t i = 0; i < usernames.size(); i++)
        if (usernames[i] == username)
        {
            return balances[i];
        }
    return 0.0;
}



int main() {
    int choice;
    string username, password, email, expiry_date;
    double amount;

    while (true) {
        cout << "\n1. Create Account\n2. Login\n3. Show Account\n4. Deposit\n5. Withdraw\n6. Check Balance\n7. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter username : ";
            cin >> username;
            cout << "Enter password : ";
                cin >> password;
                cout <<"email : ";
             cin>>email;
            create_account(username, password, email);
        }
        else if (choice == 2) {
            cout << "Enter username and password: ";
            cin >> username >> password;
            cout << (login(username, password) ? "Login Successful" : "Login Failed") << endl;
        }
        else if (choice == 3) {
            cout << "Enter username: ";
            cin >> username;
            show_account(username);
        }
        else if (choice == 4) {
            cout << "Enter username and deposit amount: ";
            cin >> username >> amount;
            deposit(username, amount);
        }
        else if (choice == 5) {
            cout << "Enter username and withdrawal amount: ";
            cin >> username >> amount;
            withdrawal(username, amount);
        }
        else if (choice == 6) {
            cout << "Enter username: ";
            cin >> username;
            cout << "Balance: " << check_balance(username) << endl;
        }

        else if (choice == 7) {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid choice! Please enter a number between 1 and 8." << endl;
        }
    }
    return 0;
}
