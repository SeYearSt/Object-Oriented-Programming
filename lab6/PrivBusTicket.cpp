#include "PrivBusTicket.h"
#include <sstream>
using namespace std;

int PrivBusTicket::countP = 0;

PrivBusTicket::PrivBusTicket():BusTicket()
{
	privileges = true;
	countP++;
	numP = countP;
	cout << "PrivBusTicket()\n";
}
PrivBusTicket::PrivBusTicket(const string &name) :BusTicket(name)
{
	countP++;
	numP = count;
	cout << "PrivBusTicket(const string &)\n";
	privileges = true;
}

PrivBusTicket::~PrivBusTicket()
{
}

int PrivBusTicket::getCountP()
{
	return countP;
}
int PrivBusTicket::getNumP()
{
	return numP;
}
std::string PrivBusTicket::toString()
{
	stringstream ss;
	ss << "Owner`s of this ticket is :" << (passenger.empty() ? "\n" : passenger + "\n");
	ss << "Composted :" << (control ? "true\n" : "false\n");
	ss << "Bought out :" << (location.empty() ? "\n" : location + "\n");
	ss << "Departure from :" << (departure.empty() ? "\n" : departure + "\n");
	ss << "Arrival to :" << (arrival.empty() ? "\n" : arrival + "\n");
	ss << "Time departure :" << (timeDeparture.empty() ? "\n" : timeDeparture + "\n");
	ss << "Time arrival :" << (timeArrival.empty() ? "\n" : timeArrival + "\n");
	ss << "Bought at :" << (timeBuy.empty() ? "\n" : timeBuy + "\n");
	ss << "BusId :" << (busId.empty() ? "\n" : busId + "\n");
	ss << "Ticket Id :" << id << endl;
	ss << "Sold :" << (sold ? "true\n" : "false\n");
	ss << "Type :" << type + "\n";
	ss << "Privigeles :" << (privileges ? "Avalible\n" : "Isn`t avalible\n");
	return ss.str();
}
void PrivBusTicket::fromString(const string &str)
{
	int len = 1000;
	char lim = ':';
	string temp, temp2;
	stringstream ss;
	ss << str;
	ss.ignore(len, lim);
	getline(ss, passenger);
	ss.ignore(len, lim);
	temp.clear();
	getline(ss, temp);
	control = (temp == "true") ? true : false;
	ss.ignore(len, lim);
	getline(ss, location);
	ss.ignore(len, lim);
	getline(ss, departure);
	ss.ignore(len, lim);
	getline(ss,arrival);
	getline(ss, timeBuy);
	ss.ignore(len, lim);
	getline(ss, busId);
	ss.ignore(len, lim);
	ss >> id;
	ss.ignore(len, lim);
	temp.clear();
	getline(ss, temp);
	sold = (temp == "true") ? true : false;
	ss.ignore(len, lim);
	getline(ss, type);
	ss.ignore(len, lim);
	ss >> temp;
	privileges = (temp == "Avalible") ? true : false;// помилка під час зчитування 
}
void PrivBusTicket::output(ostream &out){
	out << "Owner`s of this ticket is :" << (passenger.empty() ? "\n" : passenger + "\n");
	out << "Composted :" << (control ? "true\n" : "false\n");
	out << "Bought out :" << (location.empty() ? "\n" : location + "\n");
	out << "Departure from :" << (departure.empty() ? "\n" : departure + "\n");
	out << "Arrival to :" << (arrival.empty() ? "\n" : arrival + "\n");
	out << "Time departure :" << (timeDeparture.empty() ? "\n" : timeDeparture + "\n");
	out << "Time arrival :" << (timeArrival.empty() ? "\n" : timeArrival + "\n");
	out << "Bought at :" << (timeBuy.empty() ? "\n" : timeBuy + "\n");
	out << "BusId :" << (busId.empty() ? "\n" : busId + "\n");
	out << "Ticket Id :" << id << endl;
	out << "Sold :" << (sold ? "true\n" : "false\n");
	out << "Type :" << type + "\n";
	out << "Privigeles :" << (privileges ? "Avalible\n" : "Isn`t avalible\n");
}