/*
 * Inventory.h
 * Comp 220 Bookstore Project
 * Written by Joe Cleveland, Chase McGough, and Anthony Pizzo
 * This file is the ADT definition for Inventory, a data type used to store books
*/

#ifndef TEMPLATELIST_LIST_H
#define TEMPLATELIST_LIST_H

#include <stdexcept>
#include <string>
#include <iostream>
#include "Book.h"

class Inventory {
public:
    /**
     * Destructor, call destructor of implementation
     */
    virtual ~Inventory(){};

    /**
     * Adds a new type of item to the inventory
     * @param item The item to add
     */
    virtual void addItem(Book item)=0;

    /**
     * Sell an item in the inventory
     * @param title Title of Item to sell
     */
    virtual void sellItem(std::string title)=0;

    /**
     * Finds and returns a reference to an item
     * Linear Search
     * @param title The title of the book
     * @return The book
     */
    virtual Book& getItemAt(int index)=0;

    /**
     * Finds and returns a reference to an item
     * Binary Search
     * @param title The title of the book
     * @return The book
     */
    virtual Book& binGetItem(std::string title)=0;

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

    /**
     * Lists items in the inventory
     * @return A string list of the inventory
     */
    virtual std::string listInventory()=0;

    /**
     * Checks if the item exists in the inventory
     * @param title
     * @return
     */
    virtual bool itemExists(std::string title)=0;
};

#endif //TEMPLATELIST_LIST_H
