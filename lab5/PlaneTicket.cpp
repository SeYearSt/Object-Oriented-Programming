#include "PlaneTicket.h"



PlaneTicket::PlaneTicket() :Ticket()
{
	std::cout << "PlaneTicket()";
	type = "Plane";
}

PlaneTicket::PlaneTicket(char *name):Ticket(name)
{
	std::cout << "PlaneTicket(char*)";
	type = "Plane";
}


PlaneTicket::~PlaneTicket()
{
}
