#include <iostream>
using namespace std;

class Index 
{
public:
	string ime;
	int broj;
	int godinaUpisa;
	double prosjek;

	Index();
	int prikazPodataka();
	~Index();
};

Index::Index() { ime = "Nema"; broj = 0; godinaUpisa = 0; prosjek = 0.00; };

int Index::prikazPodataka() {
	cout << "Ime: " << ime << ", godina upisa: " << godinaUpisa;
	cout << ", broj indeksa: " << broj << ", prosjek: " << prosjek << "." << endl << endl;
	return 0;
}

Index::~Index() { cout << "Nema upisanog." << endl; }

int main()
{
	Index mojIndex; mojIndex.prikazPodataka();
	return 0;
}