#ifndef _INT_LIST_H_
#define _INT_LIST_H_

#include <iostream>
#include "Node.h"

using namespace std;

class IntList
{
private:
    Node* head_;
    int numElements;
public:
    // Constructor
    IntList();

    // Destructor
    ~IntList();

    // Functions for modifiying the list
    /** Appends the value to the end of the list
    @param num The value to be appended to the end of the list */
    void append(int num);

    /** Checks if the value is in the list
    @param num The value to be checked
    @return True if the list contains the value, false otherwise */
    bool contains(int num);

    /** Displays the contents of the list */
    void display();

    /** Inserts the value in ascending order
    @param num The value to be inserted into to the list */
    void insert(int num);

    /** Determines if the list is empty or not
    @return True if the list is empty, false otherwise */
    bool isEmpty();

    /** Returns the integer number of elements in the list
    @return The integer number of elements in the list */
    int length();

    /** Removes the first occurence of the value
    @param num The value to be removed from to the list
    @return True if the value was successfully removed, false otherwise */
    bool remove(int num);

    // void sort(); // if there's time
};

#endif // _INT_LIST_H_
