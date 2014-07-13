/*
 * =====================================================================================
 *
 *       Filename:  window.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/04/14 21:34:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "window.h"
#include "timer.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include "boost/filesystem.hpp"
namespace fs = boost::filesystem;
extern "C" Timer timer;
Window::Window(){
	if(this->init() != 0){
		std::cout << "Quitting..." << std::endl;
		SDL_Quit();
	}
}
int Window::init(){
	this->win = nullptr;
	this->ren = nullptr;

	if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
		std::cout << SDL_GetError() << std::endl;
	}

	this->win = SDL_CreateWindow("Hello World", 100,100, 640, 480, SDL_WINDOW_SHOWN);

	if(this->win == nullptr){
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}
	this->ren = SDL_CreateRenderer(this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(this->ren == nullptr){
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}
	if(TTF_Init() == -1){
		std::cout << "Cannot init TTF" << std::endl;
		std::cout << TTF_GetError() << std::endl;
	}
	return 0;
}
void Window::drawRect(){
	SDL_RenderClear(this->ren);
	SDL_SetRenderDrawColor(this->ren, 255, 0, 0, 255);
	SDL_Rect r;
	r.x = 50;
	r.y = 50;
	r.w = 50;
	r.h = 0;

	SDL_RenderDrawRect(this->ren, &r);
	SDL_RenderPresent(this->ren);
	SDL_Delay(5000);
	SDL_DestroyWindow(this->win);
	SDL_Quit();
}
void Window::drawFPS(int diff){
	if (diff == 0){
		return;
	}
	SDL_RenderClear(this->ren);
	SDL_Surface* win_s = SDL_GetWindowSurface(this->win);
	TTF_Font* font = this->getFont(50);
	SDL_Color color{255,0,0};
	SDL_Surface* surf = TTF_RenderText_Blended(font, std::to_string(1000/diff).c_str(), color);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(this->ren, surf);
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);

	SDL_Rect dest;
	dest.x =0; dest.y = 0; dest.w = 100; dest.h=100;
	SDL_RenderCopy(this->ren, tex, NULL,&dest);
	SDL_RenderPresent(this->ren);
	SDL_DestroyTexture(tex);

}
TTF_Font* Window::getFont(int s){
	fs::path font_path = fs::path(fs::current_path()) / fs::path("gtw.ttf");
	TTF_Font* font = nullptr;
	font = TTF_OpenFont(font_path.c_str(), s);
	if (font == nullptr){
		throw std::runtime_error(TTF_GetError());
	}
	return font;
}

SDL_Renderer* Window::get_renderer() const{
	return this->ren;
}

SDL_Window* Window::get_window() const{
	return this->win;
}
