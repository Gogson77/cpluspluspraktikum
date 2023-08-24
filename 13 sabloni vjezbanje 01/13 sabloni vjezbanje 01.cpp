#include <iostream>

using namespace std;

template <class T> 
T myMax(T i, T j) { return i > j ? i : j; }

class Krug {
	double r;

public:
	Krug(double rr=0) : r(rr){}
	double dohvatiR() { return r; }
	void upis() { cout << "Unesi poluprecnik kruga: "; cin >> r; }
	~Krug() {}
};

class Tacka {
	double x, y;

public:
	Tacka(double xx = 0, double yy = 0) : x(xx), y(yy) {}
	void upis() { cout << "Unesi koordinate tacke: "; cin >> x >> y; }
	void pisi() const { cout << "tacka [ " << x << ", " << y << " ]" << endl << endl; }
	double udaljenost() { return x * x + y * y; }
	~Tacka() {}
};

class Pravougaonik {
	double a, b;

public:
	Pravougaonik(double aa = 0, double bb = 0) : a(aa), b(bb) {}
	void upis() { cout << "Unesi duzinu i sirinu pravougaonika: "; cin >> a >> b; }
	void pisi() { cout << "pravougaonik a = " << a << ", b = " << b << endl << endl; }
	double povrsina() { return a * b; }
	~Pravougaonik() {}
};

int main()
{
	int m, n;
	char p, q;
	Tacka A, B, pomt;
	Krug s, t;
	Pravougaonik x, y, pomp;

	//veci od dva cijela broja
	cout << "Unesi dva cijela broja: ";
	cin >> m >> n;
	cout << "Veci broj je " << myMax(m, n) << endl << endl;

	//veci od dva karaktera
	cout << "Unesi dva karaktera: ";
	cin >> p >> q;
	cout << "Veci karakter je " << myMax(p, q) << endl << endl;
	
	//Veci od dvije tacke - udaljenija od koordinatnog pocetka
	cout << "Prva tacka" << endl;
	A.upis();
	cout << "Druga tacka" << endl;
	B.upis();
	if (myMax(A.udaljenost(), B.udaljenost()) == A.udaljenost())
		pomt = A;
	else pomt = B;
	cout << "Udaljenija od koordinatnog pocetka je ";
	pomt.pisi();

	//Veci od dva kruga
	cout << "Prvi krug" << endl;
	s.upis();
	cout << "Drugi krug" << endl;
	t.upis();
	cout << "Veci krug r = " << myMax(s.dohvatiR(), t.dohvatiR()) << endl << endl;

	//Veci od dva pravougaonika
	cout << "Prvi pravougaonik" << endl;
	x.upis();
	cout << "Drugi pravougaonik" << endl;
	y.upis();
	if (myMax(x.povrsina(), y.povrsina()) == x.povrsina())
		pomp = x;
	else pomp = y;
	cout << "Veci je ";
	pomp.pisi();

	return 0;
}
