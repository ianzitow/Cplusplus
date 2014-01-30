/*
 * Earth.h
 *
 *  Created on: 25/05/2013
 *      Author: Ian
 */

#ifndef EARTH_H_
#define EARTH_H_

#include "Planet.h"

class Earth : public Planet {
private:
	float vx, vy;
public:
	Earth(Sprite *sprite, float x, float y, int hitPoints = 1);
	virtual ~Earth();
	void update(int dt, float cameraX = 0.0, float cameraY = 0.0);
	float getVX();
	float getVY();
};

#endif /* EARTH_H_ */
