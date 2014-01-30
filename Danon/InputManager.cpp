/*
 * InputManager.cpp
 *
 *  Created on: 17/05/2013
 *      Author: Ian
 */

#include "InputManager.h"

InputManager* InputManager::instance = NULL;

InputManager::InputManager() {
	// TODO Auto-generated constructor stub
	InputManager::Update();
	//this->quitGame = false;
}

InputManager::~InputManager() {
	// TODO Auto-generated destructor stub
}

void InputManager::Update() {
	SDL_Event event;

	for (int i = 0; i < N_KEYS; i++) {
		this->keyDown[i] = false;
		this->keyUp[i] = false;
	}

	for (int i = 0; i < N_MOUSE_BUTTONS; i++) {
		this->mouseDown[i] = false;
		this->mouseUp[i] = false;
	}

	this->teclado = SDL_GetKeyState(NULL);
	this->mouse = SDL_GetMouseState(&mouseX, &mouseY);
	this->quitGame = false;

	while(SDL_PollEvent(&event))
	{
		switch (event.type) {
			case SDL_KEYDOWN:
				this->keyDown[event.key.keysym.sym] = true;
				break;
			case SDL_KEYUP:
				this->keyUp[event.key.keysym.sym] = true;
				break;
			case SDL_MOUSEMOTION:
				break;
			case SDL_MOUSEBUTTONDOWN:
				this->mouseDown[event.button.button] = true;
				break;
			case SDL_MOUSEBUTTONUP:
				this->mouseUp[event.button.button] = true;
				break;
			case SDL_QUIT:
				this->quitGame = true;
				break;
		}
	}
}

bool InputManager::isKeyUp(int key) {
	if (this->keyUp[key]) return true;
	else return false;
}

bool InputManager::isKeyDown(int key) {
	if (this->keyDown[key]) return true;
	else return false;
}

bool InputManager::isMouseUp(int button) {
	if (this->mouseUp[button]) return true;
	else return false;
}

bool InputManager::isMouseDown(int button) {
	if (this->mouseDown[button]) return true;
	else return false;
}

int InputManager::mousePosX() {
	return this->mouseX;
}

int InputManager::mousePosY() {
	return this->mouseY;
}

bool InputManager::QuitGame() {
	if (this->quitGame) return true;
	else return false;
}

bool InputManager::isKeyPressed(int key) {
	if (this->teclado[key]) return true;
	else return false;
}

bool InputManager::isMousePressed(Uint8 button) {
	if (this->mouse) return true;
	else return false;
}

bool InputManager::isMouseInside(SDL_Rect *rect, float posX, float posY) {

	SDL_GetMouseState( &mouseX, &mouseY );

	if ((this->mouseX > posX) && (this->mouseX < (posX + rect->w)) &&
			(this->mouseY > posY) && (this->mouseY < (posY + rect->h))) return true;
	else return false;

}

InputManager * InputManager::getInstance() {
	//static InputManager instance;
	if (instance == NULL) instance = new InputManager();
	return instance;
}
