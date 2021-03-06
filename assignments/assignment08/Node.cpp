// Joshua Saunders
// CO SCI 140 (Section 15029) - Assignment 08
// Due May 26, 2019
#include "Node.h"

Node::Node(const int num, Node* const nextPtr)
{
    data_ = num;
    next_ = nextPtr;
}

Node::~Node()
{
}

// Getters
int Node::data() const
{
    return data_;
}

Node* Node::next() const
{
    return next_;
}

// Setters
void Node::data(const int num)
{
    data_ = num;
}

void Node::next(Node* const nextPtr)
{
    next_ = nextPtr;
}
