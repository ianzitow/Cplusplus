/*
 * Text.cpp
 *
 *  Created on: 07/06/2013
 *      Author: Ian
 */

#include "Text.h"
#include "SDLBase.h"

Text::Text(std::string fontFile, std::string text, SDL_Color color, int ptsize, int style, int x, int y) {
	// TODO Auto-generated constructor stub
	this->fontFile = fontFile;
	this->font = TTF_OpenFont(fontFile.c_str(), ptsize);
	this->text = text;
	this->ptsize = ptsize;
	this->style = style;
	TTF_SetFontStyle(font, style);
	this->color = color;
	this->textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	this->box.x = x;
	this->box.y = y;
	int wAux, hAux;
	TTF_SizeText(this->font, text.c_str(), &wAux, &hAux);
	box.w = (Uint16) wAux;
	box.h = (Uint16) hAux;
}

Text::~Text() {
	// TODO Auto-generated destructor stub
	TTF_CloseFont(font);
	SDL_FreeSurface(textSurface);
}

void Text::render(int cameraX, int cameraY) {
	SDLBase::renderSurface(textSurface, NULL, &box);
}

void Text::setPos(int x, int y) {
	this->box.x = x;
	this->box.y = y;
}

void Text::setText(std::string text) {
	SDL_FreeSurface(textSurface);
	this->text = text;
	this->textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	int wAux, hAux;
	TTF_SizeText(this->font, text.c_str(), &wAux, &hAux);
	box.w = (Uint16) wAux;
	box.h = (Uint16) hAux;
}

void Text::setStyle(int style) {
	SDL_FreeSurface(textSurface);
	TTF_SetFontStyle(font, style);
	this->textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	render();
	int wAux, hAux;
	TTF_SizeText(this->font, text.c_str(), &wAux, &hAux);
	box.w = (Uint16) wAux;
	box.h = (Uint16) hAux;
}

void Text::setColor(SDL_Color color) {
	SDL_FreeSurface(textSurface);
	this->textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	render();
	int wAux, hAux;
	TTF_SizeText(this->font, text.c_str(), &wAux, &hAux);
	box.w = (Uint16) wAux;
	box.h = (Uint16) hAux;
}

void Text::setSize(int ptsize) {
	SDL_FreeSurface(textSurface);
	this->font = TTF_OpenFont(fontFile.c_str(), ptsize);
	this->textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	render();
	int wAux, hAux;
	TTF_SizeText(this->font, text.c_str(), &wAux, &hAux);
	box.w = (Uint16) wAux;
	box.h = (Uint16) hAux;
}
