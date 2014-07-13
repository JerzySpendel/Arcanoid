all: teach

teach: main.o timer.o window.o player.o bricks.o ball.o
	g++ main.o timer.o window.o player.o bricks.o ball.o -o arcanoid -lSDL2 -lSDL2_ttf -lSDL2_gfx -lboost_system -lboost_filesystem

main.o: main.cpp
	g++ -c main.cpp -I/usr/include/SDL2 -lSDL2 -std=c++11

window.o: window.cpp
	g++ -c window.cpp -I/usr/include/SDL2 -lSDL2 -lSDL2_ttf -lboost_system -lboost_filesystem -std=c++11

timer.o: timer.cpp
	g++ -c timer.cpp -I/usr/include/SDL2 -lSDL2 -std=c++11

player.o: player.cpp
	g++ -c player.cpp -I/usr/include/SDL2 -lSDL2 -std=c++11

bricks.o: bricks.cpp
	g++ -c bricks.cpp -I/usr/include/SDL2 -lSDL2 -std=c++11

ball.o: ball.cpp
	g++ -c ball.cpp -I/usr/include/SDL2 -lSDL2 -lSDL2_gfx -std=c++11
clean:
	rm -rf *.o
