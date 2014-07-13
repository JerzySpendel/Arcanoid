/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  File created for teaching myself
 *
 *        Version:  1.0
 *        Created:  07/04/14 20:30:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jerzy Spendel (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "timer.h"
#include "player.h"
#include "bricks.h"
#include "ball.h"
Timer timer{10};
int main(){
	Window* w = new Window();
	Player* p = new Player(w);
	BricksManager* bricksM = new BricksManager(w);
	Ball* b = new Ball(w, bricksM);
	SDL_Event e;

	bool quit = false;
	while(!quit){
		SDL_SetRenderDrawColor(w->get_renderer(), 0,0,0,255);
		SDL_RenderClear(w->get_renderer());

		int diff = timer.Tick();
		while(SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true;
			}
			p->handle_event(&e);
		}
		p->update(diff);
		b->update(diff);
		p->draw();
		bricksM->draw();
		b->draw();

		std::cout << "DIFF: " <<diff << std::endl;
		SDL_RenderPresent(w->get_renderer());
	}
}

