#pragma once
#include "Ticket.h"
class BussTicket :
	public Ticket
{
protected :
	char *type;
public:
	virtual void funct() { ; }
	BussTicket();
	BussTicket(char*);
	~BussTicket();
};

