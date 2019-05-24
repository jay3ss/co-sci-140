#include "Node.h"

Node::Node(int num, Node* nextPtr)
{
    data_ = num;
    next_ = nextPtr;
}

Node::~Node()
{
}

// Getters
int Node::data()
{
    return data_;
}

Node* Node::next()
{
    return next_;
}

// Setters
void Node::data(int num)
{
    data_ = num;
}

void Node::next(Node* nextPtr)
{
    next_ = nextPtr;
}
