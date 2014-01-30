/*
 * Moon.cpp
 *
 *  Created on: 25/05/2013
 *      Author: Ian
 */

#include "Moon.h"

Moon::Moon(Sprite *sprite, int hitPoints, Planet *center) : Planet(sprite, center->getX(), center->getY(), hitPoints) {
	// TODO Auto-generated constructor stub
	this->angle = 0.0;
	this->radius = center->getRadius();
	this->center = center;
}

Moon::~Moon() {
	// TODO Auto-generated destructor stub
}

void Moon::update(int dt, float cameraX, float cameraY) {

	angle += 0.3*dt;
	angle = fmod(angle, 360);

	this->x = (sin((this->angle)*PI/180))*radius + center->getX() + 25;
	this->y = (cos((this->angle)*PI/180))*radius + center->getY() + 25;

}
