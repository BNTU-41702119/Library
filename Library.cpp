#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Book {
    string title;
    string author;
};

class BookCard {
    Book book;
    int issued = 0;

public:
    BookCard(string title, string author)
    {
        book.title = title;
        book.author = author;
    }

public: 
    void printInfo()
    {
        cout << "Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "Issued: " << issued << endl;
    }

public:
    void issue()
    {
        issued += 1;
    }

public:
    void issue(int count)
    {
        issued += count;
    }

public:
    Book getBook()
    {
        return book;
    }

public:
    int getIssuedCount()
    {
        return issued;
    }

public:
    void changeTitle(string title)
    {
        book.title = title;
    }

public:
    void changeAuthor(string author)
    {
        book.author = author;
    }
};

class Library {
    string title;
    int rating = 0;
    stack <BookCard> booksCards;

public:
    Library(string title)
    {
        this->title = title;
    }

public:
    void addBookCard(BookCard bookCard)
    {
        booksCards.push(bookCard);
    }

public:
    void createBookCard(string title, string author)
    {
        BookCard bookCard = BookCard(title, author);
        addBookCard(bookCard);
    }

public:
    void showAllBooks()
    {
        stack <BookCard> tempStack;

        while (!booksCards.empty())
        {
            BookCard bookCard = booksCards.top();
            bookCard.printInfo();
            tempStack.push(bookCard);
            booksCards.pop();
        }

        while (!tempStack.empty())
        {
            booksCards.push(tempStack.top());
            tempStack.pop();
        }
    }
};

int main()
{
    BookCard firstBook = BookCard("First", "Art");

    firstBook.printInfo();

    firstBook.issue();

    firstBook.issue(4);

    firstBook.printInfo();

    Library firstLibrary = Library("First");

    firstLibrary.addBookCard(firstBook);
    firstLibrary.createBookCard("Second", "Art");

    firstLibrary.showAllBooks();
}
