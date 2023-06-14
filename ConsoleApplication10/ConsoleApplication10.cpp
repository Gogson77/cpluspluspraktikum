#include <iostream>
using namespace std;

class Primjer 
{
public:
	int broj;
	Primjer() {	broj = 0; }
	~Primjer() { cout << "Ja sam destruktor." << endl; }
};

int main() 
{
	Primjer mojPrimjer;
	cout << mojPrimjer.broj << endl;
	return 0;
}