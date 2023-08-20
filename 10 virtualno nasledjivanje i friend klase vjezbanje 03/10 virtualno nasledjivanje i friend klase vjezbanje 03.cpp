#include <iostream>

using namespace std;

class kOsoba {
private:
	int brlicne;
	friend class ImenikPrijatelj;
protected:
	int brtel;
public:
	char ime[5];
	kOsoba() { }
	void fUpis() {
		cout << "Unesi broj licne karte: "; cin >> brlicne;
		cout << "Unesi broj telefona: "; cin >> brtel;
		cout << "Unesi ime: "; cin >> ime;
	}
	void fIspis() const {
		cout << "Broj licne karte: " << brlicne << endl;
		cout << "Broj telefona: " << brtel << endl;
		cout << "Ime: " << ime << endl;
	}
	~kOsoba() { }
};
class iImenikPrivatni :private kOsoba {
public:
	iImenikPrivatni() { }
	void fUpisivanje() { fUpis(); }
	void fPristupanje() { brtel = 12345; }
	void fIspisivanje() { fIspis(); }
	~iImenikPrivatni() {};
};
class ImenikPrijatelj {
private:
public:	
	kOsoba os;
	ImenikPrijatelj() { }
	void fUpisivanje() { os.fUpis(); }
	void fPristupanje() { os.brlicne = 123459; os.brtel = 12345; }
	void fIspisivanje() { os.fIspis(); }
	~ImenikPrijatelj();
};
class iMojPrivatni :public iImenikPrivatni {
public:
	iMojPrivatni() { }
	void fCitaj() { fUpisivanje(); }
	void fPristup() { brtel = 12345; }	// GRESKA, brtel je private
	void fPisi() { fIspisivanje(); }
	~iMojPrivatni();
};
class iMojPrijatelj :public ImenikPrijatelj {
public:
	iMojPrijatelj() { }
	void fCitaj() { fUpisivanje(); }
	void fPisi() { fIspisivanje(); }
	~iMojPrijatelj();
};

void main()
{
	iMojPrivatni oMojPrivatni;
	ImenikPrijatelj oImenikPrijatelj;
	iMojPrijatelj oMojPrijatelj;

	cout << "Unesi ime: ";
	//cin >> oMojPrivatni.ime;		// GRESKA, ime je private
	cin >> oImenikPrijatelj.os.ime;	// MOZE, ime je public
	cin >> oMojPrijatelj.os.ime;		// MOZE, ime je public

	cout << "Unesi broj telefona: ";
	//cin >> oMojPrivatni.brtel;		// GRESKA, brtel je private
	//cin >> oImenikPrijatelj.os.brtel;	// GRESKA, brtel je protected
	//cin >> oMojPrijatelj.os.brtel;		// GRESKA, brtel je protected


	cout << "Unesi broj licne karte: ";
	//cin >> oMojPrivatni.brlicne;		// GRESKA, brlicne je private
	//cin >> oImenikPrijatelj.os.brlicne;	// GRESKA, brlicne je protected
	//cin >> oMojPrijatelj.os.brlicne;	// GRESKA, brlicne je protected
}
