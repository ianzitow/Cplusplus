/*
 * SDLBase.cpp
 *
 *  Created on: 12/04/2013
 *      Author: Ian
 */

#include "SDLBase.h"
SDL_Surface *SDLBase::screen = 0;

SDLBase::SDLBase() {
	// TODO Auto-generated constructor stub

}

SDLBase::~SDLBase() {
	// TODO Auto-generated destructor stub

}

int SDLBase::inicializaSDL() {
	SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_TIMER);
	screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
	SDL_WM_SetCaption("Trabalho 4 <10/0050280>", "Exercicio 3 <10/0050280>");
	TTF_Init();
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	return 0;
}

void SDLBase::encerraSDL() {
	TTF_Quit();
	Mix_Quit();
	SDL_Quit();
}

SDL_Surface * SDLBase::loadImage(std::string arquivo) {
	if (screen == 0) {
		std::cerr << "Erro: SDL nao inicializada" << std::endl;
		return NULL;
	}

	SDL_Surface *surface = 0;
	SDL_Surface *surfaceAuxiliar = 0;

	surface = IMG_Load(arquivo.c_str());

	if (surface == 0) {
		std::cerr << "Erro: ao carregar imagem" << arquivo << std::endl;
		return NULL;
	}

	if (surface->format->Amask != 0) {
		surfaceAuxiliar = SDL_DisplayFormatAlpha(surface);
	} else {
		surfaceAuxiliar = SDL_DisplayFormat(surface);
	}

	SDL_FreeSurface(surface);

	return surfaceAuxiliar;
}

void SDLBase::renderSurface(SDL_Surface *surface, SDL_Rect *clip, SDL_Rect *dst) {
	SDL_BlitSurface(surface, clip, screen, dst);
}

void SDLBase::atualizarTela() {
	SDL_Flip(screen);
}

void SDLBase::drawLine(int x1, int y1, int x2, int y2, int rgb, int spacing)
{
	int deltax = abs(x2 - x1); // The difference between the x's
	int deltay = abs(y2 - y1); // The difference between the y's
	int x = x1;                // Start x off at the first pixel
	int y = y1;                // Start y off at the first pixel
	int xinc1 = 0;
	int yinc1 = 0;
	int xinc2 = 0;
	int yinc2 = 0;
	int den = 0;
	int num = 0;
	int numadd = 0;
	int numpixels = 0;

	if (x2 >= x1)              // The x-values are increasing
	{
		xinc1 = 1;
		xinc2 = 1;
	}
	else                       // The x-values are decreasing
	{
		xinc1 = -1;
		xinc2 = -1;
	}

	if (y2 >= y1)              // The y-values are increasing
	{
		yinc1 = 1;
		yinc2 = 1;
	}
	else                       // The y-values are decreasing
	{
		yinc1 = -1;
		yinc2 = -1;
	}

	if (deltax >= deltay)		// There is at least one x-value for every y-value
	{
		xinc1 = 0;				// Don't change the x when numerator >= denominator
		yinc2 = 0;				// Don't change the y for every iteration
		den = deltax;
		num = deltax / 2;
		numadd = deltay;
		numpixels = deltax;		// There are more x-values than y-values
	}
	else						// There is at least one y-value for every x-value
	{
		xinc2 = 0;				// Don't change the x for every iteration
		yinc1 = 0;				// Don't change the y when numerator >= denominator
		den = deltay;
		num = deltay / 2;
		numadd = deltax;
		numpixels = deltay;		// There are more y-values than x-values
	}

	for (int curpixel = 1; curpixel <= numpixels; curpixel++)
	{
		if (spacing == 0)
		{
			SDL_Rect pixel = {x,y,1,1};
			SDL_FillRect(screen,&pixel,rgb);
		}
		else if (curpixel % spacing >= spacing/2)
		{
			SDL_Rect pixel = {x,y,1,1};
			SDL_FillRect(screen,&pixel,rgb);
		}

		num += numadd;         // Increase the numerator by the top of the fraction
		if (num >= den)        // Check if numerator >= denominator
		{
			num -= den;         // Calculate the new numerator value
			x += xinc1;         // Change the x as appropriate
			y += yinc1;         // Change the y as appropriate
		}
		x += xinc2;             // Change the x as appropriate
		y += yinc2;             // Change the y as appropriate
	}
}

SDL_Surface* SDLBase::rotoZoom(SDL_Surface *surface, float angle, float scalex, float scaley) {
	if((surface != NULL) && (scalex > 0) && (scaley > 0)) {
		return rotozoomSurfaceXY(surface, (double) angle, (double) scalex, (double) scaley, SMOOTHING_ON);
	} else return NULL;
}

SDL_Surface* SDLBase::clip(SDL_Surface *original, SDL_Rect *clip) {
	if ((original != NULL) && (clip != NULL)) {
		SDL_Surface *surfaceAux;
		surfaceAux = SDL_CreateRGBSurface(SDL_SWSURFACE, clip->w, clip->h, screen->format->BitsPerPixel, screen->format->Rmask, screen->format->Gmask, screen->format->Bmask, screen->format->Amask);
		SDL_BlitSurface(original, clip, surfaceAux, NULL);
		return surfaceAux;
	}
	else return NULL;
}
