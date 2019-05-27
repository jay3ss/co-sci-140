// Joshua Saunders
// CO SCI 140 (Section 15029) - Assignment 08
// Due May 26, 2019
#ifndef _NODE_H_
#define _NODE_H_

class Node
{
private:
    int data_;
    Node* next_;
public:
    Node(const int num = 0, Node* const nextPtr = nullptr);
    ~Node();

    // Getters
    int data() const;
    Node* next() const;

    // Setters
    void data(const int num);
    void next(Node* const nextPtr);
};

#endif // _NODE_H_
