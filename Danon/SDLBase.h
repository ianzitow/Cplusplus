/*
 * SDLBase.h
 *
 *  Created on: 12/04/2013
 *      Author: Ian
 */

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_rotozoom.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#ifndef SDLBASE_H_
#define SDLBASE_H_

//#define DEBUG
#define SMOOTH 1

class SDLBase {
public:
	SDLBase();
	virtual ~SDLBase();
	static SDL_Surface *screen;
	static int inicializaSDL();
	static void encerraSDL();
	static SDL_Surface* getScreen() {return screen;};
	static SDL_Surface* loadImage(std::string arquivo);
	static void renderSurface(SDL_Surface *surface, SDL_Rect *clip = NULL, SDL_Rect *dst = NULL);
	static void atualizarTela();
	static void drawLine(int x1, int y1, int x2, int y2, int rgb, int spacing);
	static SDL_Surface* rotoZoom(SDL_Surface *surface, float angle, float scalex = 1.0, float scaley = 1.0);
	static SDL_Surface* clip(SDL_Surface *original, SDL_Rect *clip);
};

#endif /* SDLBASE_H_ */
