#include "Game.hpp"
#include "CicleState.hpp"
#include "RecState.hpp"

int main()
{
    Game game(800, 600, "SFML", new CircleState);

    return game.run();
}
