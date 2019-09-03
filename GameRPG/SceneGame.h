#pragma once
#include "Scene.h"
#include "Input.h"
#include "WorkingDirectory.h"
#include "Object.h"
#include "C_Sprite.h"
#include "C_KeyboardMovement.h"
#include "ResourceAllocator.h"
#include "ObjectCollection.h"


class SceneGame:public Scene
{
public:
	SceneGame(WorkingDirectory& workingDir,
		ResourceAllocator<sf::Texture>& textureAllocator);

	void OnCreate()override;
	void OnDestroy()override;

	void OnActivate()override;
		
	void ProcessInput();
	void LateUpdate(float deltaTime)override;
	void Update(float deltaTime)override;
	void Draw(Window& window)override;
	~SceneGame();

private:
	WorkingDirectory& workingDir;
	ResourceAllocator<sf::Texture>& textureAllocator;
	Input input;
	
	ObjectCollection objects;

	
};

