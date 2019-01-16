#include <iostream>
#include "pytanie.h"
#include <fstream>
#include <cstdlib>


using namespace std;

void Pytanie::wczytywanie_z_pliku ()
{
    fstream plik;
    plik.open("quiz.txt",ios::in);
    if(plik.good()==false)
    {
        cout<<"B³¹d wczytania pliku";
        exit(0);
    }
    int nr_linii=(nr_pytania-1)*6+1;
    int aktualny_nr_linii=1;
    string linia_tekstu;
    while(getline(plik,linia_tekstu))
    {
        if(aktualny_nr_linii==nr_linii)tresc_pytania=linia_tekstu;
        if(aktualny_nr_linii==nr_linii+1)odp_a=linia_tekstu;
        if(aktualny_nr_linii==nr_linii+2)odp_b=linia_tekstu;
        if(aktualny_nr_linii==nr_linii+3)odp_c=linia_tekstu;
        if(aktualny_nr_linii==nr_linii+4)odp_d=linia_tekstu;
        if(aktualny_nr_linii==nr_linii+5)poprawna=linia_tekstu;
        aktualny_nr_linii++;
    }
    plik.close();
}
void Pytanie::zadaj_pytanie()
{
    cout<<tresc_pytania<<endl;
    cout<<"----------------------------"<<endl;
    cout<<odp_a<<endl;
    cout<<odp_b<<endl;
    cout<<odp_c<<endl;
    cout<<odp_d<<endl<<endl;
    cout<<"Twoja odpowiedz: ";
    cin>>odpowiedz;
}
void Pytanie::sprawdz_odpowiedz ()
{
    if(odpowiedz==poprawna)
    {
        punkt =1;
    }else punkt=0;

}
