//
// Created by Joseph Cleveland on 11/14/17.
//

#include "BookStore.h"
#include "ArrayList.h"


/**
 * Default Constructor
 */
BookStore::BookStore() {
    booksInStore = new ArrayList<Book>();
    int numBooks = 5;
}

/**
 * Copy Constructor
 * Duplicates data to new bookstore
 * @param bookstoreToCopy Data to duplicate
 */
BookStore::BookStore(const BookStore &bookstoreToCopy) {

}

/**
 * Overload Assignment Operator
 * Overwrites current bookstore with data from bookstoreToCopy
 * @param bookstoreToCopy Data to duplicate
 * @return Address to the overwritten BookStore
 */
BookStore& BookStore::operator=(const BookStore &bookstoreToCopy) {
    return *this;
}

/**
 * Destructor
 */
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

/**
 *
 * @param A
 * @param B
 * @return
 */
bool BookStore::isAlphabeticallyGreaterThan(std::string A, std::string B) {
    int A_Value = stringAlphaValue(A);
    int B_Value = stringAlphaValue(B);
    return A > B;
}

/**
 *
 * @return
 */
std::string* BookStore::list() {
    return nullptr;
}

/**
 *
 * @param title
 * @param want
 * @param have
 */
void BookStore::add(std::string title, int want, int have) {

}

/**
 *
 * @param title
 * @param newWant
 */
void BookStore::setWant(std::string title, int newWant) {

}

/**
 *
 * @param title
 * @param newHave
 */
void BookStore::setHave(std::string title, int newHave) {

}

/**
 *
 * @param title
 * @return
 */
int BookStore::getWant(std::string title) {
    return 0;
}

/**
 *
 * @param title
 * @return
 */
int BookStore::getHave(std::string title) {
    return 0;
}

/**
 *
 * @param title
 * @return
 */
std::string* BookStore::getWaitList(std::string title) {
    return nullptr;
}

/**
 *
 * @param title
 */
void BookStore::sell(std::string title) {

}

/**
 *
 * @param outputFile
 */
void BookStore::order(std::string outputFile) {

}

/**
 *
 * @param inputFile
 */
void BookStore::deliver(std::string inputFile) {

}

/**
 *
 * @param outputFile
 */
void BookStore::returnBooks(std::string outputFile) {

}
