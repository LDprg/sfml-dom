#pragma once

#include "Game.hpp"
#include "Gamestate.hpp"

class RecState : public Gamestate
{
public:
    RecState()
        : shape({200.f, 300.f})
    {
        shape.setFillColor(sf::Color::Red);
    }

    void event(Game &game, sf::Event &event) override;

    void update(Game &game) override {}

    void draw(Game &game) override
    {
        game.window.draw(shape);
    }

protected:
    sf::RectangleShape shape;
};