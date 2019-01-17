#include <iostream>
#include <SFML/Graphics.hpp>

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
    string odpA="odpA",odpB="odpB",odpC="odpC",odpD="odpD";
    sf::RectangleShape PrzyciskA;

    void wczytywanie_z_pliku ();
    void zadaj_pytanie (int x, int y);
    void sprawdz_odpowiedz ();
    static void utworz_przycisk(int szerokosc,int wysokosc,string odpa,string odpb,string odpc,string odpd,int x, int y);
    void wyswietl();

};
