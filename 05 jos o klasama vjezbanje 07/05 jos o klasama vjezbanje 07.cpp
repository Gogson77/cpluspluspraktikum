#include <iostream>
#include "kocka.h"

using namespace std;

int main() {
    double stranica;
    Kocka* nizKocki = nullptr;
    int brojKocki = 0;

    while (true) {
        cout << "Unesite duzinu stranice kocke (ili negativan broj za kraj unosa): ";
        cin >> stranica;

        if (stranica < 0)
            break;

        // Alociramo novi prostor za niz kocki
        Kocka* noviNizKocki = new Kocka[brojKocki + 1];

        // Kopiramo postojeće kocke u novi niz
        for (int i = 0; i < brojKocki; i++) {
            noviNizKocki[i] = nizKocki[i];
        }

        // Dodajemo novu kocku na kraj niza
        noviNizKocki[brojKocki] = Kocka(stranica);

        // Oslobađamo staru memoriju
        delete[] nizKocki;

        // Ažuriramo pokazivač na novi niz
        nizKocki = noviNizKocki;

        // Povećavamo broj kocki u nizu
        brojKocki++;
    }

    // Pronalaženje kocke sa najvećom površinom (najmanjom zapreminom)
    double maxPovrsina = 0;
    double minZapremina = nizKocki[0].zapremina();
    int indexNajvecePovrsine = 0;

    for (int i = 0; i < brojKocki; i++) {
        double povrsina = nizKocki[i].povrsina();
        double zapremina = nizKocki[i].zapremina();

        if (povrsina > maxPovrsina) {
            maxPovrsina = povrsina;
            minZapremina = zapremina;
            indexNajvecePovrsine = i;
        }
        else if (povrsina == maxPovrsina && zapremina < minZapremina) {
            minZapremina = zapremina;
            indexNajvecePovrsine = i;
        }
    }

    // Ispis rezultata
    cout << "Kocka sa najvecom povrsinom (i najmanjom zapreminom): " << endl;
    cout << "Duzina stranice: " << nizKocki[indexNajvecePovrsine].getStranica() << endl;
    cout << "Povrsina: " << maxPovrsina << endl;
    cout << "Zapremina: " << minZapremina << endl;

    // Oslobađamo alociranu memoriju
    delete[] nizKocki;

    return 0;
}


/*
Projektovati  klasu za kocku:
	atributi: dužina stranice  a
	metode: konstruktor, dohvatanje atributa, čitanje, pisanje, površina (6*a2), zapremina (a3), 			        destruktor.
Sastaviti glavni program koji:
	pročita dinamički niz kocki
	pronalazi kocku koja ima najveću površinu (najmanju zapreminu) i ispiše rezultat
	ponavlja prethodne korake sve dok se za dužinu niza ne pročita nedozvoljena vrednost

Napomena: Zadatak raditi u tri datoteke.
*/