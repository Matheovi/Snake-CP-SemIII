#ifndef GAME_H_
#define GAME_H_
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "snake.h"
#include "board.h"
#include "apple.h"
#include "options.h"
// -*- lsst-c++ -*-

/**
 *@brief class that runs the game
 */
class Game
{
     /**
     *This is window on which board, snake and apple are displayed as well as score counter and game over screen
     * */
    sf::RenderWindow window;
     /**
     *This is snake object
     *there is only one snake in game so thats why as field in game class
     * */
    Snake snake;
     /**
     *This is board on which snake is drawn
     */
    Board board;
     /**
     *This is an apple. Snake eats apple and grows in size
     */
    Apple apple;
public:
     /**
     * default constructor that creates a window of size specified in options file, and creates all objects that belong to it
     */
    Game();
    /**
    *core function that starts a game
    */
    void run();
};

#endif
