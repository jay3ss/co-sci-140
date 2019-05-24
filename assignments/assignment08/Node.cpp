#include "Node.h"

Node::Node(int num, Node* nextPtr)
{
    data_ = num;
    next_ = nextPtr;
}

Node::~Node()
{
}
