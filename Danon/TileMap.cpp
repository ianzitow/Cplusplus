/*
 * TileMap.cpp
 *
 *  Created on: 14/05/2013
 *      Author: Ian
 */

#include "TileMap.h"

TileMap::TileMap(int mapWidth, int mapHeight, int tileSize, int layers, TileSet *tileSet) {
	this->mapWidth = mapWidth;
	this->mapHeight = mapHeight;
	this->mapLayers = layers;
	this->tileSet = tileSet;

	//this->tileMatrix.assign(mapWidth, std::vector<std::vector<int> >(mapHeight, std::vector<int>(mapLayers,-1)));

	this->tileMatrix.resize(mapWidth);
	for (int x = 0; x < this->mapWidth; ++x) {
		this->tileMatrix[x].resize(mapHeight);
		for (int y = 0; y < this->mapHeight; ++y) {
			this->tileMatrix[x][y].resize(mapLayers);
		}
	}

	for(unsigned int i = 0; i < this->tileMatrix.size(); ++i) {
		for (unsigned int j = 0; j < this->tileMatrix[0].size(); ++j) {
			for (unsigned int z = 0; z < this->tileMatrix[0][0].size(); ++z) {
				this->tileMatrix[i][j][z] = -1;
			}
		}
	}

}

TileMap::TileMap(std::string mapa, TileSet *tileSet) {
	this->mapWidth = 0;
	this->mapHeight = 0;
	this->mapLayers = 0;
	this->tileSet = tileSet;
	TileMap::load(mapa);
}

TileMap::~TileMap() {
	// TODO Auto-generated destructor stub
}

int TileMap::height() {
	return mapHeight;
}

int TileMap::width() {
	return mapWidth;
}

int TileMap::layers() {
	return mapLayers;
}

void TileMap::render(float cameraX, float cameraY) {
	if (this->tileSet != NULL) {
		for(unsigned int i = 0; i < this->tileMatrix.size(); ++i) {
			for (unsigned int j = 0; j < this->tileMatrix[0].size(); ++j) {
				for (unsigned int z = 0; z < this->tileMatrix[0][0].size(); ++z) {
					if (this->tileMatrix[i][j][z] >= 0) {
						//std::clog << i << " " << j << " " << z << " " << tileMatrix[i][j][z] << std::endl;
						this->tileSet->render(tileMatrix[i][j][z] - 1, i*this->tileSet->getTileWidth() - cameraX, j*this->tileSet->getTileHeight() - cameraY);
					}
				}
			}
		}
	}
}

void TileMap::renderLayer(float cameraX, float cameraY, int layer) {
	if (this->tileSet != NULL) {
		for(unsigned int i = 0; i < this->tileMatrix.size(); ++i) {
			for (unsigned int j = 0; j < this->tileMatrix[0].size(); ++j) {
					if (this->tileMatrix[i][j][layer] >= 0) {
						//std::clog << i << " " << j << " " << z << " " << tileMatrix[i][j][z] << std::endl;
						this->tileSet->render(tileMatrix[i][j][layer] - 1 , i*this->tileSet->getTileWidth() - cameraX, j*this->tileSet->getTileHeight() - cameraY);
					}
			}
		}
	}
}

void TileMap::load(std::string mapPath) {
	FILE *fp;
	char c, num[2];
	int d, u[520], i = 0, ii, jj, z;
	int altura, largura, camadas;

	fp = fopen((char*)mapPath.c_str(), "r");

	std::cout << fp << std::endl;

    do{
		c = getc(fp);
		if ((c != ',') && (c != ' ')) {
			num[0] = c;
			num[1] = getc(fp);
			num[2] = '\0';
			d = atoi(num);
			u[i] = d;
			i++;
		}
	 } while(c != EOF);

	altura = u[0];
	largura = u[1];
	camadas = u[2];

	this->tileMatrix.resize(largura);
	for (int x = 0; x < largura; ++x) {
		this->tileMatrix[x].resize(altura);
		for (int y = 0; y < altura; ++y) {
			this->tileMatrix[x][y].resize(camadas);
		}
	}

	i = 3;
	for(z = 0; z < camadas; z++) {
	    for(ii = 0; ii < altura; ii++) {
	        for(jj = 0; jj < largura; jj++) {
	            tileMatrix[jj][ii][z] = u[i];
	            printf("%d,", u[i]);
	            i++;
	        }
	    }
	}

}

void TileMap::setTileset(TileSet *tileSet) {
	this->tileSet = tileSet;
}

int & TileMap::at(int x, int y, int z) {
	return (this->tileMatrix[x][y][z]);
}
