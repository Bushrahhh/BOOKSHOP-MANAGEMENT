#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    double price;
    int quantity;

public:
    Book(const string& title, double price, int quantity) : title(title), price(price), quantity(quantity) {}

    const string& getTitle() const {
        return title;
    }

    double getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }
};

class Customer {
private:
    string username;

public:
    Customer(const string& username) : username(username) {}

    void buyBook(Book* books[], int numBooks) {
        string title;
        cout << "Enter the title of the book you want to buy: ";
        cin >> title;

        for (int i = 0; i < numBooks; ++i) {
            if (books[i]->getTitle() == title) {
                int quantity;
                cout << "Enter the quantity you want to buy: ";
                cin >> quantity;

                if (quantity <= books[i]->getQuantity()) {
                    double totalCost = quantity * books[i]->getPrice();
                    books[i]->setQuantity(books[i]->getQuantity() - quantity);
                    cout << "You bought " << quantity << " copies of " << title << " for $" << totalCost << endl;
                } else {
                    cout << "Sorry, there are not enough copies available." << endl;
                }
                return;
            }
        }
        cout << "Sorry, the book with title " << title << " is not available." << endl;
    }

    void refundBook(Book* books[], int numBooks) {
        string title;
        cout << "Enter the title of the book you want to refund: ";
        cin >> title;

        for (int i = 0; i < numBooks; ++i) {
            if (books[i]->getTitle() == title) {
                int quantity;
                cout << "Enter the quantity you want to refund: ";
                cin >> quantity;

                if (quantity <= books[i]->getQuantity()) {
                    double refundAmount = quantity * books[i]->getPrice();
                    books[i]->setQuantity(books[i]->getQuantity() + quantity);
                    cout << "You refunded " << quantity << " copies of " << title << " for a total refund of $" << refundAmount << endl;
                } else {
                    cout << "You can't refund more copies than you bought." << endl;
                }
                return;
            }
        }
        cout << "Sorry, the book with title " << title << " is not available for refund." << endl;
    }

    const string& getUsername() const {
        return username;
    }
};

int main() {
    string username;
    cout << "Enter your username: ";
    cin >> username;

    Customer customer(username);

    const int numBooks = 3;
    Book* books[numBooks] = {
        new Book("Book1", 10.99, 5),
        new Book("Book2", 15.99, 3),
        new Book("Book3", 20.49, 7)
    };

    cout << "Welcome, " << customer.getUsername() << "!" << endl;

    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Buy a book" << endl;
        cout << "2. Refund a book" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                customer.buyBook(books, numBooks);
                break;
            case 2:
                customer.refundBook(books, numBooks);
                break;
            case 3:
                cout << "Goodbye!" << endl;
                // Deallocate memory for books
                for (int i = 0; i < numBooks; ++i) {
                    delete books[i];
                }
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }
    }

    return 0;
}
