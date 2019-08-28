#include "pch.h"
#include "C_KeyboardMovement.h"
#include "Object.h"


C_KeyboardMovement::C_KeyboardMovement(Object* owner)
	:Component(owner), moveSpeed(100)
{
}

C_KeyboardMovement::~C_KeyboardMovement()
{
}

void C_KeyboardMovement::SetInput(Input * input)
{
	this->input = input;
}

void C_KeyboardMovement::SetMovementSpeed(int moveSpeed)
{
	this->moveSpeed = moveSpeed;
}

void C_KeyboardMovement::Update(float deltaTime)
{
	if (input == nullptr)
	{
		return;
	}

	int xMove = 0;
	if (input->IsKeyPressed(Input::Key::Left))
	{
		xMove = -moveSpeed;
	}
	else if (input->IsKeyPressed(Input::Key::Right))
	{
		xMove = moveSpeed;
	}

	int yMove = 0;
	if (input->IsKeyPressed(Input::Key::Up))
	{
		yMove = -moveSpeed;
	}
	else if (input->IsKeyPressed(Input::Key::Down))
	{
		yMove = moveSpeed;
	}

	float xFrameMove = xMove * deltaTime;
	float yFrameMove = yMove * deltaTime;

	owner->transform->AddPosition(xFrameMove, yFrameMove);


}
