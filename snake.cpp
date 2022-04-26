#include "snake.h"
#include "apple.h"
#include <iostream>
#include "options.h"

Snake::Snake()
    : currentDirection{Direction::RIGHT}
{
    segments.push_back(sf::Vector2f(0, 10.f));
    segments.push_back(sf::Vector2f(0, 20.f));
    segments.push_back(sf::Vector2f(0, 30.f));
}

bool Snake::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && currentDirection != Direction::DOWN)
    {
        currentDirection = Direction::UP;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && currentDirection != Direction::LEFT)
    {
        currentDirection = Direction::RIGHT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && currentDirection != Direction::UP)
    {
        currentDirection = Direction::DOWN;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && currentDirection != Direction::RIGHT)
    {
        currentDirection = Direction::LEFT;
    }
    float dx = 0.f, dy = 0.f;
    switch (currentDirection)
    {
    case Direction::UP:
        dx = 0.f;
        dy = -10.f;
        break;
    case Direction::RIGHT:
        dx = 10.f;
        dy = 0.f;
        break;
    case Direction::DOWN:
        dx = 0.f;
        dy = 10.f;
        break;
    case Direction::LEFT:
        dx = -10.f;
        dy = 0.f;
        break;
    }

    if (segments[0].x < 0)
    {
        segments[0].x = Options::getInstance().windowSizeX - 10.f;
    }
    else if (segments[0].x >= Options::getInstance().windowSizeX)
    {
        segments[0].x = 0;
    }
    else if (segments[0].y < 0)
    {
        segments[0].y = Options::getInstance().windowSizeY * 6 / 7 - 10.f;
    }
    else if (segments[0].y >= Options::getInstance().windowSizeY * 6 / 7)
    {
        segments[0].y = 0;
    }

    //save position of the last element for the extending the snake while eating
    lastSegmentPosition = segments[segments.size() - 1];
    //whole body
    for (unsigned int i = segments.size() - 1; i > 0; --i)
    {
        segments[i].x = segments[i - 1].x;
        segments[i].y = segments[i - 1].y;
    }
    //head
    segments[0].x += dx;
    segments[0].y += dy;

    //check collisions head with body
    for (int i = 1; i < segments.size(); i++)
    {
        if (segments[0] == segments[i])
        {
            std::cout << "ouch\n";
            return true;
        }
    }
    return false;
}

void Snake::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::RectangleShape rect;
    rect.setFillColor(sf::Color::Green);
    rect.setSize(sf::Vector2f(10.f, 10.f));

    for (auto el : segments)
    {
        rect.setPosition(el.x, el.y);
        target.draw(rect, states);
    }
}

std::ostream &operator<<(std::ostream &os, const Snake &snake)
{
    os << ", x: " << snake.segments[0].x << ", y: " << snake.segments[0].y;
    os << std::endl;
    return os;
}