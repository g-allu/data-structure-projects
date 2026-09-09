#include "DriverDatabase.h"
#include "DerivedDrivers.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

DriverDatabase::DriverDatabase() {}

DriverDatabase::~DriverDatabase() {
    Node* current = activeList.getHead();
    while (current != nullptr) {
        delete current->getData();
        current = current->getNext();
    }
    current = inactiveList.getHead();
    while (current != nullptr) {
        delete current->getData();
        current = current->getNext();
    }
}

void DriverDatabase::addDriver(Driver* d) {
    activeList.insertBack(d);
    lookupTable.insert(d);
    recentStack.push(d);
    processQueue.enqueue(d);
}

Driver* DriverDatabase::searchDriver(const string& id) const {
    return lookupTable.search(id);
}

bool DriverDatabase::deactivateDriver(const string& id) {
    Driver* d = searchDriver(id);
    if (d == nullptr) return false;

    activeList.remove(id);
    lookupTable.remove(id);
    inactiveList.insertBack(d);
    return true;
}

void DriverDatabase::getNewestLicensed(int n) {
    cout << "\n--- Top " << n << " Newest Licensed Drivers ---\n";
    int count = 0;
    while (!recentStack.isEmpty() && count < n) {
        Driver* d = recentStack.pop();
        d->displayInfo();
        count++;
    }
}

void DriverDatabase::getOldestLicensed(int n) {
    cout << "\n--- Top " << n << " Oldest Licensed Drivers ---\n";
    int count = 0;
    while (!processQueue.isEmpty() && count < n) {
        Driver* d = processQueue.dequeue();
        d->displayInfo();
        count++;
    }
}

void DriverDatabase::printAllActive() const {
    cout << "\n--- Active Drivers ---\n";
    activeList.display();
}

void DriverDatabase::printAllInactive() const {
    cout << "\n--- Inactive Drivers ---\n";
    inactiveList.display();
}

void DriverDatabase::loadFromFile(const string& path) {
    ifstream file(path);
    if (!file.is_open()) {
        cout << "Could not open file: " << path << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, name, dob_s, street, city, county, work_s, exp_s, med_s, lic_s, tick_s, loc;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, dob_s, ',');
        getline(ss, street, ',');
        getline(ss, city, ',');
        getline(ss, county, ',');
        getline(ss, work_s, ',');
        getline(ss, exp_s, ',');
        getline(ss, med_s, ',');
        getline(ss, lic_s, ',');
        getline(ss, tick_s, ',');
        getline(ss, loc, ',');

        WorkCategory wc = WorkCategory::STUDENT;
        if (work_s == "1") wc = WorkCategory::GOVERNMENT;
        else if (work_s == "2") wc = WorkCategory::SELF_EMPLOYED;
        else if (work_s == "3") wc = WorkCategory::BUSINESS_OWNER;
        else if (work_s == "4") wc = WorkCategory::PRIVATE_SECTOR;

        int exp = 0;
        try { exp = stoi(exp_s); } catch(...) {}

        MedicalCondition mn = MedicalCondition::FIT;
        if (med_s == "1") mn = MedicalCondition::VISION_IMPAIRED;
        else if (med_s == "2") mn = MedicalCondition::UPPER_EXTREMITY;
        else if (med_s == "3") mn = MedicalCondition::LOCOMOTOR_DISABILITY;

        Date dob(1, 1, 1980);
        Date lic(1, 1, 2010);
        Address addr(street, city, county);
        
        Driver* d = nullptr;
        if (wc == WorkCategory::STUDENT || exp < 5) {
            d = new YouthDriver(id, name, dob, addr, wc, exp, mn, lic);
        } else if (exp >= 15) {
            d = new SeniorDriver(id, name, dob, addr, wc, exp, mn, lic);
        } else {
            d = new MiddleAgeDriver(id, name, dob, addr, wc, exp, mn, lic);
        }

        if (tick_s == "1") {
            Ticket t;
            t.issueTicket(Date(1, 1, 2022), loc);
            d->setTicket(t);
        }
        
        addDriver(d);
    }
    file.close();
}
