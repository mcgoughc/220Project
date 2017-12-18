/*
 * Book.cpp
 * Comp 220 Bookstore Project
 * Written by Joe Cleveland, Chase McGough, and Anthony Pizzo
 * This file is the method definitions of Book
*/

#include "Book.h"



Book::Book() {
    title = "NONE";
    haveValue = 0;
    wantValue = 0;
    waitListLength = 0;
    waitList = new LinkedQueue<Person>();
}

Book::Book(const Book& booktoCopy) {
    title = booktoCopy.title;
    haveValue = booktoCopy.haveValue;
    wantValue = booktoCopy.wantValue;
    waitListLength = booktoCopy.waitListLength;
    waitList = new LinkedQueue<Person>(booktoCopy.waitList);
}

Book& Book::operator=(const Book& booktoCopy) {
    if (this != &booktoCopy) {
        delete waitList;

        title = booktoCopy.title;
        haveValue = booktoCopy.haveValue;
        wantValue = booktoCopy.wantValue;
        waitListLength = booktoCopy.waitListLength;
        waitList = new LinkedQueue<Person>(booktoCopy.waitList);
    }
    return *this;
}

Book::~Book() {
    delete waitList;
}

Book::Book(std::string title, int want, int have) {
    this->title = title;
    haveValue = have;
    wantValue = want;
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

std::string Book::getWaitList() {
    std::string output;
    if(waitList->isEmpty()){
        output = "";
    }else{
        output = waitList->toString();
    }
    return output;
}

bool Book::isWaitListEmpty() {
    return waitList->isEmpty();
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


