#include <iostream>
#include <string>
using namespace std;

class Vozilo
{
public:
	string naziv;
	int najBrzina;
	string boja;

	Vozilo(string n, int nb, string b);

	int prikazPodataka();
	int prikazPodataka(string naziv, int najBrzina, string boja);

	~Vozilo();
};

Vozilo::Vozilo(string n, int nb, string b) 
{
	this->naziv = n;
	this->najBrzina = nb;
	this->boja = b;
};

int Vozilo::prikazPodataka() {
	cout << "Naziv vozila: " << naziv << endl;
	cout << "Najveca brzina vozila: " << najBrzina << endl;
	cout << "Boja vozila: " << boja << endl << endl;
	return 0;
}

int Vozilo::prikazPodataka(string naziv, int najBrzina, string boja)
{
	cout << "Naziv vozila: " << naziv <<  endl;
	cout << "Najveca brzina vozila: " << najBrzina << endl;
	cout << "Boja vozila: " << boja << endl << endl;
	return 0;
}

Vozilo::~Vozilo() { cout << "Ovo je destruktor" << endl; };

int main() 
{
	Vozilo moje("Zastava", 120, "plava");
	moje.prikazPodataka();
	moje.prikazPodataka("Golf", 160, "crvena");
	moje.prikazPodataka();
	return 0;
}