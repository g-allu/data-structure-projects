#ifndef TICKET_H
#define TICKET_H

#include <string>
#include "Date.h"

class Ticket {
private:
    bool has_ticket;
    Date ticketDate;
    std::string location;
public:
    Ticket();
    void issueTicket(const Date& d, const std::string& loc);
    std::string getLocation() const;
    Date getDate() const;
    bool hasTicket() const;
    std::string toString() const;
};

#endif // TICKET_H
