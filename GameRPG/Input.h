#pragma once
#include <SFML/Graphics.hpp>
#include "Bitmask.h"

class Input
{
public:
	enum class Key
	{
		None = 0,
		Left = 1,
		Right = 2,
		Up = 3,
		Down = 4,
		Esc = 5
	};


	Input();
	~Input();
	bool IsKeyPressed(Key keyCode);
	bool IsKeyDown(Key keyCode);
	bool IsKeyUp(Key keyCode);

	void Update();
private:
	Bitmask thisFrameKeys;
	Bitmask lastFrameKeys;

};

