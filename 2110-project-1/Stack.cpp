#include "Stack.h"

Stack::Stack() : top(nullptr), size(0) {}

Stack::~Stack() {
    Node* current = top;
    while (current != nullptr) {
        Node* nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
}

void Stack::push(Driver* d) {
    Node* newNode = new Node(d);
    newNode->setNext(top);
    top = newNode;
    size++;
}

Driver* Stack::pop() {
    if (isEmpty()) return nullptr;
    Node* toDelete = top;
    Driver* d = toDelete->getData();
    top = top->getNext();
    delete toDelete;
    size--;
    return d;
}

Driver* Stack::peek() const {
    if (isEmpty()) return nullptr;
    return top->getData();
}

bool Stack::isEmpty() const {
    return size == 0;
}

int Stack::getSize() const { return size; }
