#ifndef CONTAINER1_HPP
#define CONTAINER1_HPP

#include "Client.hpp"



using namespace std;

class Container1 {
    private: 
        Node* head;
        Node* tail;

    public:
        Container1();
        ~Container1();

        void insertAtBeginning(Client c);
        void insertAtEnd(Client c);
        bool insertAfterName(string name ,Client c);
        bool insertAfterAge(int age, Client c);
        bool insertAfterGender(char gender, Client c);

        Node* getFirst();
        Node* getLast();
        Node* getByName(string name);
        Node* getByAge(int age);
        Node* getByGender(char gender);
};

#endif