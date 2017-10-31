#include "TicketOffice.h"
#include "BussTicket.h"


TicketOffice::TicketOffice()
{
}


TicketOffice::~TicketOffice()
{
}
 int TicketOffice::getCount() {
	return BussTicket::getCount();
}
void TicketOffice::buy() {
	return BussTicket::buy();
}
void buy(char *name) {
	BussTicket::buy(name);
}
void buy(char *name, char*from, char *to) {
	BussTicket::buy(name, from, to);
}
