#include <iostream>
using namespace std;

float f1(int i, int j) { return 0; };

void f2(float a, float b, float c) {};

void fStampa(const char* x);

int main()
{
	fStampa("U ovom kodu postoje sintaksne greske.");
	return 0;
}

void fStampa(const char* x)
{
	cout << x << endl;
	cout << "Nadji ih." << endl;
}