all:
	g++ -c main.cpp game.cpp snake.cpp board.cpp functions.cpp apple.cpp options.cpp
	g++ main.o snake.o game.o board.o functions.o apple.o options.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app
