#include "pch.h"
#include "SceneSplashScreen.h"


SceneSplashScreen::SceneSplashScreen(WorkingDirectory& workingDir,
	SceneStateMachine& sceneStateMachine,
	Window& window,	ResourceAllocator<sf::Texture>& textureAllocator) :sceneStateMachine(sceneStateMachine),
	workingDir(workingDir), window(window),textureAllocator(textureAllocator), switchToState(0), currentSeconds(0.f),
	showForSeconds(3.f)
{
}


SceneSplashScreen::~SceneSplashScreen()
{
}

void SceneSplashScreen::OnCreate()
{

	int textureID = textureAllocator.add(workingDir.Get() + "graphics/mainmenu.png");
	
	if (textureID >= 0)
	{
	
		std::shared_ptr<sf::Texture> texture = textureAllocator.Get(textureID);
		splashSprite.setTexture(*texture);

		sf::FloatRect spriteSize = splashSprite.getLocalBounds();

		splashSprite.setOrigin(spriteSize.width * 0.5f,
			spriteSize.height * 0.5f);
		splashSprite.setScale(0.5f, 0.5f);

		sf::Vector2u windowCenter = window.GetCenter();

		splashSprite.setPosition(static_cast<float>(windowCenter.x),
			static_cast<float>(windowCenter.y));
	}
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
	}

}

void SceneSplashScreen::Draw(Window & window)
{
	window.Draw(splashSprite);
}
