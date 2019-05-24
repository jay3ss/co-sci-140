#ifndef _NODE_H_
#define _NODE_H_

class Node
{
private:
    int data_;
    Node* next_;
public:
    Node(int num = 0, Node* nextPtr = nullptr);
    ~Node();

    // Getters
    int data();
    Node* next();

    // Setters
    void data(int num);
    void next(Node* nextPtr);
};

#endif // _NODE_H_
