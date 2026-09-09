#include "Container1.hpp"

Container1::Container1()
{
    head = nullptr;
    tail = nullptr;
}

Container1::~Container1()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *nextNode = current->getNext();

        delete current;

        current = nextNode;
    }
}

void Container1::insertAtBeginning(Client c)
{
    Node *newNode = new Node(c, nullptr, head);

    if (head)
    {
        head->setPrev(newNode);
    }

    else
    {
        tail = newNode;
    }

    head = newNode;
}

void Container1::insertAtEnd(Client c)
{
    Node *newNode = new Node(c, tail, nullptr);

    if (tail)
    {
        tail->setNext(newNode);
    }

    else
    {
        head = newNode;
    }

    tail = newNode;
}


bool Container1::insertAfterName(string name, Client c)
{
    Node* current = getByName(name);
    if(!current) return false;

    Node* newNode = new Node(c, current, current->getNext());

    if(current->getNext()){
        current->getNext()->setPrev(newNode);
    }

    else tail = newNode;

    current->setNext(newNode);
    return true;
}

bool Container1::insertAfterAge(int age, Client c)
{
        Node* current = getByAge(age);
    if(!current) return false;

    Node* newNode = new Node(c, current, current->getNext());

    if(current->getNext()){
        current->getNext()->setPrev(newNode);
    }

    else tail = newNode;

    current->setNext(newNode);
    return true;
}

bool Container1::insertAfterGender(char gender, Client c)
{
        Node* current = getByGender(gender);
    if(!current) return false;

    Node* newNode = new Node(c, current, current->getNext());

    if(current->getNext()){
        current->getNext()->setPrev(newNode);
    }

    else tail = newNode;

    current->setNext(newNode);
    return true;
}

Node *Container1::getFirst()
{
    return head;
}

Node *Container1::getLast()
{
    return tail;
}

Node *Container1::getByName(string name)
{
    Node *current = head;

    while (current)
    {
        if (current->getClient().getName() == name)
        {
            return current;
        }
        current = current->getNext();
    }

    return nullptr;
}

Node *Container1::getByAge(int age)
{
    Node *current = head;

    while (current)
    {
        if (current->getClient().getAge() == age)
        {
            return current;
        }
        current = current->getNext();
    }

    return nullptr;
}

Node *Container1::getByGender(char gender)
{
    Node *current = head;

    while (current)
    {
        if (current->getClient().getGender() == gender)
        {
            return current;
        }
        current = current->getNext();
    }

    return nullptr;
}
