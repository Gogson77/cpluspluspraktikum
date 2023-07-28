#include <iostream>

using namespace std;

class kKomplex {
	float realni, imag;
public:
	kKomplex(float r = 0, float i = 0) { realni = r; imag = i; };
	// c = a + b
	friend kKomplex operator + (kKomplex pom1, kKomplex pom2); 
	// a += b
	kKomplex& operator += (kKomplex pom);
	void fPisi() { cout << " = " << realni << " + " << imag << "i" << endl; }
	~kKomplex() {};
};

kKomplex operator + (kKomplex prvi, kKomplex drugi)
{
	kKomplex zbir;
	zbir.realni = prvi.realni + drugi.realni;
	zbir.imag = prvi.imag + drugi.imag;
	return zbir;
}

inline kKomplex& kKomplex::operator += (kKomplex pom) {
	realni += pom.realni;
	imag += pom.imag;
	return* this;
}

int main()
{
	kKomplex a(1, 3);
	kKomplex b(2, 5);
	kKomplex c;
	kKomplex d;
	kKomplex e;
	float x = 3.14;
	cout << "x = " << x << endl;
	cout << "a";
	a.fPisi();
	cout << "b";
	b.fPisi();
	cout << "c";
	c.fPisi();
	cout << "d";
	d.fPisi();
	cout << "e";
	e.fPisi();
	cout << endl << endl;

	c = a + kKomplex(b);
	cout << "c = a + b";
	c.fPisi();
	cout << endl;

	d = x + kKomplex(a);
	cout << "d = x + a";
	d.fPisi();
	cout << endl;

	e += x;
	cout << "e = e + x";
	e.fPisi();
	cout << endl;

	return 0;
}