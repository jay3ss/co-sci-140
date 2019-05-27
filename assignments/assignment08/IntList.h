// Joshua Saunders
// CO SCI 140 (Section 15029) - Assignment 08
// Due May 26, 2019
#ifndef _INT_LIST_H_
#define _INT_LIST_H_

#include <iostream>
#include "Node.h"

using namespace std;

class IntList
{
private:
    Node* head_;
public:
    // Constructor
    IntList();

    // Destructor
    ~IntList();

    // Functions for modifiying the list
    /** Appends the value to the end of the list
    @param num The value to be appended to the end of the list */
    void append(int num);

    /** Displays the contents of the list */
    void display();

    /** Inserts the value in ascending order
    @param num The value to be inserted into to the list */
    void insert(int num);

    /** Determines if the list is empty or not
    @return True if the list is empty, false otherwise */
    bool isEmpty();

    /** Removes the first occurence of the value
    @param num The value to be removed from to the list
    @return True if the value was successfully removed, false otherwise */
    bool remove(int num);

    // void sort(); // if there's time
};

#endif // _INT_LIST_H_
