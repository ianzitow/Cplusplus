/*
 * StateGame.h
 *
 *  Created on: 13/04/2013
 *      Author: Ian
 */

#include "State.h"
#include "StateManager.h"
#include "PlanetRed.h"
#include "TileSet.h"
#include "TileMap.h"
#include "Earth.h"
#include "Moon.h"
#include "FollowerObject.h"
#include "AccObject.h"

#define SCROLL 20.0f
#define TILE_SIZE 75
#define TILEMAP_SIZE 16
#define N_TEXTURES 30

#ifndef STATEGAME_H_
#define STATEGAME_H_

class StateGame : public State {
private:
	Sprite *bg;
	Sprite *planetSprite;
	Sprite *newPlanetSprite;
	Sprite *moonSprite;
	Sprite *followerSprite;
	std::vector<Planet *> planetArray;
	Earth *earth;
	Moon *moon;
	FollowerObject *ufo;
	Point pos;
	TileSet *tileSet;
	TileMap *tilemap;
	AccObject *ship;
	Animation *boom, *shipAnim, *shipTurnAnim;
	Text *instrucoes;
	Audio *music, *sfx;
	Timer *timer;
	struct {
		float x, y;
	} camera;
	struct {
		float x, y;
	} cameraSpeed;
	SDL_Color color;
	bool quit;
	InputManager *InpMan;
	float boomX, boomY;
	int dt, frameStart, frameEnd, returnState;
	void checkCollision(int dt);
public:
	StateGame();
	virtual ~StateGame();
	void run();
	void addPlanet(int cameraX, int cameraY);
	void checkPlanets();
	void processEvents();
	void buildMap();
	int update(int dt);
	void render();
	float getCameraX();
	float getCameraY();
	int unload();
	void load(int stack = 0);
};

#endif /* GAMEMANAGER_H_ */
