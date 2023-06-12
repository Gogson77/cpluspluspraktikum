#pragma once
#include <iostream>
#include <string>

class Otac
{
public:
	char ime[30];
	int god;

	Otac();
	Otac(int g);
	Otac(int g, char i[30]);
	Otac(char i[30], int g);

	~Otac();
};

