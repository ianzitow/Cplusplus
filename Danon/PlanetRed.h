/*
 * PlanetRed.h
 *
 *  Created on: 21/05/2013
 *      Author: Ian
 */

#ifndef PLANETRED_H_
#define PLANETRED_H_

#include "Planet.h"
#include "InputManager.h"

class PlanetRed : public Planet {
private:
	struct {
		float x, y;
	} camera;
public:
	PlanetRed(Sprite *sprite, float x, float y, int hitPoints = 1);
	virtual ~PlanetRed();
	void update(int dt, float cameraX, float cameraY);
	void setCameraX(float x);
	void setCameraY(float y);
};

#endif /* PLANETRED_H_ */
