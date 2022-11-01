#include "Sounds.h"


class Game {
	int winX, winY;
	const char* Title;
public:


		Sounds sounds;
	void Init() {

		winX = 1000;
		winY = 800;
		Title = "Pong";

		InitWindow(winX, winY, Title);

		SetWindowState(FLAG_VSYNC_HINT);
		sounds.Init();
	}


	
	void update() {
		
		Ball ball;
		Paddle paddle;
		Board board;
		Score score;
		
		while (!WindowShouldClose()) {
			ball.Collisions();
			paddle.Collisions();
			

			paddle.input();
			score.UpdateScore();
			if (ball.x < 0)
				score.playerScore1++;
				
			BeginDrawing();
			ClearBackground(BLACK);

			ball.Draw();
			score.DrawScore();
			paddle.Draw();
			board.MidLine();
			board.Border();
			DrawFPS(0, 0);
			EndDrawing();
		}
		CloseWindow();
	}
};