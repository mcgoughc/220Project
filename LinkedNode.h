//
// Created by Toby Dragon on 10/24/16.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include <string>

//TODO Clean up + Add comments/headers

template <class T>
class LinkedNode {

private:
    T item;
    LinkedNode* next;

public:
    LinkedNode(const T& item);
    LinkedNode( const LinkedNode<T>& nodeToCopy); //only copies item, next is set to nullptr
    T getItem();
    LinkedNode* getNext();
    void setItem(T newItem);
    void setNext(LinkedNode* newNext);
};

#include "LinkedNode.inl"

#endif //LINKEDNODE_H
