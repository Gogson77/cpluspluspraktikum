#include <iostream>
#include <string>
#include "kTakmicenje.h"
using namespace std;

int main()
{
	kTakmicenje oAtletika("Mika_Peric", 1, 45, 450.80, Ne);
	kTakmicenje oTenis("Vlada_Tadic", 3, 45, 450.80, Ne);
	oAtletika.fNagrada();
	cout << endl;
	oTenis.fNagrada();
 	return 0;
}