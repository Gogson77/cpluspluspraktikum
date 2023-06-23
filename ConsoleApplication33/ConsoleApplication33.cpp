# include <iostream>
# include <string.h>
using namespace std;
# define cUvecanje 0.320

// deklaracija klase
class kRadnik
{
public:
	char pPrezime[20];
	char pIme[15];
	float pKoef;
	int pGodStaza;
	float pBrojSati;
	int pPlata;
	kRadnik(char pP[20], char pI[15], float pK, int pGS, float pBS);
	int fPlata();
	int fIsplata();
	~kRadnik();
};

// definicija konstruktora
kRadnik::kRadnik(char pP[20], char pI[15], float pK, int pGS, float pBS)
{
	strcpy(pPrezime, pP);
	strcpy(pIme, pI);
	pKoef = pK;
	pGodStaza = pGS;
	pBrojSati = pBS;
};
// definicija funkcije fPlata
int kRadnik::fPlata()
{
	pPlata = (int)((pGodStaza < 20 || pKoef > 2.550) ? pBrojSati * pKoef * pGodStaza :
		pBrojSati * (pKoef + cUvecanje) * pGodStaza);
	cout << "Za radnika " << pPrezime << " " << pIme;
	cout << " plata je " << pPlata << " dinara.";
	cout << endl;
	return 0;
};
// definicija funkcije fIsplata
int kRadnik::fIsplata()
{
	cout << "Nacin isplate:" << endl;
	cout << pPlata / 1000 << " novcanica od 1000 dinara." << endl;
	cout << (pPlata % 1000) / 200 << " novcanica od 200 dinara." << endl;
	cout << ((pPlata % 1000) % 200) / 50 << " novcanica od 50 dinara." << endl;
	cout << (((pPlata % 1000) % 200) % 50) / 10 << " novcanica od 10 dinara." << endl;
	cout << (((pPlata % 1000) % 200) % 50) % 10 << " novcanica od 1 dinar." << endl << endl;
	return 0;
};
// definicija destruktora
kRadnik :: ~kRadnik()
{
	cout << "Plata je isplacena!" << endl << endl;
};
// glavni program
int main()
{
	kRadnik oCistacica("Miric", "Milica", 1.545, 15, 200);
	kRadnik oDirektor("Peric", "Petar", 5.256, 25, 150);
	cout << "CISTACICA:" << endl;
	oCistacica.fPlata();
	oCistacica.fIsplata();
	cout << "DIREKTOR:" << endl;
	oDirektor.fPlata();
	oDirektor.fIsplata();
	return 0;
}
