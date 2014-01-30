/*
 * StateManager.h
 *
 *  Created on: 08/06/2013
 *      Author: Ian
 */

#ifndef STATEMANAGER_H_
#define STATEMANAGER_H_

#define STATE 0
#define STATEMENU 1
#define STATEGAME 2
#define STATEQUIT 3
#define STATEWINLOSE 4

#define WIN 7
#define LOSE 8

#include "State.h"
#include "SDLBase.h"
#include "StateMenu.h"
#include "InputManager.h"
#include <time.h>
#include "Timer.h"
#include "StateWinLose.h"
#include "StateGame.h"

class StateManager {
private:
	State *estadoAtual;
	int stack, dt, frameStart, frameEnd, timeOut;
	bool quit;
	Timer *timer;
public:
	StateManager();
	virtual ~StateManager();
	void run();
};

#endif /* STATEMANAGER_H_ */
