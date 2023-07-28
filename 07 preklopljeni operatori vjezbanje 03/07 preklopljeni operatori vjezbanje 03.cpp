#include <iostream>
#include <string.h>

using namespace std;

class kText {
	char* txt;
public:
	kText(const char* niz);
	kText(const kText& reftxt);
	kText& operator = (const kText& reftxt);
	void fPisi();
	~kText() {};
};

// konstruktor, koji inicijalizuje objekat
inline kText::kText(const char* niz)
{
	txt = new char[strlen(niz) + 1];
	if (txt) strcpy_s(txt, strlen(niz) + 1, niz);
}

// konstruktor kopije, koji kopira niz karaktera u objekat
inline kText::kText(const kText& reftxt) {
	txt = new char[strlen(reftxt.txt) + 1];
	if (txt) strcpy_s(txt, strlen(reftxt.txt) + 1, reftxt.txt);
}

// funkcija koja kopira niz karaktera u objekat
inline kText& kText::operator=(const kText& reftxt) {
	if (&reftxt != this) {
		delete[] txt;
		txt = new char[strlen(reftxt.txt) + 1];
		if (txt) strcpy_s(txt, strlen(reftxt.txt) + 1, reftxt.txt);
	}
	return *this;
}

inline void kText::fPisi()
{
	int i;
	for (i = 0; i < strlen(txt) + 1; i++)
		cout << *(txt + i);
}


int main()
{
	kText a("Dobar dan.");	// poziva se konstruktor  kText (const char *niz)
	cout << "a = ";
	a.fPisi();			// a = "Dobar dan."
	kText b = kText("Zdravo.");	// poziva se konstruktor kText (const char *niz)	
	cout << "\nb = ";
	b.fPisi(); 			// b = "Zdravo."
	a = b;				// poziva se funkcija   kText & operator = (const kText &reftxt)
	// da nije definisana funkcija pozivao bi se konstruktor kopije
	cout << "\na = ";
	a.fPisi();			// a = "Zdravo."
	cout << endl << endl;

}