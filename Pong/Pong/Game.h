#pragma once
#include <raylib.h>
#include "paddle.h"
#include "Ball.h"

class Game {
public:
	int winX, winY;
	const char* Title;

	void Init() {

		winX = 800;
		winY = 600;
		Title = "pong";

		InitWindow(winX, winY, Title);
		SetWindowState(FLAG_VSYNC_HINT);
	}
	void Collisions() {
	}
	
	void update() {
		
			Ball ball;
			Paddle paddle;


			

		while (!WindowShouldClose()) {

			ball.Collisions();

			if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.rad, Rectangle{ paddle.x1 - paddle.width1 / 2, paddle.y1 - paddle.height1 / 2, 10, 100 }))
			{
				if (ball.speedX < 0)
				{
					ball.speedX *= -1.1f;
					ball.speedY = (ball.y - paddle.y1) / (paddle.height1 / 2) * ball.speedX;
					ball.speedX += 50;
					ball.speedY += 50;
				}
			}
			if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.rad, Rectangle{ paddle.x2 - paddle.width2 / 2, paddle.y2 - paddle.height2 / 2, 10, 100 }))
			{
				if (ball.speedX > 0)
				{
					ball.speedX *= -1.1f;
					ball.speedY = (ball.y - paddle.y2) / (paddle.height2 / 2) * -ball.speedX;
					ball.speedX -= 50;
					ball.speedY -= 50;

				}
			}
			if (ball.y < 0)
				break;
			paddle.input();
			BeginDrawing();
			ClearBackground(BLACK);

			ball.Draw();
			paddle.Draw();
			//DrawFPS(0, 0);
			EndDrawing();
		}
		CloseWindow();
	}
};