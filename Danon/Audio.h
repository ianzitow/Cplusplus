/*
 * Audio.h
 *
 *  Created on: 08/06/2013
 *      Author: Ian
 */

#ifndef AUDIO_H_
#define AUDIO_H_

#include "SDLBase.h"

class Audio {
private:
	std::string fileName;
	Mix_Chunk *sound;
	Mix_Music *music;
	int channel;
public:
	Audio(std::string fileName, int type);
	virtual ~Audio();
	void Play(int n);
	void Stop();
};

#endif /* AUDIO_H_ */
