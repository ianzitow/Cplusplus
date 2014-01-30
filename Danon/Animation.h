/*
 * Animation.h
 *
 *  Created on: 02/06/2013
 *      Author: Ian
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "Sprite.h"

class Animation: public Sprite {
private:
	int n_sprites;
	int time;
	int frameSkip;
	int frameTime;
	SDL_Rect clipRect;
	struct Rect {
		int w, h;
	} rect;
public:
	Animation(std::string filename, int frameTime, int n_sprites);
	virtual ~Animation();
	void update(int dt);
	void setFrame(int frame);
	void setFrameTime(int time);
	int getFrameTime();
	int getNumSprites();
};

#endif /* ANIMATION_H_ */
