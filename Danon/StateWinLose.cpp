/*
 * StateWinLose.cpp
 *
 *  Created on: 08/06/2013
 *      Author: Ian
 */

#include "StateWinLose.h"

StateWinLose::StateWinLose() {
	bg = NULL;
	text = NULL;
	music = NULL;

}

StateWinLose::~StateWinLose() {
	// TODO Auto-generated destructor stub
}

void StateWinLose::load(int stack) {
	SDL_Color color;
	color.r = 255;
	color.g = 165;
	color.b = 0;

	if (stack == WIN) {
		bg = new Sprite("img/stateWin.jpg");
		text = new Text("ttf/DiabloLight.ttf", "PRESS SPACE TO RESTART", color, 16, TTF_STYLE_BOLD, 0, 0);
		music = new Audio("sfx/stateWin.mp3", 1);
	} else if (stack == LOSE) {
		bg = new Sprite("img/stateLose.jpg");
		text = new Text("ttf/DiabloLight.ttf", "PRESS SPACE TO RESTART", color, 16, TTF_STYLE_BOLD, 0, 0);
		music = new Audio("sfx/stateLose.mp3", 1);
	}

	music->Play(-1);
}

int StateWinLose::unload() {
	delete(bg);
	delete(text);
	delete(music);
	return 0;
}

int StateWinLose::update(int dt) {
	if(InputManager::getInstance()->isKeyPressed(SDLK_SPACE)) {
		return STATEMENU;
	} else if (InputManager::getInstance()->isKeyPressed(SDLK_ESCAPE)) {
		return STATEQUIT;
	}
}

void StateWinLose::render() {
	bg->render(0,0);
	text->render(0,0);
}
