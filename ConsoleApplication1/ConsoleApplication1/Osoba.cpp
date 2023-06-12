#include "Osoba.h"

Osoba::Osoba() {
    cout << "Defaultni konstruktor" << endl;
};

Osoba::Osoba(string i, string p, string mb, string m) {

    cout << "Konstruktor sa argumentima" << endl;
	this->ime = i;
	this->prezime = p;
	this->matBroj = mb;
	this->mesto = m;
};

Osoba::Osoba(Osoba& s) {
    cout << "Kopija konstruktora" << endl;
    this->ime = s.ime;
    this->prezime = s.prezime;
    this->matBroj = s.matBroj;
    this->mesto = s.mesto;
}

void Osoba::prikazPodataka() {
    cout << "Ja sam " << this->ime << " " << this->prezime << endl;
    cout << "Moj maticni broj je " << this->matBroj << endl;
};

void Osoba::mestoBoravka() { cout << "Stanujem u " << this->mesto << endl;};

Osoba::~Osoba() {cout << "Osoba je unistena." << endl;};
