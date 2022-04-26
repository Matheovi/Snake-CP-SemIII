#include "apple.h"
#include "functions.h"
#include "options.h"

Apple::Apple() : position(randomInt(0, Options::getInstance().windowSizeX / 10) * 10.f, randomInt(0, (Options::getInstance().windowSizeY - 110) / 10) * 10.f)
{
}

void Apple::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::RectangleShape apple;
    apple.setFillColor(sf::Color::Red);
    apple.setSize(sf::Vector2f(10.f, 10.f));
    apple.setPosition(position);
    target.draw(apple);
}

void Apple::changePosition()
{
    position = sf::Vector2f(randomInt(0, Options::getInstance().windowSizeX / 10) * 10.f, randomInt(0, (Options::getInstance().windowSizeY - 110) / 10) * 10.f);
}
