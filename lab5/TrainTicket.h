#pragma once
#include "Ticket.h"
class TrainTicket :
	public Ticket
{
	char *type;
public:
	void funct() {};
	TrainTicket();
	TrainTicket(char*);
	~TrainTicket();
};

