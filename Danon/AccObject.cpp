/*
 * AccObject.cpp
 *
 *  Created on: 03/06/2013
 *      Author: Ian
 */

#include "AccObject.h"

AccObject::AccObject(Animation *animation, Animation *extra, float x, float y, float w, float h, int hitPoints) : GameObject(x, y, animation->getClip().w/animation->getNumSprites(), animation->getClip().h) {
	this->animation = animation;
	this->extra = extra;
	this->hitPoints = hitPoints;
	this->speed = 0;
	this->acceleration = 0;
	this->rotation = 0;
	this->a = 0;
	this->vx = 0;
	this->vy = 0;
}

AccObject::~AccObject() {
	// TODO Auto-generated destructor stub
}

void AccObject::render(float cameraX, float cameraY) {
	if(animation != NULL) {
		this->animation->render(this->getX() - cameraX, this->getY() - cameraY);
	}
}

void AccObject::update(int dt, float cameraX, float cameraY) {

	if(InputManager::getInstance()->isKeyPressed(SDLK_a)) {
		rotation += 10;
		this->extra->setFrame(1);
	} else if (InputManager::getInstance()->isKeyPressed(SDLK_d)) {
		rotation -= 10;
		this->extra->setFrame(3);
	} else if (InputManager::getInstance()->isKeyPressed(SDLK_w)) {
		a = dt*0.005;
		this->animation->setFrame(2);
	} else if (InputManager::getInstance()->isKeyPressed(SDLK_s)) {
		a = -dt*0.005;
		this->animation->setFrame(2);
	}

	vx = vx + a*dt;
	vy = vy + a*dt;

	a = 0;

	vx = 0.99*vx;
	vy = 0.99*vy;

	if (vx < 0.1) vx = 0;
	if (vy < 0.1) vy = 0;

	x -= vx * (float) cos((double)((rotation - 90) * (PI/180)));
	y -= vy * (float) -sin((double)((rotation - 90) * (PI/180)));

	box.x = x;
	box.y = y;

	this->animation->update(dt);

	this->animation->rotoZoom(rotation);

}

void AccObject::lowerHitPoints() {
	hitPoints -= 1;
}

void AccObject::resetHitPoints() {
	hitPoints = 0;
}

int AccObject::getHitPoints() {
	return hitPoints;
}
