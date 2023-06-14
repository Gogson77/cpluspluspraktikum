#include <iostream>
using namespace std;

class Knjiga {
public:
	string naziv;
	string pisac;
	int brojStrana;
	double cijena;

	Knjiga();
	Knjiga(string n, string p, int bs, double c);

	void prikazPodataka();

	~Knjiga();
};

Knjiga::Knjiga() 
{ 
	naziv = "Nista"; pisac = "Nema"; brojStrana = 0; cijena = 0.00;
};

Knjiga::Knjiga(string n, string p, int bs, double c) 
{
	naziv = n; pisac = p; brojStrana = bs; cijena = c;
};

void Knjiga::prikazPodataka() {
	cout << "Ovo je " << naziv << ", napisao je " << pisac;
	cout << ", ima " << brojStrana << " strana i kosta " << cijena << "KM." << endl;
}

Knjiga::~Knjiga() { cout << "Ovo su knjige iz programskih jezika." << endl; }

int main() {
	Knjiga mojaKnjiga; mojaKnjiga.prikazPodataka();
	Knjiga najdrazaKnjiga("Pascal", "Ciric", 200, 350.56); najdrazaKnjiga.prikazPodataka();

	return 0;
}