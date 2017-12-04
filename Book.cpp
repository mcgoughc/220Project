//
// Created by Chase McGough on 11/28/17.
//

#include "Book.h"
#include "LinkedQueue.h"

Book::Book() {
    title = "NONE";
    author = "NONE";
    haveValue = 0;
    wantValue = 0;
    waitListLength = 0;
    waitList = new LinkedQueue<Person>();
}

Book::Book(std::string title, std::string author, int want, int have) {
    this->title = title;
    this->author = author;
    haveValue = want;
    wantValue = have;
    waitListLength = 0;
    waitList = new LinkedQueue<Person>();
}

void Book::addToWaitList(Person &p) {
    waitList->enqueue(p);
    waitListLength++;
}

Person Book::removeFromWaitList() {
    if(waitListLength == 0){
        throw std::out_of_range("No people in waitlist");
    }else {
        waitListLength--;
        return waitList->dequeue();
    }
}

std::string* Book::getWaitList() { //FIXME returns pointer? Should return string?
    std::string* returnList = new std::string[waitListLength];
    Queue<Person>* waitListCopy = waitList;
    for(int listIndex = 0; listIndex < waitListLength; listIndex++){
        returnList[listIndex] = waitListCopy->dequeue().toString(); //FIXME Can we get waitlist without emptying it?
    }
    return returnList;
}

int Book::getHaveValue() {
    return haveValue;
}

void Book::setHaveValue(int newValue) {
    if (newValue < 0) {
        throw std::out_of_range("Invalid entry");
    }
    else {
        haveValue = newValue;
    }
}

int Book::getWantValue() {
    return wantValue;
}

void Book::setWantValue(int newValue) {
    if (newValue < 0) {
        throw std::out_of_range("Invalid entry");
    }
    wantValue = newValue;
}

std::string Book::getTitle() {
    return title;
}

