#pragma once
#include <iostream>
#include <string>
using namespace std;
class Ticket {
	
protected:
	static int count;
	bool control;
	bool sold;
	string location, departure, arrival, timeDeparture, timeArrival, busId, timeBuy;
	string *stops;
	bool baggage;
public:
	string passenger;
	//virtual void funct() = 0;
	unsigned int id;
	Ticket();
	Ticket(const string &);
	Ticket(const Ticket &);
	~Ticket();
	static int getCount();
	void input(std::istream&);
	void write(std::ostream &);
	void setName(const string&);
	friend class TicketOffice;
	string *getName();
	unsigned int getId();
	virtual bool buy();
	virtual void buy(const string &);
	virtual void buy(const string &, const string &, const string &);
};
std::string currentDate();
std::string currentTime();

//char *getTime();
//void buy(Ticket *);