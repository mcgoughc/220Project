//
// Created by Chase McGough on 11/28/17.
//

#ifndef INC_220PROJECT_BOOK_H
#define INC_220PROJECT_BOOK_H

#include <string>
#include "Person.h"
#include "Queue.h"

class Book {
private:
    std::string title;
    std::string author;
    int haveValue;
    int wantValue;
    Queue<Person>* waitList;
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
    Book(std::string title, std::string author, int want, int have);

    //TODO Copy Constructor
    //TODO Assignment Operator
    //TODO Destructor

    /**
     * Adds person to the end of the wait list.
     * @param p Person to add.
     */
    void addToWaitList(Person& p);
    /**
     * Removes person on the front of the wait list.
     * @return The person removed
     */
    Person removeFromWaitList();
    /**
     * @return The wait list as an array of strings
     */
    std::string getWaitList();

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
     *
     * @return title
     */
    std::string getTitle();

    /**
     * @return author of book
     */
    std::string getAuthor();
};


#endif //INC_220PROJECT_BOOK_H
