//
// Created by Chase McGough on 11/30/17.
//


#include <iostream>
#include "ArrayList.h"


//Constructor
template <class T>
ArrayList<T>::ArrayList(int initialCapacity) {
    array = new T[initialCapacity];
    currCapacity = initialCapacity;
    currItemCount = 0;
}


//Copy Constructor
template <class T>
ArrayList<T>::ArrayList(const ArrayList& arrayListToCopy) {
    currItemCount = arrayListToCopy.currItemCount;
    currCapacity = arrayListToCopy.currCapacity;

    array = new T[currCapacity];
    for (int i = 0; i < currItemCount; ++i) {
        array[i] = arrayListToCopy.array[i];
    }
}


//Overloaded Assignment Operator
template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T> &arrayListToCopy) {
    if(this != &arrayListToCopy){
        delete[] array;

        currItemCount = arrayListToCopy.currItemCount;
        currCapacity = arrayListToCopy.currCapacity;

        array = new T[currCapacity];
        for (int i = 0; i < currItemCount; ++i) {
            array[i] = arrayListToCopy.array[i];
        }
    }
    return *this;
}


//Destructor
template <class T>
ArrayList<T>::~ArrayList() {
    //IS THIS NEEDED?
    /*
    for (int i = 0; i < currCapacity; ++i) {
        delete i;
    }
    */
    delete[] array;
}

template <class T>
T* ArrayList<T>::copyArray(const T* arrayToCopy, int size) {
    T* dupArray = new T[size];

    for (int i = 0; i < size; ++i) {
        dupArray[i] = arrayToCopy[i];
    }

    return dupArray;
}

template <class T>
void ArrayList<T>::doubleCapacity() {
    T* tempArray = copyArray(array, currItemCount);

    delete[] array;
    currCapacity = currCapacity*2;
    array = new T[currCapacity];


    for (int j = 0; j < currItemCount; ++j) {
        array[j] = tempArray[j];
    }

    delete[] tempArray;
    tempArray = nullptr;
}


template <class T>
void ArrayList<T>::insertAtEnd(T itemToAdd) {
    if(currCapacity-2 <= currItemCount){
        doubleCapacity();
    }

    array[currItemCount] = itemToAdd;
    currItemCount++;
}


template <class T>
void ArrayList<T>::insertAtFront(T itemToAdd) {
    if(currItemCount == currCapacity) {
        doubleCapacity();
    }

    for (int i = currItemCount-1; i > -1; i--) {
        array[i+1] = array[i];
    }

    array[0] = itemToAdd;
    currItemCount++;
}

template <class T>
void ArrayList<T>::insertAt(T itemToAdd, int index) {
    if(index < 0 || index > currItemCount){
        throw std::out_of_range("<Index not in range>");
    }

    //std::cout << "index in method: " << index << std::endl;
    if(currItemCount == currCapacity) {
        doubleCapacity();
    }

    for (int i = currItemCount-1; i >= index; i--) {
        array[i+1] = array[i];
    }

    array[index] = itemToAdd;
    currItemCount++;
}

template <class T>
T ArrayList<T>::getValueAt(int index) {
    if(index < currItemCount && index >= 0){
        return array[index];
    } else{
        throw std::out_of_range("<Index not in range>");
    }
}

template <class T>
T ArrayList<T>::removeValueAt(int index) {
    if(index < 0 || index > currItemCount){
        throw std::out_of_range("Index not in range");
    }

    T output = array[index];
    currItemCount--;

    for (int i = index; i < currItemCount; ++i) {
        array[i] = array[i+1];
    }

    return output;
}

template <class T>
bool ArrayList<T>::isEmpty() {
    return currItemCount == 0;
}

template <class T>
int ArrayList<T>::itemCount() {
    return currItemCount;
}

template <class T>
void ArrayList<T>::clearList() {
    currItemCount = 0;
}

/*
template <class T>
int ArrayList<T>::find(T& itemToFind) {
    if(currItemCount <= 0){
        return -1;
    }

    for (int i = 0; i < currItemCount; ++i) {
        if(&array[i] == &itemToFind){
            return i;
        }

    }
    return -1;
}

template <class T>
int ArrayList<T>::findLast(T itemToFind) {
    if(currItemCount <= 0){
        return -1;
    }

    for (int i = currItemCount - 1; i > 0; i--) {
        if (array[i] == itemToFind) {
            return i;
        }
    }

    return -1;
}

int ArrayList::findMaxIndex() {
    int linesRun = 0;
    return ::findMaxIndex(array, currItemCount, linesRun);
}

template <class T>
std::string ArrayList<T>::toString() {
    std::string output = "{";

    if (currItemCount < 1) {
        output += "}";
    } else {
        for (int i = 0; i < currItemCount; ++i) {
            output += std::to_string(array[i]) + ", ";
        }
        output.erase(output.end() - 2, output.end());
        output += "}";
    }

    return output;
}

*/