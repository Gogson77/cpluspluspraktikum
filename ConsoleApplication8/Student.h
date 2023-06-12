#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	string ime;
	string prezime;
	string brojIndeksa;
	int godinaUpisa;
public:
	Student();
	Student(string, string, string, int);
	Student(Student &s);

	void prikazPodataka();

	~Student();
};

