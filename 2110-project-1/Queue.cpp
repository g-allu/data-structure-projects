#include "Queue.h"

Queue::Queue() : front(nullptr), rear(nullptr), size(0) {}

Queue::~Queue() {
    Node* current = front;
    while (current != nullptr) {
        Node* nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
}

void Queue::enqueue(Driver* d) {
    Node* newNode = new Node(d);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->setNext(newNode);
        rear = newNode;
    }
    size++;
}

Driver* Queue::dequeue() {
    if (isEmpty()) return nullptr;
    Node* toDelete = front;
    Driver* d = toDelete->getData();
    front = front->getNext();
    if (!front) rear = nullptr;
    delete toDelete;
    size--;
    return d;
}

Driver* Queue::peek() const {
    if (isEmpty()) return nullptr;
    return front->getData();
}

bool Queue::isEmpty() const {
    return size == 0;
}

int Queue::getSize() const { return size; }
