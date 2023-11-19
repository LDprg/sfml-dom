#include "CicleState.hpp"
#include "Game.hpp"

int main()
{
    Game game(800, 600, "SFML", &CircleState());

    return game.run();
}