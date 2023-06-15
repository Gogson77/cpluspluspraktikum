#include <iostream>
using namespace std;

struct sMonitor
{
	string pMarka;
	int pVelicina;
};



int main()
{
	sMonitor pMojMon, pTvojMon;
	pMojMon.pMarka = "DTK";
	pMojMon.pVelicina = 15;
	pTvojMon.pMarka = "Samsung";
	pTvojMon.pVelicina = 17;
	cout << "Marka monitora: " << pMojMon.pMarka <<
		", velicina monitora: " << pMojMon.pVelicina << endl;
	
	cout << "Marka monitora: " << pTvojMon.pMarka <<
		", velicina monitora: " << pTvojMon.pVelicina << endl;
	return 0;
}