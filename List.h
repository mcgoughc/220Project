//
// Created by Chase McGough on 11/30/17.
//


//TODO Clean up + Add comments

#ifndef TEMPLATELIST_LIST_H
#define TEMPLATELIST_LIST_H

#include <stdexcept>

template <class T>
class List {
public:
    //Destructor
    virtual ~List(){};

    /**
     * appends the new item to the end of the list
     * @param itemToAdd the item to add to the end of the array
     * @post the list has an additional value in it, at the end
     */
    virtual void insertAtEnd(T itemToAdd)=0;

    /**
     * appends the new item to the beginning of the list
     * @param itemToAdd the item to add to the beginning of the list
     * @post the list has an additional value in it, at the beginning
     *    all other items are shifted down by one index
     */
    virtual void insertAtFront(T itemToAdd)=0;

    /**
     * inserts the item into the list so that it can be found with get(index)
     * @param itemToAdd the item to add
     * @param index the location in which to insert this item
     * @post the list has an additional value in it at the specified index,
     *        all further values have been shifted down by one index
     * @throws out_of_range exception if index is invalid (< 0 or >currItemCount)
     */
    virtual void insertAt(T itemToAdd, int index)=0;

    /**
     * gets a value from the list
     * @param index the location from which to get the value
     * @returns a reference to the item at index
     * @throws out_of_range exception if index is invalid
     */
    virtual T& getValueAt(int index)=0;

    /**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    virtual T removeValueAt(int index)=0;

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
     * removes all valid items from the list
     * @post the list is completely clear of valid items
     */
    virtual void clearList()=0;

    /**
     * gives a string representation of the current list
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
    //virtual std::string toString()=0;


    /**
     * finds the largest value in the array
     * @return the first index of the maximum value, or -1 if size < 1
     */
    //virtual int findMaxIndex()=0;

    /**
     * Searches an int array for a certain value
     * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
     */
    //virtual int find(T itemToFind)=0;

    /**
     * Searches an int array for a certain value
     * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
     */
    //virtual int findLast(T itemToFind)=0;
};

#endif //TEMPLATELIST_LIST_H
