/*
 * StateGame.cpp
 *
 *  Created on: 13/04/2013
 *      Author: Ian
 */

#include "StateGame.h"
//#define DEBUG

StateGame::StateGame() {
	// TODO Auto-generated constructor stub

}

StateGame::~StateGame() {
	// TODO Auto-generated destructor stub

}

void StateGame::load(int stack) {
	this->bg = new Sprite("img/fundo.png");
	this->planetSprite = new Sprite("img/PlanetaVermelho.png");
	this->newPlanetSprite = new Sprite("img/PlanetaTerra.png");
	this->newPlanetSprite->rotoZoom(0, 3, 3);
	this->earth = new Earth(this->newPlanetSprite, -1000 + rand() % 3000, -1000 + rand() % 3000);
	this->moonSprite = new Sprite("img/Lua.png");
	this->moon = new Moon(this->moonSprite, 1, this->earth);
	this->followerSprite = new Sprite("img/ufo.png");
	this->ufo = new FollowerObject(this->followerSprite, rand() % 1000, rand() % 1000);
	this->boom = new Animation("img/BoomSheet.png", 50, 8);
	this->shipAnim = new Animation("img/NaveSheet.png", 50, 4);
	this->shipTurnAnim = new Animation("img/NaveTurnSheet.png", 50, 4);
	this->ship = new AccObject(this->shipAnim, this->shipTurnAnim, 400, 300, this->shipAnim->getWidth(), this->shipAnim->getHeight(), 20);
	//this->shipTurning = new AccObject(this->shipTurnAnim, this->ship->getX(), this->ship->getY(), this->shipAnim->getWidth(), this->shipTurnAnim->getHeight(), this->ship->getHitPoints());
	this->boomX = 0;
	this->boomY = 0;
	color.r = 255;
	color.g = 165;
	color.b = 0;
	this->instrucoes = new Text("ttf/DiabloLight.ttf", "Use AWSD para a nave e botão direito do mouse para o UFO", color, 16, TTF_STYLE_BOLD, 0, 0);
	this->music = new Audio("sfx/stateGame.mp3",1);
	this->sfx = new Audio("sfx/boom.wav", 0);
	this->music->Play(-1);
	this->timer = new Timer();
	this->timer->start();
	/*
	this->tileSet = new TileSet(TILE_SIZE, TILE_SIZE);
	char file[29] = "img/tileset/SpaceTile-00.png";
	for(int i=1;i<=N_TEXTURES;i++){
		file[23]='0'+i%10;
		file[22]='0'+i/10;
		this->tileSet->addTile(file);
	}
	this->tilemap = new TileMap(TILEMAP_SIZE, TILEMAP_SIZE, TILE_SIZE, 1, tileSet);
	buildMap();
	*/
	this->tileSet = new TileSet(TILE_SIZE, TILE_SIZE, "img/Tileset.png");
	this->tilemap = new TileMap("map/tileMap.txt", this->tileSet);

	this->camera.x = 0;
	this->camera.y = 0;
	this->cameraSpeed.x = 0;
	this->cameraSpeed.y = 0;

	this->quit = false;

	InpMan = InputManager::getInstance();

	this->frameEnd = 0;
	this->frameStart = 0;
	this->dt = 1;
	this->returnState = 0;
}

int StateGame::unload() {
	int who;

	if (ship != NULL) {
		who = WIN;
	} else if (ufo != NULL) {
		who = LOSE;
	}

	delete(this->bg);
	delete(this->planetSprite);
	delete(this->tilemap);
	delete(this->tileSet);
	delete(this->newPlanetSprite);
	delete(this->earth);
	delete(this->moon);
	delete(this->ufo);
	delete(this->boom);
	delete(this->shipAnim);
	delete(this->shipTurnAnim);
	delete(this->ship);
	delete(this->music);
	delete(this->sfx);
	delete(this->timer);

	return who;
}

/*
void GameManager::run() {
	while(!InpMan->QuitGame())
	{
		this->frameStart = SDL_GetTicks();


		GameManager::processEvents();

		GameManager::update(this->dt);


		GameManager::checkPlanets();

		GameManager::render(camera.x, camera.y);

		SDLBase::atualizarTela();
		this->frameEnd = SDL_GetTicks();
		this->dt = this->frameEnd - this->frameStart;
		if (this->dt < 1000/30) SDL_Delay((1000/30) - this->dt);
	}
}
*/

void StateGame::addPlanet(int cameraX, int cameraY) {

	PlanetRed *novoPlaneta = new PlanetRed(this->planetSprite, -3000 + rand() % 6000, -3000 + rand() % 6000, 1 + (rand() % 20));
	this->planetArray.push_back(novoPlaneta);

}

void StateGame::checkPlanets() {
	for(std::vector<Planet*>::iterator it = planetArray.end() - 1; it != planetArray.begin() - 1; --it) {
		if ((*it)->getHitPoints() <= 0) {
			it = this->planetArray.erase(it);
		}
	}
}

void StateGame::processEvents()
{

	if (!InpMan->QuitGame()) {

		/*
		if (InpMan->isMouseDown(SDL_BUTTON_LEFT)) {
			for(std::vector<Planet*>::iterator it = planetArray.end() - 1;
								it != planetArray.begin() - 1; --it)
				{
					Planet *planet = *it;
					SDL_Rect planetRect = planet->sprite->getClip();
					planetRect.x = planet->position.x - camera.x;
					planetRect.y = planet->position.y - camera.y;
					if( InpMan->isMouseInside(&planetRect) )
					{
						std::cout << "planeta acertado" << std::endl;
						// acerta o planeta, dando dano aleatório entre 10 e 19

						planet->hitpoints -= rand() % 10 + 10;
						planetRect.x = 0;
						planetRect.y = 0;
						// acertamos apenas um planeta
						// portanto saímos do break
						break;
					}
				}
		}
		*/

		/*
		if (InpMan->isKeyDown(SDLK_UP)) {
			cameraSpeed.y -= SCROLL;
		}
		else if (InpMan->isKeyDown(SDLK_DOWN)) {
			cameraSpeed.y += SCROLL;
		}
		else if (InpMan->isKeyDown(SDLK_LEFT)) {
			cameraSpeed.x -= SCROLL;
		}
		else if (InpMan->isKeyDown(SDLK_RIGHT)) {
			cameraSpeed.x += SCROLL;
		}
		else if (InpMan->isKeyDown(SDLK_SPACE)) {
			addPlanet(camera.x, camera.y);
		} */

		/*
		if (InpMan->isMouseDown(SDL_BUTTON_LEFT)) {
					addPlanet(camera.x, camera.y);
		}
		*/

		/*
		if (InpMan->isKeyUp(SDLK_UP)) {
			cameraSpeed.y += SCROLL;
		}
		else if (InpMan->isKeyUp(SDLK_DOWN)) {
			cameraSpeed.y -= SCROLL;
		}
		else if (InpMan->isKeyUp(SDLK_LEFT)) {
			cameraSpeed.x += SCROLL;
		}
		else if(InpMan->isKeyUp(SDLK_RIGHT))
		{
			cameraSpeed.x -= SCROLL;
		}
		*/

		if (ufo != NULL) {
			//if(InpMan->isMouseDown(SDL_BUTTON_RIGHT)) {
			if(InpMan->isMouseDown(SDL_BUTTON_RIGHT)) {

				//int mousePosX, mousePosY;

				//SDL_GetMouseState( &mousePosX, &mousePosY );

				//pos.x = (float) mousePosX;
				//pos.y = (float) mousePosY;

				pos.x = ship->getX() + 30;
				pos.y = ship->getY() + 30;

				//pos.x += camera.x;
				//pos.y += camera.y;

				ufo->enqueueCommand(pos);
			}
		}

		if(InpMan->isKeyPressed(SDLK_BACKSPACE)) {
			returnState = STATEMENU;
		}

		if(InpMan->isKeyPressed(SDLK_ESCAPE)) {
			returnState = STATEQUIT;
		}

		InpMan->Update();

		}

}

/*
{
	// procura um evento
	SDL_Event event;
	while( SDL_PollEvent( &event ) && !quit ) // inicializar um atributo quit do tipo bool com o valor false
	{
		// um evento foi achado
		if( event.type == SDL_QUIT )
			quit = true;
		else if( event.type == SDL_MOUSEBUTTONDOWN )
		{
			// obtém o estado do mouse
			int mouseX, mouseY;
			SDL_GetMouseState( &mouseX, &mouseY );

			// percorre o array de planetas de forma invertida
			// até achar o planeta que o usuário clicou.
			// percorremos de forma invertida porque os últimos
			// planetas são desenhados no topo, e estes serão
			// atingidos primeiro
			for(std::vector<Planet*>::iterator it = planetArray.end() - 1;
					it != planetArray.begin() - 1; --it)
			{
				Planet *planet = *it;

				if( mouseX + camera.x >= planet->position.x &&
						mouseX + camera.x < planet->position.x + planet->sprite->getClip().w &&
						mouseY + camera.y>= planet->position.y &&
						mouseY + camera.y < planet->position.y + planet->sprite->getClip().h )
				{
					// acerta o planeta, dando dano aleatório entre 10 e 19

					planet->hitpoints -= rand() % 10 + 10;

					// acertamos apenas um planeta
					// portanto saímos do break
					break;
				}
			}
		}
		else if( event.type == SDL_KEYDOWN )
		{
			// uma tecla foi pressionada
			if( event.key.keysym.sym == SDLK_ESCAPE )
			{
				// se a tecla ESC foi pressionada, sair do programa
				quit = true;
			}
			// Determina as variÃ¡veis de velocidade da cÃ¢mera
			// de acordo com as teclas pressionadas
			else if( event.key.keysym.sym == SDLK_UP )
				cameraSpeed.y -= SCROLL;
			else if( event.key.keysym.sym == SDLK_DOWN )
				cameraSpeed.y += SCROLL;
			else if( event.key.keysym.sym == SDLK_LEFT )
				cameraSpeed.x -= SCROLL;
			else if( event.key.keysym.sym == SDLK_RIGHT )
				cameraSpeed.x += SCROLL;
			else if( event.key.keysym.sym == SDLK_SPACE )
			{
				addPlanet(camera.x, camera.y);
			}
		}
		else if( event.type == SDL_KEYUP )
		{
			// uma tecla foi solta

			// diminui as variÃ¡veis de velocidade da cÃ¢mera
			// para que elas voltam a ser zero caso uma tecla
			// tenha sido solta
			if( event.key.keysym.sym == SDLK_UP )
				cameraSpeed.y += SCROLL;
			else if( event.key.keysym.sym == SDLK_DOWN )
				cameraSpeed.y -= SCROLL;
			else if( event.key.keysym.sym == SDLK_LEFT )
				cameraSpeed.x += SCROLL;
			else if( event.key.keysym.sym == SDLK_RIGHT )
				cameraSpeed.x -= SCROLL;
		}
	}
	// fim do loop de eventos
	 */

void StateGame::buildMap()
{
	tilemap->at( 0, 0) = 0;
	tilemap->at( 1, 0) = 1;
	tilemap->at( 2, 0) = 1;
	tilemap->at( 3, 0) = 1;
	tilemap->at( 4, 0) = 1;
	tilemap->at( 5, 0) = 1;
	tilemap->at( 6, 0) = 1;
	tilemap->at( 7, 0) = 1;
	tilemap->at( 8, 0) = 1;
	tilemap->at( 9, 0) = 1;
	tilemap->at(10, 0) = 1;
	tilemap->at(11, 0) = 1;
	tilemap->at(12, 0) = 5;
	tilemap->at(13, 0) = -1;
	tilemap->at(14, 0) = -1;
	tilemap->at(15, 0) = -1;
	tilemap->at( 0, 1) = 6;
	tilemap->at( 1, 1) = 10;
	tilemap->at( 2, 1) = 10;
	tilemap->at( 3, 1) = 10;
	tilemap->at( 4, 1) = 10;
	tilemap->at( 5, 1) = 10;
	tilemap->at( 6, 1) = 10;
	tilemap->at( 7, 1) = 10;
	tilemap->at( 8, 1) = 10;
	tilemap->at( 9, 1) = 10;
	tilemap->at(10, 1) = 10;
	tilemap->at(11, 1) = 10;
	tilemap->at(12, 1) = 11;
	tilemap->at(13, 1) = -1;
	tilemap->at(14, 1) = -1;
	tilemap->at(15, 1) = -1;
	tilemap->at( 0, 2) = 12;
	tilemap->at( 1, 2) = 7;
	tilemap->at( 2, 2) = 8;
	tilemap->at( 3, 2) = 8;
	tilemap->at( 4, 2) = 8;
	tilemap->at( 5, 2) = 8;
	tilemap->at( 6, 2) = 8;
	tilemap->at( 7, 2) = 8;
	tilemap->at( 8, 2) = 9;
	tilemap->at( 9, 2) = 10;
	tilemap->at(10, 2) = 10;
	tilemap->at(11, 2) = 10;
	tilemap->at(12, 2) = 17;
	tilemap->at(13, 2) = -1;
	tilemap->at(14, 2) = -1;
	tilemap->at(15, 2) = -1;
	tilemap->at( 0, 3) = 6;
	tilemap->at( 1, 3) = 13;
	tilemap->at( 2, 3) = 14;
	tilemap->at( 3, 3) = 14;
	tilemap->at( 4, 3) = 14;
	tilemap->at( 5, 3) = 14;
	tilemap->at( 6, 3) = 14;
	tilemap->at( 7, 3) = 14;
	tilemap->at( 8, 3) = 15;
	tilemap->at( 9, 3) = 10;
	tilemap->at(10, 3) = 10;
	tilemap->at(11, 3) = 10;
	tilemap->at(12, 3) = 11;
	tilemap->at(13, 3) = -1;
	tilemap->at(14, 3) = -1;
	tilemap->at(15, 3) = -1;
	tilemap->at( 0, 4) = 12;
	tilemap->at( 1, 4) = 13;
	tilemap->at( 2, 4) = 14;
	tilemap->at( 3, 4) = 14;
	tilemap->at( 4, 4) = 14;
	tilemap->at( 5, 4) = 14;
	tilemap->at( 6, 4) = 14;
	tilemap->at( 7, 4) = 14;
	tilemap->at( 8, 4) = 15;
	tilemap->at( 9, 4) = 7;
	tilemap->at(10, 4) = 25;
	tilemap->at(11, 4) = 28;
	tilemap->at(12, 4) = 29;
	tilemap->at(13, 4) = -1;
	tilemap->at(14, 4) = -1;
	tilemap->at(15, 4) = -1;
	tilemap->at( 0, 5) = 6;
	tilemap->at( 1, 5) = 13;
	tilemap->at( 2, 5) = 14;
	tilemap->at( 3, 5) = 14;
	tilemap->at( 4, 5) = 14;
	tilemap->at( 5, 5) = 14;
	tilemap->at( 6, 5) = 14;
	tilemap->at( 7, 5) = 14;
	tilemap->at( 8, 5) = 15;
	tilemap->at( 9, 5) = 19;
	tilemap->at(10, 5) = 3;
	tilemap->at(11, 5) = 4;
	tilemap->at(12, 5) = 5;
	tilemap->at(13, 5) = -1;
	tilemap->at(14, 5) = -1;
	tilemap->at(15, 5) = -1;
	tilemap->at( 0, 6) = 6;
	tilemap->at( 1, 6) = 13;
	tilemap->at( 2, 6) = 14;
	tilemap->at( 3, 6) = 14;
	tilemap->at( 4, 6) = 14;
	tilemap->at( 5, 6) = 14;
	tilemap->at( 6, 6) = 14;
	tilemap->at( 7, 6) = 14;
	tilemap->at( 8, 6) = 15;
	tilemap->at( 9, 6) = 10;
	tilemap->at(10, 6) = 10;
	tilemap->at(11, 6) = 10;
	tilemap->at(12, 6) = 11;
	tilemap->at(13, 6) = -1;
	tilemap->at(14, 6) = -1;
	tilemap->at(15, 6) = -1;
	tilemap->at( 0, 7) = 12;
	tilemap->at( 1, 7) = 13;
	tilemap->at( 2, 7) = 14;
	tilemap->at( 3, 7) = 14;
	tilemap->at( 4, 7) = 14;
	tilemap->at( 5, 7) = 14;
	tilemap->at( 6, 7) = 14;
	tilemap->at( 7, 7) = 14;
	tilemap->at( 8, 7) = 15;
	tilemap->at( 9, 7) = 10;
	tilemap->at(10, 7) = 10;
	tilemap->at(11, 7) = 10;
	tilemap->at(12, 7) = 17;
	tilemap->at(13, 7) = -1;
	tilemap->at(14, 7) = -1;
	tilemap->at(15, 7) = -1;
	tilemap->at( 0, 8) = 6;
	tilemap->at( 1, 8) = 19;
	tilemap->at( 2, 8) = 20;
	tilemap->at( 3, 8) = 20;
	tilemap->at( 4, 8) = 20;
	tilemap->at( 5, 8) = 20;
	tilemap->at( 6, 8) = 20;
	tilemap->at( 7, 8) = 20;
	tilemap->at( 8, 8) = 21;
	tilemap->at( 9, 8) = 10;
	tilemap->at(10, 8) = 10;
	tilemap->at(11, 8) = 10;
	tilemap->at(12, 8) = 11;
	tilemap->at(13, 8) = -1;
	tilemap->at(14, 8) = -1;
	tilemap->at(15, 8) = -1;
	tilemap->at( 0, 9) = 24;
	tilemap->at( 1, 9) = 25;
	tilemap->at( 2, 9) = 25;
	tilemap->at( 3, 9) = 25;
	tilemap->at( 4, 9) = 25;
	tilemap->at( 5, 9) = 25;
	tilemap->at( 6, 9) = 25;
	tilemap->at( 7, 9) = 25;
	tilemap->at( 8, 9) = 25;
	tilemap->at( 9, 9) = 26;
	tilemap->at(10, 9) = 26;
	tilemap->at(11, 9) = 26;
	tilemap->at(12, 9) = 29;
	tilemap->at(13, 9) = -1;
	tilemap->at(14, 9) = -1;
	tilemap->at(15, 9) = -1;
	tilemap->at( 0,10) = -1;
	tilemap->at( 1,10) = -1;
	tilemap->at( 2,10) = -1;
	tilemap->at( 3,10) = -1;
	tilemap->at( 4,10) = -1;
	tilemap->at( 5,10) = -1;
	tilemap->at( 6,10) = -1;
	tilemap->at( 7,10) = -1;
	tilemap->at( 8,10) = -1;
	tilemap->at( 9,10) = -1;
	tilemap->at(10,10) = -1;
	tilemap->at(11,10) = -1;
	tilemap->at(12,10) = -1;
	tilemap->at(13,10) = -1;
	tilemap->at(14,10) = -1;
	tilemap->at(15,10) = -1;
	tilemap->at( 0,11) = 0;
	tilemap->at( 1,11) = 1;
	tilemap->at( 2,11) = 1;
	tilemap->at( 3,11) = 5;
	tilemap->at( 4,11) = -1;
	tilemap->at( 5,11) = 0;
	tilemap->at( 6,11) = 2;
	tilemap->at( 7,11) = 3;
	tilemap->at( 8,11) = 4;
	tilemap->at( 9,11) = 5;
	tilemap->at(10,11) = -1;
	tilemap->at(11,11) = -1;
	tilemap->at(12,11) = -1;
	tilemap->at(13,11) = -1;
	tilemap->at(14,11) = -1;
	tilemap->at(15,11) = -1;
	tilemap->at( 0,12) = 6;
	tilemap->at( 1,12) = 7;
	tilemap->at( 2,12) = 28;
	tilemap->at( 3,12) = 29;
	tilemap->at( 4,12) = -1;
	tilemap->at( 5,12) = 12;
	tilemap->at( 6,12) = 10;
	tilemap->at( 7,12) = 10;
	tilemap->at( 8,12) = 10;
	tilemap->at( 9,12) = 17;
	tilemap->at(10,12) = -1;
	tilemap->at(11,12) = -1;
	tilemap->at(12,12) = -1;
	tilemap->at(13,12) = 0;
	tilemap->at(14,12) = 5;
	tilemap->at(15,12) = -1;
	tilemap->at( 0,13) = 18;
	tilemap->at( 1,13) = 17;
	tilemap->at( 2,13) = -1;
	tilemap->at( 3,13) = -1;
	tilemap->at( 4,13) = -1;
	tilemap->at( 5,13) = 6;
	tilemap->at( 6,13) = 10;
	tilemap->at( 7,13) = 10;
	tilemap->at( 8,13) = 10;
	tilemap->at( 9,13) = 11;
	tilemap->at(10,13) = -1;
	tilemap->at(11,13) = -1;
	tilemap->at(12,13) = -1;
	tilemap->at(13,13) = 24;
	tilemap->at(14,13) = 29;
	tilemap->at(15,13) = -1;
	tilemap->at( 0,14) = 24;
	tilemap->at( 1,14) = 29;
	tilemap->at( 2,14) = -1;
	tilemap->at( 3,14) = -1;
	tilemap->at( 4,14) = -1;
	tilemap->at( 5,14) = 24;
	tilemap->at( 6,14) = 25;
	tilemap->at( 7,14) = 27;
	tilemap->at( 8,14) = 28;
	tilemap->at( 9,14) = 29;
	tilemap->at(10,14) = -1;
	tilemap->at(11,14) = -1;
	tilemap->at(12,14) = -1;
	tilemap->at(13,14) = -1;
	tilemap->at(14,14) = -1;
	tilemap->at(15,14) = -1;
	// A linha 15 tem apenas -1, nao é necessário preenche-la, pois
	// o mapa é inicializado com -1
}

int StateGame::update(int dt) {
	//camera.x += cameraSpeed.x;
	//camera.y += cameraSpeed.y;

	StateGame::processEvents();

	for(std::vector<Planet*>::iterator it = planetArray.end() - 1; it != planetArray.begin() - 1; --it) {
		(*it)->update(dt, camera.x, camera.y);
	}

	//GameManager::checkPlanets();

	//this->earth->update(dt);
	this->moon->update(dt);

	timer->pause();
	if (ufo != NULL) {
		ufo->update(dt);
		if((timer->getTime() % 30) >= 15) {
			addPlanet(camera.x, camera.y);
		}
		timer->resume();
	}
	if (ship != NULL) {
		ship->update(dt, camera.x, camera.y);
		camera.x = ship->getX() - 800/2 + this->shipAnim->getWidth()/(this->shipAnim->getNumSprites()+3);
		camera.y = ship->getY() - 600/2 + this->shipAnim->getHeight();
	}
	boom->update(dt);

	StateGame::checkCollision(dt);
	StateGame::checkPlanets();

	return returnState;

}

void StateGame::render() {
	bg->render(0,0);
	//tilemap->render(cameraX, cameraY);
	tilemap->renderLayer(camera.x*0.85, camera.y*0.85,0);
	tilemap->renderLayer(camera.x, camera.y, 1);
	earth->render(camera.x, camera.y);
	moon->render(camera.x, camera.y);
	for(std::vector<Planet *>::iterator it = this->planetArray.begin(); it != this->planetArray.end(); ++it) {
		(*it)->render(camera.x, camera.y);
	}
	if (boomX != 0 && boomY != 0) {
		boom->render(boomX - camera.x, boomY - camera.y);
	}
	if (ufo != NULL) {
		ufo->renderQueueLines(camera.x, camera.y);
		ufo->render(camera.x, camera.y);
	}
	if (ship != NULL) {
		ship->render(camera.x, camera.y);
	}
	this->instrucoes->render(camera.x, camera.y);
}

float StateGame::getCameraX() {
	return camera.x;
}

float StateGame::getCameraY() {
	return camera.y;
}

void StateGame::checkCollision(int dt) {
	if ((ufo != NULL) && (ship != NULL)) {

		for(std::vector<Planet*>::iterator it = planetArray.end() - 1; it != planetArray.begin() - 1; --it) {
			if ((*it)->collidesWith(ship)) {
				boomX = (*it)->getX();
				boomY = (*it)->getY();
				it = this->planetArray.erase(it);
				ship->lowerHitPoints();
				this->sfx->Play(1);
			}
		}

		if (ufo->collidesWith(ship)) {
			ship->resetHitPoints();
			this->sfx->Play(1);
		}

		if(ship->collidesWith(earth)) {
			boomX = ufo->getX();
			boomY = ufo->getY();
			delete(ufo);
			ufo = NULL;
			boom->update(dt);
			this->sfx->Play(1);
		}

		if (ship->getHitPoints() <= 0) {
			boomX = ship->getX();
			boomY = ship->getY();
			delete(ship);
			ship = NULL;
			boom->update(dt);
			this->sfx->Play(1);
		}
	} else {
		returnState = STATEWINLOSE;
	}
}
