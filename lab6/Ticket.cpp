#define _CRT_SECURE_NO_WARNINGS

#include "Ticket.h"
#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;



std::string currentDate() // function helper
{
	time_t now = time(NULL);
	struct tm tstruct;
	char buf[40];
	tstruct = *localtime(&now);
	//format: day DD-MM-YYYY
	strftime(buf, sizeof(buf), "%d/%m/%Y", &tstruct);
	return buf;
}
std::string currentTime() //function helper
{
	time_t now = time(NULL);
	struct tm tstruct;
	char buf[40];
	tstruct = *localtime(&now);
	//format: HH:mm:ss
	strftime(buf, sizeof(buf), "%X", &tstruct);
	return buf;
}

int Ticket::count = 0;

Ticket::Ticket() {
	cout << "Ticket()\n";
	count++;
	id = count;
	control = false;
	baggage = true;
	sold = false;
}
Ticket::Ticket(const string & name)
{
	passenger = name;

	cout << "Ticket(const string & )\n";
	count++;
	id = count;
	control = false;
	baggage = true;
	sold = false;
}
Ticket::Ticket(const Ticket & A)
{
	cout << "Ticket(ticket &)\n";
	this->passenger = A.passenger;
	this->control = A.control;
	this->sold = A.sold;
	this->location = A.location;
	this->departure = A.departure;
	this->arrival = A.arrival;
	this->timeDeparture = A.timeDeparture;
	this->timeArrival = A.timeArrival;
	this->busId = A.busId;
	this->baggage = A.baggage;
}
Ticket::~Ticket()
{
	//empty
}
void Ticket::input(istream & in) {
	if (!sold) {
		if (passenger.empty()) {
			getline(in,passenger);;
		}
		else clog << "this ticket already has owner: " << "\'" << passenger << "\'" << endl;
	}
	else clog << "This ticket was bought at:" << timeBuy;
}
void Ticket::output(ostream & out)
{
	out << "Owner`s of this ticket is :" << (passenger.empty() ?"\n": passenger+"\n");
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
	out << "Type :" << type+"\n";
}
void Ticket::setPassenger(const string & name) {
	if (!sold)	passenger = name; else clog << "This ticket was bought at :" << timeBuy;
}
string Ticket::getPassenger()
{
	return passenger;
}
unsigned int Ticket::getId()
{
	return id;
}
int Ticket::getCount()
{
	return count;
}
bool Ticket::buy() {
	return sold;
} 
void Ticket::buy(const string &name) {
	if (!sold){
		sold = true;
		passenger = name;
		timeBuy = currentDate();
		timeBuy += " " + currentTime();
}
}
void Ticket::buy(const string &name, const string & from, const string & to)
{
	if (!sold) {
		sold = true;
		if (!name.empty()) {
			passenger = name;
		}
		else clog << "This string is empty\n";
		if (!from.empty()) {
			departure = from;
		}
		else clog << "This string is empty\n";
		if (!to.empty()) {
			arrival = to;
		}
		else clog << "TThis string is empty\n";

		timeBuy = currentDate();
		timeBuy += " " + currentTime();

	}
	else clog << "This ticket is sold\n";
}
