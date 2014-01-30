/*
 * StateMenu.cpp
 *
 *  Created on: 08/06/2013
 *      Author: Ian
 */

#include "StateMenu.h"

StateMenu::StateMenu() {
	bg = NULL;
	text = NULL;
	music = NULL;
}

StateMenu::~StateMenu() {

}

void StateMenu::load(int stack) {
	SDL_Color color;
	color.r = 255;
	color.g = 165;
	color.b = 0;

	bg = new Sprite("img/stateMenu.jpg");
	text = new Text("ttf/DiabloLight.ttf", "PRESS SPACE TO START", color, 16, TTF_STYLE_BOLD, 0, 0);
	music = new Audio("sfx/stateGame.mp3", 1);
	music->Play(-1);
}

int StateMenu::unload() {
	delete(bg);
	delete(text);
	delete(music);
	return 0;
}

int StateMenu::update(int dt) {

		if(InputManager::getInstance()->isKeyPressed(SDLK_SPACE)) {
			return STATEGAME;
		} else if (InputManager::getInstance()->isKeyPressed(SDLK_ESCAPE)) {
			return STATEQUIT;
		} else return STATE;
}

void StateMenu::render() {
	bg->render(0,0);
	text->render(0,0);
}
