#ifndef PONG_BOARD_H
#define PONG_BOARD_H

#include <raylib.h>

class Board {

public:
	void MidLine()
	{
		DrawLine(GetScreenWidth() / 2 - 5, 0, GetScreenWidth() / 2 + 5, GetScreenHeight(), WHITE);
	}
	void Border()
	{
		DrawRectangleLines(0, 0, GetScreenWidth(), GetScreenHeight(), WHITE);
	}
};
#endif // !PONG_BOARD_H