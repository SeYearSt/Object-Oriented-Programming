#define _CRT_SECURE_NO_WARNINGS
#include <stack>
#include <string>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <iterator>
using namespace std;

int loadFileToStack(istream_iterator<char>&i,stack<string>&stringStack) {
	int count = 0;
	string buf;
	while (i != istream_iterator<char>()) {
		cout << *i;
		if (*i++=='\n') { cout << "\n"; }
		/*buf = *i;
		cout << buf;
		++i;*/
	}
	/*while (!f.eof()) {
		string buf;
		getline(f, buf, '\n');
		buf += '\n';
		stringStack.push(buf);
		count++;
	}*/
	return count;
}
int loadFileToStack(ifstream &f,stack <string>& stringStack ) {
	int count=0;
	while (!f.eof()) {
		string buf;
		getline(f, buf, '\n');
		buf += '\n';
		stringStack.push(buf);
		count++;
	}
	return count;
}
void purge(stack <string> &stringStack) {
	while (!stringStack.empty()) {
		cout << stringStack.top();
		stringStack.pop();
	}
}
void renumber(stack<string> & stringStack,int count) {
	stack<string> newStack;
	int i = 0;
	while (!stringStack.empty()) {
		string temp;
		temp += to_string(count-i);
		++i;
		temp += ": ";
		temp += stringStack.top();
		stringStack.pop();
		newStack.push(temp);
	}
	stringStack = newStack;
}

void main() {
	//int count;
	stack<string> stringStack;
	ifstream f( "main.cpp" );
	if ( !f ) { cout << "fail to open file!\n"; return; }
	istream_iterator<char>i(f);
	loadFileToStack( i, stringStack );
	/*Task first. --------------------------------------------------------------------------*/
	/*ifstream f("main.cpp");
	if (!f) { return; cout << "File to open file!\n"; }
	stack<string> stringStack;
	count=loadFileToStack(f, stringStack);
	renumber(stringStack,count);
	purge(stringStack);
	f.close();
	/* ---------------------------------------------------------------------------------------*/
	cout << "\nEnd of main";
	while (!_kbhit());
}

