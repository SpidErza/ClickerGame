#include "raylib.h"

constexpr auto SCREEN_WIDTH  = 1280;
constexpr auto SCREEN_HEIGHT = 720;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "The Boring Button");
    SetTargetFPS(60);

    Texture2D button = LoadTexture(ASSETS_PATH"button.png");
	int score = 0;
	int level = 0;

    while (!WindowShouldClose())
    {
		Vector2 mousePos = GetMousePosition();

        BeginDrawing();

        ClearBackground(PURPLE);

        const int button_x = 365; //x position of texture
        const int button_y = 185; //y position of texture

        DrawTexture(button, button_x, button_y, WHITE);
		
		if (mousePos.x > button_x && mousePos.y > button_y && mousePos.x < 915 && mousePos.y < 365) 
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				const char* text = "+1 point";
				const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
				DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, button_y + button.height + text_size.y + 10, 20, BLACK);
				score++;
			}
		}
		DrawText(TextFormat("Score: %i ", score), 20, 50, 20, BLACK);

		if (score == 10)
		{
			level = 1;
		}
		if (score == 20)
		{
			level = 2;
		}
		if (score == 30)
		{
			level = 3;
		}
		if (score == 40)
		{
			level = 4;
		}
		if (score == 50)
		{
			level = 5;
		}
		if (score == 60)
		{
			level = 6;
		}
		if (score == 70)
		{
			level = 7;
		}
		if (score == 80)
		{
			level = 8;
		}
		if (score == 90)
		{
			level = 9;
		}
		if (score == 100)
		{
			level = 10;
			DrawText(TextFormat("Cogratulations! YOU WON!"), 450, 290, 30, GREEN);
		}
		DrawText(TextFormat("Level: %i", level), 20, 20, 25, BLACK);

        EndDrawing();
    }

    UnloadTexture(button);

    CloseWindow();
    return 0;
}