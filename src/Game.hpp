#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "Gamestate.hpp"

class Game
{
    friend Gamestate;

public:
    Game(unsigned int x, unsigned int y, std::string title, Gamestate* gamestate)
        : window(sf::VideoMode(x, y), title)
        //  ,shape2({200, 300})
    {
        // shape2.setFillColor(sf::Color::Red);
        this->gamestate = gamestate;
    }

    ~Game()
    {
        delete gamestate;
    }

    int run()
    {
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                gamestate->event(*this, event);
            }

            gamestate->update(*this);

            window.clear();

            // window.draw(shape2);

            gamestate->draw(*this);

            window.display();
        }
    }

    sf::RenderWindow window;

// protected:
//     sf::RectangleShape shape2;

private:
    Gamestate *gamestate;
};