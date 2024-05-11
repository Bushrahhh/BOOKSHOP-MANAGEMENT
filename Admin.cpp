#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class User {
protected:
    string username;
    string password;
    int status;
public:
    User() : status(0) {}
    User(const string& uname, const string& pwd, int stat) : username(uname), password(pwd), status(stat) {}
    string getUsername() const { return username; }
    void setUsername(const string& uname) { username = uname; }
    string getPassword() const { return password; }
    void setPassword(const string& pwd) { password = pwd; }
    int getStatus() const { return status; }
    void setStatus(int stat) { status = stat; }
};

class Library {
protected:
    vector<User> userArray;
public:
    void addUser(const User& newUser) { userArray.push_back(newUser); }
    void removeUser(const string& username) { 
        for (size_t i = 0; i < userArray.size(); ++i) {
            if (userArray[i].getUsername() == username) {
                userArray.erase(userArray.begin() + i);
                return;
            }
        }
    }
    void printAllUsers() const {
        cout << "List of all users:" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "|       Username      |      Password      |   Status  |" << endl;
        cout << "----------------------------------------------------" << endl;
        for (const auto& user : userArray) {
            cout << "|" << setw(21) << user.getUsername() << "|" << setw(19) << user.getPassword() << "|";
            switch (user.getStatus()) {
                case 1:
                    cout << setw(10) << "Administrator" << "|" << endl;
                    break;
                case 2:
                    cout << setw(10) << "Staff" << "|" << endl;
                    break;
                case 3:
                    cout << setw(10) << "Customer" << "|" << endl;
                    break;
                default:
                    cout << setw(10) << "Unknown" << "|" << endl;
                    break;
            }
        }
        cout << "----------------------------------------------------" << endl;
    }
};

class Admin {
public:
    static void addUser(Library& lib) {
        string name, pwd;
        cout << "Please input the username you want to register: ";
        cin >> name;
        cout << "Please input the password: ";
        cin >> pwd;
        User newUser(name, pwd, 3); // Assume new users are customers by default
        lib.addUser(newUser);
        cout << "User added successfully!" << endl;
    }

    static void removeUser(Library& lib) {
        string name;
        cout << "Please input the username you want to delete: ";
        cin >> name;
        lib.removeUser(name);
        cout << "User deleted successfully!" << endl;
    }

    static void printAllUsers(const Library& lib) {
        lib.printAllUsers();
    }
};

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
}
