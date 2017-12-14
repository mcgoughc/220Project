//
// Created by Chase McGough on 11/30/17.
//

#ifndef TEMPLATELIST_ARRAYLIST_H
#define TEMPLATELIST_ARRAYLIST_H

#include "Inventory.h"

//TODO Clean up + Add comments/headers

class MissingBook : public std::exception{};
class BookHaveEmpty : public std::exception{};

class ArrayInventory : public Inventory{
private:
    //pointer to the start of the array
    Book* array;
    //count of the number of valid items currently stored in the array
    int currItemCount;
    //size of the current array
    int currCapacity;

    /**
     * replaces the old array with an array twice the size
     * private method only called within ArrayList when necessary
     * @post: array points to a new array of twice the size with values copied from the old one,
     *        the old array is deleted.
     */
    void doubleCapacity();

    /**
     * Inserts book at index.
     * @param itemToAdd Book to add
     * @param index Index to add it at
     */
    void insertAt(Book itemToAdd, int index);

    Book* copyArray(const Book* arrayToCopy, int size);

public:
    /**
     * Constructor
     * creates an ArrayInventory
     * @param: initialCapacity (the starting size of the array, defaults to size 5
     */
    ArrayInventory(int initialCapacity=5);

    //Copy Constructor
    ArrayInventory(const ArrayInventory& inventoryToCopy);

    //Overloaded Assignment Operator
    ArrayInventory& operator=(const ArrayInventory& inventoryToCopy);

    //Destructor
    ~ArrayInventory();


    /**
     * Adds a new type of item to the inventory
     * Adds in alphabetical order by title
     * @param item The item to add
     */
    void addItem(Book item);

    /**
     * Sell an item in the inventory
     * @param title Title of Item to sell
     */
    void sellItem(std::string title);

    /**
    * Finds and returns a reference to an item
     * Linear Search
    * @param title The title of the book
    * @return The book
    */
    Book& getItemAt(int index);

    /**
     * Finds and returns a reference to an item
     * Binary Search
     * @param title The title of the book
     * @return The book
     */
    Book& binGetItem(std::string title);

    /**
     * Finds and returns the index of an item
     * Binary Search
     * @param title The tile of the book
     * @return The index of the book, or -1 if no book is found
     */
    int getIndex(std::string title);

    /**
     * checks if there are any valid items in the inventory
     * @returns true if there are no valid items in the inventory, false otherwise
     */
    bool isEmpty();

    /**
     * returns a count of valid items currently in the inventory
     * @returns the number of valid items in the inventory
     */
    int itemCount();

    /**
    * Lists items in the inventory
    * @return A string list of the inventory
    */
    std::string listInventory();

    bool itemExists(std::string title);


};

#endif //TEMPLATELIST_ARRAYLIST_H
