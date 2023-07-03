#include <iostream>
using namespace std;

class kPodaci {
public:
	struct sNaziv {
		char pIme[15];
		char pPrezime[20];
	};

	sNaziv pNaziv;
	int pGodRod;

	kPodaci() {
		strcpy_s(pNaziv.pIme, "Nema");
		strcpy_s(pNaziv.pPrezime, "Nema");
		pGodRod = 0;
	};

	kPodaci(sNaziv pN, int pGR) {
		strcpy_s(pNaziv.pIme, pN.pIme);
		strcpy_s(pNaziv.pPrezime, pN.pPrezime);
		pGodRod = pGR;
	};

	int fUpis() {
		cout << "Ime: ";
		cin >> pNaziv.pIme;
		cout << "Prezime: ";
		cin >> pNaziv.pPrezime;
		cout << "Godina rodjenja: ";
		cin >> pGodRod;
		cout << endl;
		return 0;
	};

	int fIspis() {
		cout << "Ime: " << pNaziv.pIme;
		cout << ", Prezime: " << pNaziv.pPrezime;
		cout << ", Godina rodjenja: " << pGodRod;
		cout << endl;
		return 0;
	};

	int fStarost() {
		cout << "Starost osobe je " << 2023-pGodRod << " godina." << endl;
		return 0;
	};

	~kPodaci() { cout << "Rad u tri datoteke." << endl; };
};

	int main()
{
		kPodaci oMoji;
		oMoji.fUpis();
		oMoji.fIspis();
		oMoji.fStarost();

	return 0;
}
