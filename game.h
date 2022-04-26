#ifndef GAME_H_
#define GAME_H_
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "snake.h"
#include "board.h"
#include "apple.h"
#include "options.h"

class Game
{
    sf::RenderWindow window;
    Snake snake;
    Board board;
    Apple apple;
public:
	///default constructor that creates a window of size specified in options file, and creates all objects that belong to it
    Game();
	///core function that starts a game
    void run();
};

#endif
