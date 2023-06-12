#include <iostream>
#include "Otac.h"

using namespace std;

int main()
{
	Otac moj;// poziva se konstruktor kOtac( )
	Otac njegov(45);// poziva se konstruktor kOtac (int)
	Otac tvoj(30, "Laza");// poziva se konstruktor kOtac (int, char)
	Otac vas("Mika", 25);// poziva se konstruktor kOtac (char, int)

	cout << moj.ime << " " << moj.god << endl; //Petar, 50
	cout << njegov.god << endl; //45
	cout << tvoj.ime << " " << tvoj.god << endl; //Laza 30
	cout << vas.ime << " " << vas.god << endl; //Mika 25
}