/*
 * =====================================================================================
 *
 *       Filename:  window.h
 *
 *    Description:  Header file for window.cpp
 *
 *        Version:  1.0
 *        Created:  07/04/14 21:32:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _H_WINDOW_
#define _H_WINDOW_

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
class Window{
	SDL_Window* win;
	SDL_Renderer *ren;

	public:
	Window();
	int init();
	void drawRect();
	TTF_Font* getFont(int s);
	void drawFPS(int);

	SDL_Renderer* get_renderer() const;
	SDL_Window* get_window() const;
};

#endif
