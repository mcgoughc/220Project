/*
 * LinkedQueue.h
 * Comp 220 Bookstore Project
 * Written by Joe Cleveland, Chase McGough, and Anthony Pizzo
 * This file is the definition of a LinkedQueue which is implemented by Queue
*/

#ifndef STACKSANDQUEUES_LINKED_QUEUE_H
#define STACKSANDQUEUES_LINKED_QUEUE_H

#include <string>
#include <stdexcept>
#include "LinkedNode.h"
#include "Queue.h"



template <class T>
class LinkedQueue : public Queue<T> {
private:
    LinkedNode<T>* front;
    LinkedNode<T>* end;

public:
    
    /**
     * Constructor
     * Creates a new empty queue
     */
    LinkedQueue();

    /**
     * Copy Constructor
     * @param queueToCopy
     */
    LinkedQueue(const LinkedQueue<T>* queueToCopy);

    /**
     * Overloaded Assignment Operator
     * @param queueToCopy
     * @return Address of the overwritten queue
     */
    LinkedQueue<T>& operator=(const LinkedQueue<T>& queueToCopy);

    /**
     * Destuctor
     */
    ~LinkedQueue();
    
    /**
     * Adds item to the end of the queue
     * @param item
     */
    void enqueue(T item);

    /**
     * Returns the item at the front of the queue
     * Throws out_of_range if queue is empty
     * @return Item from queue
     */
    T dequeue();

    /**
     * @return True if queue is empty
     */
    bool isEmpty();

    /**
     * Writes the items to a string
     * @return String of items in the queue
     */
    std::string toString();

};

#include "LinkedQueue.inl"

#endif //STACKSANDQUEUES_LINKED_QUEUE_H
