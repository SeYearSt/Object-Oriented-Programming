#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "PrivBusTicket.h"
#include "NumInterface.h"
using namespace std;

void sortTickets(PrivBusTicket * arr, int left, int right)
{
	
	int i = left, j = right;
	int temp = (left + right) / 2;
	int p = arr[(left + right) / 2].getNumP(); // вибір елемента, відносно якого ділитиметься масив;
	while (i <= j) {
		while (arr[i].getNumP() > p)
			i++;
		while (arr[j].getNumP() < p)
			j--;
		if (i <= j) {
			PrivBusTicket tempPtrClass;
			tempPtrClass= arr[i];
			arr[i] = arr[j];
			arr[j] = tempPtrClass;
			i++;
			j--;
		}
	};
	if (left < j) // сортування лівої і правої частин масиву;
		sortTickets(arr, left, j);
	if (i < right)
		sortTickets(arr, i, right);
}

std::ostream& operator << (std::ostream& out,  PrivBusTicket A) {
	out << A.toString();
	return out;
}
std::istream& operator >> (istream & in, PrivBusTicket A ) {
	string temp;
	getline(in, temp);
	A.fromString(temp);
	return in;
}



void main() {
	PrivBusTicket A("oleh"), arrayOfPrivBusTicket[10];
	sortTickets(arrayOfPrivBusTicket, 0,9);
	cout << endl<<A;
	cin >> A;
	system("pause");
}