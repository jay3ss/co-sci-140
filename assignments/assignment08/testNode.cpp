#include <iostream>
#include "Node.h"

using namespace std;

int main()
{
    Node node1(15);
    Node node2(137, &node1);
    Node node3(187, &node2);

    Node* nodePtr = &node3;

    while (nodePtr != nullptr)
    {
        cout << nodePtr->data() << endl;
        nodePtr = nodePtr->next();
    }
}
