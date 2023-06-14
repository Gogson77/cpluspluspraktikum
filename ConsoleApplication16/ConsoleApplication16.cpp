#include <iostream>
using namespace std;

int main() 
{
	int cijeliBroj = 97;
	float floatBroj = 2.3;
	double doubleBroj = 2.3456;
	char slovo = 'c';
	
	slovo = 101; cout << slovo << endl;
	floatBroj = slovo; cout << floatBroj << endl;
	doubleBroj = slovo; cout << doubleBroj << endl;
	cout << endl;

	return 0;
}