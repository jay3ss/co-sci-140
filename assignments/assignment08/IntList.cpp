#include "IntList.h"

IntList::IntList()
{
    head_ = nullptr;
}

IntList::~IntList()
{
    Node* currNodePtr = head_;
    Node* prevNodePtr = nullptr;

    while(currNodePtr != nullptr)
    {
        // Delete the node and return it to the system
        prevNodePtr = currNodePtr;
        // NOTE: Advance the node otherwise we'll delete the head pointer. Had
        // to learn this the Hard Way
        currNodePtr = currNodePtr->next();
        delete prevNodePtr;
        prevNodePtr = nullptr;
    }
}

// Functions for modifiying the list
void IntList::append(int num)
{
    Node* nodePtr = head_;
    // Allocate more space for the new node
    Node* newNodePtr = new Node(num);

    // The list is empty
    if (isEmpty())
    {
        head_ = newNodePtr;
    }
    else
    {
        // Find the last node
        while (nodePtr->next() != nullptr)
        {
            nodePtr = nodePtr->next();
        }
        // Add the node to the end of list
        nodePtr->next(newNodePtr);
    }
}

/** Checks if the value is in the list */
bool IntList::contains(int num)
{
    // Traverse the list, checking if the value is in the list. If it is,
    // return immediately
    Node* nodePtr = head_;

    while (nodePtr != nullptr)
    {
        if (nodePtr->data() == num)
        {
            return true;
        }
        nodePtr = nodePtr->next();
    }
    return false;

}

/** Displays the contents of the list */
void IntList::display()
{
    // Display each value in the list on its own line
    Node* nodePtr = head_;
    while (nodePtr != nullptr)
    {
        cout << nodePtr->data() << endl;
        nodePtr = nodePtr->next();
    }
}

/** Inserts the value in ascending order */
void IntList::insert(int num)
{
    Node* currNodePtr = head_;
    Node* newNodePtr = new Node(num);

    if(isEmpty())
    {
        head_ = newNodePtr;
    }
    else
    {
        Node* prevNodePtr = nullptr;
        // Traverse the list until we encounter a node with a value greater
        // than the one that we're inserting
        while (currNodePtr != nullptr && currNodePtr->data() < num)
        {
            prevNodePtr = currNodePtr;
            currNodePtr = currNodePtr->next();
        }

        // The new node should be the first
        if (prevNodePtr == nullptr)
        {
            head_ = newNodePtr;
            newNodePtr->next(currNodePtr);
        }
        // Insert it either within the list, between the previous and current
        // nodes, or at the end of the list
        else
        {
            prevNodePtr->next(newNodePtr);
            newNodePtr->next(currNodePtr);
        }
    }
}

/** Determines if the list is empty or not */
bool IntList::isEmpty()
{
    return head_ == nullptr;
}

/** Returns the integer number of elements in the list */
int IntList::length(){ return -1; }

/** Removes the first occurence of the value */
bool IntList::remove(int num)
{
    // The list is empty, so return false
    if (head_ == nullptr)
    {
        return false;
    }
    Node *currNodePtr = head_;
    Node* prevNodePtr = currNodePtr;

    // Traverse the list, checking if the value is in the list. If it is,
    // return immediately
    while (currNodePtr != nullptr)
    {
        if (currNodePtr->data() == num)
        {
            // We found a node that is contains the value, so set the previous
            // node's next pointer to the current node's next pointer then
            // detach the current node and return it to the system
            prevNodePtr->next(currNodePtr->next());
            delete currNodePtr;
            currNodePtr = nullptr;

            // We found the node to delete so return true
            return true;
        }
		prevNodePtr = currNodePtr;
        currNodePtr = currNodePtr->next();
    }
    // Couldn't find the value so return false
    return false;
}
