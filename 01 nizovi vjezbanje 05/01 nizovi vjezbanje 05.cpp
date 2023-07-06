#include <iostream>

using namespace std;

void fStampa(void);

void main()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		cout << "\nIteracija " << i + 1 << ".";
		fStampa();
	}
	cout << endl;
}

void fStampa(void) 
{
	static int x = 0;
	int y = 0;
	cout << " x = " << x++ << ", y = " << y++ << endl;
};