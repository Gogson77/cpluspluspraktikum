#include <iostream>
using namespace std;

class Otac 
{
public:
	string ime;
	int godine;

	Otac();
	Otac(int);
	Otac(int, string);
	Otac(string, int);

	int prikazPodataka();
	~Otac();
};

Otac::Otac() { ime = "Petar"; godine = 50; };
Otac::Otac(int g) { godine = g; };
Otac::Otac(int g, string i) { godine = g; ime = i; };
Otac::Otac(string i, int g) { ime = i; godine = g; };

int Otac::prikazPodataka() 
{
	cout << "Ime: " << ime << endl;
	cout << "Godine: " << godine << endl << endl;
	return 0;
};

Otac::~Otac() { cout << "Kraj" << endl; }

int main() 
{
	Otac mojOtac; mojOtac.prikazPodataka();
	Otac tvojOtac(45); tvojOtac.prikazPodataka();
	Otac njenOtac(33, "Goran"); njenOtac.prikazPodataka();
	Otac njegov("Bruno", 56); njegov.prikazPodataka();
	return 0;
}