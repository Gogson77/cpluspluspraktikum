#include <iostream>

using namespace std;

class Y {
public:
	void fPrijateljNijeClan();
};

class X {
	friend void fPrijateljClan(int, X&);
	friend void Y::fPrijateljNijeClan();
	int i;
public:
	void fStavi(int j) { i = j; }
};

void fPrijateljClan(int k, X& ox) {
	ox.i = k;
};

void main()
{
	X ox;
	ox.fStavi(5); 
	fPrijateljClan(6, ox);
}