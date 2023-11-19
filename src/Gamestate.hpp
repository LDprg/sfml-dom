#pragma once

#include <SFML/Graphics.hpp>

class Game;

class Gamestate
{
public:
    virtual void event(Game& game, sf::Event& event) = 0;
    virtual void update(Game& game) = 0;
    virtual void draw(Game& game) = 0;
};