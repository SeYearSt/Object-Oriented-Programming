#pragma once
#include "Ticket.h"
class PlaneTicket :
	public Ticket
{
	char *type;
public:
	void funct() {};
	PlaneTicket();
	PlaneTicket(char*);
	~PlaneTicket();
};

