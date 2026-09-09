#include "Container3.hpp"

Container3::Container3()
{
    front = nullptr;
    back = nullptr;
}

Container3::~Container3()
{
    while(front != nullptr){
        Node* temp = front;
        front = front->getNext();
        delete temp;
    }
}

void Container3::insertToQueue(Client c)
{
    Node* newNode = new Node(c, nullptr, nullptr);
    if (!back)
    {
        front = back = newNode;
        return;
    }

    back->setNext(newNode);
    back = newNode;
    
}

Node *Container3::getOldest()
{
    if(!front) return nullptr;
    Node* oldest = front;
    front = front->getNext();

    if(!front) {
        back = nullptr;
    }

    oldest->setNext(nullptr);

    return oldest;
}
