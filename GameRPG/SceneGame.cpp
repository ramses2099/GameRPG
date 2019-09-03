#include "pch.h"
#include "SceneGame.h"
#include "C_Animation.h"


SceneGame::SceneGame(WorkingDirectory& workingDir,
	ResourceAllocator<sf::Texture>& textureAllocator)
	:workingDir(workingDir), textureAllocator(textureAllocator)
{
}

void SceneGame::OnCreate()
{

	std::shared_ptr<Object> player = std::make_shared<Object>();

	auto sprite = player->AddComponent<C_Sprite>();
	sprite->SetTextureAllocator(&textureAllocator);

	auto movement = player->AddComponent<C_KeyboardMovement>();
	movement->SetInput(&input);

	auto animation = player->AddComponent<C_Animation>();
	int vikingTextureID = textureAllocator.add(workingDir.Get() + "graphics/Viking.png");

	const int frameWidth = 165;
	const int frameHeight = 145;
	/*--
	sprite->Load(workingDir.Get() + "graphics/Sprite-boter.png");

	auto tran = player->GetComponent<C_Transform>();
	tran->SetPosition(sf::Vector2f(250.f, 250.f));
	

	std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>(FacingDirection::Right);//2

	// How long we want to show each frame.
	const float idleAnimFrameSeconds = 0.2f;

	idleAnimation->AddFrame(vikingTextureID, 600, 0,
		frameWidth, frameHeight, idleAnimFrameSeconds);//3
	idleAnimation->AddFrame(vikingTextureID, 800, 0,
		frameWidth, frameHeight, idleAnimFrameSeconds);
	idleAnimation->AddFrame(vikingTextureID, 0, 145,
		frameWidth, frameHeight, idleAnimFrameSeconds);
	idleAnimation->AddFrame(vikingTextureID, 200, 145,
		frameWidth, frameHeight, idleAnimFrameSeconds);

	// This adds the idle animation that we’ve just built. 
	// It will also set it as our active animation.
	animation->AddAnimation(AnimationState::Idle, idleAnimation);
	*/
	std::shared_ptr<Animation> walkAnimation =
		std::make_shared<Animation>(FacingDirection::Right);
	const float walkAnimFrameSeconds = 0.15f;

	// Create the frames.
	walkAnimation->AddFrame(vikingTextureID, 600, 290,
		frameWidth, frameHeight, walkAnimFrameSeconds);
	walkAnimation->AddFrame(vikingTextureID, 800, 290,
		frameWidth, frameHeight, walkAnimFrameSeconds);
	walkAnimation->AddFrame(vikingTextureID, 0, 435,
		frameWidth, frameHeight, walkAnimFrameSeconds);
	walkAnimation->AddFrame(vikingTextureID, 200, 435,
		frameWidth, frameHeight, walkAnimFrameSeconds);
	walkAnimation->AddFrame(vikingTextureID, 400, 435,
		frameWidth, frameHeight, walkAnimFrameSeconds);

	// Add animation to our Viking.
	animation->AddAnimation(AnimationState::Walk, walkAnimation);


	objects.Add(player);

}

void SceneGame::OnDestroy()
{
}

void SceneGame::OnActivate()
{
}


void SceneGame::ProcessInput()
{
	input.Update();
}

void SceneGame::LateUpdate(float deltaTime)
{
	objects.LateUpdate(deltaTime);
}

void SceneGame::Update(float deltaTime)
{
	objects.ProcessRemovals();
	objects.ProcessNewObjects();

	objects.Update(deltaTime);
}

void SceneGame::Draw(Window & window)
{
	objects.Draw(window);
}

SceneGame::~SceneGame()
{
}
