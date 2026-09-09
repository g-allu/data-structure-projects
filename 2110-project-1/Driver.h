#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <iostream>
#include "Enums.h"
#include "Date.h"
#include "Address.h"
#include "Ticket.h"

class Driver {
protected:
    std::string driverId;
    std::string name;
    Date dob;
    Address address;
    WorkCategory workCategory;
    int experienceYears;
    MedicalCondition medicalConditions;
    Date licenseIssueDate;
    Ticket ticket;

public:
    Driver(std::string id, std::string n, Date d, Address addr, WorkCategory wc, 
           int exp, MedicalCondition med, Date issueD);
    virtual ~Driver() {}

    std::string getDriverId() const;
    std::string getName() const;
    Ticket getTicket() const;
    void setTicket(const Ticket& t);
    Address getAddress() const;
    Date getLicenseIssueDate() const;
    WorkCategory getWorkCategory() const;
    int getExperienceYears() const;
    MedicalCondition getMedicalCondition() const;

    virtual void displayInfo() const = 0;
};

#endif // DRIVER_H
