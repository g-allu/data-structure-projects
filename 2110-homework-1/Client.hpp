#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>

using namespace std;

class Client
{
private:
    string name;
    char gender;
    int age;
    int numMembers;
    string dob;

public:
    Client(string name = "",
           char gender = ' ',
           int age = 0,
           int numMembers = 0,
           string dob = "")
    {
        this->name = name;
        this->gender = gender;
        this->age = age;
        this->dob = dob;
        this->numMembers = numMembers;
    };

    string getName() { return name; };
    char getGender() { return gender; };
    int getAge() { return age; };
    int getNumMembers() { return numMembers; };
    string getDOB() { return dob; };

    void setName(string name) { this->name = name; };
    void setGender(char gender) { this->gender = gender; };
    void setAge(int age) { this->age = age; };
    void getNumMebers(int num) { numMembers = num; };
    void getDOB(string dob) { this->dob = dob; };
};

class Node
{
private:
    Client data;
    Node *prev;
    Node *next;

public:
    Node(Client c, Node *p = nullptr, Node *n = nullptr) : data(c), prev(p), next(n) {};

    Client getClient() { return data; };
    Node *getPrev() { return prev; };
    Node *getNext() { return next; };

    void setPrev(Node *p) { prev = p; };
    void setNext(Node *n) { next = n; };
};

#endif