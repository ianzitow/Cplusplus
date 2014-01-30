/*
 * main.cpp
 *
 *  Created on: 14/04/2013
 *      Author: Ian
 */

#include "StateManager.h"

int main(int argc, char **argv) {
	//SDLBase::inicializaSDL();
	StateManager *objeto = new StateManager();
	//std::cout<<"comecou2"<<std::endl;
	objeto->run();
	//std::cout<<"terminou"<<std::endl;
	delete(objeto);

	return 0;
}


