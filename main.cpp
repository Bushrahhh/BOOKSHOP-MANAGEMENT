#include "Admin.h"
#include "Library.h"
#include <iostream>

using namespace std;

int main() {
    Library lib;
    char choice;
    while (true) {
        cout << "Welcome to the admin panel!" << endl;
        cout << "1. Add User" << endl;
        cout << "2. Remove User" << endl;
        cout << "3. Print All Users" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case '1':
                Admin::addUser(lib);
                break;
            case '2':
                Admin::removeUser(lib);
                break;
            case '3':
                Admin::printAllUsers(lib);
                break;
            case '0':
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }
    return 0;
}
