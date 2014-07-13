/*
 * =====================================================================================
 *
 *       Filename:  ball.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/14 19:57:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jerzy Spendel, 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "ball.h"
#include "window.h"
#include "bricks.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL2_gfxPrimitives.h"
#include <iostream>
#include <stdexcept>

SDL_Color* mapRGBA(Uint32 pixel){
	SDL_Color* c = new SDL_Color;
	int i_pixel = pixel;
	int r_m = 0xFF000000;
	int g_m = 0x00FF0000;
	int b_m = 0x0000FF00;
	int a_m = 0x000000FF;
	c->r = (i_pixel & r_m) >> 24;
	c->g = (i_pixel & g_m) >> 16;
	c->b = (i_pixel & b_m) >> 8;
	c->a = i_pixel & a_m;
	return c;
}

Uint32 lower_alpha(Uint32 pixel){
	int alpha = pixel & 0x000000FF;
	alpha = alpha/2;
	return ((pixel & 0xFFFFFF00) | alpha);
}

Ball::Ball(Window* win, BricksManager* bricksM){
	this->bricksM = bricksM;
	this->win = win;
	this->x = 100.0; this->y = 100.0; this->speed = 10;
	this->radius = 10;
	this->texture_width = this->radius*2+2;
	this->texture_height = this->radius*2+2;

	this->prepare_ball_texture();
	this->count_pixels();
	this->s_Vector = SDL_Point{0,-1}; //Per second 100 pixels right, and 100 pixels up
}
void Ball::prepare_ball_texture(){
	SDL_Renderer* ren = this->win->get_renderer();
	SDL_Texture* tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, this->texture_width, this->texture_height);
	SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);
	SDL_SetRenderTarget(ren, tex);
	aacircleRGBA(ren, this->radius, this->radius, this->radius, 0, 255, 0, 255);
	SDL_SetRenderTarget(ren, NULL);

	this->ball_texture = tex;
}

void Ball::count_pixels(){
	SDL_Renderer* ren = this->win->get_renderer();
	int width = this->texture_width; // Width equals height -> square.
	int pitch=width*4;
	Uint32* pixels = new Uint32[width*width];
	SDL_SetRenderTarget(ren, this->ball_texture);
	SDL_RenderReadPixels(ren, NULL, SDL_PIXELFORMAT_RGBA8888, pixels, pitch);
	for(int xx=0;xx<width;xx++){
		for(int yy=0;yy<width;yy++){
			int i = yy*width+xx;
			SDL_Color* c = mapRGBA(pixels[i]);
			if( (int)c->g > 10){ //Let's say rgb(>10,x,y) is enough green (x->0, y->0)
				SDL_Point p;
				p.x = xx; p.y=yy;
				this->balls_points.push_back(p);
			}
		}
	}
	SDL_UpdateTexture(this->ball_texture, NULL, (void*) pixels, pitch);
	SDL_SetRenderTarget(ren, NULL);
	std::cout << this->balls_points.size() << std::endl;

}

void Ball::update(int dt){
	if(dt != 0){
		this->x = this->x+this->s_Vector.x*this->speed*(1/(float)dt);
		this->y = this->y+this->s_Vector.y*this->speed*(1/(float)dt);
		std::cout << "x = " << this->x << std::endl;
	}
	this->check_collision();
}
void Ball::set_speed(int s){
	this->speed = s;
}
void Ball::draw(){
	SDL_Rect r;
	r.x = (int)this->x, r.y=(int)this->y; r.w = this->texture_width; r.h = this->texture_height;
	SDL_RenderCopy(this->win->get_renderer(), this->ball_texture, NULL, &r);
}

void Ball::check_collision(){
	for(int i=0;i<this->bricksM->get_bricks()->size();i++){
		SDL_Rect brick = this->bricksM->get_bricks()->at(i);
		for(int j=0;j<this->balls_points.size();j++){
			SDL_Point p = this->balls_points.at(j);
			if(point_collides_with_rect(this, &p, &brick)){
				throw std::runtime_error("Kolizja");
			}
		}
	}
}

bool point_collides_with_rect(Ball* b, const SDL_Point* p, const SDL_Rect* r){
	SDL_Point p_p{(int)b->x+p->x, (int)b->y+p->y};
	if(p_p.x >= r->x && p_p.x <= r->x + r->w){
		if(p_p.y == r->y+r->h){
			return true;
		}
	}
	return false;
}
