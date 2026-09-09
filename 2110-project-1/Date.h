#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int d = 1, int m = 1, int y = 2000);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    std::string toString() const;
    bool isValid() const;
    int compareTo(const Date& other) const;
};

#endif // DATE_H
