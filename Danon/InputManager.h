/*
 * InputManager.h
 *
 *  Created on: 17/05/2013
 *      Author: Ian
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include "SDLBase.h"

#define N_KEYS 320
#define N_MOUSE_BUTTONS 7

class InputManager {
private:
	Uint8 mouse, *teclado;
	Uint8 keyDown[N_KEYS], keyUp[N_KEYS];
	bool quitGame;
	Uint8 mouseDown[N_MOUSE_BUTTONS], mouseUp[N_MOUSE_BUTTONS];
	int mouseX, mouseY;
	static InputManager *instance;
	InputManager();
public:
	virtual ~InputManager();
	static InputManager *getInstance();
	void Update();
	bool isKeyDown(int key);
	bool isKeyUp(int key);
	bool isKeyPressed(int key);
	bool isMouseDown(int button);
	bool isMouseUp(int button);
	bool isMousePressed(Uint8 button);
	int mousePosX();
	int mousePosY();
	bool isMouseInside(SDL_Rect *rect, float posX, float posY);
	bool QuitGame();
};

#endif /* INPUTMANAGER_H_ */
