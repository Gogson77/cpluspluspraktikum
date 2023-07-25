#include <iostream>
#include <stdlib.h>
#define MAX_IME 15

using namespace std;

struct sStudent {
	char ime[MAX_IME + 1];
	char prezime[MAX_IME + 1];
	int reg_broj;
	int god_upisa;
};

//struct S { int i; };

int main()
{
	sStudent* pStud;

	pStud = new sStudent;

	if (pStud == NULL) {
		cout << "Nije uspjela dodjela memorije." << endl;
		exit(1);
	}

	cout << "\nUnesite ime, prezime, registarski broj i godinu upisa:" << endl;
	cin >> pStud->ime >> pStud->prezime >> pStud->reg_broj >> pStud->god_upisa;

	cout << "\nUnijeti podaci:" << endl;
	cout << pStud->ime << " " << pStud->prezime << " ";
	cout << pStud->reg_broj << " " << pStud->god_upisa;
	
	cout << endl << endl;
	
	pStud = 0;
	delete(pStud);

	//S s;
	//s.i = 5;
	//int* pok = &s.i;
	//int j = *pok;
	//cout << j;

	return 0;
}