/*
 * Text.h
 *
 *  Created on: 07/06/2013
 *      Author: Ian
 */

#ifndef TEXT_H_
#define TEXT_H_

#include "SDLBase.h"
#include <string>

class Text {
private:
	TTF_Font *font;
	SDL_Surface *textSurface;
	std::string fontFile;
	std::string text;
	int style;
	int ptsize;
	SDL_Color color;
	SDL_Rect box;
public:
	Text(std::string fontFile, std::string text, SDL_Color color, int ptsize = 10, int style = 0, int x = 0, int y = 0);
	virtual ~Text();
	void render(int cameraX = 0, int cameraY = 0);
	void setPos(int x, int y);
	void setText(std::string text);
	void setColor(SDL_Color color);
	void setStyle(int style);
	void setSize(int ptsize);
};

#endif /* TEXT_H_ */
