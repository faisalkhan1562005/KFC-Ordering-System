#include <iostream>
#include <string>
using namespace std;

struct Book
{
    string title;
    string author;
    bool isBorrowed;
};

const int maxBooks = 100;  // Maximum capacity of the library
Book books[maxBooks];
int bookCount = 0;


// Function Declarations
void addBook();
void deleteBook();
void searchBook();
void viewBooks();
void borrowBook();
void returnBook();
void checkAvailability();
void getBookCount();
void getBorrowedCount();
void getAvailableBooksCount();
void clearLibrary();
void viewBooksByAuthor();
void updateBookDetails();
void viewBorrowedBooks();
void menu();

int main()
{

    cout << "\033[31m"
        << "  _     _ _                            __  __                                                   _   \n"
        << " | |   (_| |__  _ __ __ _ _ __ _   _  |  \\/  | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_ \n"
        << " | |   | | '_ \\| '__/ _` | '__| | | | | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ | '_ ` _ \\ / _ | '_ \\| __|\n"
        << " | |___| | |_) | | | (_| | |  | |_| | | |  | | (_| | | | | (_| | (_| |  __| | | | | |  __| | | | |_ \n"
        << " |_____|_|_.__/|_|  \\__,_|_|   \\__, | |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__|\n"
        << "                               |___/                            |___/                               \n"
        << "\033[0m";
    menu();
    return 0;
}

// Function Definitions

void addBook()
{
    if (bookCount >= maxBooks)
    {
        cout << "Library is full, cannot add more books.\n";
        return;
    }
    Book newBook;
    cin.ignore(); // Clear input buffer
    cout << "Enter book title: ";
    getline(cin, newBook.title);
    cout << "Enter author name: ";
    getline(cin, newBook.author);
    newBook.isBorrowed = false;  // Default: book is available
    books[bookCount++] = newBook;
    cout << "Book added successfully!\n";
}

void deleteBook()
{
    string title;
    cin.ignore();
    cout << "Enter the title of the book to delete: ";
    getline(cin, title);
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].title == title)
        {
            for (int j = i; j < bookCount - 1; j++)
            {
                books[j] = books[j + 1];  // Shift books left
            }
            bookCount--;
            cout << "Book deleted successfully!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void searchBook()
{
    string title;
    cin.ignore();
    cout << "Enter the title of the book to search: ";
    getline(cin, title);
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].title == title)
        {
            cout << "Book found: " << books[i].title << " by " << books[i].author << "\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void viewBooks()
{
    if (bookCount == 0)
    {
        cout << "No books available.\n";
        return;
    }
    for (int i = 0; i < bookCount; i++)
    {
        cout << "Title: " << books[i].title << ", Author: " << books[i].author;
        cout << (books[i].isBorrowed ? " (Borrowed)" : " (Available)") << "\n";
    }
}

void borrowBook()
{
    string title;
    cin.ignore();
    cout << "Enter book title to borrow: ";
    getline(cin, title);
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].title == title)
        {
            if (!books[i].isBorrowed)
            {
                books[i].isBorrowed = true;
                cout << "Book borrowed successfully!\n";
            }
            else
            {
                cout << "Book is already borrowed.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

void returnBook()
{
    string title;
    cin.ignore();
    cout << "Enter book title to return: ";
    getline(cin, title);
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].title == title)
        {
            if (books[i].isBorrowed)
            {
                books[i].isBorrowed = false;
                cout << "Book returned successfully!\n";
            }
            else
            {
                cout << "This book is not borrowed.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

void checkAvailability()
{
    string title;
    cin.ignore();
    cout << "Enter book title to check availability: ";
    getline(cin, title);
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].title == title)
        {
            cout << (books[i].isBorrowed ? "Book is borrowed." : "Book is available.") << "\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void getBookCount()
{
    cout << "Total books: " << bookCount << "\n";
}

void getBorrowedCount()
{
    int count = 0;
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].isBorrowed) count++;
    }
    cout << "Total borrowed books: " << count << "\n";
}

void getAvailableBooksCount()
{
    int count = 0;
    for (int i = 0; i < bookCount; i++)
    {
        if (!books[i].isBorrowed) count++;
    }
    cout << "Total available books: " << count << "\n";
}

void clearLibrary()
{
    bookCount = 0;  // Reset the library
    cout << "Library cleared.\n";
}

void viewBooksByAuthor()
{
    string author;
    cin.ignore();
    cout << "Enter author name: ";
    getline(cin, author);
    bool found = false;
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].author == author)
        {
            cout << "Title: " << books[i].title << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No books found by this author.\n";
    }
}

void updateBookDetails()
{
    string title;
    cin.ignore();
    cout << "Enter the title of the book to update: ";
    getline(cin, title);
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].title == title)
        {
            cout << "Enter new author name: ";
            getline(cin, books[i].author);
            cout << "Book details updated.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void viewBorrowedBooks()
{
    bool found = false;
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].isBorrowed)
        {
            cout << "Title: " << books[i].title << " by " << books[i].author << "\n";
            found = true;
        }
    }
    if (!found)
    {
        cout << "No borrowed books.\n";
    }
}

void menu()
{
    int choice;
    do {



       

        // Menu Design
        cout << "\033[34m" << "\n=======================================\n" << "\033[0m";
        cout << "\033[32m" << "       Library Management System       \n" << "\033[0m";
        cout << "\033[34m" << "=======================================\n" << "\033[0m";
        cout << "  1. Add Book                          \n";
        cout << "  2. Delete Book                       \n";
        cout << "  3. Search Book                       \n";
        cout << "  4. View All Books                    \n";
        cout << "  5. Borrow Book                       \n";
        cout << "  6. Return Book                       \n";
        cout << "  7. Check Availability                \n";
        cout << "  8. Get Total Book Count              \n";
        cout << "  9. Get Borrowed Book Count           \n";
        cout << " 10. Get Available Book Count          \n";
        cout << " 11. Clear Library                     \n";
        cout << " 12. View Books by Author              \n";
        cout << " 13. Update Book Details               \n";
        cout << " 14. View Borrowed Books               \n";
        cout << " 15. Exit                              \n";
        cout << "\033[34m" << "=======================================\n" << "\033[0m";
        cout << "\033[33m" << "Enter your choice: " << "\033[0m";


        if (!(cin >> choice)) {
            cin.clear(); // Clear invalid input flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Wrong input, please enter a valid number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            deleteBook();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            viewBooks();
            break;
        case 5:
            borrowBook();
            break;
        case 6:
            returnBook();
            break;
        case 7:
            checkAvailability();
            break;
        case 8:
            getBookCount();
            break;
        case 9:
            getBorrowedCount();
            break;
        case 10:
            getAvailableBooksCount();
            break;
        case 11:
            clearLibrary();
            break;
        case 12:
            viewBooksByAuthor();
            break;
        case 13:
            updateBookDetails();
            break;
        case 14:
            viewBorrowedBooks();
            break;
        case 15:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Wrong input, please select a valid option.\n";
        }
    } while (choice != 15);
}