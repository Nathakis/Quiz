#include <iostream>
#include "pytanie.h"
#include <fstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>


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
void Pytanie::zadaj_pytanie(int x, int y)
{
    sf::Font czcionka;
    czcionka.loadFromFile("Bevan.ttf");
    sf::Text trescPytania(tresc_pytania,czcionka);
    trescPytania.setFont(czcionka);
    trescPytania.setCharacterSize(10);
    trescPytania.setFillColor(sf::Color::White);
    trescPytania.setPosition(x,y);
    utworz_przycisk(800,50,odp_a,odp_b,odp_c,odp_d,(x/2-100),(y/2+200));



}

static void Pytanie::utworz_przycisk(int szerokosc,int wysokosc,string odpa,string odpb,string odpc,string odpd,int x, int y)
{
    sf::RectangleShape PrzyciskA(sf::Vector2f(szerokosc,wysokosc));
    PrzyciskA.setFillColor(sf::Color(250,100,100,200));
    PrzyciskA.setOrigin(wysokosc/2,szerokosc/2);
    PrzyciskA.setPosition(x,y);
    sf::Font czcionka;
    czcionka.loadFromFile("Bevan.ttf");
    sf::Text tekst1(odpa,czcionka);
    tekst1.setCharacterSize(10);
    tekst1.setFillColor(sf::Color::White);
    tekst1.setPosition(x,y);

    sf::RectangleShape PrzyciskB(sf::Vector2f(szerokosc,wysokosc));
    PrzyciskB.setFillColor(sf::Color(250,100,100,200));
    PrzyciskB.setOrigin(wysokosc/2,szerokosc/2);
    PrzyciskB.setPosition(x,y);
    sf::Text tekst2(odpb,czcionka);
    tekst2.setCharacterSize(10);
    tekst2.setFillColor(sf::Color::White);
    tekst2.setPosition(x,y+100);

    sf::RectangleShape PrzyciskC(sf::Vector2f(szerokosc,wysokosc));
    PrzyciskC.setFillColor(sf::Color(250,100,100,200));
    PrzyciskC.setOrigin(wysokosc/2,szerokosc/2);
    PrzyciskC.setPosition(x,y);
    sf::Text tekst3(odpc,czcionka);
    tekst3.setCharacterSize(10);
    tekst3.setFillColor(sf::Color::White);
    tekst3.setPosition(x,y+100);

    sf::RectangleShape PrzyciskD(sf::Vector2f(szerokosc,wysokosc));
    PrzyciskD.setFillColor(sf::Color(250,100,100,200));
    PrzyciskD.setOrigin(wysokosc/2,szerokosc/2);
    PrzyciskD.setPosition(x,y);
    sf::Text tekst4(odpd,czcionka);
    tekst4.setCharacterSize(10);
    tekst4.setFillColor(sf::Color::White);
    tekst4.setPosition(x,y+100);


}

void Pytanie::sprawdz_odpowiedz ()
{
    //if(event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)


    if(odpowiedz==poprawna)
    {
        punkt +=1;
    }else punkt+=0;
    nr_pytania+=1;
}

void Pytanie::wyswietl()
{
    sf::window.draw(trescPytania);
    sf::window.draw(PrzyciskA;
    window.draw(PrzyciskB);
    window.draw(PrzyciskC);
    window.draw(PrzyciskD);
}

