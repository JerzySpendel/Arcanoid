/*
 * =====================================================================================
 *
 *       Filename:  player.h
 *
 *    Description:  Class for managing player and display
 *
 *        Version:  1.0
 *        Created:  07/07/14 16:06:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jerzy Spendel, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "SDL2/SDL.h"
#include "window.h"
const double SPEED = 0.2;
enum Direction {
	LEFT=0,
	RIGHT=1,
	STOP=2
};
class Player{
	const Window* window;
	SDL_Renderer* ren;
	int x;
	Direction dir;
	public:

	Player(const Window*);
	void handle_event(const SDL_Event*);
	void draw();
	void update(int);

};
