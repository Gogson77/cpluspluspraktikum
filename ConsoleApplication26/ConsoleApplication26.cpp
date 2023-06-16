#include <iostream>
#include <string.h>
using namespace std;

union uSkola {
	char srednja[20];
	char fakultet[15];
};

int main()
{
	uSkola mojaSkola;
	strcpy_s(mojaSkola.srednja, "Gimnazija");
	cout << mojaSkola.srednja << endl;

	strcpy_s(mojaSkola.fakultet, "ITEP");
	cout << mojaSkola.fakultet << endl;

	cout << mojaSkola.srednja << endl;

	return 0;
}