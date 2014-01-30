/*
 * FollowerObject.h
 *
 *  Created on: 28/05/2013
 *      Author: Ian
 */

#ifndef FOLLOWEROBJECT_H_
#define FOLLOWEROBJECT_H_

#include "GameObject.h"
#include "SDLBase.h"
#include "Sprite.h"
#include <math.h>
#include <queue>

typedef struct point {
	float x, y;
} Point;

class FollowerObject: public GameObject {
private:
	Sprite *sprite;
	float speedX, speedY;
	std::queue<Point> coordinatesQueue;
	float distX, distY;
	Point target;
public:
	FollowerObject(Sprite *sprite, float x, float y);
	virtual ~FollowerObject();
	void update(int dt, float cameraX = 0, float cameraY = 0);
	void render(float cameraX, float cameraY);
	void enqueueCommand(Point pos);
	void renderQueueLines(float camera, float cameraY);
};

#endif /* FOLLOWEROBJECT_H_ */
