#ifndef PONG_SOUNDS_H
#define PONG_SOUNDS_H

#include "Score.h"
#include "Board.h"


class Sounds{
public:
	Sound pong1;
	Sound pong2;
	Sound wall;
	void Init()
	{
		InitAudioDevice();

		pong1 = LoadSound("pong1.wav");
		pong2 = LoadSound("pong2.wav");
		wall = LoadSound("wall.wav");
	}
	void PlaySoundPaddle1()
	{
		PlaySoundMulti(pong1);
	}
	void PlaySoundPaddle2()
	{
		PlaySoundMulti(pong2);
	}
	void PlaySoundWall()
	{
		PlaySoundMulti(wall);
	}

};

#endif // !PONG_SOUNDS_H