# include <iostream>
# include <string>

using namespace std;

struct sIme {
	char pIme[15];
	char pPrezime[20];
};

class kFilm {
	sIme pReziser;
public:
	char pNaziv[25];
	float pHonorar;
	kFilm();
	void fUpisivanje();
	float& fIzracunaj(float cena, int broj);
	int fIspisi();
	~kFilm();
};

kFilm::kFilm()
{
	strcpy_s(pReziser.pIme, "Nema ");
	strcpy_s(pReziser.pPrezime, "Nema");
	strcpy_s(pNaziv, "Nema");
	pHonorar = 0.00;
};

void kFilm::fUpisivanje()
{
	cout << "Unesi naziv filma: " << endl;
	cin >> pNaziv;
	cout << "\nUnesi ime i prezime rezisera: " << endl;
	cin >> pReziser.pIme >> pReziser.pPrezime;
};

float& kFilm::fIzracunaj(float cena, int broj) {
	float& ref = pHonorar;
	ref = broj * cena;
	return ref;
};

int kFilm::fIspisi() {
	cout << "\nFilm " << pNaziv << " je ostvario honorar od " << pHonorar << " dolara. " << endl;
	return 0;
};

kFilm :: ~kFilm() {
	cout << "\nFilm je zavrsen! " << endl;
};

int main()
{
	kFilm oZabava;
	float pCenaKarte;
	int pBrGled;
	oZabava.fUpisivanje();
	cout << "\nUnesi cenu karte: ";
	cin >> pCenaKarte;
	cout << "\nUnesi broj gledalaca: ";
	cin >> pBrGled;
	oZabava.fIzracunaj(pCenaKarte, pBrGled);
	oZabava.fIspisi();

	return 0;
}
