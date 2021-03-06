/*
 * ArrayInventory.cpp
 * Comp 220 Bookstore Project
 * Written by Joe Cleveland, Chase McGough, and Anthony Pizzo
 * This file is the method definitions for ArrayInventory
*/

#include "ArrayInventory.h"


//Constructor
ArrayInventory::ArrayInventory(int initialCapacity) {
    array = new Book[initialCapacity];
    currCapacity = initialCapacity;
    currItemCount = 0;
}

//Copy Constructor
ArrayInventory::ArrayInventory(const ArrayInventory& inventoryToCopy) {
    currItemCount = inventoryToCopy.currItemCount;
    currCapacity = inventoryToCopy.currCapacity;

    array = new Book[currCapacity];
    for (int i = 0; i < currItemCount; ++i) {
        array[i] = inventoryToCopy.array[i];
    }
}

//Overloaded Assignment Operator
ArrayInventory& ArrayInventory::operator=(const ArrayInventory &inventoryToCopy) {
    if(this != &inventoryToCopy){
        delete[] array;

        currItemCount = inventoryToCopy.currItemCount;
        currCapacity = inventoryToCopy.currCapacity;

        array = new Book[currCapacity];
        for (int i = 0; i < currItemCount; ++i) {
            array[i] = inventoryToCopy.array[i];
        }
    }
    return *this;
}

//Destructor
ArrayInventory::~ArrayInventory() {
    delete[] array;
}



Book* ArrayInventory::copyArray(const Book* arrayToCopy, int size) {
    Book* dupArray = new Book[size];

    for (int i = 0; i < size; ++i) {
        dupArray[i] = arrayToCopy[i];
    }

    return dupArray;
}

void ArrayInventory::doubleCapacity() {
    Book* tempArray = copyArray(array, currItemCount);

    delete[] array;
    currCapacity = currCapacity*2;
    array = new Book[currCapacity];


    for (int j = 0; j < currItemCount; ++j) {
        array[j] = tempArray[j];
    }

    delete[] tempArray;
    tempArray = nullptr;
}

void ArrayInventory::insertAt(Book itemToAdd, int index) {
    if(index < 0 || index > currItemCount){
        throw std::out_of_range("<Index not in range>");
    }

    for (int i = currItemCount-1; i >= index; i--) {
        array[i+1] = array[i];
    }

    array[index] = itemToAdd;
    currItemCount++;
}

void ArrayInventory::addItem(Book itemToAdd) {//TODO Prevent duplicate entries
    if(currCapacity-2 <= currItemCount){
        doubleCapacity();
    }
    if(currItemCount == 0)
        insertAt(itemToAdd, 0);
    else {
        std::string itemTitle = itemToAdd.getTitle();
        //Make title all lower case for comparison purposes:
        std::transform(itemTitle.begin(), itemTitle.end(), itemTitle.begin(), ::tolower);
        bool inserted = false;
        for (int i = 0; i < currItemCount; i++) {
            std::string currTitle = array[i].getTitle();
            std::transform(currTitle.begin(), currTitle.end(), currTitle.begin(), ::tolower);
            if (itemTitle < currTitle) {
                insertAt(itemToAdd, i);
                inserted = true;
                i = currItemCount;//break condition
            }
        }
        if(!inserted)
            insertAt(itemToAdd, currItemCount);
    }
}

void ArrayInventory::sellItem(std::string title){
    Book& item = binGetItem(title);
    int haveValue = item.getHaveValue();
    if(haveValue == 0)
        throw std::out_of_range("No more copies");
    item.setHaveValue(haveValue - 1);
}

Book& ArrayInventory::getItemAt(int index) {
    if(isEmpty()){
        throw std::out_of_range("Array is empty");
    }else if(index > currItemCount || index < 0){
        throw std::out_of_range("Index out of range");
    }else{
        return array[index];
    }
}

bool ArrayInventory::isEmpty() {
    return currItemCount == 0;
}

int ArrayInventory::itemCount() {
    return currItemCount;
}

std::string ArrayInventory::listInventory(){
    std::string output;
    for(int b = 0; b < currItemCount; b++){
        output += array[b].getTitle() + "\n";
    }
    return output;
}

int binFind(Book* arrayPtr, int min, int max, std::string titleToFind){
    if(min <= max){
        int middle = (min + max)/2;
        std::string midTitle = arrayPtr[middle].getTitle();
        std::transform(midTitle.begin(), midTitle.end(), midTitle.begin(), ::tolower);
        std::transform(titleToFind.begin(), titleToFind.end(), titleToFind.begin(), ::tolower);

        if(midTitle == titleToFind){
            return middle;

        }else if(midTitle > titleToFind){
            return binFind(arrayPtr, min, middle-1, titleToFind);

        }else if(midTitle < titleToFind){
            return binFind(arrayPtr, middle+1, max, titleToFind);

        }else{
            return -1;
        }
    }else{
        return -1;
    }
}

Book& ArrayInventory::binGetItem(std::string title) {
    int idx = binFind(array, 0, currItemCount-1, title);

    if(idx == -1){
        throw MissingBook();
    }else{
        return array[idx];
    }
}

int ArrayInventory::getIndex(std::string title) {
    return binFind(array, 0, currItemCount-1, title);
}

bool ArrayInventory::itemExists(std::string title) {
    int idx = binFind(array, 0, currItemCount-1, title);
    return idx != -1;
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

bool isAlphabeticallyGreaterThan(std::string A, std::string B) {
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
}*/