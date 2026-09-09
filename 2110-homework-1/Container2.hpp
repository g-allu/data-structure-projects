#ifndef CONTAINER2_HPP
#define CONTAINER2_HPP

#include <iomanip>

#include "Client.hpp"

using namespace std;

class Container2 {
    private:
        Node* top;

    public:
        Container2();
        ~Container2();

        void insertToStack(Client c);
        Node* getTop();
};


#endif