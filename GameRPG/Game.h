#pragma once
#include "Window.h"
class Game
{
public:
	Game();
	~Game();
	void Update();
	void LateUpdate();
	void Draw();
	bool IsRunning() const;
private:
	Window window;
};

