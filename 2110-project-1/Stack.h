#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack {
private:
    Node* top;
    int size;
public:
    Stack();
    ~Stack();
    void push(Driver* d);
    Driver* pop();
    Driver* peek() const;
    bool isEmpty() const;
    int getSize() const;
};

#endif // STACK_H
