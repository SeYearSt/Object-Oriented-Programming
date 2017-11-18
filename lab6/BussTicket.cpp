#include "BussTicket.h"



BussTicket::BussTicket():Ticket()
{
	std::cout << "BussTicket()";
	type = "Buss";
}

BussTicket::BussTicket(char*name):Ticket(name) {
	std::cout << "BussTicket(char*)";
	type = "Buss";
}
BussTicket::~BussTicket()
{
}
