/*
 * Sprite.h
 *
 *  Created on: 13/04/2013
 *      Author: Ian
 */

#include "SDLBase.h"

#ifndef SPRITE_H_
#define SPRITE_H_

class Sprite {
protected:
	SDL_Surface *surface;
	SDL_Rect clipRect, dst;
	SDL_Surface *surfaceRotoZoom;
	float angle;
	float scaleX, scaleY;
public:
	Sprite(std::string arquivo);
	virtual ~Sprite();
	void update(int dt);
	void load(std::string arquivo);
	void clip(int x, int y, int w, int h);
	SDL_Rect getClip();
	int getWidth();
	int getHeight();
	void render(int x, int y);
	void restore();
	void rotoZoom(float angle, float scalex = 1.0f, float scaley = 1.0f, bool force = false);
	float getScaleX();
	float getScaleY();
};

#endif /* SPRITE_H_ */
