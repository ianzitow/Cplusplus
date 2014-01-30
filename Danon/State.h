/*
 * State.h
 *
 *  Created on: 08/06/2013
 *      Author: Ian
 */

#ifndef STATE_H_
#define STATE_H_

#include "Sprite.h"
#include "Text.h"
#include "Audio.h"
#include "InputManager.h"
#include "Sprite.h"

class State {
public:
	State();
	virtual ~State();
	virtual void load(int stack = 0) = 0;
	virtual int unload() = 0;
	virtual int update(int dt) = 0;
	virtual void render() = 0;
};

#endif /* STATE_H_ */
