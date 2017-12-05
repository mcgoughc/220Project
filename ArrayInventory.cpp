//
// Created by Chase McGough on 11/30/17.
//


#include <iostream>
#include "ArrayInventory.h"
#include "Book.h"

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

Book& ArrayInventory::getItem(std::string title) {//TODO make this a bin find instead of a linear search
    for(int b = 0; b < currItemCount; b++) {
        if(array[b].getTitle() == title)
            return array[b];
    }
}

bool ArrayInventory::isEmpty() {
    return currItemCount == 0;
}

int ArrayInventory::itemCount() {
    return currItemCount;
}
