#include "Application.h"
#include "raylib.h"
#include <stdlib.h>

#include <iostream>

Application::Application()
{

}

Application::~Application()
{

}

void Application::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, "Simple Tilemap");
	SetTargetFPS(60);

	Load();

	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}

	Unload();
}

void Application::Load()
{
	// Task1:
	// Initialise all values in m_tiles array to a random
	// value between 0 and 5 exclusive;
	// -----------------------------------------------------
	
	for (int i = 0; i < ROWS * COLS; i++)
	{
		m_tiles[i] = GetRandomValue(0, 4);
	}

	// -----------------------------------------------------
}

void Application::Unload()
{

}

void Application::Update(float deltaTime)
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();

		// Task 3:
		// TODO: Calculate row and col index based on the mouse positon

		float mousePosX = mousePos.x;
		float mousePosY = mousePos.y;

		int rowIndex = mousePosY / m_tileWidth; 
		int colIndex = mousePosX / m_tileHeight;

		

		std::cout << mousePosX << ", " << mousePosY << std::endl;

		std::cout << rowIndex << ", " << colIndex << std::endl;


		// TODO: calculate the index of the tile clicked on based on the row/col index
		int tileIndex = rowIndex + (colIndex * (m_tileWidth + m_tileHeight));

		std::cout << tileIndex << std::endl;

		m_tiles[tileIndex] += 1;
		if (m_tiles[tileIndex] >= 5)
			m_tiles[tileIndex] = 0;
	}
}

void Application::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	// Task2:
	// use a nested loop to iterate over rows and columns
	// Use raylib's DrawRect method to draw each tile in the array.
	// 	   use the row and col index multipled by m_tileHeight/m_tileWidth
	// 	   to calculate the x and y position for each rectangle.
	// 
	// change the color of the rect drawn based on the value of the tile.
	// 	   We have created a helper function you can use "GetTileColor"
	// --------------------------------------------------------------------
	// write your code here
	float xPos = 0;
	float yPos = 0;
	int i = -1;
	/*for (int x = 0; x < ROWS; x++)
	{
		for (int y = 0; y < COLS; y++)
		{
			for (int i = 0; i < ROWS * COLS; i++)
			{
				xPos += 20;
				yPos += 20;
				int index = m_tiles[i] /*(COLS * x) + y;
				//std::cout << index << std::endl;
				Color color = GetTileColor(index); // pass in the tilevalue
				DrawRectangle(xPos, yPos, m_tileWidth, m_tileHeight, color);
			}
		}
	}*/

	for (xPos = 0; xPos < ROWS * m_tileWidth; xPos += m_tileWidth)
	{
		for (yPos = 0; yPos < ROWS * m_tileHeight; yPos += m_tileHeight)
		{
			i++;
			int index = m_tiles[i];
			Color color = GetTileColor(index); // pass in the tilevalue
			DrawRectangle(xPos, yPos, m_tileWidth, m_tileHeight, color);
		}
	}

	

	

	// --------------------------------------------------------------------

	EndDrawing();
}

Color Application::GetTileColor(int tileValue)
{
	switch (tileValue)
	{
	case 0: return WHITE;
	case 1: return RED;
	case 2: return GREEN;
	case 3: return BLUE;
	case 4: return YELLOW;
	}
	
	return BLACK;
}