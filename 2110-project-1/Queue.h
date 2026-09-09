#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
public:
    Queue();
    ~Queue();
    void enqueue(Driver* d);
    Driver* dequeue();
    Driver* peek() const;
    bool isEmpty() const;
    int getSize() const;
};

#endif // QUEUE_H
