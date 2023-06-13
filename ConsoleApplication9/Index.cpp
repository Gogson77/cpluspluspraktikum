#include <iostream>
#include "Index.h"

using namespace std;

Index::Index(int b, int gu, double p, string i)
{
	broj = b;
	godUpisa = gu;
	prosek = p;
	ime = i;
}

void Index::pokaziPodatke() 
{
	cout << "Broj: " << broj << ", Godina upisa: " << godUpisa << ", prosek: " << prosek << ", ime: " << ime << endl;
};

Index::~Index() 
{
	cout << "Defaultni desktruktor" << endl;
}