#include "DerivedDrivers.h"

using namespace std;

static string getWorkStr(WorkCategory w) {
    if (w == WorkCategory::STUDENT) return "Student";
    if (w == WorkCategory::GOVERNMENT) return "Government";
    if (w == WorkCategory::SELF_EMPLOYED) return "Self Employed";
    if (w == WorkCategory::BUSINESS_OWNER) return "Business Owner";
    return "Private Sector";
}

static string getMedStr(MedicalCondition m) {
    if (m == MedicalCondition::FIT) return "Fit";
    if (m == MedicalCondition::VISION_IMPAIRED) return "Vision Impaired";
    if (m == MedicalCondition::UPPER_EXTREMITY) return "Upper Extremity Impairment";
    return "Locomotor Disability";
}

YouthDriver::YouthDriver(string id, string n, Date d, Address addr, WorkCategory wc, 
                         int exp, MedicalCondition med, Date issueD)
    : Driver(id, n, d, addr, wc, exp, med, issueD) {}

void YouthDriver::displayInfo() const {
    cout << "[Youth Driver] ID: " << driverId << " | Name: " << name << "\n"
         << "DOB: " << dob.toString() << " | License Issued: " << licenseIssueDate.toString() << "\n"
         << "Address: " << address.toString() << "\n"
         << "Work: " << getWorkStr(workCategory) << " | Exp: " << experienceYears << " yrs | Med: " << getMedStr(medicalConditions) << "\n"
         << ticket.toString() << "\n";
}

MiddleAgeDriver::MiddleAgeDriver(string id, string n, Date d, Address addr, WorkCategory wc, 
                                 int exp, MedicalCondition med, Date issueD)
    : Driver(id, n, d, addr, wc, exp, med, issueD) {}

void MiddleAgeDriver::displayInfo() const {
    cout << "[Middle-Age Driver] ID: " << driverId << " | Name: " << name << "\n"
         << "DOB: " << dob.toString() << " | License Issued: " << licenseIssueDate.toString() << "\n"
         << "Address: " << address.toString() << "\n"
         << "Work: " << getWorkStr(workCategory) << " | Exp: " << experienceYears << " yrs | Med: " << getMedStr(medicalConditions) << "\n"
         << ticket.toString() << "\n";
}

SeniorDriver::SeniorDriver(string id, string n, Date d, Address addr, WorkCategory wc, 
                           int exp, MedicalCondition med, Date issueD)
    : Driver(id, n, d, addr, wc, exp, med, issueD) {}

void SeniorDriver::displayInfo() const {
    cout << "[Senior Driver] ID: " << driverId << " | Name: " << name << "\n"
         << "DOB: " << dob.toString() << " | License Issued: " << licenseIssueDate.toString() << "\n"
         << "Address: " << address.toString() << "\n"
         << "Work: " << getWorkStr(workCategory) << " | Exp: " << experienceYears << " yrs | Med: " << getMedStr(medicalConditions) << "\n"
         << ticket.toString() << "\n";
}
