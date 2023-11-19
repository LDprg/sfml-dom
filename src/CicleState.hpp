#pragma once

#include "Game.hpp"
#include "Gamestate.hpp"

class CircleState : public Gamestate
{
public:
    CircleState()
        : shape(100.f)
    {
        shape.setFillColor(sf::Color::Green);
    }

    void event(Game &game, sf::Event &event) override;

    void update(Game &game) override {}

    void draw(Game &game) override
    {
        game.window.draw(shape);
    }

protected:
    sf::CircleShape shape;
};