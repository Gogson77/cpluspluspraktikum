#include <iostream>
using namespace std;

typedef enum eAranzman { nema, privatno, agencija, hotel };

class Ljetovanje {
public:
	string mjesto;
	string drzava;
	int brojDana;
	eAranzman nacin;

	Ljetovanje();
	Ljetovanje(string, string, int, eAranzman);
	
	void ispis();

	~Ljetovanje();
};

Ljetovanje::Ljetovanje() { 
	mjesto = "Nema"; drzava = "Nema"; brojDana = 0; nacin = nema;
};

Ljetovanje::Ljetovanje(string m, string d, int bd, eAranzman n) {
	mjesto = m; drzava = d; brojDana = bd; nacin = n;
}

void Ljetovanje::ispis() {
	cout << "Ljetovao sam " << brojDana << " dana u mjestu " << mjesto;
	cout << ", drzava " << drzava << ". Aranzman je " << nacin << endl;
}

Ljetovanje::~Ljetovanje() { cout << "Kraj" << endl; }
int main()
{
	Ljetovanje mojeLjetovanje; mojeLjetovanje.ispis();
	Ljetovanje naseLjetovanje("Ljubljana", "Slovenija", 15, privatno); naseLjetovanje.ispis();
	
	return 0;
}