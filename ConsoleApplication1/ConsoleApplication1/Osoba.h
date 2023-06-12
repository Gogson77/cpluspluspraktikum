#pragma once
#include <iostream>
#include <string>

using namespace std;

class Osoba 
{
private:
    string ime;
    string prezime;
    string matBroj;
    string mesto;

public:
    Osoba();
    Osoba(string, string, string, string);
    Osoba(Osoba& s);

    void prikazPodataka();
    void mestoBoravka();
    
    ~Osoba();
};