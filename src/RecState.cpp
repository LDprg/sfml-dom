#include "RecState.hpp"

#include "CicleState.hpp"

void RecState::event(Game &game, sf::Event &event) 
{
    if (event.type == sf::Event::KeyPressed)
        game.changeState(std::make_unique<CircleState>());
}
