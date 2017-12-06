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

/**
 * Helper function for isAlphabeticallyGreaterThan
 * Gets alphabetical position of char
 * @param input char to calculate value of
 * @return value input char of to be used for comparison
 */
/*
int charValue(char input){
        int characterValue = (int)input;                      //Gets the ASCII value of the character
        if(characterValue >= 65 && characterValue <= 90)      //If char is between capital A to Z
            characterValue -= 64;                             //subtract so that A = 1 and Z = 26
        else if(characterValue >= 97 && characterValue <= 122)//If char is between lower-case a to z
            characterValue -= 96;                             //subtract so that a = 1 and z = 26
        else
            characterValue = 0;                               //All other characters will be ignored
    return characterValue;
}


bool BookStore::isAlphabeticallyGreaterThan(std::string A, std::string B) {
    int shorterLength = std::min(A.length(), B.length());
    bool foundGreaterCharacter = false;
    bool allEqual = true;
    for(int s = 0; s < shorterLength; s++){
        if(charValue(A.at(s)) > charValue(B.at(s))) {
            foundGreaterCharacter = true;
            allEqual = false;
        }
        else if(charValue(A.at(s)) < charValue(B.at(s))){
            allEqual = false;
        }
    }
    if(allEqual && A.length() != B.length())
        foundGreaterCharacter = false;
    return foundGreaterCharacter;
}
*/

std::string BookStore::list() {
    return nullptr;
}


void BookStore::add(std::string title, std::string author, int want, int have) {
    booksInStore->addItem(Book(title, author, want, have));
}


void BookStore::setWant(std::string title, int newWant) {

}


void BookStore::setHave(std::string title, int newHave) {

}


int BookStore::getWant(std::string title) {
    return 0;
}


int BookStore::getHave(std::string title) {
    return 0;
}


std::string* BookStore::getWaitList(std::string title) {
    return nullptr;
}


void BookStore::sell(std::string title) {
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

int BookStore::findBook(std::string titleToFind){
    return booksInStore->binGetItem(titleToFind);
}
