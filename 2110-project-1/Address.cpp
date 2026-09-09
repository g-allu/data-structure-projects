#include "Address.h"

Address::Address(std::string s, std::string c, std::string co) 
    : street(s), city(c), county(co) {}

std::string Address::toString() const {
    return street + ", " + city + ", " + county;
}

bool Address::equals(const Address& other) const {
    return (street == other.street && city == other.city && county == other.county);
}

std::string Address::getCounty() const {
    return county;
}
