/*
 * Timer.cpp
 *
 *  Created on: 08/06/2013
 *      Author: Ian
 */

#include "Timer.h"

Timer::Timer() {
	// TODO Auto-generated constructor stub

}

Timer::~Timer() {
	// TODO Auto-generated destructor stub
}

void Timer::start() {
	initialTime = SDL_GetTicks();
	paused = false;
}

void Timer::pause() {
	pauseTime = SDL_GetTicks();
	paused = true;
}

void Timer::resume() {
	initialTime = SDL_GetTicks() - (pauseTime - initialTime);
	paused = false;
}

int Timer::getTime() {
	if(paused == true) {
		return (pauseTime - initialTime);
	} else {
		return (SDL_GetTicks() - initialTime);
	}
}
