#include <iostream>
using namespace std;

class kSisar
{
public:
    kSisar() : pGodine(1) {}
    virtual ~kSisar() {}
    virtual void fGovor() const = 0;
    virtual void fHod() const = 0;

protected:
    int pGodine;
};

class kPas : public kSisar
{
public:
    void fGovor() const { cout << "Av, av!\n"; }
    void fHod() const { cout << "Walking to heel...\n"; }
};

class kMacka : public kSisar
{
public:
    void fGovor() const { cout << "Mijau!\n"; }
    void fHod() const { cout << "slinking...\n"; }
};

class kKonj : public kSisar
{
public:
    void fGovor() const { cout << "Vrrr!\n"; }
    void fHod() const { cout << "Galop...\n"; }
};

int main()
{
    // pokazivac klase
    kSisar* ptr = 0;
    int zivotinja;

    // pokazivac na funkciju clanicu klase
    typedef void (kSisar::* pokF)() const;
    pokF funkcija;

    bool fKraj = false;
    while (!fKraj)
    {
        cout << "(0)Kraj (1)pas (2)macka (3)konj: ";
        cin >> zivotinja;
        // postavljanje pokazivača na željenu klasu
        switch (zivotinja)
        {
        case 1:
            ptr = new kPas;
            break;
        case 2:
            ptr = new kMacka;
            break;
        case 3:
            ptr = new kKonj;
            break;
        default:
            fKraj = true;
            break;
        }
        if (fKraj)
            break;

        cout << "(1)Govor (2)Hod: ";
        cin >> zivotinja;
        // postavljanje pokazivača na željenu funkciju
        switch (zivotinja)
        {
        case 1:
            funkcija = &kSisar::fGovor;
            break;
        default:
            funkcija = &kSisar::fHod;
            break;
        }
        (ptr->*funkcija)(); // poziv željene funkcije, željene klase
    }

    delete ptr; // Oslobađanje resursa

    return 0;
}
