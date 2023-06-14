#include <iostream>
using namespace std;

typedef enum eZanr{ nema, triler, akcija, drama, komedija, horor };

class Film 
{
public:
	string naziv;
	string reziser;
	int trajanje;
	int zarada;
	eZanr zanr;
	double starost;

	Film();
	Film(string, string, int, int, eZanr, double);

	void ispis();

	~Film();
};

Film::Film() { 
	naziv = "nema"; reziser = "nema"; trajanje = 0;
	zarada = 0; zanr = nema; starost = 0;
}
Film::Film(string n, string r, int t, int z, eZanr znr, double s) {
	naziv = n; reziser = r; trajanje = t; 
	zarada = z; zanr = znr; starost = s;
}

void Film::ispis() {
	cout << "Ovo je film " << naziv << ", rezisera " << reziser 
		<< ", traje " << trajanje << ", zanr je " << zanr << "." << endl;
	cout << "Ukupno ostvarena zarada na filmu je " << zarada 
		<< ", a prosjecna starost glumaca je " << starost << endl << endl;
}
Film::~Film() { cout << "Kraj" << endl; }
int main()
{
	Film mojFilm; mojFilm.ispis();
	Film tvojFilm("7 samuraja", "Kurosava", 120, 540000, akcija, 33.25);
	tvojFilm.ispis();
	return 0;
}
