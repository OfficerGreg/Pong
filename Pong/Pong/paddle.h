#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include <raylib.h>

class Paddle {
public:
	float x1, y1;
	float speed1;
	float width1, height1;

	float x2, y2;
	float speed2;
	float width2, height2;

	Paddle() {
		x1 = 50;
		y1 = GetScreenHeight() / 2;
		width1 = 10;
		height1 = 100;
		speed1 = 800;

		x2 = GetScreenWidth() - 50;
		y2 = GetScreenHeight() / 2;
		width2 = 10;
		height2 = 100;
		speed2 = 800;
	}
	void input() {
		if(IsKeyDown(KEY_UP))
			y2 -= speed2 * GetFrameTime();
		if (IsKeyDown(KEY_DOWN))
			y2 += speed2 * GetFrameTime();
		if (IsKeyDown(KEY_W))
			y1 -= speed1 * GetFrameTime();
		if (IsKeyDown(KEY_S))
			y1 += speed1 * GetFrameTime();	
	}
	void Draw() {
		DrawRectangle(x1 - width1 / 2, y1 - height1 / 2, 10, 100, WHITE);
		DrawRectangle(x2 - width2 / 2, y2 - height2 / 2, 10, 100, WHITE);	
	}
	void Collisions()
	{
		if (y1 > GetScreenHeight() - height1 / 2)
			y1 -= speed1 * GetFrameTime();
		if (y1 < 0 + height1 / 2)
			y1 += speed1 * GetFrameTime();
		if (y2 > GetScreenHeight() - height2 / 2)
			y2 -= speed2 * GetFrameTime();
		if (y2 < 0 + height2 / 2)
			y2 += speed2 * GetFrameTime();
	}
};

#endif // !#define PONG_PADDLE_H