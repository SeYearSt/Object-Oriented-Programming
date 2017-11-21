#pragma once
#include "Ticket.h"
class BusTicket : public Ticket{

protected :
	string type;
public:
	virtual void abstract(){};// isn`t abstract class
	BusTicket();
	BusTicket(const string &);
	~BusTicket();
};