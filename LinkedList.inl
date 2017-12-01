//
// Created by Chase McGough on 11/30/17.
//

#include "LinkedList.h"
#include <iostream>

//Constructor
template <class T>
LinkedList<T>::LinkedList() {
    currItemCount = 0;
    front = nullptr;
    end = nullptr;
}

//Copy Constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList &listToCopy) {
    currItemCount = listToCopy.currItemCount;
    if(listToCopy.front == nullptr){
        front = nullptr;
        end = nullptr;
    }else{
        LinkedNode<T>* curr = listToCopy.front;
        LinkedNode<T>* newNode = new LinkedNode<T>(curr->getItem());
        front = newNode;
        end = newNode;
        curr = curr->getNext();

        while(curr != listToCopy.end){
            insertAtEnd(curr->getItem());
            curr = curr->getNext();
        }
        insertAtEnd(listToCopy.end->getItem());
    }
}

//Assignment Operator
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &listToCopy) {
    if(this != &listToCopy){
        clearList();
        currItemCount = listToCopy.currItemCount;

        if(listToCopy.front == nullptr){
            front = nullptr;
            end = nullptr;
        }else{
            LinkedNode<T>* curr = listToCopy.front;

            while(curr->getNext() != nullptr){
                insertAtEnd(curr->getItem());
                curr = curr->getNext();
            }
            insertAtEnd(listToCopy.end->getItem());
        }
    }

    return *this;

}

//Destructor
template <class T>
LinkedList<T>::~LinkedList() {
    while (!isEmpty() && front->getNext() != nullptr){
        LinkedNode<T>* toDelete = front;
        front = front->getNext();
        currItemCount--;
        delete toDelete;
    }
    delete front;
    front = nullptr;
    end = nullptr;

}

//Add item to end
template <class T>
void LinkedList<T>::insertAtEnd(T itemToAdd) {
    LinkedNode<T>* newNode = new LinkedNode<T>(itemToAdd);
    if(front == nullptr){
        front = newNode;
        end = newNode;
    } else{
        end->setNext(newNode);
        end = newNode;
    }
    currItemCount++;

}

//Add item to front
template <class T>
void LinkedList<T>::insertAtFront(T itemToAdd) {
    LinkedNode<T>* newNode = new LinkedNode<T>(itemToAdd);
    if(front == nullptr){
        front = newNode;
        end = newNode;
    } else{
        newNode->setNext(front);
        front = newNode;
    }
    currItemCount++;

}

//Add item at index
template <class T>
void LinkedList<T>::insertAt(T itemToAdd, int index) {
    if(index < 0 || index > currItemCount){
        throw std::out_of_range("Index not in range");
    }
    LinkedNode<T>* newNode = new LinkedNode<T>(itemToAdd);
    if(index == 0){
        newNode->setNext(front);
        front = newNode;
        currItemCount++;
    }else {
        LinkedNode<T>* first = front;
        int count = 0;
        while (first->getNext() != nullptr && count < index - 1) {
            first = first->getNext();
            count++;
        }
        LinkedNode<T>* last = first->getNext();

        first->setNext(newNode);
        newNode->setNext(last);
        currItemCount++;
    }

}

//Return value at index
template <class T>
T LinkedList<T>::getValueAt(int index) {
    if(index < 0 || index > currItemCount){
        throw std::out_of_range("Index not in range");
    }
    LinkedNode<T>* curr = front;
    for (int i = 0; i < index; ++i) {
        curr = curr->getNext();
    }
    return curr->getItem();

}

//Remove value at index
template <class T>
T LinkedList<T>::removeValueAt(int index) {
    if(index < 0 || index > currItemCount){
        throw std::out_of_range("Index not in range");
    }
    T output = 0;
    LinkedNode<T>* toDelete = front;

    if(index == 0){
        front = front->getNext();
        output = toDelete->getItem();

    }else {
        LinkedNode<T>* first = front;
        int count = 0;
        while (toDelete->getNext() != nullptr && count < index) {
            first = toDelete;
            toDelete = toDelete->getNext();
            count++;
        }

        if (toDelete == front) {
            front = front->getNext();
        } else {
            first->setNext(toDelete->getNext());
        }
        T output = toDelete->getItem();
    }

    delete toDelete;
    toDelete = nullptr;
    currItemCount--;
    return output;
}

//Return if there are no items
template <class T>
bool LinkedList<T>::isEmpty() {
    return currItemCount==0;
}

template <class T>
int LinkedList<T>::itemCount(){
    return currItemCount;
}

//Clear items from list
template <class T>
void LinkedList<T>::clearList() {
    while(!isEmpty() && front->getNext() != nullptr){
        LinkedNode<T>* temp = front;
        front = front->getNext();
        currItemCount--;
        delete temp;
    }

    currItemCount = 0;
    delete front;
    front = nullptr;
    end = nullptr;
}



//Print list as a string
template <class T>
std::string LinkedList<T>::toString() {
    LinkedNode<T>* curr = front;
    std::string output = "{";
    while(curr != nullptr){
        output += std::to_string(curr->getItem()) + ", ";
        curr = curr->getNext();
    }

    output.erase(output.end()-2, output.end());
    output += "}";
    return output;

}


//Return index of first iteration numToFind
template <class T>
T LinkedList<T>::find(T itemToFind) {
    int idx = -1;
    int count = 0;
    bool found = false;
    LinkedNode<T>* curr = front;

    while (curr != nullptr && !found){
        if(curr->getItem() == itemToFind){
            idx = count;
            found = true;
        }
        curr = curr->getNext();
        count++;
    }
    return idx;

}

//Return index of last iteration numToFind
template <class T>
T LinkedList<T>::findLast(T itemToFind) {
    int idx = -1;
    int count = 0;
    LinkedNode<T>* curr = front;

    while(curr != nullptr){
        if(curr->getItem() == itemToFind){
            idx = count;
        }
        curr = curr->getNext();
        count++;

    }
    return idx;

}

/*
//Return index of max value
int LinkedList::findMaxIndex() {
    if(front == nullptr){
        return -1;
    }
    int max = front->getItem();
    int idx = 0;
    int count = 0;
    LinkedNode* curr = front;

    while(curr != nullptr){
        if(curr->getItem() > max){
            max = curr->getItem();
            idx = count;
        }
        curr = curr->getNext();
        count++;
    }
    return idx;

}
*/