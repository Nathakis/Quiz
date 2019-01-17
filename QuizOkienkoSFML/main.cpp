#include <SFML/Graphics.hpp>
#include "pytanie.h"
#include <fstream>
#include <iostream>

string bufor,window="window";
int dlugosc_quizu=0;
int nr_pytania=1;
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

    sf::RenderWindow window(sf::VideoMode(1000, 800), "Quiz SFML",sf::Style::Close);

    while (window.isOpen())
    {
        sf::Event event;
        p[nr_pytania-1].zadaj_pytanie(1000,800);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)window.close();
            if(event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))window.close();
            if(event.type==sf::Event::MouseButtonPressed&&event.key.code==sf::Mouse::Left)
            {
            if(PrzyciskA->Pytanie::p[nr_pytania].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) == true)
                {
                    odpowiedz='A';
                    nr_pytania+=1;
                    p[nr_pytania].sprawdz_odpowiedz();
                }
                if(PrzyciskB.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) == true)
                {
                    odpowiedz='B';
                    nr_pytania+=1;
                    p[nr_pytania-1].sprawdz_odpowiedz();
                }
                if(PrzyciskC.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) == true)
                {
                    odpowiedz='C';
                    nr_pytania+=1;
                    p[nr_pytania-1].sprawdz_odpowiedz();
                }
                if(nazwa[4].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) == true)
                {
                    odpowiedz='D';
                    nr_pytania+=1;
                    p[nr_pytania-1].sprawdz_odpowiedz();
                }
            }

        }
        window.clear();
        p[nr_pytania-1].wyswietl();
        window.display();
    }

    return 0;
}
