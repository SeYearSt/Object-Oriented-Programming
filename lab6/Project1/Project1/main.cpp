#include <iostream>
#include <string>
#include "Ticket.h"
using namespace std;

void main(){
	string B = "asdasd";
	Ticket A(B);
	A.buy();
	A.write(std::cout);
//	cout << "Input your name :";
	A.input(std::cin);
	system("pause");
}