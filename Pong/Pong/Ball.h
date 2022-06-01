#pragma once
#include <raylib.h>

class Ball {
public:
	float x, y;
	float speedX, speedY;
	float rad;
	Ball(){
		x = GetScreenWidth() / 2.f;
		y = GetScreenHeight() / 2.f;
		rad = 5;
		speedX = 300;
		speedY = 300;
	}

	void Draw() {

		DrawCircle((int)x, (int)y, rad, WHITE);
	}


	void Collisions() {
		x += speedX * GetFrameTime();
		y += speedY * GetFrameTime();

		if (y < 0)
		{
			y = 0;
			speedY *= -1;
		}

		if (y > GetScreenHeight())
		{
			y = GetScreenHeight();
			speedY *= -1;
		}
		if (x < 0)
		{
			x = 0;
			speedX *= -1;
		}

		if (x > GetScreenWidth())
		{
			x = GetScreenWidth();
			speedX *= -1;
		}

	}
};