#include "Ticket.h"

Ticket::Ticket() : has_ticket(false), location("") {}

void Ticket::issueTicket(const Date& d, const std::string& loc) {
    has_ticket = true;
    ticketDate = d;
    location = loc;
}

std::string Ticket::getLocation() const {
    return location;
}

Date Ticket::getDate() const {
    return ticketDate;
}

bool Ticket::hasTicket() const {
    return has_ticket;
}

std::string Ticket::toString() const {
    if (!has_ticket) return "No tickets";
    return "Ticket Date: " + ticketDate.toString() + ", Location: " + location;
}
