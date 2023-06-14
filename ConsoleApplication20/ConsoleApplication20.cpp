#include <iostream>
using namespace std;

int main()
{
	typedef enum eSedmica { pon, uto, sri, cet, pet, sub, ned };
	eSedmica dan;
	dan = uto;
	cout << dan << endl;

	return 0;
}