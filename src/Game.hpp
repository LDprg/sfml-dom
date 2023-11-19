#pragma once

#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Gamestate.hpp"

class Game
{
    friend Gamestate;

public:
    Game(unsigned int x, unsigned int y, std::string title, std::unique_ptr<Gamestate> gamestate)
        : window(sf::VideoMode(x, y), title)
    {
        changeState(std::move(gamestate));
    }

    void changeState(std::unique_ptr<Gamestate>&& gamestate)
    {
        this->gamestate.swap(gamestate);
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
    std::unique_ptr<Gamestate> gamestate;
};
