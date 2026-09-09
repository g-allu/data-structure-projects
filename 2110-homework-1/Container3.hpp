#ifndef CONTAINER3_HPP
#define CONTAINER3_HPP

#include "Client.hpp"


#include <iomanip>

using namespace std;

class Container3 {
    private:
        Node* front;
        Node* back;

    public:
        Container3();
        ~Container3();

        void insertToQueue(Client C);
        Node* getOldest();
};

#endif