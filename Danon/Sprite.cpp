/*
 * Sprite.cpp
 *
 *  Created on: 13/04/2013
 *      Author: Ian
 */

#include "Sprite.h"

Sprite::Sprite(std::string arquivo) {
	// TODO Auto-generated constructor stub
	surface = NULL;
	Sprite::load(arquivo);
	angle = 0;
	scaleX = 1.0;
	scaleY = 1.0;
	surfaceRotoZoom = NULL;
}

Sprite::~Sprite() {
	// TODO Auto-generated destructor stub
	if (surface != NULL) {
		SDL_FreeSurface(surface);
	}
}

void Sprite::load(std::string arquivo) {
	if (surface != NULL) {
		SDL_FreeSurface(surface);
	}
	surface = SDLBase::loadImage(arquivo);
	clipRect.x = 0;
	clipRect.y = 0;
	clipRect.h = surface->h;
	clipRect.w = surface->w;
}

void Sprite::clip(int x, int y, int w, int h) {

	if ((this->clipRect.x != x) || (this->clipRect.y != y) || (this->clipRect.h != h) || (this->clipRect.w != w)) {
		clipRect.x = x;
		clipRect.y = y;
		clipRect.w = w;
		clipRect.h = h;

		if (this->surfaceRotoZoom != NULL) {
			Sprite::rotoZoom(angle, scaleX, scaleY, true);
		}
	}
}

SDL_Rect Sprite::getClip() {
	return clipRect;
}

void Sprite::render(int x, int y) {
	dst.x = x;
	dst.y = y;

	if (this->surfaceRotoZoom != NULL) {
		dst.x += (clipRect.w/2) - (surfaceRotoZoom->w/2);
		dst.y += (clipRect.h/2) - (surfaceRotoZoom->h/2);
		SDLBase::renderSurface(surfaceRotoZoom, NULL, &dst);
	} else {
		SDLBase::renderSurface(surface, &clipRect, &dst);
	}
}

int Sprite::getWidth() {
	return surface->w;
}

int Sprite::getHeight() {
	return surface->h;
}

void Sprite::restore() {
	SDL_FreeSurface(surfaceRotoZoom);
}

void Sprite::rotoZoom(float angle, float scalex, float scaley, bool force) {
	if((this->angle != angle) || (this->scaleX != scalex) || (this->scaleY != scaley) || force == true) {
		if (this->surfaceRotoZoom != NULL) {
			Sprite::restore();
		}

		this->angle = angle;
		this->scaleX = scalex;
		this->scaleY = scaley;

		if ((this->clipRect.x != 0) || (this->clipRect.y != 0) || (this->clipRect.h != this->surface->h) || (this->clipRect.w != this->surface->w)) {
			SDL_Rect clipRectAux = clipRect;
			this->surfaceRotoZoom = SDLBase::clip(surface, &clipRectAux);
			this->surfaceRotoZoom = SDLBase::rotoZoom(this->surfaceRotoZoom, this->angle, this->scaleX, this->scaleY);
		} else {
			this->surfaceRotoZoom = SDLBase::rotoZoom(this->surface, this->angle, this->scaleX, this->scaleY);
		}
	}
}

float Sprite::getScaleX() {
	return scaleX;
}

float Sprite::getScaleY() {
	return scaleY;
}
