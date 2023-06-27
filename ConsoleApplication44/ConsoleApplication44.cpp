#include <iostream>
using namespace std;

int main()
{
	int x;
	cout << " Brojevi od 1 do 30 koji su deljivi brojem 3: " << endl;
	for (x = 1; x <= 30; x++)
	{
		if (x % 3 != 0)
			continue;
		cout << x << endl;
	}
	return 0;
}