#ifndef DERIVED_DRIVERS_H
#define DERIVED_DRIVERS_H

#include "Driver.h"

class YouthDriver : public Driver {
public:
    YouthDriver(std::string id, std::string n, Date d, Address addr, WorkCategory wc, 
                int exp, MedicalCondition med, Date issueD);
    void displayInfo() const override;
};

class MiddleAgeDriver : public Driver {
public:
    MiddleAgeDriver(std::string id, std::string n, Date d, Address addr, WorkCategory wc, 
                    int exp, MedicalCondition med, Date issueD);
    void displayInfo() const override;
};

class SeniorDriver : public Driver {
public:
    SeniorDriver(std::string id, std::string n, Date d, Address addr, WorkCategory wc, 
                 int exp, MedicalCondition med, Date issueD);
    void displayInfo() const override;
};

#endif // DERIVED_DRIVERS_H
