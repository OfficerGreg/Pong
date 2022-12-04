#include "Game.h"

Game::Game(int screenWidth, int screenHeight){

    assert(!GetWindowHandle());
    InitWindow(screenWidth, screenHeight, "Pong");

    SetTargetFPS(60);

    //init ball
    ball.initBall(500, 500, 15);

    //left paddle init
    player1Paddle.position(50, GetScreenHeight() / 2);
    player1Score = '0';

    //right paddle init
    player2Paddle.position(GetScreenWidth() - 50, GetScreenHeight() / 2);
    player2Score = '0';

    //winner

    winner_msg = nullptr;

    start = false;


}

Game::~Game(){
    CloseWindow();
}

bool Game::GameshouldClose(){
    return WindowShouldClose();
}

void Game::Tick(){
    BeginDrawing();
    Update();
    Draw();

    UpdateControls();


    EndDrawing();
}

void Game::Draw(){

    ClearBackground(BLACK);

    ball.Draw();

    DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), WHITE);

    player1Paddle.Draw(WHITE);
    player2Paddle.Draw(WHITE);

    DrawText(player1Score.c_str(), GetScreenWidth() / 2 - 80, 50, 40, WHITE);
    DrawText(player2Score.c_str(), GetScreenWidth() / 2 + 60, 50, 40, WHITE);

    DrawRectangleLines(20, 20, GetScreenWidth() - 40, GetScreenHeight() - 40, WHITE);


}

void Game::Update(){
    if (start == false){

        int startingTextWidth = MeasureText("Press Space to Start", 60);
        DrawText("Press Space to Start", GetScreenWidth() / 2 - startingTextWidth / 2, GetScreenHeight() / 2 - 250, 60, WHITE);

        if (IsKeyPressed(KEY_SPACE)){
            ball.x += ball.ballSpeed_X * GetFrameTime();
            ball.y += ball.ballSpeed_Y * GetFrameTime();
            start = true;
        }

    }
    else{
        ball.x += ball.ballSpeed_X * GetFrameTime();
        ball.y += ball.ballSpeed_Y * GetFrameTime();



        if (ball.y < 20){
            ball.y = 20;
            ball.ballSpeed_Y *= -1;
        }

        if (ball.y > GetScreenHeight() - 20){
            ball.y = GetScreenHeight() - 20;
            ball.ballSpeed_Y *= -1;
        }

        //collision player 1
        if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, player1Paddle.GetRect())){
            if (ball.ballSpeed_X < 0){
                ball.ballSpeed_X *= -1.1f;
            }
        }

        //collision player 2
        if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, player2Paddle.GetRect())){
            if (ball.ballSpeed_X > 0){
                ball.ballSpeed_X *= -1.1f;
            }
        }

        //winner msg
        if (ball.x < 20){
            winner_msg = "Player 2 Wins";
        }

        if (ball.x > GetScreenWidth() - 20){
            winner_msg = "Player 1 Wins";
        }

        if (winner_msg && IsKeyPressed(KEY_SPACE)){
            if (ball.x < 0){
                player2Score = std::to_string(player2Paddle.UpScore());

                ball.speed(400, 400);
            }

            if (ball.x > GetScreenWidth()){
                player1Score = std::to_string(player1Paddle.UpScore());
                ball.speed(-1 * 400, 400);

            }

            ball.x = GetScreenWidth() / 2.0f;
            ball.y = GetScreenHeight() / 2.0f;

            player1Paddle.y = GetScreenHeight() / 2;
            player2Paddle.y = GetScreenHeight() / 2;

            winner_msg = NULL;

        }
        if (winner_msg){
            int widthText = MeasureText(winner_msg, 60);
            DrawText(winner_msg, GetScreenWidth() / 2 - widthText / 2, GetScreenHeight() / 2 - 30, 60, WHITE);
        }

    }

}

void Game::UpdateControls(){
    //player 1
    if (IsKeyDown(KEY_W))
    {
        if (player1Paddle.y > 50) {
            player1Paddle.y -= player1Paddle.speed * GetFrameTime();
        }

    }


    if (IsKeyDown(KEY_S))
    {
        if (player1Paddle.y < GetScreenHeight() - 55)
        {
            player1Paddle.y += player1Paddle.speed * GetFrameTime();
        }

    }

    //player 2
    if (IsKeyDown(KEY_UP)){
        if (player2Paddle.y > 55){
            player2Paddle.y -= player2Paddle.speed * GetFrameTime();
        }
    }


    if (IsKeyDown(KEY_DOWN)){
        if (player2Paddle.y < GetScreenHeight() - 55){

            player2Paddle.y += player2Paddle.speed * GetFrameTime();
        }
    }
}

