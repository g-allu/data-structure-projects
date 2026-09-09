#include "Driver.h"

Driver::Driver(std::string id, std::string n, Date d, Address addr, WorkCategory wc, 
               int exp, MedicalCondition med, Date issueD)
    : driverId(id), name(n), dob(d), address(addr), workCategory(wc),
      experienceYears(exp), medicalConditions(med), licenseIssueDate(issueD) {}

std::string Driver::getDriverId() const { return driverId; }
std::string Driver::getName() const { return name; }
Ticket Driver::getTicket() const { return ticket; }
void Driver::setTicket(const Ticket& t) { ticket = t; }
Address Driver::getAddress() const { return address; }
Date Driver::getLicenseIssueDate() const { return licenseIssueDate; }
WorkCategory Driver::getWorkCategory() const { return workCategory; }
int Driver::getExperienceYears() const { return experienceYears; }
MedicalCondition Driver::getMedicalCondition() const { return medicalConditions; }
