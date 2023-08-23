#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

class Student 
{
public:
	Student() {}
	~Student() {}

	int dohvatiIndex() { return index; }
	char* dohvatiIme() { return ime; }
	void upisImena(char* im) { strcpy_s(ime, im); }
	void upisIndexa(int ind) { index = ind; }
	void upis();

private:
	int index;
	char ime[30];
};

void Student::upis() {
	cout << "\nUnesi ime studenta: ";
	cin >> ime;
	cout << "Unesi broj indexa: ";
	cin >> index;
}

int main()
{
	Student student;
	char imeDatoteke[80];
	char pom;
	int izbor = 1;

	cout << "Unesi ime datoteke: ";
	cin >> imeDatoteke;

	//unos jednog sloga
	ofstream fout(imeDatoteke, ios::app);
	student.upis();
	fout << student.dohvatiIme() << " ";
	fout << student.dohvatiIndex() << endl;
	

	//ispisivanje datoteke
	ifstream fin(imeDatoteke); //otvara datoteku za citanje
	cout << "\n\nSadrzaj datoteke:" << endl << endl;
	while (fin.get(pom))
		cout << pom;
	fin.close();
	
	///dodavanje slogova na kraj datoteke
	while (izbor != 0) 
	{
		cout << "\nHoces li da upisujes jos slogova u datoteku (da-1 ili ne-0)?" << endl;
		cin >> izbor;
		if (izbor == 0) break;
		student.upis();
		fout << student.dohvatiIme() << " ";
		fout << student.dohvatiIndex() << endl;

	}
	fout.close();

	//ispisivanje sadrzaja datoteke
	fin.open(imeDatoteke); //otvara datoteku za citanje
	cout << "\n\nSadrzaj datoteke:" << endl << endl;
	while (fin.get(pom))
		cout << pom;
	fin.close();

	cout << endl;
	return 0;
}