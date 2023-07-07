#include <iostream>

using namespace std;

void main()
{
	int i;
	char cniz[10];
	int iniz[10];
	double dniz[10];
	cout << "\t\t Char \t\t    Int \t   Double \n\n";
	for (i = 0; i < 10; i++)
	{
		cout << "Element " << i + 1 << ". \t " << &cniz[i] << " \t ";
		cout << &iniz[i] << " \t " << &dniz[i] << endl;
	}
	cout << endl;
}
