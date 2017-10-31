#pragma once
#include <iostream>
class Ticket {
	
protected:
	static int count;
	bool control;
	bool sold;
	char *location;
	char *departure;
	char *arrival;
	char *timeDeparture;
	char *timeArrival;
	char *busId;
	char **stops;
	int roomNumber;
	bool baggage;
public:
	virtual void funct() = 0;
	unsigned int id;
	char *timeBuy;
	static int getCount();
	void input(std::istream&);
	void write(std::ostream &);
	void setName(char*);
	virtual bool buy();
	virtual void buy(char *);
	virtual void buy(char *, char *, char *);
	Ticket();
	Ticket(char*);
	Ticket(const Ticket &);
	~Ticket();
	friend class TicketOffice;
	char* passenger;
	char *getName();
	unsigned int getId();
};
char *getTime();
void buy(Ticket *);