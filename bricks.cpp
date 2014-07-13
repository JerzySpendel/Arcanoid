/*
 * =====================================================================================
 *
 *       Filename:  bricks.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/14 13:25:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "bricks.h"
#include <iostream>
BricksManager::BricksManager(Window* win){
	this->win = win;
	int width,height;
	SDL_GetWindowSize(this->win->get_window(),&width,&height);

	for(int x=0; x<width; x+= BRICK_WIDTH){
		SDL_Rect r;
		r.x = x; r.w=BRICK_WIDTH; r.h=BRICK_HEIGHT; r.y=0;
		std::cout << x << std::endl;
		this->bricks.push_back(r);
	}
}

std::vector<SDL_Rect>* BricksManager::get_bricks(){
	return &(this->bricks);
}

void BricksManager::draw(){
	SDL_Renderer* ren = this->win->get_renderer();
	SDL_SetRenderDrawColor(ren, 0,0,255,255);
	for(int i=0;i<this->bricks.size();i++){
		SDL_Rect r = this->bricks.at(i);
		SDL_RenderDrawRect(ren, &r);
	}
}
