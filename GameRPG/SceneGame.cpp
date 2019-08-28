#include "pch.h"
#include "SceneGame.h"


SceneGame::SceneGame(WorkingDirectory& workingDir,
	ResourceAllocator<sf::Texture>& textureAllocator)
	:workingDir(workingDir),textureAllocator(textureAllocator)
{
}

void SceneGame::OnCreate()
{

	player = std::make_shared<Object>();
	auto sprite = player->AddComponent<C_Sprite>();
	sprite->SetTextureAllocator(&textureAllocator);
	sprite->Load(workingDir.Get() + "graphics/Sprite-boter.png");
	
	auto tran = player->GetComponent<C_Transform>();
	tran->SetPosition(sf::Vector2f(250.f, 250.f));

	auto movement = player->AddComponent<C_KeyboardMovement>();	
	movement->SetInput(&input);

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
	player->LateUpdate(deltaTime);
}

void SceneGame::Update(float deltaTime)
{
	player->Update(deltaTime);
}

void SceneGame::Draw(Window & window)
{
	player->Draw(window);
}

SceneGame::~SceneGame()
{
}
