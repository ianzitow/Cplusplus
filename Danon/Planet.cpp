/*
 * Planet.cpp
 *
 *  Created on: 21/04/2013
 *      Author: Ian
 */

#include "Planet.h"

Planet::Planet(Sprite *sprite, float x, float y, int hitPoints) : GameObject(x, y, sprite->getWidth(), sprite->getHeight()) {
	// TODO Auto-generated constructor stub
	this->sprite = sprite;
	this->hitPoints = hitPoints;
	//this->x = x;
	//this->y = y;
}

Planet::~Planet() {
	// TODO Auto-generated destructor stub
}

void Planet::render(float cameraX, float cameraY) {
	if(sprite != NULL) {
		this->sprite->render(this->getX() - cameraX, this->getY() - cameraY);
	}
}

int Planet::getHitPoints() {
	return this->hitPoints;
}

int Planet::getRadius() {
	return (this->sprite->getScaleX())*this->sprite->getWidth()/2;
}
