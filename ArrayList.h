//
// Created by Chase McGough on 11/30/17.
//

#ifndef TEMPLATELIST_ARRAYLIST_H
#define TEMPLATELIST_ARRAYLIST_H

#include <stdexcept>
#include <string>
#include "Inventory.h"

//TODO Clean up + Add comments/headers

template <class T>
class ArrayList{
private:
    //pointer to the start of the array
    T* array;
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

    T* copyArray(const T* arrayToCopy, int size);

public:
    /**
     * Constructor
     * creates an arrayList
     * @param: initialCapacity (the starting size of the array, defaults to size 5
     */
    ArrayList(int initialCapacity=5);

    //Copy Constructor
    ArrayList(const ArrayList& arrayListToCopy);

    //Overloaded Assignment Operator
    ArrayList& operator=(const ArrayList& arrayListToCopy);

    //Destructor
    ~ArrayList();

    /**
     * appends the new item to the end of the list
     * @param itemToAdd the item to add to the end of the array
     * @post the list has an additional value in it, at the end
     */
    void insertAtEnd(T itemToAdd);

    /**
     * appends the new item to the beginning of the list
     * @param itemToAdd the item to add to the beginning of the list
     * @post the list has an additional value in it, at the beginning
     *    all other items are shifted down by one index
     */
    void insertAtFront(T itemToAdd);

    /**
     * inserts the item into the list so that it can be found with get(index)
     * @param itemToAdd the item to add
     * @param index the location in which to insert this item
     * @post the list has an additional value in it at the specified index,
     *        all further values have been shifted down by one index
     * @throws out_of_range exception if index is invalid (< 0 or >currItemCount)
     */
    void insertAt(T itemToAdd, int index);

    /**
     * gets a value from the list
     * @param index the location from which to get the value
     * @returns a reference to the item at index
     * @throws out_of_range exception if index is invalid
     */
    T& getValueAt(int index);

    /**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    T removeValueAt(int index);

    /**
     * checks if there are any valid items in the list
     * @returns true if there are no valid items in the list, false otherwise
     */
    bool isEmpty();

    /**
     * returns a count of valid items currently in the list
     * @returns the number of valid items in the list
     */
    int itemCount();

    /**
     * removes all valid items from the list
     * @post the list is completely clear of valid items
     */
    void clearList();

    /**
     * gives a string representation of the current list
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
    //std::string toString();

    /**
     * finds the largest value in the array
     * @post numLinesRun is updated to include lines run by this function
     * @return the first index of the maximum value, or -1 if size < 1
     */
    //int findMaxIndex();

    /**
     * Searches an int array for a certain value
     * @post numLinesRun is updated to include lines run by this function
     * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
     */
    //int find(T itemToFind);

    /**
     * Searches an int array for a certain value
     * @post numLinesRun is updated to include lines run by this function
     * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
     */
    //int findLast(T itemToFind);

};

#include "ArrayList.inl"

#endif //TEMPLATELIST_ARRAYLIST_H
