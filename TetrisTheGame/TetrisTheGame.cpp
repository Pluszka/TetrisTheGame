#include <iostream>
#include <raylib.h>
#include "Game.h"
#include "Color.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(500, 620, "Tetris The Game");
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.HandleInput();
        if (EventTriggered(0.2)){
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("Score", 330, 15, 38, green);
        DrawText("Next", 330, 175, 38, green);
        if (game.gameOver) {
            DrawText("GAME OVER", 320, 450, 28, red);
        }
        DrawRectangleRounded({ 320, 55, 170,60 }, 0.3, 6, blue);
        char scoreText[10];
        snprintf(scoreText, sizeof(scoreText), "%d", game.score);
        int textSize = MeasureText(scoreText, 38);

        int posTextX = 320 + (170 - textSize) / 2;
        int posTextY = 55 + (60 - 38) / 2;

        DrawText(scoreText, posTextX, posTextY, 38, green);
        DrawRectangleRounded({ 320, 215, 170,180 }, 0.3, 6, blue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}