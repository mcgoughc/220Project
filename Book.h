//
// Created by Chase McGough on 11/28/17.
//

#ifndef INC_220PROJECT_BOOK_H
#define INC_220PROJECT_BOOK_H

#include <string>
#include "Person.h"

class Book {
private:
    std::string title;
    int haveValue;
    int wantValue;
    Queue<Person>* waitList;

public:
    void addToWaitList(Person& p);
    Person removeFromWaitList();

};


#endif //INC_220PROJECT_BOOK_H
