#include "BusTicket.h"
//using namespace std;


BusTicket::BusTicket():Ticket()
{
	cout << "BussTicket()\n";
	type = "Buss";
}

BusTicket::BusTicket(const string &name):Ticket(name) 
{
	cout << "BussTicket(const string &)\n";
	type = "Buss";
}
BusTicket::~BusTicket()
{
}
