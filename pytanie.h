#include <iostream>

using namespace std;

class Pytanie
{
public:

    string tresc_pytania;
    string odp_a,odp_b,odp_c,odp_d;
    int nr_pytania;
    string poprawna;
    string odpowiedz;
    int punkt;

    void wczytywanie_z_pliku ();
    void zadaj_pytanie ();
    void sprawdz_odpowiedz ();

};
