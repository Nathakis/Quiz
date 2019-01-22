#include <SFML/Graphics.hpp>
#include "Button.h"
#include <iostream>
#include "answer.h"


using namespace std;
using namespace sf;
int frame=0;
bool przyciskApressbool,przyciskBpressbool,przyciskCpressbool,przyciskDpressbool;
bool przyciskArelasebool,przyciskBrelasebool,przyciskCrelasebool,przyciskDrelasebool;
bool polepytaniabool=true;
string wordA;
string wordB;
string wordC;
string wordD;
string tresc_pytania;
string answer;
string punkty_slowo;
int punkty=0;
int nr_pytania=1;





int main()
{
    setlocale(LC_ALL, "");
    sf::RenderWindow window(sf::VideoMode(800, 500), "Quiz");
    window.setVerticalSyncEnabled(true);
    Button polePytania(400,80,700,140,tresc_pytania,100,100,100,100);
    Button przyciskA(400,200,800,50,wordA,100,200,100,100);
    Button przyciskApress(400,200,800,50,wordA,100,100,100,100);
    Button przyciskB(400,275,800,50,wordB,100,200,100,100);
    Button przyciskBpress(400,275,800,50,wordB,100,100,100,100);
    Button przyciskC(400,350,800,50,wordC,100,200,100,100);
    Button przyciskCpress(400,350,800,50,wordC,100,100,100,100);
    Button przyciskD(400,425,800,50,wordA,100,200,100,100);
    Button przyciskDpress(400,425,800,50,wordA,100,100,100,100);
    Button punktyButton(400,480,100,20,punkty_slowo,100,100,100,100);


    while (window.isOpen())
    {
        window.clear();

        ///KOLEJKA ZDARZEN
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();

            if(event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left&&przyciskA.contains(event.mouseButton.x, event.mouseButton.y) == true)
            {
                przyciskApressbool=true;
                przyciskArelasebool=false;
                answer='a';
                if(pytanie(nr_pytania,6)==answer)punkty++;
                nr_pytania++;

            }
            else
            {
                przyciskApressbool=false;
                przyciskArelasebool=true;
            }
            if(event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left&&przyciskB.contains(event.mouseButton.x, event.mouseButton.y) == true)
            {
                przyciskBpressbool=true;
                przyciskBrelasebool=false;
                answer='b';
                if(pytanie(nr_pytania,6)==answer)punkty++;
                nr_pytania++;
            }
            else
            {
                przyciskBpressbool=false;
                przyciskBrelasebool=true;
            }
            if(event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left&&przyciskC.contains(event.mouseButton.x, event.mouseButton.y) == true)
            {
                przyciskCpressbool=true;
                przyciskCrelasebool=false;
                answer='c';
                if(pytanie(nr_pytania,6)==answer)punkty++;
                nr_pytania++;
            }
            else
            {
                przyciskCpressbool=false;
                przyciskCrelasebool=true;
            }
            if(event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left&&przyciskD.contains(event.mouseButton.x, event.mouseButton.y) == true)
            {
                przyciskDpressbool=true;
                przyciskDrelasebool=false;
                answer='d';
                if(pytanie(nr_pytania,6)==answer)punkty++;
                nr_pytania++;
            }
            else
            {
                przyciskDpressbool=false;
                przyciskDrelasebool=true;
            }
        }


        ///POZOSTALE CZYNNOSCI

        punktyButton.setString(punkty_slowo);
        punkty_slowo = to_string(punkty);

        tresc_pytania=pytanie(nr_pytania,1);
        polePytania.setString(tresc_pytania);
        wordA=pytanie(nr_pytania,2);
        wordB=pytanie(nr_pytania,3);
        wordC=pytanie(nr_pytania,4);
        wordD=pytanie(nr_pytania,5);
        przyciskA.setString(wordA);
        przyciskB.setString(wordB);
        przyciskC.setString(wordC);
        przyciskD.setString(wordD);


        frame++;
        if(frame>60)
        {
            frame=0;
        }
        system("cls");
        cout<<frame<<endl;
        cout<<pytanie(nr_pytania,6)<<endl;
        cout<<punkty<<endl;


        ///WYSWIETLANIE NA EKRANIE

        if(przyciskApressbool==true)
        {
            window.draw(przyciskApress);
        }
        if(przyciskArelasebool==true)
        {
            window.draw(przyciskA);
        }
        if(przyciskBpressbool==true)
        {
            window.draw(przyciskBpress);
        }
        if(przyciskBrelasebool==true)
        {
            window.draw(przyciskB);
        }
        if(przyciskCpressbool==true)
        {
            window.draw(przyciskCpress);
        }
        if(przyciskCrelasebool==true)
        {
            window.draw(przyciskC);
        }
        if(przyciskDpressbool==true)
        {
            window.draw(przyciskDpress);
        }
        if(przyciskDrelasebool==true)
        {
            window.draw(przyciskD);
        }
        if(polepytaniabool==true)
        {
            window.draw(polePytania);
        }
        window.draw(punktyButton);
        window.display();
    }

    return 0;
}
