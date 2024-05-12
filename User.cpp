#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string name;
    string isbn;
    string author;
public:
    // Default constructor
    Book() : name(""), isbn(""), author("") {}

    // Parameterized constructor
    Book(const string& name, const string& isbn, const string& author)
        : name(name), isbn(isbn), author(author) {}

    // Getters
    string getName() const { return name; }
    string getIsbn() const { return isbn; }
    string getAuthor() const { return author; }
};

class Library {
protected:
    static const int MAX_BOOKS = 100;
    Book bookArray[MAX_BOOKS];
    int numBooks;

public:
    // Constructor
    Library() : numBooks(0) {}

    // Methods
    void addBook(const Book& book) {
        if (numBooks < MAX_BOOKS) {
            bookArray[numBooks++] = book;
            cout << "Book added successfully!" << endl;
        } else {
            cout << "Library is full. Cannot add more books." << endl;
        }
    }

    virtual void print() const = 0;
};

class User : public Library {
public:
    void print() const override {
        cout << "Printing User Library" << endl;
        for (int i = 0; i < numBooks; ++i) {
            cout << "Name: " << bookArray[i].getName() << ", ISBN: " << bookArray[i].getIsbn() << endl;
        }
    }
};

class Cashier : public Library {
public:
    void print() const override {
        cout << "Printing Cashier Library" << endl;
        for (int i = 0; i < numBooks; ++i) {
            cout << "Name: " << bookArray[i].getName() << ", ISBN: " << bookArray[i].getIsbn() << endl;
        }
    }
};

int main() {
    User user;
    user.addBook(Book("Book1", "12345", "Author1"));
    user.addBook(Book("Book2", "23456", "Author2"));
    user.print();

    Cashier cashier;
    cashier.addBook(Book("Book3", "34567", "Author3"));
    cashier.print();

    return 0;
}
