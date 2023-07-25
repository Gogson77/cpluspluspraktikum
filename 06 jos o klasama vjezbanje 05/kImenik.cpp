#include "kImenik.h"
#include <iostream>
#include <cstring>

using namespace std;

int kImenik::pBroj = 0;

kImenik::kImenik() : pRedniBroj(0) {
	strcpy_s(pIme, "");
	strcpy_s(pAdr.pUlica, "");
	pAdr.pBroj = 0;
	strcpy_s(pAdr.pGrad, "");
	strcpy_s(pTelefon, "");
}

void kImenik::fUpis() {
	kImenik::pBroj += 1;
	pRedniBroj = kImenik::pBroj;
	cout << "Unesi ime: ";
	cin >> pIme;
	cout << "Unesi ulicu, broj i grad: ";
	cin >> pAdr.pUlica >> pAdr.pBroj >> pAdr.pGrad;
	cout << "Unesi broj telefona: ";
	cin >> pTelefon;
};

void kImenik::fListaj() const {
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~ ADRESE ~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Redni broj:\t" << pRedniBroj << endl;
	cout << "Ime:\t\t" << pIme << endl;
	cout << "Ulica i broj:\t" << pAdr.pUlica << " " << pAdr.pBroj << endl;
	cout << "Grad:\t\t" << pAdr.pGrad << endl;
	cout << "Telefon:\t\t" << pTelefon << endl << endl;
};

void kImenik::fPrikazi() const {
	cout << "\nPod rednim brojem:\t" << pRedniBroj << " se nalazi: " << endl;
	cout << "\nIme:\t\t" << pIme << endl;
	cout << "\nUlica i broj:\t" << pAdr.pUlica << " " << pAdr.pBroj << endl;
	cout << "\nGrad:\t\t" << pAdr.pGrad << endl;
	cout << "\nTelefon:\t\t" << pTelefon << endl << endl;
};

kImenik::~kImenik() {
};