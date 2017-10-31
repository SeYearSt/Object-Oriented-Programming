#define _CRT_SECURE_NO_WARNINGS

#include "Ticket.h"
#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;


std::string currentDate(){
	time_t now = time(NULL);
	struct tm tstruct;
	char buf[40];
	tstruct = *localtime(&now);
	//format: day DD-MM-YYYY
	strftime(buf, sizeof(buf), "%d/%m/%Y", &tstruct);
	return buf;
}
std::string currentTime(){
	time_t now = time(NULL);
	struct tm tstruct;
	char buf[40];
	tstruct = *localtime(&now);
	//format: HH:mm:ss
	strftime(buf, sizeof(buf), "%X", &tstruct);
	return buf;
}

//char * getTime() {
//	char * timeStr = new char[18];
//	char *tempStr = new char[10];
//	time_t t = time(0);
//	struct tm * now = localtime(&t);
//	_itoa(now->tm_year + 1900, tempStr, 10);
//	strcpy(timeStr, tempStr);
//	strcpy(timeStr + strlen(timeStr), "-");
//	_itoa(now->tm_mon + 1, tempStr, 10);
//	strcpy(timeStr + strlen(timeStr), tempStr);
//	strcpy(timeStr + strlen(timeStr), "-");
//	_itoa(now->tm_mday, tempStr, 10);
//	strcpy(timeStr + strlen(timeStr), tempStr);
//	strcpy(timeStr + strlen(timeStr), " ");
//	_itoa(now->tm_hour, tempStr, 10);
//	strcpy(timeStr + strlen(timeStr), tempStr);
//	strcpy(timeStr + strlen(timeStr), ":");
//	_itoa(now->tm_min, tempStr, 10);
//	if ((now->tm_min) < 10) strcpy(timeStr + strlen(timeStr), "0");
//	strcpy(timeStr + strlen(timeStr), tempStr);
//	return timeStr;
//}


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
	cout << "Ticket(const string & )\n";
	count++;
	id = count;
	control = false;
	passenger = name;
	baggage = true;
	sold = false;
}
Ticket::Ticket(const Ticket &A)
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
	this->stops = A.stops;
	this->baggage = A.baggage;
}
Ticket::~Ticket()
{
	
	//if (stops) deleteStops(stops);

}
void Ticket::input(std::istream &in) {
	if (!sold) {
		if (passenger.empty()) {
			in>>passenger;
		}
		else cout << "this ticket already has owner: " << "\'" << passenger << "\'" << endl;
	}
	else cout << "This ticket was bought at:" << timeBuy;
}
void Ticket::write(std::ostream &out)
{
	out << "Owner`s of this ticket is :" << (passenger.empty() ?"\n": passenger);
	out << "Time buy :" << (timeBuy.empty() ? "\n": timeBuy);
	out << "Composted :" << (control ? "true\n" : "false\n");
	out << "Bought out :" << (location.empty() ? "\n": location);
	out << "Departure from :" << (departure.empty() ? "\n": departure);
	out << "Arrival to :" << (arrival.empty() ? "\n":arrival);
	out << "Time departure :" << (departure.empty() ?"\n": departure);
	out << "Bought at :" << (timeBuy.empty()? "\n":timeBuy);
	out << "Ticket Id :" << id << endl;
	out << "Sold :" << (sold ? "true\n" : "false\n");
}/*
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
}*/
bool Ticket::buy() {
	//timeBuy = currentDate();
	//timeBuy +=" "+currentTime()+"\n";
	return true;
}
 
void Ticket::buy(const string &name) {
	if (!sold){
		sold = true;
		passenger = name;
		timeBuy = currentDate();
		timeBuy += " " + currentTime() + "\n";
}
}
void Ticket::buy(const string &name, const string & from, const string & to)
{
	if (!sold) {
		sold = true;
		if (!name.empty()) {
			passenger = name;
		}
		else cout << "This string is empty\n";
		if (!from.empty()) {
			departure = from;
		}
		else cout << "This string is empty\n";
		if (!to.empty()) {
			arrival = to;
		}
		else cout << "TThis string is empty\n";

		timeBuy = currentDate();
		timeBuy += " " + currentTime() + "\n";

	}
	else cout << "This ticket is sold\n";
}

void buy(Ticket *p)
{
	p->buy();
}
