#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
#include <string>

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList();
    ~LinkedList();

    void insertFront(Driver* d);
    void insertBack(Driver* d);
    bool remove(std::string id);
    Driver* search(std::string id) const;
    int getSize() const;
    void display() const;
    Node* getHead() const;
};

#endif // LINKED_LIST_H
