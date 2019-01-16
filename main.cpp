#include <iostream>
#include "pytanie.h"
int liczba_punktow;
using namespace std;
int main()
{
    setlocale(LC_ALL,"");
    Pytanie p1;
    p1.nr_pytania=1;
    p1.wczytywanie_z_pliku();
    p1.zadaj_pytanie();
    p1.sprawdz_odpowiedz();
    liczba_punktow+=p1.punkt;
    cout<<endl<<liczba_punktow;

    return 0;
}
