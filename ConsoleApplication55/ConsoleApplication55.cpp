#include <iostream>
#include <math.h>

using namespace std;

class kKvadrat {
public:
	float pStranica;
	kKvadrat(float pS) { pStranica = pS; };
	int fIzracunPovrsine() { cout << "Povrsina kvadrata je: " << pow(pStranica,2) << endl; return 0; };
	~kKvadrat() { cout << "Kvadrat je unisten." << endl << endl; };
};

class iKocka : public kKvadrat {
public:
	iKocka(float pS) : kKvadrat(pS) {};
	int fIzracunPovrsine() { cout << "Povrsina kocke je: " << 6 * pow(pStranica, 2) << endl; return 0; };
	~iKocka(){ cout << "Kocka je unistena." << endl << endl; };
};

int main()
{
	kKvadrat oKvadrat(3);
	iKocka oKocka(3);
	oKvadrat.fIzracunPovrsine();
	oKocka.fIzracunPovrsine();
	return 0;
}