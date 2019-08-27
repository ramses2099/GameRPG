#pragma once
#include "Window.h"
#include "WorkingDirectory.h"
#include "Input.h"
#include "SceneStateMachine.h"
#include "SceneSplashScreen.h"
#include "SceneGame.h"

class Game
{
public:
	Game();
	~Game();
	void ProcessInput();
	void Update();
	void LateUpdate();
	void Draw();
	bool IsRunning() const;

	void CalculateDeltaTime();
private:
	Window window;
	WorkingDirectory workingDir;
	Input input;

	sf::Clock clock;
	float deltaTime;

	SceneStateMachine sceneStateMachine;

};

