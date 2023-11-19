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
    {
        changeState(gamestate);
    }

    ~Game()
    {
        delete gamestate;
    }

    void changeState(Gamestate* gamestate)
    {
        delete this->gamestate;
        this->gamestate = gamestate;
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

            gamestate->draw(*this);

            window.display();
        }
    }

    sf::RenderWindow window;

private:
    Gamestate *gamestate;
};
