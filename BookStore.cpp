//
// Created by Joseph Cleveland on 11/14/17.
//

#include "BookStore.h"
#include "ArrayInventory.h"
#include <fstream>
#include <sstream>

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
        throw std::out_of_range("Empty array");
    }
    booksInStore->sellItem(title);
}

void BookStore::order(std::string outputFile) {
    std::ofstream fout (outputFile);
    if (fout) {
        std::string printData = booksInStore->listInventory();
        std::stringstream bookList(printData);
        while(bookList){
            std::string book;
            getline(bookList, book);
            if(book != "") {
                int orderNumber = getWant(book) - getHave(book);
                book =  std::to_string(orderNumber) + " " + book;
                fout << book << std::endl;
            }
        }
        fout.close();
    }
    else {
        std::cout << "Error in opening " + outputFile;
    }
}

void BookStore::deliver(std::string inputFile) {
    std::ifstream fin (inputFile);
    if(fin){

    }
    else{
        std::cout << "Error in opening " + inputFile;
    }
    //TODO finish up
}

void BookStore::returnBooks(std::string outputFile) {
    //TODO file IO
}

Book& BookStore::findBook(std::string titleToFind){
    return booksInStore->binGetItem(titleToFind);
}

Book& BookStore::findBookByIndex(int idx) {
    return booksInStore->getItemAt(idx);
}

int BookStore::bookCount() {
    return booksInStore->itemCount();
}

bool BookStore::bookCheck(std::string title) {
    return booksInStore->itemExists(title);
}