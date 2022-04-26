#include "options.h"
#include <fstream>

void Options::loadFromFile(std::string filename)
{
    std::fstream file;
    file.open(filename);
    if (!file)
    {
        return;
    }
    file >> windowSizeX;
    file >> windowSizeY;
    file >> snakeSpeed;
}