#include "board.h"
#include "game.h"
#include <iostream>
#include "options.h"
Board::Board() : area(sf::Vector2f(Options::getInstance().windowSizeX * 10.f, (Options::getInstance().windowSizeY / 7))), score(0)
{

    float X = Options::getInstance().windowSizeX;
    float Y = Options::getInstance().windowSizeY;
    float guiYPosition = Y * 6 / 7;
    float snakeSignYPosition = guiYPosition + 3.f;

    area.setPosition(sf::Vector2f(0, guiYPosition));
    area.setFillColor(sf::Color::Cyan);
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "error loading a font"
                  << "\n";
    }
    else
    {
        text.setFont(font);
        text.setPosition(sf::Vector2f(5, snakeSignYPosition));
        text.setString("SNAKE");
        text.setFillColor(sf::Color::Red);
        scoreText.setFont(font);
        scoreText.setString(std::to_string(score));
        scoreText.setFillColor(sf::Color::Magenta);
        scoreText.setPosition(sf::Vector2f(X - 50.f, snakeSignYPosition));
    }
}

void Board::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(area, states);
    target.draw(text, states);
    target.draw(scoreText, states);
}

void Board::setScore(int value)
{
    score = value;
    scoreText.setString(std::to_string(score));
}
int Board::getScore()
{
    return score;
}