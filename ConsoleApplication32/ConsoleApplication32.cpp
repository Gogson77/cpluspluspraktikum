#include <iostream>
#include <string.h>
#include "kRadnik.h"
using namespace std;

int main()
{
	kRadnik oCistacica("Miric", "Milica", 1.545, 15, 200);
	kRadnik oDirektor("Peric", "Petar", 5.256,25,150);
	cout << "CISTACICA:" << endl;
	oCistacica.fPlata();
	oCistacica.fIsplata();
	cout << "DIREKTOR:" << endl;
	oDirektor.fPlata();
	oDirektor.fIsplata();
	return 0;
}
