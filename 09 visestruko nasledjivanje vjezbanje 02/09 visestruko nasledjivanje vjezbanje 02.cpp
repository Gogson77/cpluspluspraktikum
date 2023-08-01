#include <iostream>

using namespace std;

class kOsnovna {};

class kIzvedena : public kOsnovna {};

void f(kOsnovna&);

void main()
{
	kIzvedena oIzvedena;
	kIzvedena* pokIz = &oIzvedena;

	// pokOs = (kOsnovna *) pokIz;
	kOsnovna* pokOs = pokIz;

	// f ( (kOsnovna &) oIzvedena ); 
	f(oIzvedena);
}