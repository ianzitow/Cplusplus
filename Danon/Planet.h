/*
 * Planet.h
 *
 *  Created on: 21/04/2013
 *      Author: Ian
 */

#include "GameObject.h"
#include "Sprite.h"

#ifndef PLANET_H_
#define PLANET_H_

class Planet : public GameObject {
protected:
	Sprite *sprite;
	int hitPoints;
public:
	Planet(Sprite *sprite, float x, float y, int hitPoints);
	virtual ~Planet();
	void render(float cameraX = 0.0, float cameraY = 0.0);
	virtual void update(int dt, float cameraX, float cameraY) = 0;
	int getHitPoints();
	int getRadius();
};

#endif /* PLANET_H_ */
