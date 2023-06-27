#include <iostream>
using namespace std;

int main()
{
	int stepen, max;
	cout << "Unesi gornju granicu :" << endl;
	cin >> max;
	stepen = 1;
	do
	{
		cout << stepen << endl;
		stepen *= 2;
	} while (stepen <= max);
	return 0;

	/*
	int x, p;
	x = p = 1;
	while (x < 10)
	{
		p *= x;
		x++;
		cout << "proizvod je: " << p << endl;
	}
	return 0;*/

}