#pragma once>
#include <string>
using namespace std;

class Index
{
public:
	int broj;
	int godUpisa;
	double prosek;
	string ime;

	Index(int, int, double, string);

	void pokaziPodatke();

	~Index();
};

