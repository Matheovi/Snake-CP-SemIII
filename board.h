#ifndef BOARD_H_
#define BOARD_H_
#include "snake.h"
#include "apple.h"
#include "options.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <string>

class Board : public sf::Drawable
{
    sf::RectangleShape area;
    sf::Font font;
    sf::Text text;
    sf::Text scoreText;
    int score;

public:
	///default constructor, that generates gui
    Board();
	///draws a gui to the target
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	///function that updates a score to print, and then prints it to the gui
    int drawScore();
	///function that sets a score variable. It takes as an argument a value to replace
    void setScore(int value);
	///function returning score
    int getScore();
	///function that checks if snakes head touches apple
    friend void checkCollision(Snake &snake, Apple &apple, Board &board);
};

#endif
