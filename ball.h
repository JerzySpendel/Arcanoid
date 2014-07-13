/*
 *
 * =====================================================================================
 *
 *       Filename:  ball.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/14 16:05:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _H_BALL
#define _H_BALL
#include "bricks.h"
#include "window.h"
#include "SDL2/SDL.h"
#include <vector>
SDL_Color* mapRGBA(Uint32 pixel);
Uint32 lower_alpha(Uint32 pixel);

class Ball{
	private:
	float x,y;
	int speed, radius;
	int texture_width, texture_height;
	BricksManager* bricksM;
	Window* win;
	SDL_Texture* ball_texture;
	std::vector<SDL_Point> balls_points;
	SDL_Point s_Vector;

	void prepare_ball_texture();
	void count_pixels();
	friend bool point_collides_with_rect(Ball*, const SDL_Point*, const SDL_Rect*);

	public:
	Ball(Window*, BricksManager*);
	void set_speed(int);
	void draw();
	void update(int);
	void check_collision();
};

#endif
