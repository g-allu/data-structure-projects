#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "LinkedList.h"
#include <string>

class HashTable {
private:
    static const int TABLE_SIZE = 101;
    LinkedList table[TABLE_SIZE];
public:
    HashTable();
    int hash(std::string id) const;
    void insert(Driver* d);
    Driver* search(std::string id) const;
    bool remove(std::string id);
    void display() const;
};

#endif // HASH_TABLE_H
