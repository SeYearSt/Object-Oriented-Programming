#include <iostream>
#include <string>
#include <sstream>
#include "PrivBusTicket.h"
#include "NumInterface.h"
using namespace std;

void sortTICKETS(NumInterface * ARR, int left, int right)
{
	int i = left, j = right;
	int p = ARR[(left + right) / 2].getCountP(); // вибір елемента, відносно якого ділитиметься масив;
	while (i <= j) {
		while (ARR[i].getNumP() < p)
			i++;
		while (ARR[j].getNumP() > p)
			j--;
		if (i <= j) {
			NumInterface *tmp = &ARR[i];
			ARR[i] = ARR[j];
			ARR[j] = *tmp;
			i++;
			j--;
		}
	};
	if (left < j) // сортування лівої і правої частин масиву;
		sortTICKETS(ARR, left, j);
	if (i < right)
		sortTICKETS(ARR, i, right);
}


void main(){
	PrivBusTicket A[100], B;
	//NumInterface A;
		sortTICKETS(A,30,40);
	system("pause");
}