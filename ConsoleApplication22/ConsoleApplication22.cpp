#include <iostream>
#include <string>
using namespace std;

typedef enum eStanovanje { stud_dom = 1, privatno, kod_roditelja };
typedef enum eIzdrzavanje { stud_kredit = 1, sam_radi, roditelji };

class Student {
public:
	string ime;
	string prezime;
	string matBroj;
	int brojInd;
	int godUpisa;
	eStanovanje stanuje;
	eIzdrzavanje izdrzava;

	void ispisiPodatke();

};

void Student::ispisiPodatke() {
	cout << "Ime " << ime << endl;
	cout << "Prezime " << prezime << endl;
	cout << "Maticni broj " << matBroj << endl;
	cout << "Broj indeksa " << brojInd << " / godina upisa " << godUpisa << endl;
	cout << "Stanuje " << stanuje << endl;
	cout << "Izdrazavanje " << izdrzava << endl;
}

int main()
{
	Student prvi; 
	prvi.ime = "Petar";
	prvi.prezime = "Peric";
	prvi.matBroj = "120963778656";
	prvi.brojInd = 545;
	prvi.godUpisa = 2023;
	prvi.stanuje = privatno;
	prvi.izdrzava = roditelji;
	prvi.ispisiPodatke();

	return 0;
}
