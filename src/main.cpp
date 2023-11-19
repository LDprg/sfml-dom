#include <memory>

#include "Game.hpp"
#include "CicleState.hpp"
#include "RecState.hpp"

int main()
{
    Game game(800, 600, "SFML", std::make_unique<CircleState>());

    return game.run();
}
