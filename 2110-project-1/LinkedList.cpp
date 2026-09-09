#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
}

void LinkedList::insertFront(Driver* d) {
    Node* newNode = new Node(d);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->setNext(head);
        head = newNode;
    }
    size++;
}

void LinkedList::insertBack(Driver* d) {
    Node* newNode = new Node(d);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
    }
    size++;
}

bool LinkedList::remove(std::string id) {
    if (!head) return false;
    
    if (head->getData()->getDriverId() == id) {
        Node* toDelete = head;
        head = head->getNext();
        if (!head) tail = nullptr;
        delete toDelete;
        size--;
        return true;
    }

    Node* current = head;
    while (current->getNext() != nullptr && current->getNext()->getData()->getDriverId() != id) {
        current = current->getNext();
    }

    if (current->getNext() != nullptr) {
        Node* toDelete = current->getNext();
        current->setNext(toDelete->getNext());
        if (toDelete == tail) tail = current;
        delete toDelete;
        size--;
        return true;
    }
    
    return false;
}

Driver* LinkedList::search(std::string id) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->getData()->getDriverId() == id)
            return current->getData();
        current = current->getNext();
    }
    return nullptr;
}

int LinkedList::getSize() const { return size; }
Node* LinkedList::getHead() const { return head; }

void LinkedList::display() const {
    Node* current = head;
    while (current != nullptr) {
        current->getData()->displayInfo();
        std::cout << "-------------------\n";
        current = current->getNext();
    }
}
