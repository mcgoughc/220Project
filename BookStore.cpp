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

BookStore::~BookStore() {
    delete booksInStore;
}

std::string BookStore::list() {
    return booksInStore->listInventory();
}

void BookStore::add(std::string title, int want, int have) {
    Book bkToAdd = Book(title, want, have);
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
                if(orderNumber > 0) {
                    book = std::to_string(orderNumber) + " " + book;
                    fout << book << std::endl;
                }
                else if(orderNumber < 0){
                    std::cout << "Note: " << book << "'s have value is greater than want. You should create a return invoice" << std::endl;
                }
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
        while(!fin.eof()) {
            std::string numberInput;
            fin >> numberInput;
            std::string titleInput;
            std::getline(fin, titleInput);
            titleInput.erase(0, 1);
            if(numberInput == "" || titleInput == "")
                break;
            int numberOfBook;
            try {
                numberOfBook = std::stoi(numberInput);
            }catch(std::invalid_argument e){
                std::cout << "Delivery file not formatted properly" << std::endl;
                fin.close();
                return;
            }

            if(booksInStore->itemExists(titleInput)) {
                Book& currentBook = findBook(titleInput);
                int newHaveValue = currentBook.getHaveValue() + numberOfBook;
                bool endOfWaitList = false;
                if(!currentBook.isWaitListEmpty())
                    std::cout << "Deliver " + titleInput + " to the following customers on the wait list:" << std::endl;
                while (!currentBook.isWaitListEmpty() && newHaveValue > 0) {
                    try {
                        std::cout << currentBook.removeFromWaitList().toString() << std::endl;
                        newHaveValue--;
                    } catch (std::out_of_range e) {
                        endOfWaitList = true;
                    }
                }
                currentBook.setHaveValue(newHaveValue);
            }
            else{
                add(titleInput, 0, numberOfBook);
            }

        }
        fin.close();
    }
    else{
        std::cout << "Error in opening " + inputFile;
    }
}

void BookStore::returnBooks(std::string outputFile) {
    std::ofstream fout (outputFile);
    if (fout) {
        std::string printData = booksInStore->listInventory();
        std::stringstream bookList(printData);
        while(bookList){
            std::string book;
            getline(bookList, book);
            if(book != "") {
                int wantValue = getWant(book);
                int returnNumber = getHave(book) - wantValue;
                if(returnNumber > 0) {
                    setHave(book, wantValue);
                    book = std::to_string(returnNumber) + " " + book;
                    fout << book << std::endl;
                }
                else if (returnNumber < 0){
                    std::cout << "Note: " << book << "'s want value is greater than have. You should create an order" << std::endl;
                }
            }
        }
        fout.close();
    }
    else {
        std::cout << "Error in opening " + outputFile;
    }
}

void BookStore::load(std::string inputFile){
    std::ifstream fin (inputFile);
    if(fin){
        std::string inputLine;
        while(std::getline(fin, inputLine)){

        }
    }
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