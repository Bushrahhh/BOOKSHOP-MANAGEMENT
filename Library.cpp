#include <iostream>
#include <vector>
#include <string>

using namespace std;

class User {
private:
    string username;
    string password;
    int status;

public:
    // Constructor
    User(const string& username, const string& password, int status) : username(username), password(password), status(status) {}

    // Getters
    string getUsername() const { return username; }
    string getPassword() const { return password; }
    int getStatus() const { return status; }

    // Setters
    void setUsername(const string& username) { this->username = username; }
    void setPassword(const string& password) { this->password = password; }
    void setStatus(int status) { this->status = status; }
};

class Book {
private:
    string name;
    string isbn;
    string author;
    int number;
    int category;
    int price;
    double discount;
    int disc_num;
    string information;

public:
    // Constructor
    Book(const string& name, const string& isbn, const string& author, int number, int category, int price, double discount, int disc_num, const string& information) : 
        name(name), isbn(isbn), author(author), number(number), category(category), price(price), discount(discount), disc_num(disc_num), information(information) {}

    // Getters
    string getName() const { return name; }
    string getIsbn() const { return isbn; }
    string getAuthor() const { return author; }
    int getNumber() const { return number; }
    int getCategory() const { return category; }
    int getPrice() const { return price; }
    double getDiscount() const { return discount; }
    int getDiscNum() const { return disc_num; }
    string getInformation() const { return information; }

    // Setters
    void setName(const string& name) { this->name = name; }
    void setIsbn(const string& isbn) { this->isbn = isbn; }
    void setAuthor(const string& author) { this->author = author; }
    void setNumber(int number) { this->number = number; }
    void setCategory(int category) { this->category = category; }
    void setPrice(int price) { this->price = price; }
    void setDiscount(double discount) { this->discount = discount; }
    void setDiscNum(int disc_num) { this->disc_num = disc_num; }
    void setInformation(const string& information) { this->information = information; }
};

class Library {
private:
    vector<User> userArray;
    vector<Book> bookArray;
    int income;
    int outcome;

public:
    // Constructor
    Library() : income(0), outcome(0) {}

    // Methods
    void addUser(const User& user) { userArray.push_back(user); }
    void addBook(const Book& book) { bookArray.push_back(book); }
    void loadUser(); // Implementation will be added
    void loadBook(); // Implementation will be added
    void loadCash(); // Implementation will be added
};

void Library::loadUser() {
    // Simulated loading of user data from storage
    // This method will populate the userArray with data
}

void Library::loadBook() {
    // Simulated loading of book data from storage
    // This method will populate the bookArray with data
}

void Library::loadCash() {
    // Simulated loading of cash data from storage
    // This method will set the income and outcome
}

int main() {
    Library library;
    library.loadUser();
    library.loadBook();
    library.loadCash();

    // Main program logic goes here

    return 0;
}
