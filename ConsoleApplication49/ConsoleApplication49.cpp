#include <iostream>
#include <cstring>
using namespace std;

class kPrevoznoSredstvo {
public:
    char pMarka[20];
    int pMaxBrzina;
    kPrevoznoSredstvo(const char* pM, int pMB);
    int fPrevoz();
    ~kPrevoznoSredstvo();
};

kPrevoznoSredstvo::kPrevoznoSredstvo(const char* pM, int pMB) {
    strcpy_s(pMarka, pM);
    pMaxBrzina = pMB;
}

int kPrevoznoSredstvo::fPrevoz() {
    cout << "Ovo je prevozno sredstvo " << pMarka << endl;
    return 0;
}

kPrevoznoSredstvo::~kPrevoznoSredstvo() {
    cout << "Kraj prevoznog sredstva." << endl;
}

class iTeretnoVozilo : public kPrevoznoSredstvo {
public:
    float pNosivost;
    iTeretnoVozilo(const char* pM, int pMB, float pN);
    ~iTeretnoVozilo();
};

iTeretnoVozilo::iTeretnoVozilo(
    const char* pM,
    int pMB,
    float pN) : kPrevoznoSredstvo(pM, pMB) {
    pNosivost = pN;
}

iTeretnoVozilo::~iTeretnoVozilo() { 
    cout << "Kraj teretnog vozila." << endl; };

int main()
{
    return 0;
}
