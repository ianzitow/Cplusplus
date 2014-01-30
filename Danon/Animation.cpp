/*
 * Animation.cpp
 *
 *  Created on: 02/06/2013
 *      Author: Ian
 */

#include "Animation.h"

Animation::Animation(std::string filename, int frameTime, int n_sprites) : Sprite(filename) {
	// TODO Auto-generated constructor stub
	this->frameTime = frameTime;
	this->n_sprites = n_sprites;
	this->rect.w = this->surface->w/n_sprites;
	this->rect.h = this->surface->h;
	this->clipRect.x = 0;
	this->clipRect.y = 0;
	this->clipRect.w = rect.w;
	this->clipRect.h = rect.h;
	this->time = 0;
	this->frameSkip = 0;
}

Animation::~Animation() {
	// TODO Auto-generated destructor stub
}

void Animation::update(int dt) {
	time += dt;

	frameSkip = time/frameTime;
	time = time % frameTime;

	clipRect.x += clipRect.w*frameSkip;

	if (clipRect.x >= surface->w) {
		clipRect.x = (clipRect.x - surface->w) % clipRect.w;
	}

	Sprite::clip(clipRect.x, clipRect.y, clipRect.w, clipRect.h);
}

void Animation::setFrame(int frame) {
	clipRect.x += clipRect.w*frame;

	if (clipRect.x > surface->w) {
		clipRect.x = (clipRect.x - surface->w) % surface->w;
	}

	Sprite::clip(clipRect.x, clipRect.y, clipRect.w, clipRect.h);
}

void Animation::setFrameTime(int time) {
	if (time > 0) this->frameTime = time;
}

int Animation::getFrameTime() {
	return this->frameTime;
}

int Animation::getNumSprites() {
	return this->n_sprites;
}
