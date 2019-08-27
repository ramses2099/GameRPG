#include "pch.h"
#include "SceneSplashScreen.h"


SceneSplashScreen::SceneSplashScreen(WorkingDirectory& workingDir,
	SceneStateMachine& sceneStateMachine,
	Window& window) :sceneStateMachine(sceneStateMachine),
	workingDir(workingDir), window(window), switchToState(0), currentSeconds(0.f),
	showForSeconds(3.f)
{
}


SceneSplashScreen::~SceneSplashScreen()
{
}

void SceneSplashScreen::OnCreate()
{
	splashTexture.loadFromFile(workingDir.Get() + "graphics/mainmenu.png");
	splashSprite.setTexture(splashTexture);

	sf::FloatRect spriteSize = splashSprite.getLocalBounds();

	splashSprite.setOrigin(spriteSize.width * 0.5f,
		spriteSize.height * 0.5f);
	splashSprite.setScale(0.5f, 0.5f);

	sf::Vector2u windowCenter = window.GetCenter();

	splashSprite.setPosition(static_cast<float>(windowCenter.x), 
		static_cast<float>(windowCenter.y));
}

void SceneSplashScreen::OnDestroy()
{
}

void SceneSplashScreen::OnActivate()
{
	currentSeconds = 0.f;
}

void SceneSplashScreen::SetSwitchToScene(unsigned int id)
{
	switchToState = id;
}

void SceneSplashScreen::Update(float deltaTime)
{
	
	currentSeconds += deltaTime;
	if(currentSeconds >= showForSeconds)
	{
		sceneStateMachine.SwitchTo(switchToState);
		std::cout << "ok";
	}

}

void SceneSplashScreen::Draw(Window & window)
{
	window.Draw(splashSprite);
}
