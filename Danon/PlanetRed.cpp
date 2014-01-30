/*
 * PlanetRed.cpp
 *
 *  Created on: 21/05/2013
 *      Author: Ian
 */

#include "PlanetRed.h"

PlanetRed::PlanetRed(Sprite *sprite, float x, float y, int hitPoints) : Planet(sprite, x, y, hitPoints) {
	//Planet::Planet(sprite, x, y, hitPoints);
}

PlanetRed::~PlanetRed() {
	// TODO Auto-generated destructor stub
}

void PlanetRed::update(int dt, float cameraX, float cameraY) {
	if (InputManager::getInstance()->isMouseDown(SDL_BUTTON_LEFT)) {
		SDL_Rect planetRect = this->sprite->getClip();
		float planetX = this->x - cameraX;
		float planetY = this->y - cameraY;
		/*
		if( InputManager::getInstance()->isMouseInside(&planetRect, planetX, planetY) )
		{
			std::cout << "planeta acertado" << std::endl;
			// acerta o planeta, dando dano aleatório entre 10 e 19

			this->hitPoints -= rand() % 10 + 10;
			//planetRect.x = 0;
			//planetRect.y = 0;
		}
		*/
	}
}

void PlanetRed::setCameraX(float x) {
	this->camera.x = x;
}

void PlanetRed::setCameraY(float y) {
	this->camera.y = y;
}
