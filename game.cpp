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
    sf::Text gameOverText;
    sf::Font arial;
    arial.loadFromFile("arial.ttf");
    gameOverText.setString("Score: " + std::to_string(board.getScore()));
    gameOverText.setFont(arial);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setOutlineColor(sf::Color::White);
    gameOverText.setPosition(sf::Vector2f(Options::getInstance().windowSizeX / 4, Options::getInstance().windowSizeY / 4));
    gameOverText.setScale(sf::Vector2f(2, 2));
    window.draw(gameOverText);
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
        gameOverText.setString("Game Over\nScore: " + std::to_string(board.getScore()));
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

            window.draw(gameOverText);
            window.display();
            std::chrono::milliseconds time(4000);
            std::this_thread::sleep_for(time);
            exit(0);
        }
        window.display();
    }
}
