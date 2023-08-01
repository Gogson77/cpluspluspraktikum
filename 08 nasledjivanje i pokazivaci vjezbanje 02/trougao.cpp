#include "trougao.h"
#include <iostream>

void Trougao::citaj() {
	cout << "\n\nA?";
	A.citaj();
	cout << "\n\nB?";
	B.citaj();
	cout << "\n\nC?";
	C.citaj();
}

void Trougao::pisi() const {
	cout << "A "; A.pisi();
	cout << "B "; B.pisi();
	cout << "C "; C.pisi();
	cout << "\nO = " << O();
	cout << "\nP = " << P();
	cout << endl;
}
