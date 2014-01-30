/*
 * Audio.cpp
 *
 *  Created on: 08/06/2013
 *      Author: Ian
 */

#include "Audio.h"

Audio::Audio(std::string fileName, int type) {
	// TODO Auto-generated constructor stub
	if(type == 0) {
		sound = Mix_LoadWAV(fileName.c_str());
		music = NULL;
	} else if (type == 1) {
		music = Mix_LoadMUS(fileName.c_str());
		sound = NULL;
	}
	channel = 0;
}

Audio::~Audio() {
	// TODO Auto-generated destructor stub
	if (sound != NULL) Mix_FreeChunk(sound);
	if (music != NULL) Mix_FreeMusic(music);
}

void Audio::Play(int n) {
	if (music != NULL) {
		Mix_PlayMusic(music, n);
	} else if (sound != NULL) {
		channel = Mix_PlayChannel(channel, sound, n);
	}
}

void Audio::Stop() {
	if (music != NULL) {
		Mix_FadeOutMusic(10);
	} else if (sound != NULL) {
		Mix_HaltChannel(channel);
	}
}
