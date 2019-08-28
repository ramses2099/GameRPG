#include "pch.h"
#include "Game.h"


Game::Game() :window("that game engine")
{
	std::shared_ptr<SceneSplashScreen> splashScreen =
		std::make_shared<SceneSplashScreen>(workingDir, 
			sceneStateMachine, window,textureAllocator);

	std::shared_ptr<SceneGame> sceneGame =
		std::make_shared<SceneGame>(workingDir,textureAllocator);
	
	unsigned int splashScreenId = sceneStateMachine.Add(splashScreen);
	unsigned int gameScreenId = sceneStateMachine.Add(sceneGame);

	splashScreen->SetSwitchToScene(gameScreenId);

	sceneStateMachine.SwitchTo(splashScreenId);
	
	deltaTime = clock.restart().asSeconds();

	
}


Game::~Game()
{
}

void Game::ProcessInput()
{
	sceneStateMachine.ProccessInput();
}

void Game::Update()
{
	window.Update();

	sceneStateMachine.Update(deltaTime);

}

void Game::LateUpdate()
{
	sceneStateMachine.LateUpdate(deltaTime);
}

void Game::Draw()
{
	window.BeginDraw();

	sceneStateMachine.Draw(window);

	window.EndDraw();
	
}

bool Game::IsRunning() const
{
	return window.IsOpen();
}

void Game::CalculateDeltaTime()
{
	deltaTime = clock.restart().asSeconds();
}
