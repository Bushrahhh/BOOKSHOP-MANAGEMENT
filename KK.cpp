#include <iostream>
#include <vector>

class Book {
private:
    std::string name;
    std::string isbn;
    std::string author;
public:
    Book(const std::string& name, const std::string& isbn, const std::string& author)
        : name(name), isbn(isbn), author(author) {}

    std::string GetName() const { return name; }
    std::string GetIsbn() const { return isbn; }
    std::string GetAuthor() const { return author; }
};

class Staff {
private:
    std::vector<Book> books;
public:
    void AddBook(const Book& book);
    void ViewBooks();
};

void Staff::AddBook(const Book& book) {
    books.push_back(book);
    std::cout << "Book added successfully!" << std::endl;
}

void Staff::ViewBooks() {
    std::cout << "Listing all books:" << std::endl;
    for (const auto& book : books) {
        std::cout << "Name: " << book.GetName() << ", ISBN: " << book.GetIsbn() << ", Author: " << book.GetAuthor() << std::endl;
    }
}

int main() {
    Staff staff;
    char choice;
    std::string name, isbn, author;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add a book" << std::endl;
        std::cout << "2. View all books" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                std::cout << "Enter book name: ";
                std::cin >> name;
                std::cout << "Enter book ISBN: ";
                std::cin >> isbn;
                std::cout << "Enter book author: ";
                std::cin >> author;
                staff.AddBook(Book(name, isbn, author));
                break;
            case '2':
                staff.ViewBooks();
                break;
            case '0':
                std::cout << "Exiting program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != '0');

    return 0;
}
