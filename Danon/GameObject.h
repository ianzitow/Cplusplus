/*
 * GameObject.h
 *
 *  Created on: 21/05/2013
 *      Author: Ian
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <cmath>

typedef struct rect {
	float x, y, w, h;
} Rect;

class GameObject {
protected:
	float x, y;
	float diffX, diffY;
	Rect box;
public:
	GameObject(float x, float y, float w, float h);
	virtual ~GameObject();
	virtual void update(int dt, float cameraX, float cameraY) = 0;
	virtual void render(float cameraX, float cameraY) = 0;
	float getX();
	float getY();
	bool collidesWith(GameObject *other);
};

#endif /* GAMEOBJECT_H_ */
