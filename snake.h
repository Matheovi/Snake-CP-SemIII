#ifndef SNAKE_H_
#define SNAKE_H_
#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

class Apple;

class Board;

class Snake : public sf::Drawable
{
    enum class Direction
    {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };
    Direction currentDirection;
    std::vector<sf::Vector2f> segments;
    sf::RectangleShape rect;
    sf::Vector2f lastSegmentPosition;

public:
    ///default snake constructor, that generates 3 beggining connected rectangles
    Snake(Snake &&snake)
    {
        currentDirection = std::move(snake.currentDirection);
    }
    Snake();
    ///function that updates a position of all snake tiles. It returns a boolean that shows if snake hit itsself or not.
    bool update();
    ///function that returns a reference to the head position of a snake
    sf::Vector2f &getHeadPosition();
    ///draws a snake to the target
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    ///checks if snakes head is in the same place as apple. If yes, then change apple position, and increment score in board
    friend void checkCollision(Snake &snake, Apple &apple, Board &board);
    friend std::ostream &operator<<(std::ostream &os, const Snake &snake);
};

#endif
