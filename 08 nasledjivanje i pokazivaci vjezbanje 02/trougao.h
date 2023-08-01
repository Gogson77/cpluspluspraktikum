#pragma once
#include "tacka.h"
#include <math.h>

class Trougao {
	Tacka A, B, C;
public:
	Trougao(
		Tacka AA=Tacka(-1,-1),
		Tacka BB=Tacka(1,-1),
		Tacka CC=Tacka(0,1)
	) {
		A = AA;
		B = BB;
		C = CC;
	};
	Tacka dohvati_A()const { return A; }
	Tacka dohvati_B()const { return B; }
	Tacka dohvati_C()const { return C; }
	double a() const { return rastojanje(B, C); }
	double b() const { return rastojanje(A, C); }
	double c() const { return rastojanje(A, B); }
	double O() const { return a() + b() + c(); }
	double P() const {
		double s = O() / 2;
		return ( sqrt( s*( s-a())*(s-b())*(s-c()) ));
	};
		void citaj();
		void pisi()const;
	~Trougao() {};
};


