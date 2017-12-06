//
// Created by Chase McGough on 11/30/17.
//


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

void ArrayInventory::addItem(Book itemToAdd) {
    if(currCapacity-2 <= currItemCount){
        doubleCapacity();
    }
    std::string itemTitle = itemToAdd.getTitle();
    //Make title all lower case for comparison purposes:
    std::transform(itemTitle.begin(), itemTitle.end(), itemTitle.begin(), ::tolower);
    for(int i = 0; i < currItemCount; i++){
        std::string currTitle = array[i].getTitle();
        std::transform(currTitle.begin(), currTitle.end(), currTitle.begin(), ::tolower);

        if(itemToAdd.getTitle() < array[i].getTitle())
            insertAt(itemToAdd, i);
    }
    currItemCount++;
}

void ArrayInventory::sellItem(std::string title){
    for(int b = 0; b < currItemCount; b++){
        int haveValue = array[b].getHaveValue();
        if(haveValue == 0)
            throw std::out_of_range("Trying to sell too many inventory items.");
        array[b].setHaveValue(haveValue - 1);
    }
}

Book& ArrayInventory::getItem(std::string title) {
    for(int b = 0; b < currItemCount; b++) {
        if(array[b].getTitle() == title)
            return array[b];
    }
    throw std::out_of_range("No such book exists");
}

bool ArrayInventory::isEmpty() {
    return currItemCount == 0;
}

int ArrayInventory::itemCount() {
    return currItemCount;
}

/**
 * Helper function for isAlphabeticallyGreaterThan
 * Gets alphabetical position of char
 * @param input char to calculate value of
 * @return value input char of to be used for comparison
 */
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


bool ArrayInventory::isAlphabeticallyGreaterThan(std::string A, std::string B) {
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

int ArrayInventory::binFind(Book* arrayPtr, int min, int max, std::string titleToFind){
    if(min <= max){
        int middle = (min + max)/2;

        if(isAlphabeticallyGreaterThan(arrayPtr[middle].getTitle(), titleToFind)){
            return binFind(arrayPtr, min, middle-1, titleToFind);
        }else if(!isAlphabeticallyGreaterThan(arrayPtr[middle].getTitle(), titleToFind)){
            return binFind(arrayPtr, middle+1, max, titleToFind);
        }else{
            return middle;
        }
    }else{
        return -1;
    }
}

int ArrayInventory::binGetItem(std::string title) {
    int idx = binFind(array, 0, currItemCount-1, title);
    //return idx;
    if(idx == -1){
        throw std::out_of_range("No such book exists");
    }else{
        return array[idx];
    }

}

