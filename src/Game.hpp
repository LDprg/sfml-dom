#pragma once

#include <string>

#include <SFML/Graphics.hpp>

class Game
{
public:
    Game(unsigned int x, unsigned int y, std::string title)
        : window(sf::VideoMode(x, y), title),
          shape(100.f),
          shape2({200, 300})
    {
        shape.setFillColor(sf::Color::Green);
        shape2.setFillColor(sf::Color::Red);
    }

    int run()
    {
        while (window.isOpen())
        {
            static bool space = false;

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed)
                    if (event.key.code == sf::Keyboard::Space)
                        space = !space;
            }

            window.clear();

            if (space)
                window.draw(shape);
            else
                window.draw(shape2);

            window.display();
        }
    }

protected:
    sf::RenderWindow window;

    sf::CircleShape shape;
    sf::RectangleShape shape2;
};