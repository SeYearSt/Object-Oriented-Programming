#include "TrainTicket.h"



TrainTicket::TrainTicket() :Ticket()
{
	std::cout << "TrainTicket()";
	type = "Train";
}

TrainTicket::TrainTicket(char *name) : Ticket(name) {
	std::cout << "TrainTicket()";
	type = "Train";
}

TrainTicket::~TrainTicket()
{
}
