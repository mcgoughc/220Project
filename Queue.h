/*
 * Queue.h
 * Comp 220 Bookstore Project
 * Written by Joe Cleveland, Chase McGough, and Anthony Pizzo
 * This file is the tempelated ADT definition for a Queue
*/

#ifndef INC_220PROJECT_QUEUE_H
#define INC_220PROJECT_QUEUE_H

#include <string>
#include <stdexcept>

template <class T>
class Queue {
public:

    /**
     * Destructor
     * Calls child destructors
     */
    virtual ~Queue(){};
    
    /**
     * Adds an item to the end of the queue
     * @param item Item to add
     */
    virtual void enqueue(T item)=0;

    /**
     * Removes an item from the front of the queue
     * Throws out_of_range if the queue is empty
     * @return Item at the front of the queue
     */
    virtual T dequeue()=0;

    /**
     * @return True if the queue is empty, else false
     */
    virtual bool isEmpty()=0;

    /**
     * Prints the queue
     * @return A string of items in the queue
     */
    virtual std::string toString()=0;

};

#endif //INC_220PROJECT_QUEUE_H
