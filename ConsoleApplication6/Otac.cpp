#include "Otac.h"
#include <iostream>

using namespace std;

Otac::Otac() {
	strcpy(ime, "Petar");
	god = 50;	
};

Otac::Otac(int g) {
	god = g;
};

Otac::Otac(int g, char i[30]) {
	god = g;
	strcpy(ime, i);
};

Otac::Otac(char i[30], int g) {
	strcpy(ime, i);
	god = g;
};

Otac::~Otac() {
	cout << "Kraj" << endl;
};
