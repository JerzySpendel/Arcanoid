/*
 * =====================================================================================
 *
 *       Filename:  player.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/07/14 16:09:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "SDL2/SDL.h"
#include "player.h"
#include <iostream>

Player::Player(const Window* window){
	this->window = window;
	this->ren = this->window->get_renderer();
	this->x = 0;
	this->dir = STOP;
}
void Player::draw(){
	SDL_Rect r;
	r.x = this->x;
	r.y = 400;
	r.w = 10;
	r.h = 10;

	SDL_SetRenderDrawColor(this->ren, 255, 0, 0, 255);
	SDL_RenderDrawRect(this->ren, &r);
}

void Player::handle_event(const SDL_Event* e){
	if(e->type == SDL_KEYDOWN){
		if (e->key.keysym.sym == SDLK_RIGHT){
			this->dir = RIGHT;
		}
		else if(e->key.keysym.sym == SDLK_LEFT){
			this->dir = LEFT;
		}
	}
	else if(e->type == SDL_KEYUP){
		this->dir = STOP;
	}
}

void Player::update(int dt){
	switch(this->dir){
		case RIGHT:
			this->x += (int)dt*SPEED;
			break;
		case LEFT:
			this->x -= (int)dt*SPEED;
			break;
	}
}
