#pragma once
#include "BusTicket.h"
#include "StrInterface.h"
#include "NumInterface.h"

class PrivBusTicket :
	public BusTicket,
	public NumInterface,
	public StrInterface

{
private:
	bool privileges;
	static int countP;
	int numP;
public:
	 virtual int getCountP();
	 virtual int getNumP();
 	 virtual std::string toString();
     virtual void fromString(const std::string &);
	 void output(std::ostream &);

	PrivBusTicket();
	PrivBusTicket(const string &name);
	PrivBusTicket(const PrivBusTicket &);

	~PrivBusTicket();
};


