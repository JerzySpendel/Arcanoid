/*
 * =====================================================================================
 *
 *       Filename:  Timer.cpp
 *
 *    Description:  Timer implementation
 *
 *        Version:  1.0
 *        Created:  07/05/14 00:59:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "timer.h"
#include "SDL2/SDL.h"

Timer::Timer(int min_diff){
	this->ts1 = SDL_GetTicks();
	this->ts2 = SDL_GetTicks();
	this->min_diff = min_diff;
}
unsigned int Timer::Tick(){
	unsigned int new_ts = SDL_GetTicks();
	unsigned int diff = new_ts - this->ts2;
	if (diff < this->min_diff){
		return 0;
	}
	this->ts1 = this->ts2;
	this->ts2 = new_ts;

	return diff;
}
