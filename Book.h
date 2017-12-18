/*
 * Book.h
 * Comp 220 Bookstore Project
 * Written by Joe Cleveland, Chase McGough, and Anthony Pizzo
 * This file is the class definition of Book
*/

#ifndef INC_220PROJECT_BOOK_H
#define INC_220PROJECT_BOOK_H

#include <string>
#include "Person.h"
#include "LinkedQueue.h"



class Book {
private:
    std::string title;
    int haveValue;
    int wantValue;
    LinkedQueue<Person>* waitList;
    int waitListLength;

public:
    /**
     * Default constructor
     * Constructs a blank book
     */
    Book();

    /**
     * Constructs a new book with title and author
     * @param title
     * @param author
     */
    Book(std::string title, int want, int have);

    /**
     * Copy Constructor
     * @param booktoCopy
     */
    Book(const Book& booktoCopy);

    /**
     * Overloaded assignment operator
     * @param booktoCopy
     */
    Book& operator=(const Book& booktoCopy);

    /**
     * Destructor
     */
    ~Book();

    /**
     * Adds person to the end of the wait list.
     * @param p Person to add.
     */
    void addToWaitList(Person& p);

    /**
     * Removes person on the front of the waitlist.
     * Throws out_of_range if the waitlist is empty
     * @return The person removed
     */
    Person removeFromWaitList();

    /**
     * @return The wait list as a string of names,
     *         or a blank string if the waitlist is empty
     */
    std::string getWaitList();

    /**
     * @return True if the waitlist is empty, false otherwise
     */
    bool isWaitListEmpty();

    /**
     * @return haveValue
     */
    int getHaveValue();

    /**
     * Sets haveValue to newValue
     * @param newValue
     */
    void setHaveValue(int newValue);

    /**
     * @return wantValue
     */
    int getWantValue();

    /**
     * Sets wantValue to newValue
     * @param newValue
     */
    void setWantValue(int newValue);

    /**
     * @return Title of the book
     */
    std::string getTitle();
};


#endif //INC_220PROJECT_BOOK_H
