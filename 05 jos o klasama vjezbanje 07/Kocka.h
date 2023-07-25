#ifndef KOCKA_H
#define KOCKA_H

class Kocka {
private:
    double a;

public:
    // Podrazumevani konstruktor
    Kocka() {}

    // Konstruktor sa argumentima
    Kocka(double stranica);

    // Metode za dohvatanje atributa
    double getStranica() const;

    // Metode za izračunavanje površine i zapremine
    double povrsina() const;
    double zapremina() const;

    // Destruktor
    ~Kocka();
};

#endif // KOCKA_H

