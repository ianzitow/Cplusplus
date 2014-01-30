/*
 * TileSet.cpp
 *
 *  Created on: 07/05/2013
 *      Author: Ian
 */

#include "TileSet.h"

TileSet::TileSet(int tileWidth, int tileHeight, std::string filePath) {
	this->useSingleFile = true;
	this->tileHeight = tileHeight;
	this->tileWidth = tileWidth;
	this->vTiles = NULL;
	this->tileSet = new Sprite(filePath);
	this->lines = this->tileSet->getHeight()/tileHeight;
	this->columns = this->tileSet->getWidth()/tileWidth;
}

TileSet::TileSet(int tileWidth, int tileHeight) {
	this->useSingleFile = false;
	this->columns = 0;
	this->lines = 0;
	this->tileHeight = tileHeight;
	this->tileWidth = tileWidth;
	this->tileSet = NULL;
	this->vTiles = new (std::vector<Sprite *>);

}

TileSet::~TileSet() {
	// TODO Auto-generated destructor stub
}

int TileSet::getTileHeight() {
	return this->tileHeight;
}

int TileSet::getTileWidth() {
	return this->tileWidth;
}

bool TileSet::usingSingleFile() {
	if (this->tileSet != NULL) {
		return true;
	} else {
		return false;
	}
}

void TileSet::addTile(std::string filePath) {
	if (!usingSingleFile()) {
		Sprite *novoTile = new Sprite(filePath);
		this->vTiles->push_back(novoTile);
	}
}

void TileSet::render(int index, float posX, float posY) {
	if (usingSingleFile()) {
		int x = (index % this->columns)*this->tileWidth;
		int y = (index / this->columns)*this->tileHeight;
		this->tileSet->clip(x, y, this->tileWidth, this->tileHeight);
		this->tileSet->render(posX, posY);
	} else {
		this->vTiles->at(index)->render(posX, posY);
	}
}
