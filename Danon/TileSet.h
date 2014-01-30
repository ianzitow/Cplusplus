/*
 * TileSet.h
 *
 *  Created on: 07/05/2013
 *      Author: Ian
 */

#include "Sprite.h"

#ifndef TILESET_H_
#define TILESET_H_

class TileSet {
private:
	int tileWidth, tileHeight;
	int lines, columns;
	Sprite *tileSet;
	std::vector<Sprite *> *vTiles;
	SDL_Rect *destRect;
	bool useSingleFile;
public:
	TileSet(std::string filePath, int lines, int columns);
	TileSet(int lines, int columns, std::string filePath);
	TileSet(int tileWidth, int tileHeight);
	virtual ~TileSet();
	void addTile(std::string filePath);
	void render(int index, float posX, float posY);
	bool usingSingleFile();
	int getTileWidth();
	int getTileHeight();
};

#endif /* TILESET_H_ */
