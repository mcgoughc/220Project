/*
 * LinkedNode.h
 * Comp 220 Bookstore Project
 * Written by Joe Cleveland, Chase McGough, and Anthony Pizzo
 * This file is the templated definition of a LinkedNode
*/

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include <string>



template <class T>
class LinkedNode {

private:
    T item;
    LinkedNode* next;

public:
    /**
     * Constructor. Creates a new linked node
     * @param i Item to store in the node
     */
    LinkedNode(const T& i);

    /**
     * Copy Constructor. Copies item, not next pointer
     * @param nodeToCopy
     */
    LinkedNode(const LinkedNode<T>& nodeToCopy);

    /**
     * @return Item stored in the node
     */
    T getItem();

    /**
     * @return Pointer to the next linked node
     */
    LinkedNode* getNext();

    /**
     * Puts a new item in the node
     * @param newItem
     */
    void setItem(T newItem);

    /**
     * Points next to a different node
     * @param newNext
     */
    void setNext(LinkedNode* newNext);
};

#include "LinkedNode.inl"

#endif //LINKEDNODE_H
