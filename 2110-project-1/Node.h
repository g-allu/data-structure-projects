#ifndef NODE_H
#define NODE_H

#include "Driver.h"

class Node {
private:
    Driver* data;
    Node* next;
public:
    Node(Driver* d) : data(d), next(nullptr) {}
    ~Node() {}
    Driver* getData() const { return data; }
    void setData(Driver* d) { data = d; }
    Node* getNext() const { return next; }
    void setNext(Node* n) { next = n; }
};

#endif // NODE_H
