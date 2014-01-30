/*
 * StateWinLose.h
 *
 *  Created on: 08/06/2013
 *      Author: Ian
 */

#ifndef STATEWINLOSE_H_
#define STATEWINLOSE_H_

#include "State.h"
#include "StateManager.h"

class StateWinLose: public State {
private:
	Sprite *bg;
	Text *text;
	Audio *music;
public:
	StateWinLose();
	virtual ~StateWinLose();
	void load(int stack = 0);
	int unload();
	int update(int dt);
	void render();
};

#endif /* STATEWINLOSE_H_ */
