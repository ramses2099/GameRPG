#pragma once
#include "Scene.h"
#include "Input.h"
#include "WorkingDirectory.h"

class SceneGame:public Scene
{
public:
	SceneGame(WorkingDirectory& workingDir);

	void OnCreate()override;
	void OnDestroy()override;

	void OnActivate()override;
		
	void ProcessInput();
	void Update(float deltaTime)override;
	void Draw(Window& window)override;
	~SceneGame();

private:
	WorkingDirectory& workingDir;
	Input input;
	
	sf::Sprite sprite;
	sf::Texture texture;
};

