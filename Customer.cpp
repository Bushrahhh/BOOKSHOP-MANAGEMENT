#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string isbn;
    int number;

public:
    Book(string isbn, int number) : isbn(isbn), number(number) {}

    string getIsbn() const {
        return isbn;
    }

    int getNumber() const {
        return number;
    }

    void setNumber(int newNumber) {
        number = newNumber;
    }

    double netPrice(int copies) const {
        // Placeholder calculation
        return 10.0 * copies;
    }
};

class Library {
public:
    vector<Book> bookArray;
};

class Log {};

class Customer {
private:
    Library lib;
    Log rec;

    bool isAllDigit(const string& str) {
        for (char c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }

public:
    void buyBook() {
        system("cls");
        string isbn, temp;
        cout << "Please input the ISBN number of the book that you want to buy: ";
        cin >> isbn;

        for (auto& book : lib.bookArray) {
            if (book.getIsbn() == isbn) {
                cout << "There are " << book.getNumber() << " copies of this book. How many do you want to buy? ";
                cin >> temp;

                if (isAllDigit(temp)) {
                    int copies = stoi(temp);
                    if (copies <= book.getNumber()) {
                        book.setNumber(book.getNumber() - copies);
                        cout << "Bought " << copies << " copies of that book successfully!" << endl;
                        cout << "Automatic quit after 3 seconds." << endl;
                        // Update logs and print book array
                    } else {
                        cout << "Not enough copies available." << endl;
                    }
                } else {
                    cout << "Please input a valid number." << endl;
                }
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void refund() {
        // Similar logic as buyBook, but refunding instead
    }

    void interface(const string& username) {
        char command;
        while (true) {
            system("cls");
            cout << "Welcome, " << username << "! You are a customer." << endl;
            cout << "Please choose what you want to do by entering a number:" << endl;
            cout << "1. Buy book" << endl;
            cout << "2. Refund" << endl;
            cout << "3. Exit" << endl;
            cout << "Your choice: ";
            cin >> command;

            switch (command) {
                case '1':
                    buyBook();
                    break;
                case '2':
                    refund();
                    break;
                case '3':
                    cout << "Exiting..." << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};

int main() {
    Customer customer;
    string username;

    cout << "Enter your username: ";
    cin >> username;

    customer.interface(username);

    return 0;
}


