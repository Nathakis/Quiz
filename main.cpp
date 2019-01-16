#include <iostream>
#include "pytanie.h"
#include <fstream>
#include <cstdlib>
int liczba_punktow=0;
int dlugosc_quizu=0;
string bufor;
using namespace std;
int main()
{
    setlocale(LC_ALL,"");
    Pytanie *p;
    fstream plik;
    plik.open("quiz.txt",ios::in);
    while(getline(plik,bufor))
    {
        dlugosc_quizu++;
    }
    dlugosc_quizu/=6;
    p = new Pytanie [dlugosc_quizu];
    for(int i=0;i<dlugosc_quizu;i++)
{
    cout<<endl<<"\t\t\t\t\t\t\t\t||LICZBA PUNKTÓW: "<<liczba_punktow<<" ||"<<endl<<"\t\t\t\t\t\t\t\t======================"<<endl;
    p[i].nr_pytania=i+1;
    p[i].wczytywanie_z_pliku();
    p[i].zadaj_pytanie();
    p[i].sprawdz_odpowiedz();
    liczba_punktow+=p[i].punkt;
    system("cls");
}
    delete[] p;
    return 0;
}
