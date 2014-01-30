/*
 * GameObject.cpp
 *
 *  Created on: 21/05/2013
 *      Author: Ian
 */

#include "GameObject.h"
#include <stdio.h>

GameObject::GameObject(float x, float y, float w, float h) {
	// TODO Auto-generated constructor stub
	this->x = x;
	this->y = y;
	this->box.x = x;
	this->box.y = y;
	this->box.w = w;
	this->box.h = h;
	this->diffX = 0;
	this->diffY = 0;
}

GameObject::~GameObject() {
	// TODO Auto-generated destructor stub
}

float GameObject::getX() {
	return this->x;
}

float GameObject::getY() {
	return this->y;
}

bool GameObject::collidesWith(GameObject *other) {
	diffX = box.x - other->box.x;
	diffY = box.y - other->box.y;

	printf("box.x: %f, box.y: %f, box.w: %f, box.h: %f\n", box.x,box.y,box.w,box.h);

	if ((diffX > other->box.w) || (-diffX > box.w)) {
		return false;
	}
	else if ((diffY > other->box.h) || (-diffY > box.h)) {
		return false;
	}
	else return true;

}
