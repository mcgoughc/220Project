//
// Created by Joseph Cleveland on 11/14/17.
//

#ifndef INC_220PROJECT_BOOKSTORE_H
#define INC_220PROJECT_BOOKSTORE_H

#include <string>
#include <iostream>
#include "Book.h"
#include "Inventory.h"


class BookStore{
private:
    Inventory* booksInStore;
    int numBooks;

public:

    BookStore();

    BookStore(const BookStore& bookstoreToCopy);

    BookStore& operator=(const BookStore& bookstoreToCopy);

    ~BookStore();

    /**
     * List all books alpabetically
     * @return  Array of strings of book titles
     */
    std::string list();

    /**
     * Add new book to inventory
     * @param title The title of the book to add
     * @param author The author of the book to add
     * @param want The ideal number of copies in stock
     * @param have The actual number of copies in stock
     */
    void add(std::string title, std::string author, int want, int have);

    /**
     * Set ideal number of copies for inventory
     * @param title  The title of the book to adjust
     * @param newWant  The new ideal number of copies
     */
    void setWant(std::string title, int newWant);

    /**
     * Set actual number of copies for inventory
     * @param title   The title of the book to adjust
     * @param newHave   The new actual number of copies
     */
    void setHave(std::string title, int newHave);

    /**
     * Get ideal number of copies
     * @param title  The title of the book to get
     * @return  The ideal number of copies
     */
    int getWant(std::string title);

    /**
     * Get actual number of copies
     * @param title  The title of the book to get
     * @return  The actual number of copies
     */
    int getHave(std::string title);

    /**
     * Get the wait list for a book
     * @param title  Book to get waitlist of
     * @return  Array of strings of people's names
     */
    std::string getWaitList(std::string title);

    /**
     * Sell a book, decrease have value by one
     * @param title Title of book to sell
     */
    void sell(std::string title);

    /**
     * Create a list of books and amounts to order, and write to external file
     * @param outputFile  Title of file to write
     */
    void order(std::string outputFile);

    /**
     * Add books to inventory based on external file
     * @param inputFile  Title of file to reference
     */
    void deliver(std::string inputFile);

    /**
     * Create list of books and amounts to return, write to external file, and remove those books
     * @param outputFile  Title of file to write
     */
    void returnBooks(std::string outputFile);

    /**
     * Checks if one string, A, is alphabetically greater, i.e. later in the dictionary
     * than another string, B.
     * @param A first string
     * @param B second string
     * @return true if A is greater than B
     */
    bool isAlphabeticallyGreaterThan(std::string A, std::string B);

    /**
     * Checks the array for a book that matches titleToFind
     * Capitialization must match
     * @param titleToFind
     * @return index of the book, or -1 if the list is empty/the title does not match any book
     */
    int findBook(std::string titleToFind);

};



#endif //INC_220PROJECT_BOOKSTORE_H
