/*
 * LinkedNode.inl
 * Comp 220 Bookstore Project
 * Written by Joe Cleveland, Chase McGough, and Anthony Pizzo
 * This file is the inline definition for the methods in LinkedNode
*/

#include "LinkedNode.h"

template <class T>
LinkedNode<T>::LinkedNode(const T& i) : item(i){
    next = nullptr;
}

template <class T>
LinkedNode<T>::LinkedNode(const LinkedNode<T>& nodeToCopy){
    item = nodeToCopy.item;
    next = nullptr;
}

template <class T>
T LinkedNode<T>::getItem(){
    return item;
}

template <class T>
LinkedNode<T>* LinkedNode<T>::getNext(){
    return next;
}

template <class T>
void LinkedNode<T>::setItem(T newItem){
    item = newItem;
}

template <class T>
void LinkedNode<T>::setNext(LinkedNode* newNext){
    next = newNext;
}

