#include "HashTable.h"
#include <iostream>

HashTable::HashTable() {}

int HashTable::hash(std::string id) const {
    int sum = 0;
    for (char c : id) {
        sum += static_cast<int>(c);
    }
    return sum % TABLE_SIZE;
}

void HashTable::insert(Driver* d) {
    int index = hash(d->getDriverId());
    table[index].insertBack(d);
}

Driver* HashTable::search(std::string id) const {
    int index = hash(id);
    return table[index].search(id);
}

bool HashTable::remove(std::string id) {
    int index = hash(id);
    return table[index].remove(id);
}

void HashTable::display() const {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].getSize() > 0) {
            std::cout << "Bucket " << i << ":\n";
            table[i].display();
        }
    }
}
