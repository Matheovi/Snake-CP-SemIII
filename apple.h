#ifndef APPLE_H_
#define APPLE_H_
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
class Snake;
class Board;

class Apple : public sf::Drawable
{
    sf::Vector2f position;

public:
	///default constructor, that generates snakes food at random location
    Apple();
	///function, that changes the position of apple to new random position
    void changePosition();
	///draws an apple to the target
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	///function, that checks, if snakes head touched apple
    friend void checkCollision(Snake &snake, Apple &apple, Board &board);
};

#endif
