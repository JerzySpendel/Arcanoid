/*
 * =====================================================================================
 *
 *       Filename:  bricks.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/14 01:09:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jerzy Spendel, 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _H_BRICKS_
#define _H_BRICKS_

#include <vector>
#include "SDL2/SDL.h"
#include "window.h"
const int BRICK_WIDTH = 50;
const int BRICK_HEIGHT = 20;
class BricksManager{
	Window* win;
	std::vector<SDL_Rect> bricks;

	public:
	BricksManager(Window*);
	std::vector<SDL_Rect>* get_bricks();
	void draw();
};
#endif
