#include <iostream>
using namespace std;

class kKvadrat
{
private:
	int pStrana;
public:
	kKvadrat() { pStrana = 5; }
	void fPostavi(int pStr) { pStrana = pStr; }
	int fUzmi() const { return pStrana; }
	~kKvadrat() { }
};

void main()
{
	kKvadrat* oKvadrat = new kKvadrat;
	const kKvadrat* oConstKvadrat = new kKvadrat;
	kKvadrat* const oConstPokKvadrat = new kKvadrat;

	cout << "Strana oKvadrat: " << oKvadrat->fUzmi() << endl;
	cout << "Strana oConstKvadrat: " << oConstKvadrat->fUzmi() << endl;
	cout << "Strana oConstPokKvadrat: " << oConstPokKvadrat->fUzmi() << endl << endl;

	oKvadrat->fPostavi(10);
	//	oConstKvadrat -> fPostavi (10);
	oConstPokKvadrat->fPostavi(10);

	cout << "Strana oKvadrat: " << oKvadrat->fUzmi() << endl;
	cout << "Strana oConstKvadrat: " << oConstKvadrat->fUzmi() << endl;
	cout << "Strana oConstPokKvadrat: " << oConstPokKvadrat->fUzmi() << endl << endl;
}