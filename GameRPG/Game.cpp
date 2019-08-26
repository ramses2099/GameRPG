#include "pch.h"
#include "Game.h"


Game::Game():window("that game engine")
{
}


Game::~Game()
{
}

void Game::Update()
{
	window.Update();
}

void Game::LateUpdate()
{
}

void Game::Draw()
{
	window.BeginDraw();

	window.EndDraw();
}

bool Game::IsRunning() const
{
	return window.IsOpen();
}
