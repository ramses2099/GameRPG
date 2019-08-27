#include "pch.h"
#include "SceneGame.h"


SceneGame::SceneGame(WorkingDirectory& workingDir):workingDir(workingDir)
{
}

void SceneGame::OnCreate()
{
	texture.loadFromFile(workingDir.Get() + "graphics/slime01.png");
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(350.f, 350.f));
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

void SceneGame::Update(float deltaTime)
{
	const sf::Vector2f& pos = sprite.getPosition();
	const int moveSpeed = 200; //1

	int xMove = 0;
	if (input.IsKeyPressed(Input::Key::Left))
	{
		xMove = -moveSpeed;
	}
	else if (input.IsKeyPressed(Input::Key::Right))
	{
		xMove = moveSpeed;
	}

	int yMove = 0;
	if (input.IsKeyPressed(Input::Key::Up))
	{
		yMove = -moveSpeed;
	}
	else if (input.IsKeyPressed(Input::Key::Down))
	{
		yMove = moveSpeed;
	}

	float xFrameMove = xMove * deltaTime;
	float yFrameMove = yMove * deltaTime;

	sprite.setPosition(pos.x + xFrameMove, pos.y + yFrameMove);

}

void SceneGame::Draw(Window & window)
{
	window.Draw(sprite);
}

SceneGame::~SceneGame()
{
}
