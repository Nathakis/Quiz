#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Quiz SFML",sf::Style::Close);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)window.close();
            if(event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))window.close();
            if(event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
            {
                if(shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) == true)
                {
                    shape.setFillColor(sf::Color::White);
                }
            }
            if(event.type==sf::Event::MouseButtonReleased)
            {
                shape.setFillColor(sf::Color::Green);
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
