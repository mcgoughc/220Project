//
// Created by Chase McGough on 11/28/17.
//

#include "Book.h"
#include "Queue.h"

Book::Book(std::string title, std::string author) {
    this->title = title;
    this->author = author;
    haveValue = 0;
    wantValue = 0;
    waitListLength = 0;
    //LinkedQueue<T> not yet implemented, once it is, uncomment this line:
    //waitList = new LinkedQueue<Person>();
}

void Book::addToWaitList(Person &p) {
    waitList->enqueue(p);
    waitListLength++;
}

Person Book::removeFromWaitList() {
    waitListLength--;
    return waitList->dequeue();
}

std::string* Book::getWaitList() {
    std::string* returnList = new std::string[waitListLength];
    Queue<Person>* waitListCopy = waitList;
    for(int listIndex = 0; listIndex < waitListLength; listIndex++){
        //LinkedQueue<T> not yet implemented, once it is, uncomment this line:
        //returnList[listIndex] = waitListCopy->dequeue();
    }
    return returnList;
}

int Book::getHaveValue() {
    return haveValue;
}

void Book::setHaveValue(int newValue) {
    haveValue = newValue;
}

int Book::getWantValue() {
    return wantValue;
}

void Book::setWantValue(int newValue) {
    wantValue = newValue;
}

