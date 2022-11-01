#ifndef PONG_SCORE_H
#define PONG_SCORE_H

#include "Ball.h"
#include "Paddle.h"


class Score {
public:
	const char* winnerText1 = "Player1 WON";
	const char* winnerText2 = "Player2 WON";

	int playerScore1;

	int playerScore2;
	
	void DrawScore()
	{
		DrawText(TextFormat("%01i", playerScore1), GetScreenWidth() / 2 - GetScreenWidth() / 4, GetScreenHeight() / 5, 70, WHITE);
		DrawText(TextFormat("%01i", playerScore2), GetScreenWidth() / 2 + GetScreenWidth() / 4, GetScreenHeight() / 5, 70, WHITE);
	 }

	void UpdateScore()
	{
		if (x < 0)
		{
			playerScore1++;
		}
	}
};
#endif // !PONG_SCORE_H