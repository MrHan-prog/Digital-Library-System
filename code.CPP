#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool available;

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        available = true;
    }
};

vector<Book> library;

void addBook() {
    int id;
    string title, author;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Author Name: ";
    getline(cin, author);

    library.push_back(Book(id, title, author));
    cout << "Book Added Successfully!\n";
}

void displayBooks() {
    if (library.empty()) {
        cout << "No books available.\n";
        return;
    }

    cout << "\nLibrary Books:\n";
    for (auto &book : library) {
        cout << "ID: " << book.id
             << "\nTitle: " << book.title
             << "\nAuthor: " << book.author
             << "\nStatus: "
             << (book.available ? "Available" : "Issued")
             << "\n---------------------\n";
    }
}

void issueBook() {
    int id;
    cout << "Enter Book ID to Issue: ";
    cin >> id;

    for (auto &book : library) {
        if (book.id == id) {
            if (book.available) {
                book.available = false;
                cout << "Book Issued Successfully!\n";
            } else {
                cout << "Book is already issued.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

void returnBook() {
    int id;
    cout << "Enter Book ID to Return: ";
    cin >> id;

    for (auto &book : library) {
        if (book.id == id) {
            if (!book.available) {
                book.available = true;
                cout << "Book Returned Successfully!\n";
            } else {
                cout << "Book was not issued.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== DIGITAL LIBRARY SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                issueBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                cout << "Thank You!\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
