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
    int haveValue;
    int wantValue;
    Queue<Person>* waitList;

public:
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
    std::string* getWaitList();

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
};


#endif //INC_220PROJECT_BOOK_H
