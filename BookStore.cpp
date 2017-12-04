//
// Created by Joseph Cleveland on 11/14/17.
//

#include "BookStore.h"
#include "ArrayList.h"


BookStore::BookStore() {
    booksInStore = new ArrayList<Book>();

}


BookStore::BookStore(const BookStore &bookstoreToCopy) {

}


BookStore& BookStore::operator=(const BookStore &bookstoreToCopy) {
    return *this;
}


BookStore::~BookStore() {
    delete booksInStore;
}

/**
 * Helper function for isAlphabeticallyGreaterThan
 * Strings farther in the dictionary will have a higher relative value
 * @param input String to calculate value of
 * @return value input string of to be used for comparison
 */
int stringAlphaValue(std::string input){
    int stringValue = 0;
    for(int s = 0; s < input.length();s++){                   //Step through each character of string A
        int characterValue = (int)input.at(s);                   //Gets the ASCII value of the character at position cA
        if(characterValue >= 65 && characterValue <= 90)      //If char is between capital A to Z
            characterValue -= 64;                             //subtract so that A = 1 and Z = 26
        else if(characterValue >= 97 && characterValue <= 122)//If char is between lower-case a to z
            characterValue -= 96;                             //subtract so that a = 1 and z = 26
        else
            characterValue = 0;                               //All other characters will be ignored

        stringValue += characterValue;
    }
    return stringValue;
}


bool BookStore::isAlphabeticallyGreaterThan(std::string A, std::string B) {
    int A_Value = stringAlphaValue(A);
    int B_Value = stringAlphaValue(B);
    return A > B;
}


std::string* BookStore::list() {
    return nullptr;
}


void BookStore::add(std::string title, int want, int have) {

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

}


void BookStore::order(std::string outputFile) {

}


void BookStore::deliver(std::string inputFile) {

}


void BookStore::returnBooks(std::string outputFile) {

}

int BookStore::findBook(std::string titleToFind){
    for (int i = 0; i < booksInStore->itemCount(); ++i) {
        Book currBook = booksInStore->getValueAt(i);
        std::string indexTitle = currBook
    }
}
