/*
 * LinkedQueue.inl
 * Comp 220 Bookstore Project
 * Written by Joe Cleveland, Chase McGough, and Anthony Pizzo
 * This file is the inline definition of the methods in LinkedQueue
*/
#include "LinkedQueue.h"



template <class T>
LinkedQueue<T>::LinkedQueue(){
    front = nullptr;
    end = nullptr;
}

template <class T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>* queueToCopy){
    if (queueToCopy->front == nullptr){
        front = nullptr;
        end = nullptr;
    }
    else {
        LinkedNode<T>* nodeToCopy = queueToCopy->front;
        front = new LinkedNode<T>(nodeToCopy->getItem());
        LinkedNode<T>* endOfNewChain = front;

        nodeToCopy = nodeToCopy->getNext();
        while (nodeToCopy != nullptr){
            LinkedNode<T>* newNode = new LinkedNode<T>(nodeToCopy->getItem());
            endOfNewChain->setNext(newNode);
            endOfNewChain = newNode;
            nodeToCopy = nodeToCopy->getNext();
        }
        end = endOfNewChain;
    }
}

template <class T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& queueToCopy) {
    if(this != &queueToCopy){
        while(!isEmpty()){
            LinkedNode<T>* toDelete = front;
            this->front = front->getNext();
            delete toDelete;
        }

        if(queueToCopy.front == nullptr){
            front = nullptr;
            end = nullptr;
        }else {
            LinkedNode<T>* curr = queueToCopy.front;

            while(curr->getNext() != nullptr){
                enqueue(curr->getItem());
                curr = curr->getNext();
            }
            enqueue(queueToCopy.end->getItem());
        }
    }

    return *this;
}

template <class T>
LinkedQueue<T>::~LinkedQueue(){
    while (front != nullptr){
        LinkedNode<T>* toDelete = front;
        front = front->getNext();
        delete toDelete;
    }
}

template <class T>
void LinkedQueue<T>::enqueue(T item){
    LinkedNode<T>* newNode = new LinkedNode<T>(item);
    //if front is nullptr, end should be nullptr too
    if (front == nullptr){
        front = newNode;
        end = newNode;
    }
    else {
        end->setNext(newNode);
        end = newNode;
    }
}

template <class T>
T LinkedQueue<T>::dequeue(){
    if (isEmpty()){
        throw std::out_of_range("Queue is empty");
    }
    else {
        T item = front->getItem();
        if (front == end) {
            delete front;
            front = nullptr;
            end = nullptr;
        } else {
            LinkedNode<T>* toDelete = front;
            front = front->getNext();
            delete toDelete;
        }
        return item;
    }
}

template <class T>
bool LinkedQueue<T>::isEmpty(){
    return front == nullptr;
}

template <class T>
std::string LinkedQueue<T>::toString(){
    LinkedNode<T>* curr = front;
    std::string output;
    while(curr != end){
        output += curr->getItem().toString() + "\n\n";
        curr = curr->getNext();
    }

    output += end->getItem().toString() + "\n";

    return output;
}