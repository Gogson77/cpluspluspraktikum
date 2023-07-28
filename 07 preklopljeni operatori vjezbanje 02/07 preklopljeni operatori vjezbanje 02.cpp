#include <iostream>
using namespace std;

class kKomplex {
	float realni, imag;
public:
	kKomplex(float r = 0, float i = 0) { realni = r; imag = i; };
	
	kKomplex operator++(); 
	kKomplex operator++(int i);
	kKomplex operator--();
	kKomplex operator--(int i);
	void fPisi() { cout << "Re = " << realni << " Im = " << imag << endl; }

	~kKomplex() {};
};

inline kKomplex kKomplex :: operator++() {
	++realni;
	return *this;
};

inline kKomplex kKomplex :: operator++(int i) {
	kKomplex z = *this;
	realni++;
	imag += i;
	return z;
};

inline kKomplex kKomplex :: operator--() {
	--realni;
	return *this;
}

inline  kKomplex kKomplex :: operator--(int i) {
	kKomplex z = *this;
	realni--;
	imag -= i;
	return z;
}

void main()
{
	kKomplex x(1, 3);
	cout << "Vrednost za x: ";
	x.fPisi();
	cout << endl;

	kKomplex a = ++x;		//a = ++ x = 2 + 3*i
	cout << "Vrednost za a: ";
	a.fPisi();				// a = 2 + 3*i
	cout << "Vrednost za x: ";
	x.fPisi();				// x = 2 + 3*i
	cout << endl;

	kKomplex b = x++;		// b = x ++ = 2 + 3*i
	cout << "Vrednost za b: ";
	b.fPisi();				// b = 2 + 3*i
	cout << "Vrednost za x: ";
	x.fPisi();				// x = 3 + 3*i
	cout << endl;

	kKomplex c = x.operator ++ (2);	// poziva se funkcija  kKomplex operator ++ (int i)
	cout << "Vrednost za c: ";
	c.fPisi();				// c = x = 3 + 3*i 
	cout << "Vrednost za x: ";
	x.fPisi();				// x = x + 1 + 2*i = 3 + 3*i +1 + 2*i = 4 + 5*i
	cout << endl;

	kKomplex d = --x; 	// poziva se funkcija kKomplex operator -- ( )  tj. d = -- x = 3 + 5*i
	cout << "Vrednost za x: ";
	x.fPisi();			// x = 3 + 5*i
	cout << "Vrednost za d: ";
	d.fPisi();			// d = 3 + 5*i
	cout << endl;

	kKomplex e = x--;		// e = x -- = 3 + 5*i
	cout << "Vrednost za e: ";
	e.fPisi();			// e = 3 + 5*i
	cout << "Vrednost za x: ";
	x.fPisi();			// x = 2 + 5*i
	cout << endl;

	kKomplex f = x.operator -- (2);	// poziva se funkcija  kKomplex operator -- (int i)
	cout << "Vrednost za f: ";
	f.fPisi();				// f = x = 2 + 5*i
	cout << "Vrednost za x: ";
	x.fPisi();				// x = x –1 – 2*i = 2 + 5*i – 1 – 2*i = 1 + 3*i
	cout << endl;



}