#include <iostream>
using namespace std;

class kPrevoznoSredstvo {
public:
	char pMarka[20];
	int pMaxBrzina;
	kPrevoznoSredstvo() { 
		strcpy_s(pMarka, "Nema"); pMaxBrzina = 0; 
	};
	int fUpisAtributa() {
		cout << "Upisi marku prevoznog sredstva: "; 
		cin >> pMarka; 
		cout << "Upisi najvecu brzinu prevoznog sredstva: "; cin >> pMaxBrzina; cout << endl; 
		return 0; 
	};
	int fPrevoz() { 
		cout << "Ovo je prevozno sredstvo: " << pMarka << ", najvece brzine: " << pMaxBrzina << endl << endl; return 0; 
	};
	~kPrevoznoSredstvo() { 
		cout << "Kraj prevoznog sredstva: " << pMarka << endl; 
	};
};

class iTeretnoVozilo : public kPrevoznoSredstvo {
public:
	float pNosivost;
	int fUpisAtributa() {
		cout << "Upisi marku teretnog vozila: ";
		cin >> pMarka;
		cout << "Upisi najvecu brzinu teretnog vozila: "; 
		cin >> pMaxBrzina; 
		cout << "Unesi nosivost teretnog vozila: ";
		cin >> pNosivost; cout << endl;
		return 0;
	};
	int fPrevoz() { 
		cout << "Ovo je teretno vozilo: " << pMarka << ", najvece brzine: " << pMaxBrzina << ", nosivosti : " << pNosivost << endl << endl; 
		return 0; 
	};
	iTeretnoVozilo() : kPrevoznoSredstvo() { 
		pNosivost = 0.00; 
	};
	~iTeretnoVozilo() { 
		cout << "Kraj teretnog vozila: " << pMarka << endl; 
	};
};

int main()
{
	kPrevoznoSredstvo oPrevoz;
	oPrevoz.fUpisAtributa();
	oPrevoz.fPrevoz();
	
	iTeretnoVozilo oKamion;
	oKamion.fUpisAtributa();
	oKamion.fPrevoz();
	return 0;
}