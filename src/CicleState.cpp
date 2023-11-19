#include "CicleState.hpp"

#include "RecState.hpp"

void CircleState::event(Game &game, sf::Event &event)  
{
    if (event.type == sf::Event::KeyPressed)
        game.changeState(std::make_unique<RecState>());
}
