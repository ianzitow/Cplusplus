/*
 * FollowerObject.cpp
 *
 *  Created on: 28/05/2013
 *      Author: Ian
 */

#include "FollowerObject.h"

FollowerObject::FollowerObject(Sprite *sprite, float x, float y) : GameObject(x, y, sprite->getWidth(), sprite->getHeight()){
	// TODO Auto-generated constructor stub
	this->sprite = sprite;
	this->speedX = 0.0;
	this->speedY = 0.0;
}

FollowerObject::~FollowerObject() {
	// TODO Auto-generated destructor stub
}

void FollowerObject::update(int dt, float cameraX, float cameraY) {
	if(!coordinatesQueue.empty()) {
		Point target = coordinatesQueue.front();

		if(this->speedX == 0 && this->speedY == 0) {
			this->speedX = (target.x - this->x)/(2*dt);
			this->speedY = (target.y - this->y)/(2*dt);
		}

		if ((this->x > (target.x - 5)) && (this->y > (target.y - 5)) && (this->x < (target.x + 5)) && (this->y < (target.y + 5))) {
			coordinatesQueue.pop();
			this->speedX = 0;
			this->speedY = 0;
		}
	}

	this->x += this->speedX;
	this->y += this->speedY;

	box.x = x;
	box.y = y;

}

void FollowerObject::render(float cameraX, float cameraY) {
	if(sprite != NULL) {
		this->sprite->render(this->getX() - cameraX, this->getY() - cameraY);
	}
}

void FollowerObject::renderQueueLines(float cameraX, float cameraY) {
	std::queue<Point> Auxiliar;
	Point target;
	float xAux = x, yAux = y;

	while(!coordinatesQueue.empty()) {
		target = coordinatesQueue.front();
		Auxiliar.push(target);

		SDLBase::drawLine(xAux - cameraX + (this->sprite->getWidth()/2), yAux - cameraY + (this->sprite->getHeight()/2), target.x - cameraX + (this->sprite->getWidth()/2), target.y - cameraY + (this->sprite->getHeight()/2), 0xFFFFFF, 10);

		xAux = target.x;
		yAux = target.y;

		coordinatesQueue.pop();

	}

	while(!Auxiliar.empty()) {
		target = Auxiliar.front();
		coordinatesQueue.push(target);
		Auxiliar.pop();
	}
}

void FollowerObject::enqueueCommand(Point pos) {
	pos.x -= this->sprite->getWidth()/2;
	pos.y -= this->sprite->getHeight()/2;
	coordinatesQueue.push(pos);
}
