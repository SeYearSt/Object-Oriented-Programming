#pragma once
#include "BusTicket.h"
class PrivBusTicket :
	public BusTicket
{
private:
	bool privileges;
public:
	PrivBusTicket(const string &name);
	PrivBusTicket(const PrivBusTicket &);
	void output(ostream &);
	PrivBusTicket();
	~PrivBusTicket();
};

