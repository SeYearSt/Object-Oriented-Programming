#include "PrivBusTicket.h"
using namespace std;

PrivBusTicket::PrivBusTicket() :BusTicket()
{
	cout << "PrivBusTicket()\n";
}
PrivBusTicket::PrivBusTicket(const string &name) :BusTicket(name)
{
	cout << "PrivBusTicket(const string &)\n";
	privileges = true;
}
PrivBusTicket::PrivBusTicket(const PrivBusTicket &A) : BusTicket(A)
{
	this->privileges = A.privileges;
}
PrivBusTicket::~PrivBusTicket()
{
}

void PrivBusTicket::output(ostream &out){
	out << "Owner`s of this ticket is :" << (passenger.empty() ? "\n" : passenger + "\n");
	out << "Time buy :" << (timeBuy.empty() ? "\n" : timeBuy + "\n");
	out << "Composted :" << (control ? "true\n" : "false\n");
	out << "Bought out :" << (location.empty() ? "\n" : location + "\n");
	out << "Departure from :" << (departure.empty() ? "\n" : departure + "\n");
	out << "Arrival to :" << (arrival.empty() ? "\n" : arrival + "\n");
	out << "Time departure :" << (departure.empty() ? "\n" : departure + "\n");
	out << "Bought at :" << (timeBuy.empty() ? "\n" : timeBuy + "\n");
	out << "Ticket Id :" << id << endl;
	out << "Sold :" << (sold ? "true\n" : "false\n");
	out << "Type :" << type + "\n";
	out << "Privigeles :" << (privileges ? "Avalible\n" : "Isn`t avalible\n");
}