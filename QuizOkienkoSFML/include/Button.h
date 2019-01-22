#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Button : public sf::Drawable, sf::Transformable
{
    public:
        Button(float t_X,float t_Y,float width,float height,string words,int r,int g,int b,int a);
        Button()=delete;
        ~Button()=default;
    sf::Vector2f getGlobalBounds();
    bool contains(float tt_X,float tt_Y);
    void setFillColor(int r,int g,int b,int a);
    float left();
    float right();
    float top();
    float bot();
    sf::Vector2f getSize();
    sf::Vector2f getPosition();
    void setString(string word);



    protected:

    private:
    void draw(sf::RenderTarget& target,sf::RenderStates state) const override;
    sf::RectangleShape button;
    sf::Text text;
    sf::Font font;


};

#endif // BUTTON_H
