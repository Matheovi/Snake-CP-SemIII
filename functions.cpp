#include "functions.h"
#include "snake.h"
#include "apple.h"
#include "board.h"
int randomInt(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);

    return dist(gen);
}

void checkCollision(Snake &snake, Apple &apple, Board &board)
{
    if (snake.segments[0] == apple.position)
    {
        apple.changePosition();
        snake.segments.push_back(snake.lastSegmentPosition);
        board.setScore(++board.score);
    }
}
