#include "kocka.h"

// Implementacija konstruktora sa argumentima
Kocka::Kocka(double stranica) : a(stranica) {}

// Implementacija metode za dohvatanje atributa
double Kocka::getStranica() const {
    return a;
}

// Implementacija metode za izračunavanje površine
double Kocka::povrsina() const {
    return 6 * a * a;
}

// Implementacija metode za izračunavanje zapremina
double Kocka::zapremina() const {
    return a * a * a;
}

// Implementacija destruktora
Kocka::~Kocka() {}
