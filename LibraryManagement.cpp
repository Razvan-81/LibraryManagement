#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class for Books
class Book {
private:
    string title;
    string author;
    string isbnCode;
    bool isAvailable;

public:
    // Constructor
    Book(const string& t, const string& a, const string& isbn) 
        : title(t), author(a), isbnCode(isbn), isAvailable(true) {}

    // Access methods
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getIsbnCode() const { return isbnCode; }
    bool checkAvailability() const { return isAvailable; }

    // Book management
    void borrow() {
        if (isAvailable) {
            isAvailable = false;
            cout << "The book \"" << title << "\" has been borrowed.\n";
        } else {
            cout << "The book \"" << title << "\" is not available for borrowing.\n";
        }
    }

    void returnBack() {
        isAvailable = true;
        cout << "The book \"" << title << "\" has been returned.\n";
    }
};

// Class for the Library
class Library {
private:
    vector<Book> catalog;

public:
    // Add a book to the library
    void addBook(const Book& newBook) {
        catalog.push_back(newBook);
        cout << "The book \"" << newBook.getTitle() << "\" has been added to the library.\n";
    }

    // Display all books
    void showCatalog() const {
        cout << "Library catalog:\n";
        for (const auto& book : catalog) {
            cout << "- " << book.getTitle() << " by " << book.getAuthor()
                 << " (ISBN: " << book.getIsbnCode() << ") "
                 << (book.checkAvailability() ? "[Available]" : "[Borrowed]") << "\n";
        }
    }

    // Search for a book by title
    void findBookByTitle(const string& searchTitle) const {
        for (const auto& book : catalog) {
            if (book.getTitle() == searchTitle) {
                cout << "Found: " << book.getTitle() << " by " << book.getAuthor()
                     << " (ISBN: " << book.getIsbnCode() << ") "
                     << (book.checkAvailability() ? "[Available]" : "[Borrowed]") << "\n";
                return;
            }
        }
        cout << "No book with the title \"" << searchTitle << "\" was found in the library.\n";
    }
};

int main() {
    Library library;

    // Add some books
    library.addBook(Book("Clean Code", "Robert C. Martin", "777321"));
    library.addBook(Book("The Pragmatic Programmer", "Andrew Hunt", "777122"));
    library.addBook(Book("Design Patterns", "Erich Gamma", "777371"));

    // Show the catalog
    library.showCatalog();

    // Search for a book
    library.findBookByTitle("Clean Code");

    // Attempt to borrow a book
    library.findBookByTitle("Clean Code");

    return 0;
}
