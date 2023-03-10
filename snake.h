#ifndef SNAKE_H_
#define SNAKE_H_
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <vector>

class Apple;

class Board;
/**
 * This is snake Class
 * It is inherited from sf::Drawable class, so it can override draw function
 */
class Snake : public sf::Drawable {
  /**
   * This is enum that handles the movement direction of a snake
   */
  enum class Direction { UP, RIGHT, DOWN, LEFT };

  /**
   *This is a variable that stores current enum direction of a snake
   */
  Direction currentDirection;
  /**
   * This is a dynamic memory that stores snake segments, every time snake eats
   * an apple segment is added to it
   */
  std::vector<sf::Vector2f> segments;
  /**
   *This is a rectangle shape. It represents one of the snakes segments
   */
  sf::RectangleShape rect;
  /**
   * This is last segment position. It stores the position of the snakes tail,
   * after snake moved. This place is then filled with the new segment.
   */
  sf::Vector2f lastSegmentPosition;

public:
  /// default snake constructor, that generates 3 beggining connected rectangles
  Snake(Snake &&snake) { currentDirection = std::move(snake.currentDirection); }
  Snake();
  /// function that updates a position of all snake tiles. It returns a boolean
  /// that shows if snake hit itsself or not.
  bool update();
  /// function that returns a reference to the head position of a snake
  sf::Vector2f &getHeadPosition();
  /// draws a snake to the target
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  /// checks if snakes head is in the same place as apple. If yes, then change
  /// apple position, and increment score in board
  friend void checkCollision(Snake &snake, Apple &apple, Board &board);
  /**
   *This function prints out a snake elements positions for debugging purposes
   */
  friend std::ostream &operator<<(std::ostream &os, const Snake &snake);
};

#endif
