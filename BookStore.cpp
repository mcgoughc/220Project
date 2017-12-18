/*
 * BookStore.cpp
 * Comp 220 Bookstore Project
 * Written by Joe Cleveland, Chase McGough, and Anthony Pizzo
 * This file is the method definitions for the BookStore class and handles the Inventory of books
*/

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

        std::string title;
        int want;
        int have;
        bool readingBook = false;

        std::string first;
        std::string last;
        std::string phone;
        std::string email;
        std::string contactPreference;

        while(std::getline(fin, inputLine)){
            if(inputLine == "<b>") {
                readingBook = true;
            }
            else if(inputLine == "</b>"){
                add(title, want, have);
                readingBook = false;
            }
            else if(readingBook){
                std::stringstream bookLine(inputLine);
                bookLine >> want;
                bookLine >> have;
                std::getline(bookLine, title);
                title.erase(0, 1);//Remove empty space from start
            }
            else{
                std::stringstream nameStream(inputLine);
                nameStream >> first;
                nameStream >> last;
                std::getline(fin, phone);
                std::getline(fin, email);
                std::getline(fin, contactPreference);
                int contactNumber = 0;
                if(contactPreference == "Phone Call")
                    contactNumber = 0;
                else if(contactPreference == "Send Text")
                    contactNumber = 1;
                else if(contactPreference == "Send Email")
                    contactNumber = 2;
                Person newPerson(first, last, phone, email, contactNumber);
                findBook(title).addToWaitList(newPerson);
            }
        }
    }
    else{
        std::cout << "Couldn't load from " << inputFile << ", you have a fresh bookstore" << std::endl;
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