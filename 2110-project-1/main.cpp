#include "DriverDatabase.h"
#include "DerivedDrivers.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu() {
    cout << "\n=== Driver Database Menu ===\n"
         << "1. Search driver by ID\n"
         << "2. Add a new driver\n"
         << "3. Deactivate driver (move to inactive)\n"
         << "4. Print N newest licensed drivers\n"
         << "5. Print N oldest licensed drivers\n"
         << "6. Print all active drivers\n"
         << "7. Print all inactive drivers\n"
         << "8. Exit\n"
         << "Choice: ";
}

int main() {
    DriverDatabase db;
    cout << "Loading drivers from drivers.txt...\n";
    db.loadFromFile("drivers.txt");

    bool running = true;
    while (running) {
        displayMenu();
        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        if (choice == 1) {
            string id;
            cout << "Enter Driver ID: ";
            cin >> id;
            Driver* d = db.searchDriver(id);
            if (d) d->displayInfo();
            else cout << "Driver not found.\n";
        } else if (choice == 2) {
             string id, name;
             cout << "Enter Driver ID: "; cin >> id;
             cout << "Enter Name: "; cin >> name;
             Address a("123 Main", "Denton", "Denton");
             Date dob(1, 1, 1990);
             Date lic(1, 1, 2015);
             Driver* d = new YouthDriver(id, name, dob, a, WorkCategory::STUDENT, 2, MedicalCondition::FIT, lic);
             db.addDriver(d);
             cout << "Added Youth driver mock manually.\n";
        } else if (choice == 3) {
             string id;
             cout << "Enter Driver ID to deactivate: "; cin >> id;
             if (db.deactivateDriver(id)) cout << "Driver deactivated successfully.\n";
             else cout << "Driver not found or already inactive.\n";
        } else if (choice == 4) {
             int n; cout << "Enter N: "; cin >> n;
             db.getNewestLicensed(n);
        } else if (choice == 5) {
             int n; cout << "Enter N: "; cin >> n;
             db.getOldestLicensed(n);
        } else if (choice == 6) {
             db.printAllActive();
        } else if (choice == 7) {
             db.printAllInactive();
        } else if (choice == 8) {
             running = false;
        } else {
             cout << "Invalid choice.\n";
        }
    }
    return 0;
}
