#define _CRT_SECURE_NO_WARNINGS

#include "Ticket.h"
#include <iostream>
#include <ctime>
using namespace std;

char * getTime() {
	char * timeStr = new char[18];
	char *tempStr = new char[10];
	time_t t = time(0);
	struct tm * now = localtime(&t);
	_itoa(now->tm_year + 1900, tempStr, 10);
	strcpy(timeStr, tempStr);
	strcpy(timeStr + strlen(timeStr), "-");
	_itoa(now->tm_mon + 1, tempStr, 10);
	strcpy(timeStr + strlen(timeStr), tempStr);
	strcpy(timeStr + strlen(timeStr), "-");
	_itoa(now->tm_mday, tempStr, 10);
	strcpy(timeStr + strlen(timeStr), tempStr);
	strcpy(timeStr + strlen(timeStr), " ");
	_itoa(now->tm_hour, tempStr, 10);
	strcpy(timeStr + strlen(timeStr), tempStr);
	strcpy(timeStr + strlen(timeStr), ":");
	_itoa(now->tm_min, tempStr, 10);
	if ((now->tm_min) < 10) strcpy(timeStr + strlen(timeStr), "0");
	strcpy(timeStr + strlen(timeStr), tempStr);
	return timeStr;
}

void buy(Ticket&);

int Ticket::count = 0;
Ticket::Ticket() {
	cout << "Ticket()\n";
	count++;
	id = count;
	control = false;
	passenger = nullptr;
	timeBuy = nullptr;
	location = nullptr;
	departure = nullptr;
	arrival = nullptr;
	timeDeparture = nullptr;
	timeArrival = nullptr;
	busId = nullptr;
	stops = nullptr;
	roomNumber = -1;
	baggage = true;
	sold = false;
}
Ticket::Ticket(char *name)
{
	cout << "Ticket(char *)\n";
	count++;
	id = count;
	control = false;
	if (name)passenger = _strdup(name); else passenger = nullptr;
	timeBuy = nullptr;
	location = nullptr;
	departure = nullptr;
	arrival = nullptr;
	timeDeparture = nullptr;
	timeArrival = nullptr;
	busId = nullptr;
	stops = nullptr;
	roomNumber = -1;
	baggage = true;
	sold = false;
}
Ticket::Ticket(const Ticket &A)
{
	cout << "Ticket(ticket &)\n";
	if (A.passenger)  this->passenger = _strdup(A.passenger); else this->passenger = nullptr;
	this->control = A.control;
	this->sold = A.sold;
	this->location = A.location ? A.location : nullptr;
	this->departure = A.departure ? A.departure : nullptr;
	this->arrival = A.arrival ? A.arrival : nullptr;
	this->timeDeparture = A.timeDeparture ? A.timeDeparture : nullptr;
	this->timeArrival = A.timeArrival ? A.timeArrival : nullptr;
	this->busId = A.busId ? A.busId : nullptr;
	this->stops = A.stops ? A.stops : nullptr;
	this->roomNumber = A.roomNumber;
	this->baggage = A.baggage;


}
Ticket::~Ticket()
{
	if (passenger) delete passenger;
	if (location) delete location;
	if (departure) delete departure;
	if (arrival) delete arrival;
	if (timeDeparture) delete timeDeparture;
	if (timeArrival) delete timeArrival;
	//if (stops) deleteStops(stops);

}
void Ticket::input(std::istream &in) {
	if (!sold) {
		if (!passenger) {
			char *temp = new char[31];
			in.getline(temp, 31);
			strcpy(temp + strlen(temp), "\n");
			passenger = _strdup(temp);
		}
		else cout << "this ticket already has owner: " << "\'" << passenger << "\'" << endl;
	}
	else cout << "This ticket was bought at:" << timeBuy;
}
void Ticket::write(std::ostream &in)
{
	in << "Owner`s of this ticket is :" << (passenger ? passenger : "\n");
	in << "Time buy :"<<(timeBuy?timeBuy:"\n");
	in << "Composted :" << (control ? "true\n" : "false\n");
	in << "Bought in :" << (location ? location : "\n");
	in << "Departure from :" << (departure ? departure : "\n");
	in << "Arrival to :" << (arrival ? arrival : "\n");
	in << "Time departing :" << (departure ? departure : "\n");
	in << "Bought at :" << (timeBuy ? timeBuy : "\n");
	in << "Ticket Id : " << id;
}
void Ticket::setName(char *name) {
	if (!sold)	passenger = name; else cout << "This ticket was bought at :" << timeBuy;
}
char * Ticket::getName()
{
	if (passenger) return passenger; else return "\n";
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
	 timeBuy = getTime();
	return sold ;
}
void Ticket::buy(char *name) {
	if (!sold){
		sold = true;
	if (name){
		passenger = new char[strlen(name) + 1];
		strcpy(passenger, name);
	}
	timeBuy = getTime();
}
}
 void Ticket::buy(char *name , char *from, char *to)
{
	if (!sold) {
		sold = true;
		if (name) {
			passenger = new char[strlen(name) + 1];
			strcpy(passenger, name);
		}
		else cout << "This is not avalible string\n";
		if (from) {
			departure = new char[strlen(from) + 1];
			strcpy(departure, from);
		}
		else cout << "This is not avalible string\n";
		if (to) {
			arrival = new char[strlen(to) + 1];
			strcpy(arrival, to);
		}
		else cout << "This is not avalible string\n";

		timeBuy = getTime();

	}
	else cout << "This ticket is sold\n";
}

void buy(Ticket *p)
{
	p->buy();
}
