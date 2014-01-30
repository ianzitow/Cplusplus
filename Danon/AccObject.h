/*
 * AccObject.h
 *
 *  Created on: 03/06/2013
 *      Author: Ian
 */

#ifndef ACCOBJECT_H_
#define ACCOBJECT_H_

#include "GameObject.h"
#include "Animation.h"
#include "InputManager.h"
#include <math.h>
#define PI 3.14159265

class AccObject: public GameObject {
private:
	Animation *animation;
	Animation *extra;
	float speed;
	float acceleration;
	float rotation;
	int hitPoints;
	float vx, vy, a;
public:
	AccObject(Animation *animation, Animation *extra, float x, float y, float w, float h, int hitPoints);
	void render(float cameraX, float cameraY);
	void update(int dt, float cameraX, float cameraY);
	virtual ~AccObject();
	void lowerHitPoints();
	void resetHitPoints();
	int getHitPoints();
};

#endif /* ACCOBJECT_H_ */
