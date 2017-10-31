#include <iostream>
#include <fstream>
#include "BussTicket.h"
#include "TrainTicket.h"
#include "PlaneTicket.h"
using namespace std;

void main() {
	BussTicket A;
	PlaneTicket B;
	TrainTicket C;
	buy(&C);
	C.write(std::cout);
	
	system("pause");
}