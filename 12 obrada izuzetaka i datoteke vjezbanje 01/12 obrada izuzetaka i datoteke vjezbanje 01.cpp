#include <iostream>
#include <math.h>

using namespace std;

class Niz {
public:
    Niz() {};
    virtual void izracunaj() {}
    void izuzeci();
    class Negativni {};
    class Veliki {};
    void nula();
    ~Niz() {};
    int vel;
};

void Niz::izuzeci() {
    // ispaljivanje izuzetka klase  kNiz, kako bi se pozvala f-ja  fNula
    if (vel == 0) throw Niz();

    // ispaljivanje izuzetka klase  kNegativni
    if (vel < 0) throw Negativni();

    // ispaljivanje izuzetka tipa string
    if (vel < 10) throw "mali";

    // ispaljivanje izuzetka klase  kVeliki
    if (vel > 100) throw Veliki();
};

void Niz::nula(){
    cout << "Ne postoji niz duzine 0!!!" << endl;
}

class Fibonaci : public Niz {
public:
    Fibonaci() {};
    void izracunaj()
    {
        int i, niz[50];
        niz[0] = niz[1] = 1;
        for (i = 2; i < vel; i++)
            niz[i] = niz[i - 1] + niz[i - 2];
        for (i = 0; i < vel; i++)
            cout << niz[i] << " ";
        cout << endl;
    }
    ~Fibonaci() {};

};

class Kvadrat : public Niz {
public:
    Kvadrat() {};
    int i;
    int niz[50];
    void izracunaj() {
        for (i = 0; i < vel; i++)
            niz[i] = pow(i + 1, 2);
        for (i = 0; i < vel; i++) cout << niz[i] << " ";
        cout << endl;
    }
    ~Kvadrat() {};
};

void greska(void);

int main()
{
    Niz* pok = 0;
    int izbor = 1;
    while (izbor != 0) {
        cout << "\n1-Fibonaci\t2-Kvadratni\t0-Kraj\n" << endl;
        cout << "\nUnesi izbor: ";
        cin >> izbor;

        switch (izbor)
        {
        case 1: pok = new Fibonaci; break;
        case 2: pok = new Kvadrat; break;
        case 0: default: exit(1);
        }

        // ispalivanje izuzetka tipa integer
        if (pok == 0) throw 100;

        // pokušaj hvatanja izuzetaka
        try
        {
            cout << "Unesi broj elemenata niza: ";
            cin >> pok->vel;
            pok->izuzeci();
        }

        // hvatanje izuzetka klase  kNegativni
        catch (Niz::Negativni)
        {
            cout << "Uneli ste negativnu vrednost za duzinu niza!!!" << endl;
        }

        // hvatanje izuzetka tipa string
        catch(char*a)
        {
            cout << "Mali niz!!!" << endl;
        }

        // hvatanje izuzetka klase  kVeliki
        catch (Niz::Veliki) 
        {
            cout << "Veliki niz!!!" << endl;
        }

        // hvatanje izuzetka klase  kNiz  i poziv njene f-je  fNula
        catch (Niz ob) { ob.nula(); }

        catch (int b)
        {
            cout << "Nema memorije!!!" << endl;
            exit(2);
        }
        pok->izracunaj();
    }
    delete pok;

    return 0;
}

/*
U kodu koji ste priložili postoji nekoliko problema i potencijalnih izvora grešaka. Evo nekoliko stvari koje su pogrešno ili nedovoljno riješene:

Deinicijalizacija pokazivača: U funkciji main(), pravite nove instance objekata Fibonaci i Kvadrat, ali isto tako brišete prethodno alocirane objekte samo prije izlaska iz petlje. To može dovesti do curenja memorije. Trebali biste osloboditi memoriju za svaki objekt prije nego što alocirate novi. Idealno bi bilo da odmah oslobodite memoriju prije nego što dinamički alocirate novi objekt.

Manipulacija nizom izvan granica: U funkcijama Fibonaci::izracunaj() i Kvadrat::izracunaj(), koristite petlje koje prolaze kroz vel elemenata niza. Međutim, vel se unosi putem cin nakon što ste već alocirali memoriju za niz. To može dovesti do prekoračenja granica niza i nepredvidivog ponašanja programa.

Brisanje objekta izvan petlje: Brišete objekt nakon završetka petlje. To znači da ćete obrisati samo zadnji objekt alociran u petlji. Svi prethodni objekti bit će curenje memorije. Objekte treba oslobađati odmah nakon korištenja.

Korištenje exit() umjesto return: U funkciji main(), koristite exit() za izlaz iz programa. To će odmah završiti program, a neće omogućiti pravilno oslobađanje resursa i čišćenje memorije. Preporučuje se da umjesto exit() koristite return kako biste pravilno završili izvođenje funkcije main().

Nedefinirane vrijednosti varijabli: U funkcijama Fibonaci::izracunaj() i Kvadrat::izracunaj(), koristite varijable i i niz bez inicijalizacije. To može dovesti do nepredvidivih rezultata.

Nedostatak inicijalizacije varijable vel: U petlji while u funkciji main(), ne inicijalizirate varijablu vel prije nego što je koristite u unosu broja elemenata niza. Ovo može dovesti do nepredvidivog ponašanja programa.

Nedefiniran destruktor u baznoj klasi: Klasa Niz ima destruktor deklariran, ali nema definiciju. Iako trenutno nije potrebno brisati ništa u baznoj klasi, dobra praksa je imati definiciju destruktora ako je deklariran.

Nedefiniran konstruktor u podklasama: Klase Fibonaci i Kvadrat nemaju definirane konstruktore. To može dovesti do neočekivanog ponašanja prilikom stvaranja objekata ovih klasa.

Osim toga, primijetite da koristite funkciju main() umjesto int main(), što može uzrokovati probleme u nekim okruženjima. Također, nema potrebe za #include <math.h> jer niste koristili funkciju math.h biblioteke u kodu.
*/
