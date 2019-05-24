#include "Node.h"

Node::Node(int num, Node* nextPtr)
{
    next_ = nextPtr;
    data_ = num;
}

Node::~Node()
{
}
