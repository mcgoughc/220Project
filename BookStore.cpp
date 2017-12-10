//
// Created by Joseph Cleveland on 11/14/17.
//

#include "BookStore.h"
#include "ArrayInventory.h"

BookStore::BookStore() {
    booksInStore = new ArrayInventory();
}


BookStore::BookStore(const BookStore &bookstoreToCopy) {
    //TODO
}


BookStore& BookStore::operator=(const BookStore &bookstoreToCopy) {
    return *this;
}


BookStore::~BookStore() {
    delete booksInStore;
}


std::string BookStore::list() {
    return booksInStore->listInventory();
}


void BookStore::add(std::string title, std::string author, int want, int have) {
    Book bkToAdd = Book(title, author, want, have);
    booksInStore->addItem(bkToAdd);
}


void BookStore::setWant(std::string title, int newWant) {
    booksInStore->binGetItem(title).setWantValue(newWant);
}


void BookStore::setHave(std::string title, int newHave) {
    booksInStore->binGetItem(title).setHaveValue(newHave);
}


int BookStore::getWant(std::string title) {
    return booksInStore->binGetItem(title).getWantValue();
}


int BookStore::getHave(std::string title) {
    return booksInStore->binGetItem(title).getHaveValue();
}


std::string BookStore::getWaitList(std::string title) {
    return booksInStore->binGetItem(title).getWaitList();
}


void BookStore::sell(std::string title) {
    if (booksInStore->itemCount() <= 0) {
        throw std::out_of_range("No books left to sell");
    }
    booksInStore->sellItem(title);
}


void BookStore::order(std::string outputFile) {
    //TODO file IO
}


void BookStore::deliver(std::string inputFile) {
    //TODO file IO
}


void BookStore::returnBooks(std::string outputFile) {
    //TODO file IO
}

Book& BookStore::findBook(std::string titleToFind){
    return booksInStore->binGetItem(titleToFind);
}
