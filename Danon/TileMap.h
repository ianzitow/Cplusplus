/*
 * TileMap.h
 *
 *  Created on: 14/05/2013
 *      Author: Ian
 */

#ifndef TILEMAP_H_
#define TILEMAP_H_

#include "TileSet.h"

class TileMap {
public:
	TileMap(int mapWidth, int mapHeight, int tileSize, int layers = 1, TileSet *tileSet = NULL);
	TileMap(std::string mapa, TileSet *tileSet = NULL);
	void load(std::string mapPath);
	void setTileset(TileSet *tileSet);
	int & at(int x, int y, int z = 0);
	void render(float cameraX = 0.0, float cameraY = 0.0);
	int width();
	int height();
	int layers();
	virtual ~TileMap();
	void renderLayer(float cameraX, float cameraY, int layer);
private:
	std::vector<std::vector <std::vector <int> > > tileMatrix;
	TileSet *tileSet;
	int mapWidth, mapHeight, mapLayers;
};

#endif /* TILEMAP_H_ */
