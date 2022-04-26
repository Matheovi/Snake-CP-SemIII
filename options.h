#ifndef OPT_H_
#define OPT_H_

#include <string>

class Options
{
public:
	///the only way to create a instance of the class
    static Options &getInstance()
    {
        static Options instance; 
                                 
        return instance;
    }

private:
    Options() {}

public:
	///singletons are not copyable
    Options(Options const &) = delete;
	///loading a variables from specific file
    void loadFromFile(std::string filename);
	///singletons are not assignable
    void operator=(Options const &) = delete;
    int windowSizeX;
    int windowSizeY;
    int snakeSpeed;
};
#endif
