#include "game.h"
#include "options.h"

int main()
{

    Options::getInstance().loadFromFile("options.txt");
    Game *game = new Game;
    game->run();
    delete game;
    return 0;
}