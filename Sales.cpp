#include <iostream>
#include <vector>

using namespace std;

class Book {
private:
    string name;
    string isbn;
    string author;
public:
    Book(const string& name, const string& isbn, const string& author)
        : name(name), isbn(isbn), author(author) {}

    string GetName() const { return name; }
    string GetIsbn() const { return isbn; }
    string GetAuthor() const { return author; }
};

class Staff {
private:
    vector<Book> books;
public:
    void AddBook(const Book& book);
    void ViewBooks();
};

void Staff::AddBook(const Book& book) {
    books.push_back(book);
    cout << "Book added successfully!" << endl;
}

void Staff::ViewBooks() {
    cout << "Listing all books:" << endl;
    for (const auto& book : books) {
        cout << "Name: " << book.GetName() << ", ISBN: " << book.GetIsbn() << ", Author: " << book.GetAuthor() << endl;
    }
}

int main() {
    Staff staff;
    char choice;
    string name, isbn, author;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. View all books" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter book name: ";
                cin >> name;
                cout << "Enter book ISBN: ";
                cin >> isbn;
                cout << "Enter book author: ";
                cin >> author;
                staff.AddBook(Book(name, isbn, author));
                break;
            case '2':
                staff.ViewBooks();
                break;
            case '0':
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '0');

    return 0;
}
