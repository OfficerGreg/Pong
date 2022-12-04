#pragma once

#include "Paddle.h"
#include "ball.h"

#include <string>
#include <assert.h>

class Game{
public:

    Game(int screenWidth, int screenHeight);
    ~Game();
    bool GameshouldClose();
    void Tick();
	

private:

    bool start;
    int score;

    std::string player1Score, player2Score;

    Ball ball;
    Paddle player1Paddle, player2Paddle;

    const char* winner_msg;

    void Draw();

    //Screen Update
    void Update();

    //Keyboard controls
    void UpdateControls();
};

