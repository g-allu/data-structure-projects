#ifndef DRIVER_DATABASE_H
#define DRIVER_DATABASE_H

#include "LinkedList.h"
#include "HashTable.h"
#include "Stack.h"
#include "Queue.h"
#include "Driver.h"
#include <string>

class DriverDatabase {
private:
    LinkedList activeList;
    LinkedList inactiveList;
    HashTable lookupTable;
    Stack recentStack;
    Queue processQueue;

public:
    DriverDatabase();
    ~DriverDatabase();

    void loadFromFile(const std::string& path);
    void addDriver(Driver* d);
    Driver* searchDriver(const std::string& id) const;
    bool deactivateDriver(const std::string& id);
    void getNewestLicensed(int n);
    void getOldestLicensed(int n);
    void printAllActive() const;
    void printAllInactive() const;
};

#endif // DRIVER_DATABASE_H
