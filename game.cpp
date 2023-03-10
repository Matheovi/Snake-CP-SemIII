#include "game.h"
#include "options.h"
#include <chrono>
#include <thread>

Game::Game() : window(sf::VideoMode(Options::getInstance().windowSizeX, Options::getInstance().windowSizeY), "Snake")
{
    window.setFramerateLimit(Options::getInstance().snakeSpeed);
}

void Game::run()
{
    sf::Text scoreText;
    sf::Font arial;
    arial.loadFromFile("arial.ttf");
    scoreText.setString("Score: " + std::to_string(board.getScore()));
    scoreText.setFont(arial);
    scoreText.setFillColor(sf::Color::Red);
    scoreText.setOutlineColor(sf::Color::White);
    scoreText.setPosition(sf::Vector2f(Options::getInstance().windowSizeX / 4, Options::getInstance().windowSizeY / 4));
    scoreText.setScale(sf::Vector2f(2, 2));
    window.draw(scoreText);
    bool gameOver = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (snake.update())
        {
            gameOver = true;
        }
        checkCollision(snake, apple, board);
        scoreText.setString("Game Over\nScore: " + std::to_string(board.getScore()));
        window.clear();
        if (!gameOver)
        {
            std::cout << snake;
            window.draw(board);
            window.draw(snake);
            window.draw(apple);
        }
        else
        {

            window.draw(scoreText);
            window.display();
            std::chrono::milliseconds time(4000);
            std::this_thread::sleep_for(time);
            exit(0);
        }
        window.display();
    }
}
