#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ticket {

protected:
	static int count;
	unsigned int id;
	bool control, baggage, sold;
	string location, departure, arrival, timeDeparture, timeArrival, busId, timeBuy, type;
public:
	string passenger;
	
	virtual void abstract() = 0; // abstract class
	Ticket();
	Ticket(const string &);
	//Ticket(const Ticket &);
	~Ticket();

	static int getCount();
	void input(istream &);
	void output(ostream &);
	void setPassenger(const string &);
	string getPassenger();
	unsigned int getId();
	virtual bool buy();
	virtual void buy(const string &);
	virtual void buy(const string &, const string &, const string &);
};