//
// Created by Chase McGough on 11/30/17.
//


//TODO Clean up + Add comments

#ifndef TEMPLATELIST_LIST_H
#define TEMPLATELIST_LIST_H

#include <stdexcept>

template <class T>
class Inventory {
public:
    //Destructor
    virtual ~Inventory(){};

    /**
     * Adds a new type of item to the inventory
     * @param item The item to add
     */
    virtual void addItem(T item)=0;

    /**
     * Sell an item in the inventory
     * @param item Item to sell
     */
    virtual void sellItem(T item)=0;

    /**
     * checks if there are any valid items in the list
     * @returns true if there are no valid items in the list, false otherwise
     */
    virtual bool isEmpty()=0;

    /**
     * returns a count of valid items currently in the list
     * @returns the number of valid items in the list
     */
    virtual int itemCount()=0;
};

#endif //TEMPLATELIST_LIST_H
