/*
 * StateManager.cpp
 *
 *  Created on: 08/06/2013
 *      Author: Ian
 */

#include "StateManager.h"

StateManager::StateManager() {
	SDLBase::inicializaSDL();

	dt = 1;

	estadoAtual = new StateMenu();
	estadoAtual->load();

	InputManager::getInstance()->Update();

	srand (time(NULL));

	timer = new Timer();

	stack = 0;

	quit = false;

	timeOut = 0;

}

StateManager::~StateManager() {
	// TODO Auto-generated destructor stub
	SDLBase::encerraSDL();
	estadoAtual->unload();
	delete(estadoAtual);
}

void StateManager::run() {
	timer->start();

	while(!quit) {
		/* Calculo de Timer e dt */
		frameStart = SDL_GetTicks();
		timer->pause();
		timeOut = timer->getTime();
		timer->resume();

		/* Atualização da InputManager – deve ser chamado somente aqui */
		InputManager::getInstance()->Update();

		// STATE MANAGER
		switch(estadoAtual->update(dt))
		{
			case STATE:
				// fazer nada
				break;
			case STATEMENU:
				stack = estadoAtual->unload();
				//delete(estadoAtual);
				estadoAtual = new StateMenu();
				estadoAtual->load(stack);
				break;
			case STATEGAME:
				stack = estadoAtual->unload();
				//delete(estadoAtual);
				estadoAtual = new StateGame();
				estadoAtual->load(stack);
				break;
			case STATEQUIT:
				quit = true;
				break;
			case STATEWINLOSE:
				stack = estadoAtual->unload();
				//delete(estadoAtual);
				estadoAtual = new StateWinLose();
				estadoAtual->load(stack);
				break;
		}

		/* Atualização dos objetos na tela */
		estadoAtual->render();
		SDLBase::atualizarTela();

		/* Delay */
		frameEnd = SDL_GetTicks();
		dt = frameEnd - frameStart;
		if (dt < 1000/30) SDL_Delay((1000/30) - dt);

	}
}
