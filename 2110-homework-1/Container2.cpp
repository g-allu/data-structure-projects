#include "Container2.hpp"

Container2::Container2()
{
    top = nullptr;
}

Container2::~Container2()
{
    while (top != nullptr)
    {
        Node* temp = top;
        top = top->getNext();
        delete temp;
    }
    
}

void Container2::insertToStack(Client c)
{
    Node* newNode = new Node(c, nullptr, top);
    top = newNode;
}

Node *Container2::getTop()
{
    if(!top) return nullptr;
    Node* recent = top;
    top = top->getNext();
    recent->setNext(nullptr);
    return recent;

}
