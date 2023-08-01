#include <iostream>

using namespace std;

class kAlfa {
	int a;
public:
	int b;
	void fStavi(int x) { a = b; }
};

class kBeta : public kAlfa {
	int c;
public:
	void fSmesti(int x, int y, int z) 
	{
		c = x;
		b = y;
		fStavi(z);	
	}
};

class kGama : kAlfa {
	int b, c;
public:
	void fSmesti(int x, int y, int z) 
	{
		c = x;
		b = y;
		kAlfa::b = y;
		fStavi(z);
	}
};

int main()
{
	kAlfa oAlfa;
	kBeta oBeta;
	kGama oGama;
	oAlfa.b = 55;
	oBeta.b = 55;

	// GRESKA: U klasi  kGama  clan  b  je privatni član
	//oGama.kAlfa::b = 55; 

	oAlfa.fStavi(23);
	oBeta.fStavi(23);

	// GRESKA: U klasi  kGama  je privatna funkcija
	//oGama.fStavi(23);

	oGama.fSmesti(10,55,23);
}