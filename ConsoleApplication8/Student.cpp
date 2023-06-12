#include "Student.h"

Student::Student() {
	cout << "Defaultni konstruktor" << endl;
}

Student::Student(string i, string p, string bi, int gu) {
	
	cout << "Konstruktor sa parametrima" << endl;
	this->ime = i;
	this->prezime = p;
	this->brojIndeksa = bi;
	this->godinaUpisa = gu;
}

Student::Student(Student& s) {
	cout << "Kopija konstruktora" << endl;
	this->ime = s.ime;
	this->prezime = s.prezime;
	this->brojIndeksa = s.brojIndeksa;
	this->godinaUpisa = s.godinaUpisa;
}

void Student::prikazPodataka() {
	cout << "Ime: " << this->ime << endl;
	cout << "Prezime: " << this->prezime << endl;
	cout << "Broj Indeksa: " << this->brojIndeksa<< endl;
	cout << "Godina upisa: " << this->godinaUpisa<< endl;
}

Student::~Student() {
	cout << "Destruktor pozvan" << endl;
}
