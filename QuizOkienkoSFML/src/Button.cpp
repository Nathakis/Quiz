#include "Button.h"
#include <iostream>

using namespace std;

Button::Button(float t_X,float t_Y,float width,float height,string words,int r,int g,int b,int a)
{
    button.setPosition(t_X,t_Y);
    button.setSize({width,height});
    button.setFillColor(sf::Color(r,g,b,a));
    button.setOrigin(width/2,height/2);
    font.loadFromFile("Bevan.ttf");
    text.setString(words);
    text.setCharacterSize(20);
    text.setFont(font);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width/2,textRect.height/2+10);
    text.setFillColor(sf::Color::Black);
    text.setPosition((t_X-width/5),t_Y);
}
void Button::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(this->button,state);
    target.draw(this->text,state);
}
sf::Vector2f Button::getGlobalBounds()
{
    return this->getGlobalBounds();
}
void Button::setFillColor(int r,int g,int b,int a)
{
    this->setFillColor(r,g,b,a);
}
float Button::left()
{
    return this->button.getPosition().x - button.getSize().x/2.f;
}
float Button::right()
{
    return this->button.getPosition().x + button.getSize().x/2.f;
}
float Button::top()
{
    return this->button.getPosition().y - button.getSize().y/2.f;
}
float Button::bot()
{
    return this->button.getPosition().y + button.getSize().y/2.f;
}
sf::Vector2f Button::getPosition()
{
    return this->button.getPosition();
}
sf::Vector2f Button::getSize()
{
    return this->button.getSize();
}
bool Button::contains(float tt_X,float tt_Y)
{
    if(this->button.getGlobalBounds().contains(tt_X,tt_Y))return true;
    else return false;
}
void Button::setString(string word)
{
    text.setString(word);
}
