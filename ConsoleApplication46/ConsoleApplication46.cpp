#include <iostream>
using namespace std;

class kPrva {
public:
	int pBaza;
	int fPisi() { 
		cout << " Osnovna funkcija. " << endl;
		return 0;
	}
};

class iDruga: public kPrva {
public:
	int pIzvod;
	int fIzlaz() {
		cout << " Izvedena funkcija. " << endl;
		return 0;
	}
};

int main()
{
	kPrva oOsnovna;
	iDruga oIzvedena;
	oOsnovna.pBaza = 0;
	cout << oOsnovna.pBaza << endl;
	oIzvedena.pBaza = 1;
	cout << oIzvedena.pBaza << endl;
	cout << oOsnovna.pBaza << endl;
	oOsnovna.fPisi();
	oIzvedena.fPisi();
	oIzvedena.fIzlaz();
	return 0;
}