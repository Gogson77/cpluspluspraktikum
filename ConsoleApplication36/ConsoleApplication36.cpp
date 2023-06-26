#include <iostream>
using namespace std;

class Brojevi 
{
private:
    int broj1; 
    int broj2;
    
public:
    Brojevi(int b1, int b2);
    void saberi();
    void oduzmi();
    void pomnozi();
    void podijeli();
    void veciBroj();
    void incrPrefiks();
    void decrPostfiks();
    ~Brojevi();
};

Brojevi::Brojevi(int b1, int b2)
{
    broj1 = b1;
    broj2 = b2;
};

    void Brojevi::saberi(){
        int rezultat = broj1 + broj2;
        cout << "Zbir brojeva: " << rezultat << endl;
    };
    void Brojevi::oduzmi(){
        int rezultat = broj1 - broj2;
        cout << "Razlika brojeva: " << rezultat << endl;
    };
    void Brojevi::pomnozi(){
        int rezultat = broj1 * broj2;
        cout << "Proizvod brojeva: " << rezultat << endl;
    };
    void Brojevi::podijeli(){
        if ( broj1 % broj2 == 0 && broj1 != broj2){
            int rezultat = broj1 / broj2;
            cout << "Količnik brojeva: " << rezultat << endl;
        } else {
            int rezultat = broj1 % broj2;
            cout << "Ostatak pri dijeljenju: " << rezultat << endl;
        }
    };
    void Brojevi::veciBroj(){
        int veci = (broj1 > broj2) ? broj1 : broj2;
        cout << "Veci broj: " << veci << endl;
    };
    void Brojevi::incrPrefiks(){
        ++broj1;
        ++broj2;
        cout << "Prefiksno uvecani brojevi: " << broj1 << ", " << broj2 << endl;
    };
    void Brojevi::decrPostfiks(){
        broj1--;
        broj2--;
        cout << "postfiksno smanjeni brojevi: " << broj1 << ", " << broj2 << endl;
    };

Brojevi::~Brojevi() {
    cout << "Kraj programa." << endl;
};

int main()
{
    Brojevi operatori(5,8);
    
    operatori.saberi();
    operatori.oduzmi();
    operatori.pomnozi();
    operatori.podijeli();
    operatori.veciBroj();
    operatori.incrPrefiks();
    operatori.decrPostfiks();

    return 0;
}
