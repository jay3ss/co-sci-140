// Joshua Saunders
// CO SCI 140 (Section 15029) - Assignment 08
// Due May 26, 2019
//
// Design your own linked list class to hold a series of integers. The class
// should have member functions for appending, inserting, and deleting nodes.
// Don’t forget to add a destructor that destroys the list. Demonstrate the
// class with a driver program.
#include <iostream>
#include "IntList.h"
using namespace std;

int main()
{
    // Create an instance of IntList
    IntList list;

    // Build the list
    list.append(2); // Append 2 to the list
    list.append(4); // Append 4 to the list
    list.append(6); // Append 6 to the list

    // // Display the nodes.
    cout << "Here are the initial values:\n";
    list.display();
    cout << endl;

    // // Insert the value 5 into the list.
    cout << "Now inserting the values 5 and 137.\n";
    list.insert(5);
    list.insert(137);

    // // Display the nodes now.
    cout << "Here are the nodes now.\n";
    list.display();
    cout << endl;

    // // Delete the node holding 6.
    cout << "Now deleting the last node.\n";
    list.remove(6);

    // // Display the nodes.
    cout << "Here are the nodes left.\n";
    list.display();
    cout << endl;

    // // Insert the value -1 into the list.
    cout << "Now inserting the value -1.\n";
    list.insert(-1);

    // // Display the nodes now.
    cout << "Here are the nodes now.\n";
    list.display();
    cout << endl;

    // // Delete the node holding 6.
    cout << "Now deleting the last node.\n";
    list.remove(6);

    // // Add some more data out of order to see what happens
    list.insert(-15);
    list.append(-573);

    // // Display the nodes now.
    cout << "Here are the nodes now.\n";
    list.display();
    cout << endl;

    system("pause");
    return 0;
}
