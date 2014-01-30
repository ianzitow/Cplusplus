/*
 * StateMenu.h
 *
 *  Created on: 08/06/2013
 *      Author: Ian
 */

#ifndef STATEMENU_H_
#define STATEMENU_H_

#include "State.h"
#include "StateManager.h"

class StateMenu: public State {
private:
	Sprite *bg;
	Text *text;
	Audio *music;
public:
	StateMenu();
	virtual ~StateMenu();
	void load(int stack = 0);
	int unload();
	int update(int dt);
	void render();
};

#endif /* STATEMENU_H_ */
