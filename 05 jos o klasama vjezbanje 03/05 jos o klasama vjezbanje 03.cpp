#include <iostream>

using namespace std;

class kPas
{
public:
	void fGovor() const { cout << "Av, av!\n"; }
	void fHod() const { cout << "Krece se...\n"; }
	void fJelo() const { cout << "Glodje kosti...\n"; }
	void fRezanje() const { cout << "Grrrrr\n"; }
};

// pokazivač na funkciju članicu klase
typedef void (kPas::* pokF)() const; 

int main()
{
	const int MaxFunkcija = 4;
	// niz pokazivača na funkciju članicu klase
	pokF PasFunkcija[MaxFunkcija] = 
	{
		&kPas::fGovor,
		&kPas::fHod,
		&kPas::fJelo,
		&kPas::fRezanje
	};
	// pokazivač na klasu
	kPas* pokPas = 0;
	int Metoda;
	bool fKraj = false;
	while (!fKraj)
	{
		cout << "(0)Kraj (1)Govor (2)Hod (3)Jelo (4)Rezanje: ";
		cin >> Metoda;
		if (Metoda == 0) { 
			fKraj = true;
		} else {
			pokPas = new kPas;
			// poziv željene funkcije
			(pokPas->*PasFunkcija[Metoda-1])();
			delete pokPas;
		}
	}
	return 0;
}