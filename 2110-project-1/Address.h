#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address {
private:
    std::string street;
    std::string city;
    std::string county;
public:
    Address(std::string s = "", std::string c = "", std::string co = "");
    std::string toString() const;
    bool equals(const Address& other) const;
    std::string getCounty() const;
};

#endif // ADDRESS_H
