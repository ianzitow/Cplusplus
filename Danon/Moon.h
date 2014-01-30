/*
 * Moon.h
 *
 *  Created on: 25/05/2013
 *      Author: Ian
 */

#ifndef MOON_H_
#define MOON_H_

#include "Planet.h"
#include <math.h>
#define PI 3.14159265

class Moon : public Planet {
private:
	float radius, angle;
	Planet *center;
public:
	Moon(Sprite *sprite, int hitPoints = 1, Planet *center = NULL);
	virtual ~Moon();
	void update(int dt, float cameraX = 0.0, float cameraY = 0.0);
};

#endif /* MOON_H_ */
