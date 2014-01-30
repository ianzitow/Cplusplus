/*
 * Earth.cpp
 *
 *  Created on: 25/05/2013
 *      Author: Ian
 */

#include "Earth.h"
#include "InputManager.h"

Earth::Earth(Sprite *sprite, float x, float y, int hitPoints) : Planet(sprite, x, y, hitPoints) {
	// TODO Auto-generated constructor stub
	this->vx = 0.0;
	this->vy = 0.0;
}

Earth::~Earth() {
	// TODO Auto-generated destructor stub
}

void Earth::update(int dt, float cameraX, float cameraY) {
	this->vx = 0.0;
	this->vy = 0.0;

	float c = 0.3;

	if (InputManager::getInstance()->isKeyPressed(SDLK_d)) {
		this->vx = c*dt;
	} else if (InputManager::getInstance()->isKeyPressed(SDLK_a)) {
		this->vx = -c*dt;
	} else if (InputManager::getInstance()->isKeyPressed(SDLK_s)) {
		this->vy = c*dt;
	} else if (InputManager::getInstance()->isKeyPressed(SDLK_w)) {
		this->vy = -c*dt;
	}

	this->x += this->vx;
	this->y += this->vy;
}

float Earth::getVX() {
	return this->vx;
}

float Earth::getVY() {
	return this->vy;
}
