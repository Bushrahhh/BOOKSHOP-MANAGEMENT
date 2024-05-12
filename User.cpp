#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string name;
    string isbn;
    string author;
    int number;
    int category;
    int price;
    double discount;
    int discNum;
    string information;

public:
    // Constructor
    Book(const string& name, const string& isbn, const string& author, int number, int category, int price, double discount, int discNum, const string& information) :
        name(name), isbn(isbn), author(author), number(number), category(category), price(price), discount(discount), discNum(discNum), information(information) {}

    // Getters
    string getName() const { return name; }
    string getIsbn() const { return isbn; }
    string getAuthor() const { return author; }
    int getNumber() const { return number; }
    int getCategory() const { return category; }
    int getPrice() const { return price; }
    double getDiscount() const { return discount; }
    int getDiscNum() const { return discNum; }
    string getInformation() const { return information; }

    // Setters
    void setNumber(int num) { number = num; }
};

class Library {
protected:
    vector<Book> bookArray;

public:
    // Methods
    void addBook(const Book& book) { bookArray.push_back(book); }
    virtual void print() const = 0;
};

class User : public Library {
public:
    void print() const override {
        cout << "Printing User Library" << endl;
        for(const auto& book : bookArray) {
            cout << "Name: " << book.getName() << ", ISBN: " << book.getIsbn() << endl;
        }
    }
};

class Cashier : public Library {
public:
    void print() const override {
        cout << "Printing Cashier Library" << endl;
        for(const auto& book : bookArray) {
            cout << "Name: " << book.getName() << ", ISBN: " << book.getIsbn() << endl;
        }
    }
};

int main() {
    User user;
    user.addBook(Book("Book1", "12345", "Author1", 10, 1, 20, 0.1, 1, "Information1"));
    user.addBook(Book("Book2", "23456", "Author2", 20, 2, 30, 0.2, 2, "Information2"));
    user.print();

    Cashier cashier;
    cashier.addBook(Book("Book3", "34567", "Author3", 30, 3, 40, 0.3, 3, "Information3"));
    cashier.print();

    return 0;
}
