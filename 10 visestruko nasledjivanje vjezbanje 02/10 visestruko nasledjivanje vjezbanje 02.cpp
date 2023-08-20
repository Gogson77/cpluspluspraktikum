#include <iostream>

using namespace std;

class kOsoba
{
private:
    int brlicne;
protected:
    int brtel;
public:
    char ime[15];
    kOsoba() {}
    void fUpis()
    {
        cout << "Unesi broj licne karte:";
        cin >> brlicne;
        cout << "Unesi broj telefona:";
        cin >> brtel;
        cout << "Unesi ime:";
        cin >> ime;
    }
    void fIspis() const
    {
        cout << "Broj licne karte:" << brlicne << endl;
        cout << "Broj telefona:" << brtel << endl;
        cout << "Ime:" << ime << endl;
    }
    ~kOsoba() {};
};

class iImenikJavni : public kOsoba
{
public:
    iImenikJavni() {}
    void fUpisivanje() { fUpis(); }
    void fPristupanje() { brtel = 12345; }
    void fIspisivanje() { fIspis(); }
    ~iImenikJavni() {}
};

class iImenikZasticen : protected kOsoba
{
public:
    iImenikZasticen() {}
    void fUpisivanje() { fUpis(); }
    void fPristupanje() { brtel = 12345; }
    void fIspisivanje() { fIspis(); }
    ~iImenikZasticen() {}
};

class iMojJavni : public iImenikJavni
{
public:
    iMojJavni() {}
    void fCitaj() { fUpisivanje(); }
    void fPristup() { brtel = 12345; }
    void fPisi() { fIspisivanje(); }
    ~iMojJavni() {}
};

class iMojZasticen : public iImenikZasticen 
{
public:
    iMojZasticen() {}
    void fCitaj() { fUpisivanje(); }
    void fPristup() { brtel = 12345; }
    void fPisi() { fIspisivanje(); }
    ~iMojZasticen() {}
};

void main()
{
    iMojJavni oMojJavni;
    iMojZasticen oMojZasticen;

    cout << "Unesi ime: ";
    cin >> oMojJavni.ime;
//    cin >> oMojZasticen.ime; // greska

    cout << "Unesi telefona: ";
    //cin >> oMojJavni.brtel; // greska
    //cin >> oMojZasticen.brtel; // greska

    cout << "Unesi broj licne karte: ";
    //cin >> oMojJavni.brlicne; // greska
    //cin << oMojZasticen.brlicne; // greska

}
