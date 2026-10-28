#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser() {
    string username, password;
    cout << "\n--- Registration ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();

    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password, u, p;
    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream infile("users.txt");
    bool loggedIn = false;

    while (infile >> u >> p) {
        if (u == username && p == password) {
            loggedIn = true;
            break;
        }
    }
    infile.close();

    if (loggedIn) {
        cout << "Login successful! Welcome, " << username << "!\n";
    } else {
        cout << "Error: Invalid username or password!\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n1. Register\n2. Login\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}